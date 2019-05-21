#include "MainMenu.h"

MainMenu::MainMenu(QWidget *parent) : QWidget(parent)
{
	ui.setupUi(this);

	NewGamePB = new QPushButton("New Game", this);
	SettingsPB = new QPushButton("Settings", this);
	ExitGamePB = new QPushButton("Exit", this);

	QFont font = this->font();
	font.setPointSize(14);
	NewGamePB->setFont(font);
	SettingsPB->setFont(font);
	ExitGamePB->setFont(font);

	connect(NewGamePB, SIGNAL(clicked()), parent, SLOT(on_NewGame_clicked()));
	connect(SettingsPB, SIGNAL(clicked()), parent, SLOT(on_Settings_clicked()));
	connect(ExitGamePB, SIGNAL(clicked()), parent, SLOT(on_ExitGame_clicked()));

	layout = new QVBoxLayout(this);
	layout->setSpacing(2);
	layout->setMargin(0);

	QSize SizePB = QSize(150, 30);
	NewGamePB->setFixedSize(SizePB);
	SettingsPB->setFixedSize(SizePB);
	ExitGamePB->setFixedSize(SizePB);

	layout->addWidget(NewGamePB);
	layout->addWidget(SettingsPB);
	layout->addWidget(ExitGamePB);

	layout->setAlignment(Qt::AlignCenter);
	int LayoutWidth = SizePB.width() + layout->margin();
	int LayoutHeight = 3 * (SizePB.height() + layout->spacing());
	this->setFixedSize(QSize(LayoutWidth, LayoutHeight));

	this->setStyleSheet("background-color: rgba(250, 250, 250, 210);");

	this->setLayout(layout);
}

MainMenu::~MainMenu()
{
}