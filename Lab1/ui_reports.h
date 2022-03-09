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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Reports
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame1;
    QHBoxLayout *horizontalLayout;
    QFrame *frame2;
    QHBoxLayout *horizontalLayout_3;

    void setupUi(QWidget *Reports)
    {
        if (Reports->objectName().isEmpty())
            Reports->setObjectName(QString::fromUtf8("Reports"));
        Reports->resize(670, 494);
        Reports->setMaximumSize(QSize(16777215, 800));
        verticalLayout = new QVBoxLayout(Reports);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget = new QTableWidget(Reports);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setMaximumSize(QSize(16777215, 250));

        verticalLayout->addWidget(tableWidget);

        label = new QLabel(Reports);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 50));

        verticalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        frame1 = new QFrame(Reports);
        frame1->setObjectName(QString::fromUtf8("frame1"));
        frame1->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout = new QHBoxLayout(frame1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        horizontalLayout_2->addWidget(frame1);

        frame2 = new QFrame(Reports);
        frame2->setObjectName(QString::fromUtf8("frame2"));
        horizontalLayout_3 = new QHBoxLayout(frame2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));

        horizontalLayout_2->addWidget(frame2);


        verticalLayout->addLayout(horizontalLayout_2);


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
