/********************************************************************************
** Form generated from reading UI file 'mainwindowxIlpCd.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWXILPCD_H
#define MAINWINDOWXILPCD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *EditInputFile;
    QLabel *label;
    QPushButton *btnBrowse;
    QPushButton *btnBrowse_2;
    QLabel *label_2;
    QLineEdit *EditOutputFile;
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QRadioButton *radioMonitor;
    QRadioButton *radioBasic;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(535, 231);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        EditInputFile = new QLineEdit(centralwidget);
        EditInputFile->setObjectName("EditInputFile");
        EditInputFile->setGeometry(QRect(30, 40, 451, 21));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EditInputFile->sizePolicy().hasHeightForWidth());
        EditInputFile->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(12);
        EditInputFile->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 20, 231, 16));
        label->setFont(font);
        btnBrowse = new QPushButton(centralwidget);
        btnBrowse->setObjectName("btnBrowse");
        btnBrowse->setGeometry(QRect(490, 40, 31, 24));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(12);
        font1.setBold(true);
        btnBrowse->setFont(font1);
        btnBrowse_2 = new QPushButton(centralwidget);
        btnBrowse_2->setObjectName("btnBrowse_2");
        btnBrowse_2->setGeometry(QRect(490, 90, 31, 24));
        btnBrowse_2->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 70, 231, 16));
        label_2->setFont(font);
        EditOutputFile = new QLineEdit(centralwidget);
        EditOutputFile->setObjectName("EditOutputFile");
        EditOutputFile->setGeometry(QRect(30, 90, 451, 21));
        sizePolicy.setHeightForWidth(EditOutputFile->sizePolicy().hasHeightForWidth());
        EditOutputFile->setSizePolicy(sizePolicy);
        EditOutputFile->setFont(font);
        buttonBox = new QDialogButtonBox(centralwidget);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(360, 190, 166, 24));
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(30, 120, 281, 91));
        radioMonitor = new QRadioButton(groupBox);
        radioMonitor->setObjectName("radioMonitor");
        radioMonitor->setGeometry(QRect(20, 30, 181, 22));
        radioMonitor->setChecked(true);
        radioBasic = new QRadioButton(groupBox);
        radioBasic->setObjectName("radioBasic");
        radioBasic->setGeometry(QRect(20, 60, 181, 22));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Binary input file:", nullptr));
#if QT_CONFIG(tooltip)
        btnBrowse->setToolTip(QCoreApplication::translate("MainWindow", "Browse for file", nullptr));
#endif // QT_CONFIG(tooltip)
        btnBrowse->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
#if QT_CONFIG(tooltip)
        btnBrowse_2->setToolTip(QCoreApplication::translate("MainWindow", "Browse for file", nullptr));
#endif // QT_CONFIG(tooltip)
        btnBrowse_2->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Text output file:", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Output format", nullptr));
#if QT_CONFIG(tooltip)
        radioMonitor->setToolTip(QCoreApplication::translate("MainWindow", "Output ad OSI Monitor Hex format", nullptr));
#endif // QT_CONFIG(tooltip)
        radioMonitor->setText(QCoreApplication::translate("MainWindow", "Monitor hex format", nullptr));
#if QT_CONFIG(tooltip)
        radioBasic->setToolTip(QCoreApplication::translate("MainWindow", "Output as BASIC data statements", nullptr));
#endif // QT_CONFIG(tooltip)
        radioBasic->setText(QCoreApplication::translate("MainWindow", "Basic data statements", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWXILPCD_H
