/******************************************************************************
 * @file mainwindow.cpp
 * @brief Main window for the application
 * @author Martin C. Foster
 * @date 2025-04-23 
 * 
 * @version 1.0
 * @brief
 * This file contains the implementation of the main window for the 
 * application. It is responsible for handling user input and output,
 * and for converting binary files to hexadecimal or BASIC format.  
 * It provides the user interface for the application, including buttons for 
 * selecting input and output files, and for converting binary files to 
 * hexadecimal or BASIC format.
 * 
 * @section Revision History
 * | Version | Date       | Author            | Description                              |
 * |---------|------------|-------------------|--------------------------------
 * | 1.0     | 2025-04-25 | Martin C. Foster  | Added some comments.
 * 
 ********************************************************************************/
 
#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnBrowse_clicked()
{
    const QStringList filters({"Binary files (*.prg *.elf *.bin *.)",
        "Any files (*)"
    });
    QString filename;
    QFileDialog dialog(this);
    dialog.setWindowTitle("Select input binary file");
    dialog.setAcceptMode(QFileDialog::AcceptOpen);
    dialog.setNameFilters(filters);
    if(dialog.exec()){
        filename = dialog.selectedFiles().constFirst();  //first();
        ui->EditInputFile->setText(filename);
    }
}


void MainWindow::on_btnBrowse_2_clicked()
{
    const QStringList filters({"Any files (*)"
    });
    QString filename;
    QFileDialog dialog(this);
    dialog.setWindowTitle("Select output text file");
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    dialog.setNameFilters(filters);
    if(dialog.exec()){
        filename = dialog.selectedFiles().constFirst();  //first();
        ui->EditOutputFile->setText(filename);
    }
}

void MainWindow::on_buttonBox_accepted()
{
    qInfo("Accept clicked");
    QString inFileName = ui->EditInputFile->text();
    QString outFileName = ui->EditOutputFile->text();
    QFile infile(inFileName);
    QFile outfile(outFileName);
    if(!infile.open(QIODevice::ReadOnly)){
        qWarning() << "Can't open input file: " << inFileName;
        return;
    }
    if(!outfile.open(QIODevice::WriteOnly)){
        qWarning() << "Can't open output file: " << outFileName;
        infile.close();
        return;
    }
    if(ui->radioBasic->isChecked())
        writeBasic(infile, outfile);
    else
        writeHex(infile, outfile);
    infile.close();
    outfile.close();


}

void MainWindow::on_buttonBox_rejected()
{
    qInfo("Reject clicked");
    QApplication::quit();
}

/**
 * @brief Reads a 16-bit starting address and data from an input file, and writes corresponding hexadecimal data to an output file.
 *
 * This function processes the contents of the input file by reading the first two bytes as a 16-bit starting address, then
 * reading the remaining bytes as data. The address is interpreted in little-endian order and written to the output file
 * as part of a formatted string. Each subsequent byte of data is converted to its hexadecimal representation and written
 * line by line. At the end, the function writes a final instruction to exit the insert data mode, return to the starting address, and execute.
 *
 * @param[in] infile Reference to a QFile object representing the input file containing raw bytes to process.
 * @param[out] outfile Reference to a QFile object where the processed hexadecimal representation will be written.
 */
void MainWindow::writeHex(QFile &infile, QFile &outfile)
{
    uchar byte;
    char s[8] = {0};

    QByteArray data = infile.read(2);
    if(data.size() < 2) {
        qWarning() << "error: Expected 16 bit address at the start of the file.\n";
        return; // Error
    }
    auto addrl = static_cast<uchar>(data[0]),addrh = static_cast<uchar>(data[1]);
    ushort const addr = addrl + (addrh << 8);

    sprintf(s, ".%04X/", addr);
    outfile.write(s);

    // Next read all the other bytes
    while (!infile.atEnd()) {
        data = infile.read(1);
        sprintf(s, "%02X\n", static_cast<uchar>(data[0]));
        outfile.write(s);
    }
    // Exit insert data mode and return to the start address and Go
    sprintf(s,".%04XG\n", addr);
    outfile.write(s);
}

void MainWindow::writeBasic(QFile &infile, QFile &outfile)
{
    constexpr int StartLineNumber = 9000;
    constexpr int LineIncrement = 10;
    constexpr int ItemsPerLine = 10;

    uchar byte;
    char s[120] = {0};

    QByteArray data = infile.read(2);

    // The first two bytes should be the starting address
    if(data.size() < 2) {
        qWarning() << "error: Expected 16 bit address at the start of the file.\n";
        return;
    }
    auto addrl = static_cast<uchar>(data[0]),addrh = static_cast<uchar>(data[1]);
    ushort const addr = addrl + (addrh << 8);
    uint lineNo = StartLineNumber;

    sprintf(s, "\n%u DATA %u",lineNo,addr);
    outfile.write(s);
    lineNo += LineIncrement;
    uint count = 0;
    // Next read all the other bytes to data statements
    while (!infile.atEnd()) {
        data = infile.read(1);
        if(count%ItemsPerLine == 0) {
            sprintf(s,"\n%u DATA ", lineNo);
            outfile.write(s);
            lineNo += LineIncrement;
        } else {
            outfile.write(", ");
        };
        sprintf (s,"%u", static_cast<uchar>(data[0]));
        outfile.write(s);
        count++;
    }
    outfile.write("\n");
    sprintf(s, "%u REM PUT THE DATA INTO RAM\n", lineNo);
    outfile.write(s);
    lineNo += LineIncrement;
    sprintf(s, "%u READ AD\n", lineNo);
    outfile.write(s);
    lineNo += LineIncrement;
    sprintf(s, "%u FOR I=AD TO AD+%d\n", lineNo, count-1);
    outfile.write(s);
    lineNo += LineIncrement;
    sprintf(s, "%u READ D:POKE I,D\n", lineNo);
    outfile.write(s);
    lineNo += LineIncrement;
    sprintf(s, "%u NEXT\n", lineNo);
    outfile.write(s);
    lineNo += LineIncrement;
    sprintf(s, "%u REM SET USR ADDR.\n", lineNo);
    outfile.write(s);
    lineNo += LineIncrement;
    sprintf(s, "%u POKE 11, %u: POKE 12, %u\n", lineNo, addrl, addrh);
    outfile.write(s);
    lineNo += LineIncrement;
    sprintf(s, "%u REM RUN THE PROGRAM\n", lineNo);
    outfile.write(s);
    lineNo += LineIncrement;
    sprintf(s, "%u X = USR(X)\n", lineNo);
    outfile.write(s);

}

QString MainWindow::wordToHex(qint16 word)
{
    qint8 hiByte = word / 256;
    qint8 lowByte = word % 256;
    QString hex = byteToHex(hiByte) + byteToHex(lowByte);
    return hex;
}

QString MainWindow::byteToHex(qint8 byte)
{
    QString nibs[] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F" };
    QString hex = nibs[byte/16] + nibs[byte%16];

    return hex;
}
