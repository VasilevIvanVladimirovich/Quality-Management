/********************************************************************************
** Form generated from reading UI file 'reports.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTS_H
#define UI_REPORTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Reports
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget;
    QFrame *frame1;
    QHBoxLayout *horizontalLayout;
    QWidget *tab_2;

    void setupUi(QWidget *Reports)
    {
        if (Reports->objectName().isEmpty())
            Reports->setObjectName(QString::fromUtf8("Reports"));
        Reports->resize(619, 556);
        verticalLayout = new QVBoxLayout(Reports);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(Reports);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMaximumSize(QSize(16777215, 16777215));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tableWidget = new QTableWidget(tab);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setMaximumSize(QSize(16777215, 250));

        verticalLayout_2->addWidget(tableWidget);

        frame1 = new QFrame(tab);
        frame1->setObjectName(QString::fromUtf8("frame1"));
        frame1->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout = new QHBoxLayout(frame1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        verticalLayout_2->addWidget(frame1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(Reports);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Reports);
    } // setupUi

    void retranslateUi(QWidget *Reports)
    {
        Reports->setWindowTitle(QCoreApplication::translate("Reports", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Reports", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Reports", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Reports: public Ui_Reports {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTS_H
