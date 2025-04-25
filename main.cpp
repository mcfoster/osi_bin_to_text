/*************************************************************
 * @file main.cpp
 * @brief Main function for the application
 * @author Martin C. Foster
 * @date 2023-10-01
 * @version 1.0
 */
#include "mainwindow.h"
#include <QApplication>

/********************
 * Main function
 * 
 * @param argc
 * @param argv Currently not used
 * @return 0 for success, otherwise the error code.
 * @brief
 * This is the main function of the application. 
 * It simply displays the main window for this application
 * which is described in mainwindow.cpp.
*************************************************************/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
