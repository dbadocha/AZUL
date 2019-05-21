/********************************************************************************
** Form generated from reading UI file 'Tile.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TILE_H
#define UI_TILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tile
{
public:

    void setupUi(QWidget *Tile)
    {
        if (Tile->objectName().isEmpty())
            Tile->setObjectName(QString::fromUtf8("Tile"));
        Tile->resize(400, 300);

        retranslateUi(Tile);

        QMetaObject::connectSlotsByName(Tile);
    } // setupUi

    void retranslateUi(QWidget *Tile)
    {
        Tile->setWindowTitle(QApplication::translate("Tile", "Tile", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tile: public Ui_Tile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TILE_H
