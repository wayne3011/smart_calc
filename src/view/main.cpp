#include <QApplication>

#include "smart_calc_ui.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  smart_calc_ui w;
  w.show();
  return a.exec();
}
