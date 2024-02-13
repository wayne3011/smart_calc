#ifndef SMART_CALC_UI_H
#define SMART_CALC_UI_H

#include <QKeyEvent>
#include <QMainWindow>
#include <typeinfo>

#include "qcustomplot.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class smart_calc_ui;
}
QT_END_NAMESPACE

class smart_calc_ui : public QMainWindow {
  Q_OBJECT

 public:
  smart_calc_ui(QWidget *parent = nullptr);
  ~smart_calc_ui();

 private:
  Ui::smart_calc_ui *ui;
  bool graphic_is_open = false;
  bool calc_err = false;
 private slots:
  void print_graphic();
  void symbol_clicked();
  void delete_button_clicked();
  void clear_button_clicked();
  void open_graph_clicked();
  void calculate_button_clicked();
  void number_filter(const QString &);
  void keyPressEvent(QKeyEvent *e);
};
#endif  // SMART_CALC_UI_H
