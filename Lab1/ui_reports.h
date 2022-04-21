/********************************************************************************
** Form generated from reading UI file 'reports.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTS_H
#define UI_REPORTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Reports
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidget;
    QFormLayout *formLayout;
    QFrame *frameImpotant;
    QHBoxLayout *horizontalLayout_5;
    QTableWidget *tableImpotant;
    QFormLayout *formLayout_2;
    QTableWidget *tableSatisfaction;
    QFrame *frameSatisfaction;
    QHBoxLayout *horizontalLayout_6;
    QFormLayout *formLayout_3;
    QTableWidget *tableDiscrepancy;
    QFrame *frame1;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QFormLayout *formLayout_4;
    QTableWidget *tablePoint;
    QFrame *frame2;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;

    void setupUi(QWidget *Reports)
    {
        if (Reports->objectName().isEmpty())
            Reports->setObjectName(QString::fromUtf8("Reports"));
        Reports->resize(1235, 692);
        Reports->setMaximumSize(QSize(16777215, 800));
        verticalLayout = new QVBoxLayout(Reports);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(Reports);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -1679, 1194, 2358));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tableWidget = new QTableWidget(scrollAreaWidgetContents);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setMinimumSize(QSize(0, 250));
        tableWidget->setMaximumSize(QSize(16777215, 250));

        verticalLayout_3->addWidget(tableWidget);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        frameImpotant = new QFrame(scrollAreaWidgetContents);
        frameImpotant->setObjectName(QString::fromUtf8("frameImpotant"));
        frameImpotant->setMinimumSize(QSize(0, 500));
        horizontalLayout_5 = new QHBoxLayout(frameImpotant);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));

        formLayout->setWidget(0, QFormLayout::FieldRole, frameImpotant);

        tableImpotant = new QTableWidget(scrollAreaWidgetContents);
        tableImpotant->setObjectName(QString::fromUtf8("tableImpotant"));
        tableImpotant->setMinimumSize(QSize(550, 0));
        tableImpotant->setMaximumSize(QSize(16777215, 16777215));

        formLayout->setWidget(0, QFormLayout::LabelRole, tableImpotant);


        verticalLayout_3->addLayout(formLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        tableSatisfaction = new QTableWidget(scrollAreaWidgetContents);
        tableSatisfaction->setObjectName(QString::fromUtf8("tableSatisfaction"));
        tableSatisfaction->setMinimumSize(QSize(550, 0));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, tableSatisfaction);

        frameSatisfaction = new QFrame(scrollAreaWidgetContents);
        frameSatisfaction->setObjectName(QString::fromUtf8("frameSatisfaction"));
        frameSatisfaction->setMinimumSize(QSize(0, 500));
        horizontalLayout_6 = new QHBoxLayout(frameSatisfaction);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, frameSatisfaction);


        verticalLayout_3->addLayout(formLayout_2);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        tableDiscrepancy = new QTableWidget(scrollAreaWidgetContents);
        tableDiscrepancy->setObjectName(QString::fromUtf8("tableDiscrepancy"));
        tableDiscrepancy->setMinimumSize(QSize(550, 0));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, tableDiscrepancy);

        frame1 = new QFrame(scrollAreaWidgetContents);
        frame1->setObjectName(QString::fromUtf8("frame1"));
        frame1->setMinimumSize(QSize(0, 500));
        frame1->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout = new QHBoxLayout(frame1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, frame1);


        verticalLayout_3->addLayout(formLayout_3);

        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 50));

        verticalLayout_3->addWidget(label);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        tablePoint = new QTableWidget(scrollAreaWidgetContents);
        tablePoint->setObjectName(QString::fromUtf8("tablePoint"));
        tablePoint->setMinimumSize(QSize(550, 0));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, tablePoint);

        frame2 = new QFrame(scrollAreaWidgetContents);
        frame2->setObjectName(QString::fromUtf8("frame2"));
        frame2->setMinimumSize(QSize(0, 500));
        horizontalLayout_3 = new QHBoxLayout(frame2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, frame2);


        verticalLayout_3->addLayout(formLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));

        verticalLayout_3->addLayout(horizontalLayout_2);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(Reports);

        QMetaObject::connectSlotsByName(Reports);
    } // setupUi

    void retranslateUi(QWidget *Reports)
    {
        Reports->setWindowTitle(QCoreApplication::translate("Reports", "Form", nullptr));
        label->setText(QCoreApplication::translate("Reports", "\320\243\320\264\320\276\320\262\320\273\320\265\321\202\320\262\320\276\321\200\321\221\320\275\320\275\320\276\321\201\321\202\321\214 \320\277\320\276\321\202\321\200\320\265\320\261\320\270\321\202\320\265\320\273\321\217:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Reports: public Ui_Reports {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTS_H
