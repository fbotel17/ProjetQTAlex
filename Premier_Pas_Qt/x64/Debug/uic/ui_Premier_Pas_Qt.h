/********************************************************************************
** Form generated from reading UI file 'Premier_Pas_Qt.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREMIER_PAS_QT_H
#define UI_PREMIER_PAS_QT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Premier_Pas_QtClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *NameLineEdit;
    QLineEdit *PassLineEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *MSGEdit;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *DialBox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Premier_Pas_QtClass)
    {
        if (Premier_Pas_QtClass->objectName().isEmpty())
            Premier_Pas_QtClass->setObjectName(QString::fromUtf8("Premier_Pas_QtClass"));
        Premier_Pas_QtClass->resize(828, 549);
        centralWidget = new QWidget(Premier_Pas_QtClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(60, 420, 261, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 460, 371, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 0, 311, 31));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 40, 47, 13));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 70, 61, 16));
        NameLineEdit = new QLineEdit(centralWidget);
        NameLineEdit->setObjectName(QString::fromUtf8("NameLineEdit"));
        NameLineEdit->setGeometry(QRect(90, 40, 113, 20));
        PassLineEdit = new QLineEdit(centralWidget);
        PassLineEdit->setObjectName(QString::fromUtf8("PassLineEdit"));
        PassLineEdit->setGeometry(QRect(90, 70, 113, 20));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 100, 75, 23));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(44, 340, 91, 31));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(600, 20, 47, 20));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(430, 70, 391, 61));
        MSGEdit = new QLineEdit(centralWidget);
        MSGEdit->setObjectName(QString::fromUtf8("MSGEdit"));
        MSGEdit->setGeometry(QRect(140, 340, 391, 31));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(30, 130, 781, 191));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 779, 189));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        DialBox = new QLabel(scrollAreaWidgetContents);
        DialBox->setObjectName(QString::fromUtf8("DialBox"));
        DialBox->setCursor(QCursor(Qt::ArrowCursor));

        gridLayout->addWidget(DialBox, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);
        Premier_Pas_QtClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Premier_Pas_QtClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 828, 21));
        Premier_Pas_QtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Premier_Pas_QtClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Premier_Pas_QtClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Premier_Pas_QtClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Premier_Pas_QtClass->setStatusBar(statusBar);

        retranslateUi(Premier_Pas_QtClass);
        QObject::connect(pushButton, SIGNAL(clicked()), Premier_Pas_QtClass, SLOT(onDisplayMessageButtonClicked()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), Premier_Pas_QtClass, SLOT(onDisplayConnexionClicked()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), Premier_Pas_QtClass, SLOT(onSendMessageButtonClicked()));

        QMetaObject::connectSlotsByName(Premier_Pas_QtClass);
    } // setupUi

    void retranslateUi(QMainWindow *Premier_Pas_QtClass)
    {
        Premier_Pas_QtClass->setWindowTitle(QCoreApplication::translate("Premier_Pas_QtClass", "Premier_Pas_Qt", nullptr));
        pushButton->setText(QCoreApplication::translate("Premier_Pas_QtClass", " Afficher le message de secour", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QCoreApplication::translate("Premier_Pas_QtClass", "Pseudo :", nullptr));
        label_4->setText(QCoreApplication::translate("Premier_Pas_QtClass", "Password :", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Premier_Pas_QtClass", "Connexion", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Premier_Pas_QtClass", "SEND NUDE", nullptr));
        label_5->setText(QCoreApplication::translate("Premier_Pas_QtClass", "SERVER", nullptr));
        label_6->setText(QString());
        DialBox->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Premier_Pas_QtClass: public Ui_Premier_Pas_QtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREMIER_PAS_QT_H
