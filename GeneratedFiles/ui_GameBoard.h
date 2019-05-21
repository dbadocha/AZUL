/********************************************************************************
** Form generated from reading UI file 'GameBoard.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEBOARD_H
#define UI_GAMEBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameBoard
{
public:

    void setupUi(QWidget *GameBoard)
    {
        if (GameBoard->objectName().isEmpty())
            GameBoard->setObjectName(QString::fromUtf8("GameBoard"));
        GameBoard->resize(400, 300);

        retranslateUi(GameBoard);

        QMetaObject::connectSlotsByName(GameBoard);
    } // setupUi

    void retranslateUi(QWidget *GameBoard)
    {
        GameBoard->setWindowTitle(QApplication::translate("GameBoard", "GameBoard", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameBoard: public Ui_GameBoard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEBOARD_H
