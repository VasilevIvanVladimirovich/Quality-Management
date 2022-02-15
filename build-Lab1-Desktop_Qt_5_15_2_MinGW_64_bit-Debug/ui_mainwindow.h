/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidgetImportance;
    QTableWidget *tableWidgetSatisfaction;
    QFormLayout *formLayout;
    QLabel *labelRespondent;
    QSpinBox *spinBoxRespondent;
    QLabel *labelCriteria;
    QSpinBox *spinBoxCriteria;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(639, 365);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidgetImportance = new QTableWidget(centralwidget);
        tableWidgetImportance->setObjectName(QString::fromUtf8("tableWidgetImportance"));

        verticalLayout->addWidget(tableWidgetImportance);

        tableWidgetSatisfaction = new QTableWidget(centralwidget);
        tableWidgetSatisfaction->setObjectName(QString::fromUtf8("tableWidgetSatisfaction"));

        verticalLayout->addWidget(tableWidgetSatisfaction);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        labelRespondent = new QLabel(centralwidget);
        labelRespondent->setObjectName(QString::fromUtf8("labelRespondent"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelRespondent);

        spinBoxRespondent = new QSpinBox(centralwidget);
        spinBoxRespondent->setObjectName(QString::fromUtf8("spinBoxRespondent"));
        spinBoxRespondent->setMaximum(9999);

        formLayout->setWidget(0, QFormLayout::FieldRole, spinBoxRespondent);

        labelCriteria = new QLabel(centralwidget);
        labelCriteria->setObjectName(QString::fromUtf8("labelCriteria"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelCriteria);

        spinBoxCriteria = new QSpinBox(centralwidget);
        spinBoxCriteria->setObjectName(QString::fromUtf8("spinBoxCriteria"));

        formLayout->setWidget(1, QFormLayout::FieldRole, spinBoxCriteria);


        verticalLayout->addLayout(formLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 639, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelRespondent->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273-\320\262\320\276 \321\200\320\265\321\201\320\277\320\276\320\275\320\264\320\265\321\202\320\276\320\262", nullptr));
        labelCriteria->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273-\320\262\320\276 \320\272\321\200\320\270\321\202\320\265\321\200\320\270\320\265\320\262", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\241\321\204\320\276\321\200\320\274\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\206\321\203", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\321\207\321\221\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
