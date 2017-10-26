#include "keypad_widget.h"

#include <QLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QTextStream>

#include <QDebug>


QGridLayout * KeypadWidget::setupButtons() {

	QGridLayout * layout = new QGridLayout(this);

	auto button1 = new QPushButton("1");
	QObject::connect(button1, SIGNAL(clicked()), this, SLOT(add1()));
	layout->addWidget(button1, 1, 0, 1, 1, Qt::AlignHCenter);

	auto button2 = new QPushButton("2");
	QObject::connect(button2, SIGNAL(clicked()), this, SLOT(add2()));
	layout->addWidget(button2, 1, 1, 1, 1, Qt::AlignHCenter);

	auto button3 = new QPushButton("3");
	QObject::connect(button3, SIGNAL(clicked()), this, SLOT(add3()));
	layout->addWidget(button3, 1, 2, 1, 1, Qt::AlignHCenter);

	auto button4 = new QPushButton("4");
	QObject::connect(button4, SIGNAL(clicked()), this, SLOT(add4()));
	layout->addWidget(button4, 2, 0, 1, 1, Qt::AlignHCenter);

	auto button5 = new QPushButton("5");
	QObject::connect(button5, SIGNAL(clicked()), this, SLOT(add5()));
	layout->addWidget(button5, 2, 1, 1, 1, Qt::AlignHCenter);

	auto button6 = new QPushButton("6");
	QObject::connect(button6, SIGNAL(clicked()), this, SLOT(add6()));
	layout->addWidget(button6, 2, 2, 1, 1, Qt::AlignHCenter);

	auto button7 = new QPushButton("7");
	QObject::connect(button7, SIGNAL(clicked()), this, SLOT(add7()));
	layout->addWidget(button7, 3, 0, 1, 1, Qt::AlignHCenter);

	auto button8 = new QPushButton("8");
	QObject::connect(button8, SIGNAL(clicked()), this, SLOT(add8()));
	layout->addWidget(button8, 3, 1, 1, 1, Qt::AlignHCenter);

	auto button9 = new QPushButton("9");
	QObject::connect(button9, SIGNAL(clicked()), this, SLOT(add9()));
	layout->addWidget(button9, 3, 2, 1, 1, Qt::AlignHCenter);

	auto button0 = new QPushButton("0");
	QObject::connect(button0, SIGNAL(clicked()), this, SLOT(add0()));
	layout->addWidget(button0, 4, 1, 1, 1, Qt::AlignHCenter);

	auto clear_button = new QPushButton("Clear");
	QObject::connect(clear_button, SIGNAL(clicked()), this, SLOT(clear()));
	layout->addWidget(clear_button, 5, 0, 1, -1, Qt::AlignHCenter);

	return layout;
}

QVBoxLayout * KeypadWidget::setupRadioModes() {
	QRadioButton *radio1 = new QRadioButton("Numeric");
	QRadioButton *radio2 = new QRadioButton("Binary");
	QRadioButton *radio3 = new QRadioButton("Hex");

	//connect the radio buttons
	QObject::connect(radio1, SIGNAL(clicked()), this, SLOT(setNum()));
	QObject::connect(radio2, SIGNAL(clicked()), this, SLOT(setBin()));
	QObject::connect(radio3, SIGNAL(clicked()), this, SLOT(setHex()));

	radio1->setChecked(true);
	//Make sure the mode is updated
	currentMode = NUM;

	auto radioLayout = new QVBoxLayout;
	radioLayout->addWidget(radio1);
	radioLayout->addWidget(radio2);
	radioLayout->addWidget(radio3);

	return radioLayout;
}

KeypadWidget::KeypadWidget() {

  display = new QLineEdit;
  display->setReadOnly(true);

  auto keypadBox = new QGroupBox("KeyPad", this);
  auto displayBox = new QGroupBox("Display", this);
  auto modeBox = new QGroupBox("Modes", this);

 
  auto displayLayout = new QGridLayout(this);
  displayLayout->addWidget(display, 0, 0, 1, -1, Qt::AlignHCenter);


  //setup and connect all of the buttons
  QGridLayout * layout = setupButtons();
  //setup and connect all radio buttons
  QVBoxLayout * radioLayout = setupRadioModes();

  //Set the layout of the buttons in the groupbox
  keypadBox->setLayout(layout);
  //Set the display in the groupbox
  displayBox->setLayout(displayLayout);
  //Set the mode layout in the groupbox
  modeBox->setLayout(radioLayout);

  //Now we need to layout the boxes
  auto hlay = new QHBoxLayout;
  hlay->addWidget(keypadBox);
  hlay->addWidget(modeBox);

  auto vlay = new QVBoxLayout(this);
  vlay->addWidget(displayBox);
  vlay->addLayout(hlay);

  this->setLayout(vlay);
}

KeypadWidget::~KeypadWidget(){};

void KeypadWidget::appendText(const QString &s) {

	displayState.append(s);
	
	QString stringInFormat;
	switch (currentMode)
	{
	case KeypadWidget::NUM:
		//display state is always in the correct format
		stringInFormat = QString("%1").arg(displayState.toInt(), 0, 10);
		break;
	case KeypadWidget::HEX:
		//convert to hex
		stringInFormat = QString("%1").arg(displayState.toInt(), 0, 16);
		break;
	case KeypadWidget::BIN:
		stringInFormat = QString("%1").arg(displayState.toInt(), 0, 2);
		break;
	default:
		break;
	}
	display->clear();
	display->setText(stringInFormat);
}

void KeypadWidget::add0() { appendText("0"); }

void KeypadWidget::add1() { appendText("1"); }

void KeypadWidget::add2() { appendText("2"); }

void KeypadWidget::add3() { appendText("3"); }

void KeypadWidget::add4() { appendText("4"); }

void KeypadWidget::add5() { appendText("5"); }

void KeypadWidget::add6() { appendText("6"); }

void KeypadWidget::add7() { appendText("7"); }

void KeypadWidget::add8() { appendText("8"); }

void KeypadWidget::add9() { appendText("9"); }

void KeypadWidget::clear() { 
	displayState = "";
	display->clear();

}

void KeypadWidget::setNum() {
	currentMode = NUM;
	appendText("");
}

void KeypadWidget::setHex() {
	currentMode = HEX;
	appendText("");
}

void KeypadWidget::setBin() {
	currentMode = BIN;
	appendText("");
}
