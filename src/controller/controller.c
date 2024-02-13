//
// Created by ackbarca on 06.02.24.
//
#include "controller.h"
bool solve_math_expression(const char *expression, double x, double *result) {
  char formatted_expression[MAX_EXPR_LEN + 1] = {0};
  char polish_notation[MAX_EXPR_LEN * 2 + 1] = {0};
  bool err = false;

  err = !format_str(expression, formatted_expression);
  if (!err) err = !to_postfix_form(formatted_expression, polish_notation);
  if (!err) err = !solve_notation(polish_notation, x, result);
  return err ? false : true;
}