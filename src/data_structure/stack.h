//
// Created by ackbarca on 02.02.24.
//

#ifndef STACK_H
#define STACK_H
#include <stdlib.h>
#define ALLOCATION_ERROR 1
typedef struct stack_node_t {
  char val;
  struct stack_node_t *next;
} stack_node_t;

typedef struct {
  struct stack_node_t *root;
} stack_t;

int stack_init(stack_t *stack);
int push(stack_t *stack, char value);
char pop(stack_t *stack);
void delete_stack(stack_t *stack);
#endif  // STACK_H
