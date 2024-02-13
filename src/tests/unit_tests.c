//
// Created by ackbarca on 02.02.24.
//
#include "unit_tests.h"

#include <stdlib.h>

void run_tests() {
  Suite *suite = NULL;
  SRunner *sRunner = NULL;

  Suite *suite_array[] = {create_stack_suite(), create_polish_notation_suite()};

  int count_of_tests = sizeof(suite_array) / sizeof(Suite *);
  for (int i = 0; i < count_of_tests; i++) {
    suite = suite_array[i];
    sRunner = srunner_create(suite);
    srunner_set_fork_status(sRunner, CK_NOFORK);

    srunner_run_all(sRunner, CK_NORMAL);
    srunner_free(sRunner);

    suite = NULL;
    sRunner = NULL;
  }
}

int main() { run_tests(); }
