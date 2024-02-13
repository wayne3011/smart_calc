//
// Created by ackbarca on 03.02.24.
//

#include "stack_double.h"
int stack_double_init(stack_double_t *stack) {
  stack->root = NULL;
  return 0;
}
int push_double(stack_double_t *stack, double value) {
  stack_double_node_t *new_node =
      (stack_double_node_t *)calloc(1, sizeof(stack_double_node_t));
  if (new_node == NULL) return ALLOCATION_ERROR;
  new_node->val = value;
  if (stack->root != NULL)
    new_node->next = stack->root;
  else
    new_node->next = NULL;
  stack->root = new_node;
  return 0;
}

double pop_double(stack_double_t *stack) {
  if (stack->root == NULL) return NAN;
  double value = stack->root->val;
  stack_double_node_t *deleted_node = stack->root;
  stack->root = stack->root->next;
  free(deleted_node);
  return value;
}

void delete_stack_double(stack_double_t *stack) {
  while (stack->root != NULL) {
    pop_double(stack);
  }
}