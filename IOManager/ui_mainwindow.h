/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSplitter *splitter;
    QWidget *LeftWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *DILabel;
    QLabel *DOLabel;
    QWidget *MiddleWidget;
    QGridLayout *gridLayout;
    QWidget *RightWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *BtnPreviousPage;
    QLabel *labelPageNum;
    QPushButton *BtnNextPage;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *BtnOperation;
    QLineEdit *textInput;
    QMenuBar *menuBar;
    QMenu *TestMenuBtn;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(593, 320);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        comboBox->setMinimumSize(QSize(150, 0));

        horizontalLayout->addWidget(comboBox);

        horizontalSpacer = new QSpacerItem(180, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(200, 0));

        horizontalLayout->addWidget(label);


        verticalLayout_3->addLayout(horizontalLayout);

        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy2);
        splitter->setLineWidth(1);
        splitter->setMidLineWidth(0);
        splitter->setOrientation(Qt::Horizontal);
        splitter->setOpaqueResize(false);
        splitter->setHandleWidth(1);
        splitter->setChildrenCollapsible(false);
        LeftWidget = new QWidget(splitter);
        LeftWidget->setObjectName(QStringLiteral("LeftWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(LeftWidget->sizePolicy().hasHeightForWidth());
        LeftWidget->setSizePolicy(sizePolicy3);
        LeftWidget->setMinimumSize(QSize(100, 0));
        verticalLayout_2 = new QVBoxLayout(LeftWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        DILabel = new QLabel(LeftWidget);
        DILabel->setObjectName(QStringLiteral("DILabel"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(DILabel->sizePolicy().hasHeightForWidth());
        DILabel->setSizePolicy(sizePolicy4);
        DILabel->setAlignment(Qt::AlignCenter);
        DILabel->setMargin(12);

        verticalLayout_2->addWidget(DILabel);

        DOLabel = new QLabel(LeftWidget);
        DOLabel->setObjectName(QStringLiteral("DOLabel"));
        sizePolicy4.setHeightForWidth(DOLabel->sizePolicy().hasHeightForWidth());
        DOLabel->setSizePolicy(sizePolicy4);
        DOLabel->setAlignment(Qt::AlignCenter);
        DOLabel->setWordWrap(false);
        DOLabel->setMargin(12);

        verticalLayout_2->addWidget(DOLabel);

        splitter->addWidget(LeftWidget);
        MiddleWidget = new QWidget(splitter);
        MiddleWidget->setObjectName(QStringLiteral("MiddleWidget"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(1);
        sizePolicy5.setVerticalStretch(1);
        sizePolicy5.setHeightForWidth(MiddleWidget->sizePolicy().hasHeightForWidth());
        MiddleWidget->setSizePolicy(sizePolicy5);
        gridLayout = new QGridLayout(MiddleWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        splitter->addWidget(MiddleWidget);
        RightWidget = new QWidget(splitter);
        RightWidget->setObjectName(QStringLiteral("RightWidget"));
        sizePolicy.setHeightForWidth(RightWidget->sizePolicy().hasHeightForWidth());
        RightWidget->setSizePolicy(sizePolicy);
        RightWidget->setMinimumSize(QSize(0, 0));
        RightWidget->setMaximumSize(QSize(16777215, 16777215));
        RightWidget->setSizeIncrement(QSize(0, 0));
        RightWidget->setBaseSize(QSize(0, 0));
        RightWidget->setLayoutDirection(Qt::LeftToRight);
        RightWidget->setAutoFillBackground(false);
        verticalLayout = new QVBoxLayout(RightWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(9, -1, -1, 9);
        BtnPreviousPage = new QPushButton(RightWidget);
        BtnPreviousPage->setObjectName(QStringLiteral("BtnPreviousPage"));

        verticalLayout->addWidget(BtnPreviousPage);

        labelPageNum = new QLabel(RightWidget);
        labelPageNum->setObjectName(QStringLiteral("labelPageNum"));
        sizePolicy4.setHeightForWidth(labelPageNum->sizePolicy().hasHeightForWidth());
        labelPageNum->setSizePolicy(sizePolicy4);

        verticalLayout->addWidget(labelPageNum);

        BtnNextPage = new QPushButton(RightWidget);
        BtnNextPage->setObjectName(QStringLiteral("BtnNextPage"));
        BtnNextPage->setEnabled(false);

        verticalLayout->addWidget(BtnNextPage);

        splitter->addWidget(RightWidget);

        verticalLayout_3->addWidget(splitter);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        BtnOperation = new QPushButton(centralWidget);
        BtnOperation->setObjectName(QStringLiteral("BtnOperation"));

        horizontalLayout_2->addWidget(BtnOperation);

        textInput = new QLineEdit(centralWidget);
        textInput->setObjectName(QStringLiteral("textInput"));

        horizontalLayout_2->addWidget(textInput);


        verticalLayout_3->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 593, 21));
        TestMenuBtn = new QMenu(menuBar);
        TestMenuBtn->setObjectName(QStringLiteral("TestMenuBtn"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(TestMenuBtn->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        DILabel->setText(QApplication::translate("MainWindow", "\350\274\270\345\205\245\350\250\212\350\231\237 :", nullptr));
        DOLabel->setText(QApplication::translate("MainWindow", "\350\274\270\345\207\272\350\250\212\350\231\237 :", nullptr));
        BtnPreviousPage->setText(QApplication::translate("MainWindow", "\342\206\221", nullptr));
        labelPageNum->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        BtnNextPage->setText(QApplication::translate("MainWindow", "\342\206\223", nullptr));
        BtnOperation->setText(QApplication::translate("MainWindow", "Complier", nullptr));
        TestMenuBtn->setTitle(QApplication::translate("MainWindow", "\346\270\254\350\251\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
