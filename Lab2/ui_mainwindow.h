/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_3;
    QFrame *frameRuleTwo;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QFormLayout *formLayout_4;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineMaxThird;
    QLineEdit *lineMinThird;
    QLineEdit *lineAvgThird;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *lineRangThird;
    QLabel *label_18;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_9;
    QFormLayout *formLayout_5;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *lineMaxSecond;
    QLineEdit *lineMinSecond;
    QLineEdit *lineSecondAvg;
    QSpacerItem *verticalSpacer_3;
    QLineEdit *lineRangSecond;
    QLabel *label_19;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QFormLayout *formLayout_3;
    QLabel *label_2;
    QLineEdit *LineMaxOne;
    QLabel *label_3;
    QLineEdit *lineMinOne;
    QLabel *label_4;
    QLineEdit *lineAvgOne;
    QSpacerItem *verticalSpacer;
    QLineEdit *lineRangOne;
    QLabel *label_17;
    QFrame *frameRuleFourth;
    QFormLayout *formLayout_2;
    QFrame *frameRuleThird;
    QGridLayout *gridLayout;
    QFrame *frameRuleOne;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_13;
    QFormLayout *formLayout_6;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLineEdit *linMaxFourth;
    QLineEdit *lineMinFourth;
    QLineEdit *lineAvgFourth;
    QSpacerItem *verticalSpacer_4;
    QLineEdit *lineRangFourth;
    QLabel *label_20;
    QFormLayout *formLayout_7;
    QLabel *label_21;
    QSpinBox *spinBoxCast;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1530, 1115);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(-213, -58, 1705, 1029));
        gridLayout_3 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        frameRuleTwo = new QFrame(scrollAreaWidgetContents);
        frameRuleTwo->setObjectName(QString::fromUtf8("frameRuleTwo"));
        frameRuleTwo->setMinimumSize(QSize(650, 500));
        formLayout = new QFormLayout(frameRuleTwo);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));

        gridLayout_3->addWidget(frameRuleTwo, 0, 3, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_2->addWidget(label_5);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_6);

        label_7 = new QLabel(scrollAreaWidgetContents);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_7);

        label_8 = new QLabel(scrollAreaWidgetContents);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label_8);

        lineMaxThird = new QLineEdit(scrollAreaWidgetContents);
        lineMaxThird->setObjectName(QString::fromUtf8("lineMaxThird"));
        lineMaxThird->setMaximumSize(QSize(16777215, 16777215));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, lineMaxThird);

        lineMinThird = new QLineEdit(scrollAreaWidgetContents);
        lineMinThird->setObjectName(QString::fromUtf8("lineMinThird"));
        lineMinThird->setMaximumSize(QSize(16777215, 16777215));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, lineMinThird);

        lineAvgThird = new QLineEdit(scrollAreaWidgetContents);
        lineAvgThird->setObjectName(QString::fromUtf8("lineAvgThird"));
        lineAvgThird->setMaximumSize(QSize(16777215, 16777215));

        formLayout_4->setWidget(2, QFormLayout::FieldRole, lineAvgThird);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_4->setItem(4, QFormLayout::FieldRole, verticalSpacer_2);

        lineRangThird = new QLineEdit(scrollAreaWidgetContents);
        lineRangThird->setObjectName(QString::fromUtf8("lineRangThird"));
        lineRangThird->setStyleSheet(QString::fromUtf8("background-color: green;"));

        formLayout_4->setWidget(3, QFormLayout::FieldRole, lineRangThird);

        label_18 = new QLabel(scrollAreaWidgetContents);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        formLayout_4->setWidget(3, QFormLayout::LabelRole, label_18);


        verticalLayout_2->addLayout(formLayout_4);


        gridLayout_3->addLayout(verticalLayout_2, 1, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_9 = new QLabel(scrollAreaWidgetContents);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_3->addWidget(label_9);

        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        label_10 = new QLabel(scrollAreaWidgetContents);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_10);

        label_11 = new QLabel(scrollAreaWidgetContents);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout_5->setWidget(1, QFormLayout::LabelRole, label_11);

        label_12 = new QLabel(scrollAreaWidgetContents);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout_5->setWidget(2, QFormLayout::LabelRole, label_12);

        lineMaxSecond = new QLineEdit(scrollAreaWidgetContents);
        lineMaxSecond->setObjectName(QString::fromUtf8("lineMaxSecond"));
        lineMaxSecond->setMaximumSize(QSize(16777215, 16777215));

        formLayout_5->setWidget(0, QFormLayout::FieldRole, lineMaxSecond);

        lineMinSecond = new QLineEdit(scrollAreaWidgetContents);
        lineMinSecond->setObjectName(QString::fromUtf8("lineMinSecond"));
        lineMinSecond->setMaximumSize(QSize(16777215, 16777215));

        formLayout_5->setWidget(1, QFormLayout::FieldRole, lineMinSecond);

        lineSecondAvg = new QLineEdit(scrollAreaWidgetContents);
        lineSecondAvg->setObjectName(QString::fromUtf8("lineSecondAvg"));

        formLayout_5->setWidget(2, QFormLayout::FieldRole, lineSecondAvg);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_5->setItem(4, QFormLayout::FieldRole, verticalSpacer_3);

        lineRangSecond = new QLineEdit(scrollAreaWidgetContents);
        lineRangSecond->setObjectName(QString::fromUtf8("lineRangSecond"));
        lineRangSecond->setStyleSheet(QString::fromUtf8("background-color: green;"));

        formLayout_5->setWidget(3, QFormLayout::FieldRole, lineRangSecond);

        label_19 = new QLabel(scrollAreaWidgetContents);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        formLayout_5->setWidget(3, QFormLayout::LabelRole, label_19);


        verticalLayout_3->addLayout(formLayout_5);


        gridLayout_3->addLayout(verticalLayout_3, 0, 2, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_5->addWidget(label);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_2);

        LineMaxOne = new QLineEdit(scrollAreaWidgetContents);
        LineMaxOne->setObjectName(QString::fromUtf8("LineMaxOne"));
        LineMaxOne->setMaximumSize(QSize(16777215, 16777215));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, LineMaxOne);

        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_3);

        lineMinOne = new QLineEdit(scrollAreaWidgetContents);
        lineMinOne->setObjectName(QString::fromUtf8("lineMinOne"));
        lineMinOne->setMaximumSize(QSize(16777215, 16777215));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, lineMinOne);

        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_4);

        lineAvgOne = new QLineEdit(scrollAreaWidgetContents);
        lineAvgOne->setObjectName(QString::fromUtf8("lineAvgOne"));
        lineAvgOne->setMaximumSize(QSize(16777215, 16777215));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, lineAvgOne);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_3->setItem(4, QFormLayout::FieldRole, verticalSpacer);

        lineRangOne = new QLineEdit(scrollAreaWidgetContents);
        lineRangOne->setObjectName(QString::fromUtf8("lineRangOne"));
        lineRangOne->setStyleSheet(QString::fromUtf8("background-color: green;"));

        formLayout_3->setWidget(3, QFormLayout::FieldRole, lineRangOne);

        label_17 = new QLabel(scrollAreaWidgetContents);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_17);


        verticalLayout_5->addLayout(formLayout_3);


        gridLayout_3->addLayout(verticalLayout_5, 0, 0, 1, 1);

        frameRuleFourth = new QFrame(scrollAreaWidgetContents);
        frameRuleFourth->setObjectName(QString::fromUtf8("frameRuleFourth"));
        frameRuleFourth->setMinimumSize(QSize(500, 500));
        formLayout_2 = new QFormLayout(frameRuleFourth);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));

        gridLayout_3->addWidget(frameRuleFourth, 1, 3, 1, 1);

        frameRuleThird = new QFrame(scrollAreaWidgetContents);
        frameRuleThird->setObjectName(QString::fromUtf8("frameRuleThird"));
        frameRuleThird->setMinimumSize(QSize(650, 500));
        gridLayout = new QGridLayout(frameRuleThird);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        gridLayout_3->addWidget(frameRuleThird, 1, 1, 1, 1);

        frameRuleOne = new QFrame(scrollAreaWidgetContents);
        frameRuleOne->setObjectName(QString::fromUtf8("frameRuleOne"));
        frameRuleOne->setMinimumSize(QSize(650, 500));
        horizontalLayout = new QHBoxLayout(frameRuleOne);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        gridLayout_3->addWidget(frameRuleOne, 0, 1, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_13 = new QLabel(scrollAreaWidgetContents);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_4->addWidget(label_13);

        formLayout_6 = new QFormLayout();
        formLayout_6->setObjectName(QString::fromUtf8("formLayout_6"));
        label_14 = new QLabel(scrollAreaWidgetContents);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        formLayout_6->setWidget(0, QFormLayout::LabelRole, label_14);

        label_15 = new QLabel(scrollAreaWidgetContents);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        formLayout_6->setWidget(1, QFormLayout::LabelRole, label_15);

        label_16 = new QLabel(scrollAreaWidgetContents);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        formLayout_6->setWidget(2, QFormLayout::LabelRole, label_16);

        linMaxFourth = new QLineEdit(scrollAreaWidgetContents);
        linMaxFourth->setObjectName(QString::fromUtf8("linMaxFourth"));

        formLayout_6->setWidget(0, QFormLayout::FieldRole, linMaxFourth);

        lineMinFourth = new QLineEdit(scrollAreaWidgetContents);
        lineMinFourth->setObjectName(QString::fromUtf8("lineMinFourth"));

        formLayout_6->setWidget(1, QFormLayout::FieldRole, lineMinFourth);

        lineAvgFourth = new QLineEdit(scrollAreaWidgetContents);
        lineAvgFourth->setObjectName(QString::fromUtf8("lineAvgFourth"));

        formLayout_6->setWidget(2, QFormLayout::FieldRole, lineAvgFourth);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_6->setItem(4, QFormLayout::FieldRole, verticalSpacer_4);

        lineRangFourth = new QLineEdit(scrollAreaWidgetContents);
        lineRangFourth->setObjectName(QString::fromUtf8("lineRangFourth"));
        lineRangFourth->setStyleSheet(QString::fromUtf8("background-color: green;"));

        formLayout_6->setWidget(3, QFormLayout::FieldRole, lineRangFourth);

        label_20 = new QLabel(scrollAreaWidgetContents);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        formLayout_6->setWidget(3, QFormLayout::LabelRole, label_20);


        verticalLayout_4->addLayout(formLayout_6);


        gridLayout_3->addLayout(verticalLayout_4, 1, 2, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        formLayout_7 = new QFormLayout();
        formLayout_7->setObjectName(QString::fromUtf8("formLayout_7"));
        label_21 = new QLabel(centralwidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        formLayout_7->setWidget(0, QFormLayout::LabelRole, label_21);

        spinBoxCast = new QSpinBox(centralwidget);
        spinBoxCast->setObjectName(QString::fromUtf8("spinBoxCast"));
        spinBoxCast->setMaximumSize(QSize(200, 16777215));
        spinBoxCast->setMinimum(1);
        spinBoxCast->setMaximum(999999999);

        formLayout_7->setWidget(0, QFormLayout::FieldRole, spinBoxCast);


        verticalLayout->addLayout(formLayout_7);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1530, 21));
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
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\222 \320\277\321\200\320\276\321\202\320\270\320\262\320\276\320\277\320\276\320\273\320\276\320\266\320\275\321\203\321\216 \320\276\321\202 \321\206\320\265\320\275\321\202\321\200\320\260", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\234\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\320\276", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\241\321\200\320\265\320\264\320\275\320\265\320\265", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\275\320\263", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\222 \320\277\321\200\320\276\321\202\320\270\320\262\320\276\320\277\320\276\320\273\320\276\320\266\320\275\321\203\321\216 \320\276\321\202 \321\202\320\265\320\272\321\203\321\211\320\265\320\263\320\276", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\320\234\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\320\276", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\320\241\321\200\320\265\320\264\320\275\320\265\320\265", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\275\320\263", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\235\320\265 \320\274\320\265\320\275\321\217\321\217 \320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\321\217 \320\262\320\276\321\200\320\276\320\275\320\272\320\270", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\234\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\265", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\241\321\200\320\265\320\264\320\275\320\265\320\265", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\275\320\263", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\320\222 \320\274\320\265\321\201\321\202\320\276 \320\277\321\200\320\270\320\267\320\265\320\274\320\273\320\265\320\275\320\270\321\217", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "\320\234\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "\320\241\321\200\320\265\320\264\320\275\320\265\320\265", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\275\320\263", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273-\320\262\320\276 \321\202\320\276\321\207\320\265\320\272", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\207\321\221\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
