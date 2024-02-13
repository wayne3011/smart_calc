#include "smart_calc_ui.h"

#include "ui_smart_calc.h"

extern "C" {
#include "../controller/controller.h"
}

smart_calc_ui::smart_calc_ui(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::smart_calc_ui) {
  ui->setupUi(this);
  ui->custom_plot->hide();
  ui->border_plot->hide();
  this->setFixedWidth(640);
  connect(ui->num_0_button, SIGNAL(clicked()), this, SLOT(symbol_clicked()));
  connect(ui->num_1_button, SIGNAL(clicked()), this, SLOT(symbol_clicked()));
  connect(ui->num_2_button, SIGNAL(clicked()), this, SLOT(symbol_clicked()));
  connect(ui->num_3_button, SIGNAL(clicked()), this, SLOT(symbol_clicked()));
  connect(ui->num_4_button, SIGNAL(clicked()), this, SLOT(symbol_clicked()));
  connect(ui->num_5_button, SIGNAL(clicked()), this, SLOT(symbol_clicked()));
  connect(ui->num_6_button, SIGNAL(clicked()), this, SLOT(symbol_clicked()));
  connect(ui->num_7_button, SIGNAL(clicked()), this, SLOT(symbol_clicked()));
  connect(ui->num_8_button, SIGNAL(clicked()), this, SLOT(symbol_clicked()));
  connect(ui->num_9_button, SIGNAL(clicked()), this, SLOT(symbol_clicked()));
  connect(ui->sin_button, SIGNAL(clicked()), this, SLOT(symbol_clicked()));
  connect(ui->cos_button, SIGNAL(clicked()), this, SLOT(symbol_clicked()));
  connect(ui->tan_button, SIGNAL(clicked()), this, SLOT(symbol_clicked()));
  connect(ui->acos_button, SIGNAL(clicked()), this, SLOT(symbol_clicked()));
  connect(ui->asin_button, SIGNAL(clicked()), this, SLOT(symbol_clicked()));
  connect(ui->atan_button, SIGNAL(clicked()), this, SLOT(symbol_clicked()));
  connect(ui->sqrt_button, SIGNAL(clicked()), this, SLOT(symbol_clicked()));
  connect(ui->log_button, SIGNAL(clicked()), this, SLOT(symbol_clicked()));
  connect(ui->ln_button, SIGNAL(clicked()), this, SLOT(symbol_clicked()));
  connect(ui->pow_button, SIGNAL(clicked()), this, SLOT(symbol_clicked()));
  connect(ui->pow_2_button, SIGNAL(clicked()), this, SLOT(symbol_clicked()));
  connect(ui->right_bracket_button, SIGNAL(clicked()), this,
          SLOT(symbol_clicked()));
  connect(ui->left_bracket_button, SIGNAL(clicked()), this,
          SLOT(symbol_clicked()));
  connect(ui->x_button, SIGNAL(clicked()), this, SLOT(symbol_clicked()));
  connect(ui->plus_button, SIGNAL(clicked()), this, SLOT(symbol_clicked()));
  connect(ui->minus_button, SIGNAL(clicked()), this, SLOT(symbol_clicked()));
  connect(ui->divide_button, SIGNAL(clicked()), this, SLOT(symbol_clicked()));
  connect(ui->multiply_button, SIGNAL(clicked()), this, SLOT(symbol_clicked()));
  connect(ui->dot_button, SIGNAL(clicked()), this, SLOT(symbol_clicked()));
  connect(ui->erase_button, SIGNAL(clicked()), this,
          SLOT(delete_button_clicked()));
  connect(ui->AC_button, SIGNAL(clicked()), this, SLOT(clear_button_clicked()));
  connect(ui->graph_button, SIGNAL(clicked()), this,
          SLOT(open_graph_clicked()));
  connect(ui->calculate_button, SIGNAL(clicked()), this,
          SLOT(calculate_button_clicked()));
  connect(ui->x_field, SIGNAL(textChanged(const QString &)), this,
          SLOT(number_filter(const QString &)));
  connect(ui->to_x_field, SIGNAL(textChanged(const QString &)), this,
          SLOT(number_filter(const QString &)));
  connect(ui->to_y_field, SIGNAL(textChanged(const QString &)), this,
          SLOT(number_filter(const QString &)));
  connect(ui->from_x_field, SIGNAL(textChanged(const QString &)), this,
          SLOT(number_filter(const QString &)));
  connect(ui->from_y_field, SIGNAL(textChanged(const QString &)), this,
          SLOT(number_filter(const QString &)));
}

smart_calc_ui::~smart_calc_ui() { delete ui; }

void smart_calc_ui::symbol_clicked() {
  if (calc_err) clear_button_clicked();
  QPushButton *pushedButton = (QPushButton *)sender();
  QString buttonText = pushedButton->text();
  ui->output_field->setText(ui->output_field->text() + buttonText);

  if (buttonText == "sin" || buttonText == "cos" || buttonText == "tan" ||
      buttonText == "asin" || buttonText == "acos" || buttonText == "atan" ||
      buttonText == "ln" || buttonText == "log" || buttonText == "sqrt") {
    ui->output_field->setText(ui->output_field->text() + "(");
  }
}

