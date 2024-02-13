//
// Created by ackbarca on 05.02.24.
//

#ifndef SMART_CALC_CONTROLLER_H
#define SMART_CALC_CONTROLLER_H

#include <stdbool.h>

#include "../model/polish_notation.h"
bool solve_math_expression(const char *expression, double x, double *result);
#endif  // SMART_CALC_CONTROLLER_H
