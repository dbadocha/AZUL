/********************************************************************************
** Form generated from reading UI file 'TilesWorkshop.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TILESWORKSHOP_H
#define UI_TILESWORKSHOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TilesWorkshop
{
public:

    void setupUi(QWidget *TilesWorkshop)
    {
        if (TilesWorkshop->objectName().isEmpty())
            TilesWorkshop->setObjectName(QString::fromUtf8("TilesWorkshop"));
        TilesWorkshop->resize(400, 300);

        retranslateUi(TilesWorkshop);

        QMetaObject::connectSlotsByName(TilesWorkshop);
    } // setupUi

    void retranslateUi(QWidget *TilesWorkshop)
    {
        TilesWorkshop->setWindowTitle(QApplication::translate("TilesWorkshop", "TilesWorkshop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TilesWorkshop: public Ui_TilesWorkshop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TILESWORKSHOP_H