void smart_calc_ui::delete_button_clicked() {
  QString output_field_text = ui->output_field->text();
  if (output_field_text.isEmpty()) return;

  if (output_field_text.endsWith("asin") ||
      output_field_text.endsWith("acos") ||
      output_field_text.endsWith("atan") ||
      output_field_text.endsWith("sqrt")) {
    ui->output_field->setText(
        output_field_text.mid(0, output_field_text.length() - 4));
  } else if (output_field_text.endsWith("ln")) {
    ui->output_field->setText(
        output_field_text.mid(0, output_field_text.length() - 2));
  } else if (output_field_text.endsWith("sin") ||
             output_field_text.endsWith("cos") ||
             output_field_text.endsWith("tan") ||
             output_field_text.endsWith("log")) {
    ui->output_field->setText(
        output_field_text.mid(0, output_field_text.length() - 3));
  } else
    ui->output_field->setText(
        output_field_text.mid(0, output_field_text.length() - 1));
}
void smart_calc_ui::clear_button_clicked() {
  ui->output_field->setText("");
  ui->output_field->setStyleSheet("");
  this->calc_err = false;
}
void smart_calc_ui::keyPressEvent(QKeyEvent *e) {
  if (e->text()[0].isDigit() || e->text() == "(" || e->text() == ")" ||
      e->text() == "." || e->text() == "+" || e->text() == "-" ||
      e->text() == "*" || e->text() == "/" || e->text() == "^" ||
      e->text() == "x") {
    ui->output_field->setText(ui->output_field->text() + e->text());
  }

  if (e->key() == Qt::Key_Backspace) {
    delete_button_clicked();
  }
}
void smart_calc_ui::open_graph_clicked() {
  if (!this->graphic_is_open) {
    ui->border_plot->show();
    ui->custom_plot->show();
    this->setFixedWidth(1000);
    this->graphic_is_open = true;

  } else {
    ui->border_plot->hide();
    ui->custom_plot->hide();
    this->setFixedWidth(640);
    this->graphic_is_open = false;
  }
}

void smart_calc_ui::number_filter(const QString &str) {
  ui->from_x_field->setStyleSheet("");
  ui->from_y_field->setStyleSheet("");
  ui->to_x_field->setStyleSheet("");
  ui->to_y_field->setStyleSheet("");

  QLineEdit *field = (QLineEdit *)sender();
  bool is_int = false;
  bool is_double = false;
  str.toInt(&is_int);
  str.toDouble(&is_double);

  if (!str.isEmpty() && !is_int && !(str.length() == 1 && str[0] == '-') &&
      !(field->objectName() == "x_field" && is_double)) {
    field->setText(str.left(str.length() - 1));
  }
}

void smart_calc_ui::calculate_button_clicked() {
  if (std::all_of(
          ui->border_plot->children().first()->children().begin(),
          ui->border_plot->children().first()->children().end(),
          [=](const QObject *obj) -> bool {
            return (qobject_cast<const QLineEdit *>(obj) == NULL ||
                    !qobject_cast<const QLineEdit *>(obj)->text().isEmpty());
          }) &&
      ui->x_field->text().isEmpty()) {
    print_graphic();
    return;
  }
  if (ui->output_field->text().contains('x') && ui->x_field->text().isEmpty()) {
    ui->x_field->setFocus();
    return;
  }
  double x = 0.0;
  bool x_is_number = false;
  if (ui->x_field->text() != "") {
    x = ui->x_field->text().toDouble(&x_is_number);
  }
  if (!ui->output_field->text().isEmpty()) {
    double result = 0.0;
    const char *expression = ui->output_field->text().toStdString().c_str();
    bool success = solve_math_expression(expression, x, &result);
    if (!success) {
      ui->output_field->setStyleSheet("color: rgb(204, 0, 0)");
      ui->output_field->setText("CalcErr");
      this->calc_err = true;
    } else
      ui->output_field->setText(QString::number(result));
  }
}
void smart_calc_ui::print_graphic() {
  if (ui->output_field->text().isEmpty()) return;
  QString err_stylesheet = "border: 2px solid rgb(204, 0, 0)";
  bool err = false;
  if (ui->from_x_field->text().toInt() >= ui->to_x_field->text().toInt()) {
    ui->from_x_field->setStyleSheet(err_stylesheet);
    ui->to_x_field->setStyleSheet(err_stylesheet);
    err = true;
  }
  if (ui->from_y_field->text().toInt() >= ui->to_y_field->text().toInt()) {
    ui->from_y_field->setStyleSheet(err_stylesheet);
    ui->to_y_field->setStyleSheet(err_stylesheet);
    err = true;
  }
  if (err) return;
  int min_x = ui->from_x_field->text().toInt();
  int max_x = ui->to_x_field->text().toInt();
  int min_y = ui->from_y_field->text().toInt();
  int max_y = ui->to_y_field->text().toInt();
  int count_elem = 1000;
  double step =
      static_cast<double>(std::abs(min_x) + std::abs(max_x)) / count_elem;
  QVector<double> x(count_elem), y(count_elem);

  for (int i = 0; i < count_elem; ++i) {
    x[i] = min_x + step * i;
    double result;
    bool success = solve_math_expression(
        ui->output_field->text().toStdString().c_str(), x[i], &result);
    y[i] = success && result != INFINITY && result != -INFINITY ? result : NAN;
  }
  ui->custom_plot->addGraph();
  ui->custom_plot->graph(0)->setData(x, y);

  ui->custom_plot->xAxis->setLabel("x");
  ui->custom_plot->yAxis->setLabel("y");

  ui->custom_plot->xAxis->setRange(min_x, max_x);
  ui->custom_plot->yAxis->setRange(min_y, max_y);
  ui->custom_plot->replot();
}
