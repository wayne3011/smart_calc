//
// Created by ackbarca on 02.02.24.
//
#include "stack.h"
int stack_init(stack_t *stack) {
  stack->root = NULL;
  return 0;
}
int push(stack_t *stack, char value) {
  stack_node_t *new_node = (stack_node_t *)calloc(1, sizeof(stack_node_t));
  if (new_node == NULL) return ALLOCATION_ERROR;
  new_node->val = value;
  if (stack->root != NULL) new_node->next = stack->root;
  stack->root = new_node;
  return 0;
}

char pop(stack_t *stack) {
  if (stack->root == NULL) return '\0';
  char value = stack->root->val;
  stack_node_t *deleted_node = stack->root;
  stack->root = stack->root->next;
  free(deleted_node);
  return value;
}

void delete_stack(stack_t *stack) {
  while (stack->root != NULL) {
    pop(stack);
  }
}