/********************************************************************************
** Form generated from reading UI file 'TilesPile.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TILESPILE_H
#define UI_TILESPILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TilesPile
{
public:

    void setupUi(QWidget *TilesPile)
    {
        if (TilesPile->objectName().isEmpty())
            TilesPile->setObjectName(QString::fromUtf8("TilesPile"));
        TilesPile->resize(400, 300);

        retranslateUi(TilesPile);

        QMetaObject::connectSlotsByName(TilesPile);
    } // setupUi

    void retranslateUi(QWidget *TilesPile)
    {
        TilesPile->setWindowTitle(QApplication::translate("TilesPile", "TilesPile", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TilesPile: public Ui_TilesPile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TILESPILE_H
