#include <QApplication>

#include "keypad_widget.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  KeypadWidget pad;

  pad.show();
  
  return app.exec();
}
