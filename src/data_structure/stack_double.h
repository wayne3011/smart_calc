//
// Created by ackbarca on 03.02.24.
//

#ifndef SMART_CALC_STACK_DOUBLE_H
#define SMART_CALC_STACK_DOUBLE_H
#define ALLOCATION_ERROR 1
#include <math.h>
#include <stdlib.h>
typedef struct stack_double_node_t {
  double val;
  struct stack_double_node_t *next;
} stack_double_node_t;

typedef struct {
  struct stack_double_node_t *root;
} stack_double_t;

int stack_double_init(stack_double_t *stack);
int push_double(stack_double_t *stack, double value);
double pop_double(stack_double_t *stack);
void delete_stack_double(stack_double_t *stack);
#endif  // SMART_CALC_STACK_DOUBLE_H
