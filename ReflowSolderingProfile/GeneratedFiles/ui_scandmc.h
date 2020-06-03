/********************************************************************************
** Form generated from reading UI file 'scandmc.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCANDMC_H
#define UI_SCANDMC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ScanDMC
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QLabel *labelDMC;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *lineEditDMC;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QDialogButtonBox *buttonBoxSend;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *ScanDMC)
    {
        if (ScanDMC->objectName().isEmpty())
            ScanDMC->setObjectName(QStringLiteral("ScanDMC"));
        ScanDMC->resize(559, 309);
        horizontalLayout_2 = new QHBoxLayout(ScanDMC);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_2->addItem(verticalSpacer_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(70, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        labelDMC = new QLabel(ScanDMC);
        labelDMC->setObjectName(QStringLiteral("labelDMC"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(18);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        labelDMC->setFont(font);
        labelDMC->setAutoFillBackground(true);
        labelDMC->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labelDMC);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(70, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        lineEditDMC = new QLineEdit(ScanDMC);
        lineEditDMC->setObjectName(QStringLiteral("lineEditDMC"));
        lineEditDMC->setMinimumSize(QSize(400, 0));
        lineEditDMC->setFont(font);
        lineEditDMC->setAutoFillBackground(false);

        horizontalLayout_4->addWidget(lineEditDMC);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_5 = new QSpacerItem(70, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        buttonBoxSend = new QDialogButtonBox(ScanDMC);
        buttonBoxSend->setObjectName(QStringLiteral("buttonBoxSend"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonBoxSend->sizePolicy().hasHeightForWidth());
        buttonBoxSend->setSizePolicy(sizePolicy);
        buttonBoxSend->setMinimumSize(QSize(400, 100));
        buttonBoxSend->setBaseSize(QSize(0, 0));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font1.setPointSize(18);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(9);
        buttonBoxSend->setFont(font1);
        buttonBoxSend->setAcceptDrops(false);
        buttonBoxSend->setLayoutDirection(Qt::LeftToRight);
        buttonBoxSend->setAutoFillBackground(false);
        buttonBoxSend->setStyleSheet(QString::fromUtf8("font: 75 18pt \"\345\271\274\345\234\206\";"));
        buttonBoxSend->setOrientation(Qt::Horizontal);
        buttonBoxSend->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBoxSend->setCenterButtons(true);

        horizontalLayout_5->addWidget(buttonBoxSend);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);


        verticalLayout_2->addLayout(horizontalLayout_5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout_2->addLayout(verticalLayout_2);


        retranslateUi(ScanDMC);

        QMetaObject::connectSlotsByName(ScanDMC);
    } // setupUi

    void retranslateUi(QDialog *ScanDMC)
    {
        ScanDMC->setWindowTitle(QApplication::translate("ScanDMC", "ScanDMC", 0));
        labelDMC->setText(QApplication::translate("ScanDMC", "\350\257\267\346\211\253\346\217\217\350\275\254\345\236\213\345\215\225\346\210\226\350\276\223\345\205\245\344\272\247\345\223\201\345\236\213\345\217\267", 0));
    } // retranslateUi

};

namespace Ui {
    class ScanDMC: public Ui_ScanDMC {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANDMC_H
