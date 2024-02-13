//
// Created by ackbarca on 02.02.24.
//

#ifndef SMART_CALC_POLISH_NOTATION_H
#define SMART_CALC_POLISH_NOTATION_H
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "../data_structure/stack.h"
#include "../data_structure/stack_double.h"
#define MAX_EXPR_LEN 255
int parse_operators(const char *expression, char *formatted_expression,
                    int *index, int *i);
bool to_postfix_form(char *expression, char *postfix_form);
bool is_digit(char val);
bool is_operator(char val);
bool is_binary_operator(char val);
bool is_unary_operator(char val);
void extract_number(char **postfix_form, char **expression, bool *err);
void upload_stack_with_operator(stack_t *stack, char **postfix_form, char oper);
bool upload_stack_with_bracket(stack_t *stack, char **postfix_form);
bool format_str(const char *expression, char *formatted_expression);
double perform_operator(char oper, double first_number, double second_number);
bool solve_notation(char *expression, double x, double *result);
void perform_binary_operator(const char *token, stack_double_t *stack, int *err,
                             double *operations_result);
void perform_unary_operator(const char *token, stack_double_t *stack, int *err,
                            double *operations_result);
#endif  // SMART_CALC_POLISH_NOTATION_H
