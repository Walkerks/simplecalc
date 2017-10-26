#ifndef KEYPAD_WIDGET_H
#define KEYPAD_WIDGET_H

#include <QWidget>
#include <QString>
#include <QGridLayout>
#include <QVBoxLayout>

class QLineEdit;

class KeypadWidget: public QWidget{
Q_OBJECT

public:

  KeypadWidget();
  virtual ~KeypadWidget();

protected slots:
  void add0();
  void add1();
  void add2();
  void add3();
  void add4();
  void add5();
  void add6();
  void add7();
  void add8();
  void add9();
  void clear();
  void setNum();
  void setHex();
  void setBin();
  
private:
  
	enum Modes {NUM, HEX, BIN};
	Modes currentMode;
	QLineEdit * display;
	QString displayState;

	void appendText(const QString & s);

	QGridLayout * setupButtons();
	QVBoxLayout * setupRadioModes();
  
};



#endif
