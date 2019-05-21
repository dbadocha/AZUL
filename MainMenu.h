#pragma once

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QVBoxLayout>

#include "ui_MainMenu.h"

class MainMenu : public QWidget
{
	Q_OBJECT

private:
	Ui::MainMenu ui;
	QVBoxLayout *layout = nullptr;
	QPushButton *NewGamePB = nullptr;
	QPushButton *SettingsPB = nullptr;
	QPushButton *ExitGamePB = nullptr;

public:
	explicit MainMenu(QWidget *parent = nullptr);
	~MainMenu();

signals:
	void sendMessage(const QString &);

private slots:

public slots:
};