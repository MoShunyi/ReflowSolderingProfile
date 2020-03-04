/********************************************************************************
** Form generated from reading UI file 'reflowsolderingprofile.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REFLOWSOLDERINGPROFILE_H
#define UI_REFLOWSOLDERINGPROFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReflowSolderingProfileClass
{
public:
    QAction *actionLogin;
    QAction *actionLogout;
    QAction *actionFolder;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *imageWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;

    void setupUi(QMainWindow *ReflowSolderingProfileClass)
    {
        if (ReflowSolderingProfileClass->objectName().isEmpty())
            ReflowSolderingProfileClass->setObjectName(QStringLiteral("ReflowSolderingProfileClass"));
        ReflowSolderingProfileClass->resize(600, 400);
        actionLogin = new QAction(ReflowSolderingProfileClass);
        actionLogin->setObjectName(QStringLiteral("actionLogin"));
        actionLogin->setVisible(true);
        actionLogout = new QAction(ReflowSolderingProfileClass);
        actionLogout->setObjectName(QStringLiteral("actionLogout"));
        actionFolder = new QAction(ReflowSolderingProfileClass);
        actionFolder->setObjectName(QStringLiteral("actionFolder"));
        centralWidget = new QWidget(ReflowSolderingProfileClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        imageWidget = new QWidget(centralWidget);
        imageWidget->setObjectName(QStringLiteral("imageWidget"));

        horizontalLayout->addWidget(imageWidget);

        ReflowSolderingProfileClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ReflowSolderingProfileClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        menuBar->setAutoFillBackground(true);
        menuBar->setDefaultUp(false);
        menuBar->setNativeMenuBar(true);
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu->setEnabled(true);
        menu->setAutoFillBackground(true);
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        ReflowSolderingProfileClass->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(actionLogin);
        menu->addAction(actionLogout);
        menu_2->addAction(actionFolder);

        retranslateUi(ReflowSolderingProfileClass);

        QMetaObject::connectSlotsByName(ReflowSolderingProfileClass);
    } // setupUi

    void retranslateUi(QMainWindow *ReflowSolderingProfileClass)
    {
        ReflowSolderingProfileClass->setWindowTitle(QApplication::translate("ReflowSolderingProfileClass", "ReflowSolderingProfile", 0));
        actionLogin->setText(QApplication::translate("ReflowSolderingProfileClass", "\347\231\273\345\275\225", 0));
        actionLogout->setText(QApplication::translate("ReflowSolderingProfileClass", "\346\263\250\351\224\200", 0));
        actionFolder->setText(QApplication::translate("ReflowSolderingProfileClass", "\346\211\223\345\274\200\346\226\207\344\273\266\345\244\271", 0));
        menu->setTitle(QApplication::translate("ReflowSolderingProfileClass", "\347\231\273\345\275\225/\346\263\250\351\224\200", 0));
        menu_2->setTitle(QApplication::translate("ReflowSolderingProfileClass", "\346\230\216\347\273\206", 0));
    } // retranslateUi

};

namespace Ui {
    class ReflowSolderingProfileClass: public Ui_ReflowSolderingProfileClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REFLOWSOLDERINGPROFILE_H
