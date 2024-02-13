//
// Created by ackbarca on 02.02.24.
//
#include "../data_structure/stack.h"
#include "unit_tests.h"
START_TEST(stack_init_test_1) {
  stack_t stack;
  stack_init(&stack);
  ck_assert_ptr_null(stack.root);
}

START_TEST(stack_push_test_1) {
  stack_t stack;
  stack_init(&stack);
  push(&stack, 'b');

  ck_assert_int_eq('b', pop(&stack));
}
START_TEST(stack_push_test_2) {
  stack_t stack;
  stack_init(&stack);

  push(&stack, 'b');
  push(&stack, 'c');

  ck_assert_int_eq('c', pop(&stack));
  ck_assert_int_eq('b', pop(&stack));
}

START_TEST(stack_pop_test_1) {
  stack_t stack;
  stack_init(&stack);
  push(&stack, 'a');

  ck_assert_int_eq('a', pop(&stack));
  ck_assert_ptr_null(stack.root);
}

START_TEST(stack_pop_test_2) {
  stack_t stack;
  stack_init(&stack);
  push(&stack, 'a');
  push(&stack, 'b');

  ck_assert_int_eq('b', pop(&stack));
  ck_assert_int_eq('a', pop(&stack));
  ck_assert_ptr_null(stack.root);
}

START_TEST(stack_pop_test_3) {
  stack_t stack;
  stack_init(&stack);

  ck_assert_int_eq('\0', pop(&stack));
  ck_assert_ptr_null(stack.root);
}

START_TEST(stack_delete_test_1) {
  stack_t stack;
  stack_init(&stack);
  push(&stack, 'a');
  push(&stack, 'b');
  push(&stack, 'c');
  push(&stack, 'd');

  delete_stack(&stack);
  ck_assert_ptr_null(stack.root);
}

START_TEST(stack_delete_test_2) {
  stack_t stack;
  stack_init(&stack);
  push(&stack, 'a');
  pop(&stack);
  delete_stack(&stack);
  ck_assert_ptr_null(stack.root);
}

Suite *create_stack_suite() {
  Suite *suite = suite_create("stack tests");
  TCase *stack_tc = tcase_create("stack tests");

  tcase_add_test(stack_tc, stack_init_test_1);
  tcase_add_test(stack_tc, stack_push_test_1);
  tcase_add_test(stack_tc, stack_push_test_2);
  tcase_add_test(stack_tc, stack_pop_test_1);
  tcase_add_test(stack_tc, stack_pop_test_2);
  tcase_add_test(stack_tc, stack_pop_test_3);
  tcase_add_test(stack_tc, stack_delete_test_1);
  tcase_add_test(stack_tc, stack_delete_test_2);

  suite_add_tcase(suite, stack_tc);

  return suite;
}
