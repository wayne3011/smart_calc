//
// Created by ackbarca on 03.02.24.
//
#include "../controller/controller.h"
#include "unit_tests.h"
#define ACCURACY 1e-7
START_TEST(polish_notation_test_1) {
  char* expression = "x + 10.1361466";
  double x = 3.1235356;
  double result;
  double expected_result = x + 10.1361466;

  ck_assert_int_eq(solve_math_expression(expression, x, &result), true);
  ck_assert_double_eq_tol(result, expected_result, ACCURACY);
}
START_TEST(polish_notation_test_2) {
  char* expression = "x - 10.1361466";
  double x = 3.1235356;
  double result;
  double expected_result = x - 10.1361466;

  ck_assert_int_eq(solve_math_expression(expression, x, &result), true);
  ck_assert_double_eq_tol(result, expected_result, ACCURACY);
}
START_TEST(polish_notation_test_3) {
  char* expression = "x * 10.1361466";
  double x = 3.1235356;
  double result;
  double expected_result = x * 10.1361466;

  ck_assert_int_eq(solve_math_expression(expression, x, &result), true);
  ck_assert_double_eq_tol(result, expected_result, ACCURACY);
}
START_TEST(polish_notation_test_4) {
  char* expression = "x / 10.1361466";
  double x = 3.1235356;
  double result;
  double expected_result = x / 10.1361466;

  ck_assert_int_eq(solve_math_expression(expression, x, &result), true);
  ck_assert_double_eq_tol(result, expected_result, ACCURACY);
}
START_TEST(polish_notation_test_5) {
  char* expression = "x ^ 10.1361466";
  double x = 3.1235356;
  double result;
  double expected_result = pow(x, 10.1361466);

  ck_assert_int_eq(solve_math_expression(expression, x, &result), true);
  ck_assert_double_eq_tol(result, expected_result, ACCURACY);
}
START_TEST(polish_notation_test_6) {
  char* expression = "x mod 10.1361466";
  double x = 3.1235356;
  double result;
  double expected_result = (int)x % (int)10.1361466;

  ck_assert_int_eq(solve_math_expression(expression, x, &result), true);
  ck_assert_double_eq_tol(result, expected_result, ACCURACY);
}
START_TEST(polish_notation_test_7) {
  char* expression = "-x";
  double x = 3.1235356;
  double result;

  ck_assert_int_eq(solve_math_expression(expression, x, &result), true);
  ck_assert_double_eq_tol(result, -x, ACCURACY);
}
START_TEST(polish_notation_test_8) {
  char* expression = "+x";
  double x = 3.1235356;
  double result;

  ck_assert_int_eq(solve_math_expression(expression, x, &result), true);
  ck_assert_double_eq_tol(result, x, ACCURACY);
}
START_TEST(polish_notation_test_9) {
  char* expression = "cos(x)";
  double x = 3.1235356;
  double result;
  double expected_result = cos(x);

  ck_assert_int_eq(solve_math_expression(expression, x, &result), true);
  ck_assert_double_eq_tol(result, expected_result, ACCURACY);
}
START_TEST(polish_notation_test_10) {
  char* expression = "sin(x)";
  double x = 3.1235356;
  double result;
  double expected_result = sin(x);

  ck_assert_int_eq(solve_math_expression(expression, x, &result), true);
  ck_assert_double_eq_tol(result, expected_result, ACCURACY);
}
START_TEST(polish_notation_test_11) {
  char* expression = "tan(x)";
  double x = 3.1235356;
  double result;
  double expected_result = tan(x);

  ck_assert_int_eq(solve_math_expression(expression, x, &result), true);
  ck_assert_double_eq_tol(result, expected_result, ACCURACY);
}
START_TEST(polish_notation_test_12) {
  char* expression = "acos(x)";
  double x = 3.14 / 6;
  double result;
  double expected_result = acos(x);

  ck_assert_int_eq(solve_math_expression(expression, x, &result), true);
  ck_assert_double_eq_tol(result, expected_result, ACCURACY);
}
START_TEST(polish_notation_test_13) {
  char* expression = "asin(x)";
  double x = 3.14 / 6;
  double result;
  double expected_result = asin(x);

  ck_assert_int_eq(solve_math_expression(expression, x, &result), true);
  ck_assert_double_eq_tol(result, expected_result, ACCURACY);
}
START_TEST(polish_notation_test_14) {
  char* expression = "atan(x)";
  double x = 3.1235356;
  double result;
  double expected_result = atan(x);

  ck_assert_int_eq(solve_math_expression(expression, x, &result), true);
  ck_assert_double_eq_tol(result, expected_result, ACCURACY);
}
START_TEST(polish_notation_test_15) {
  char* expression = "sqrt(x)";
  double x = 3.1235356;
  double result;
  double expected_result = sqrt(x);

  ck_assert_int_eq(solve_math_expression(expression, x, &result), true);
  ck_assert_double_eq_tol(result, expected_result, ACCURACY);
}
START_TEST(polish_notation_test_16) {
  char* expression = "ln(x)";
  double x = 3.1235356;
  double result;
  double expected_result = log(x);

  ck_assert_int_eq(solve_math_expression(expression, x, &result), true);
  ck_assert_double_eq_tol(result, expected_result, ACCURACY);
}
START_TEST(polish_notation_test_17) {
  char* expression = "log(x)";
  double x = 3.1235356;
  double result;
  double expected_result = log10(x);

  ck_assert_int_eq(solve_math_expression(expression, x, &result), true);
  ck_assert_double_eq_tol(result, expected_result, ACCURACY);
}
START_TEST(polish_notation_test_18) {
  char* expression = "sin(sin(sin(sin(1/ln(x*x)))))";
  double x = 3.1235356;
  double result;
  double expected_result = sin(sin(sin(sin(1 / log(x * x)))));

  ck_assert_int_eq(solve_math_expression(expression, x, &result), true);
  ck_assert_double_eq_tol(result, expected_result, ACCURACY);
}
START_TEST(polish_notation_test_19) {
  char* expression = "sqrt(-(1/(-x*x)))";
  double x = 3.1235356;
  double result;
  double expected_result = sqrt(-(1 / (-x * x)));

  ck_assert_int_eq(solve_math_expression(expression, x, &result), true);
  ck_assert_double_eq_tol(result, expected_result, ACCURACY);
}
START_TEST(polish_notation_test_20) {
  char* expression =
      "(sin(3.141592654/6) + cos(3.141592654/4)) * 10 / (ln(2) ^ sqrt(16))";
  double result;
  double expected_result = 52.293034664;

  ck_assert_int_eq(solve_math_expression(expression, 0.0, &result), true);
  ck_assert_double_eq_tol(result, expected_result, ACCURACY);
}
START_TEST(polish_notation_test_21) {
  char* expression = "5 * (3 + 7) - sqrt(25) ^ 2 + ln(1) / cos(3.141592654/3)";
  double result;
  double expected_result = 25;

  ck_assert_int_eq(solve_math_expression(expression, 0, &result), true);
  ck_assert_double_eq_tol(result, expected_result, ACCURACY);
}
START_TEST(polish_notation_test_22) {
  char* expression =
      "sin(3.141592654/4) * (cos(3.141592654 /6) - 10) + ln(2) / sqrt(16) ^ 3";
  double result;
  double expected_result = -6.447864951;

  ck_assert_int_eq(solve_math_expression(expression, 0, &result), true);
  ck_assert_double_eq_tol(result, expected_result, ACCURACY);
}
START_TEST(polish_notation_test_23) {
  char* expression =
      "(sin(3.141592654/4) + cos(3.141592654/6)) * atan(1) - ln(2) / (sqrt(16) "
      "^ 3)";
  double result;
  double expected_result = 1.2247047;

  ck_assert_int_eq(solve_math_expression(expression, 0, &result), true);
  ck_assert_double_eq_tol(result, expected_result, ACCURACY);
}
START_TEST(polish_notation_test_24) {
  char* expression = "-(-5.5 + 3.2) * 2.1 - 10 mod 4";
  double result;
  double expected_result = 2.83;

  ck_assert_int_eq(solve_math_expression(expression, 0, &result), true);
  ck_assert_double_eq_tol(result, expected_result, ACCURACY);
}
START_TEST(polish_notation_test_25) {
  char* expression =
      "(sin(3.141592654/6) + cos(3.141592654/4)) * 10 / (ln(2) ^ sqrt(16))";
  double result;
  double expected_result = 52.293034664;

  ck_assert_int_eq(solve_math_expression(expression, 0, &result), true);
  ck_assert_double_eq_tol(result, expected_result, ACCURACY);
}
START_TEST(polish_notation_test_26) {
  char* expression = "8.4 * -sin(3.141592654/6) + 25 mod 7 - (-sqrt(16))";
  double result;
  double expected_result = 3.8;

  ck_assert_int_eq(solve_math_expression(expression, 0, &result), true);
  ck_assert_double_eq_tol(result, expected_result, ACCURACY);
}
START_TEST(polish_notation_test_27) {
  char* expression = "-sqrt(25.5) / +ln(2.3) - (-cos(3.141592654/3)) * 3.7";
  double result;
  double expected_result = -4.212789241;

  ck_assert_int_eq(solve_math_expression(expression, 0, &result), true);
  ck_assert_double_eq_tol(result, expected_result, ACCURACY);
}
START_TEST(polish_notation_test_28) {
  char* expression = "acos(0.5) + ln(4)";
  double result;
  double expected_result = 2.4334919;

  ck_assert_int_eq(solve_math_expression(expression, 0, &result), true);
  ck_assert_double_eq_tol(result, expected_result, ACCURACY);
}
START_TEST(polish_notation_test_29) {
  char* expression = "tan(0.0872665) + asin(0.5) + log(5)";
  double result;
  double expected_result = 1.3100574;

  ck_assert_int_eq(solve_math_expression(expression, 0, &result), true);
  ck_assert_double_eq_tol(result, expected_result, ACCURACY);
}
START_TEST(polish_notation_test_30) {
  char* expression = "-sqrt(25.5) / +ln(2.3) - (-cos(3.141592654/3)) * 3.7";
  double result;
  double expected_result = -4.212789241;

  ck_assert_int_eq(solve_math_expression(expression, 0, &result), true);
  ck_assert_double_eq_tol(result, expected_result, ACCURACY);
}

START_TEST(polish_notation_invalid_test_1) {
  char* expression = "sin-(1/(-x*x))";
  double x = 3.1235356;
  double result;

  ck_assert_int_eq(solve_math_expression(expression, x, &result), false);
}

START_TEST(polish_notation_invalid_test_2) {
  char* expression = "cos(12.1245+(ln(1/2))";
  double x = 3.1235356;
  double result;

  ck_assert_int_eq(solve_math_expression(expression, x, &result), false);
}

START_TEST(polish_notation_invalid_test_3) {
  char* expression = "(1 + 2 + 3 + 4 * 5";
  double x = 3.1235356;
  double result;

  ck_assert_int_eq(solve_math_expression(expression, x, &result), false);
}
START_TEST(polish_notation_invalid_test_4) {
  char* expression = "1 + 2 + 3 + 4 * 5)";
  double x = 3.1235356;
  double result;

  ck_assert_int_eq(solve_math_expression(expression, x, &result), false);
}
START_TEST(polish_notation_invalid_test_5) {
  char* expression = "1 * 2 * 3 * 4 +";
  double x = 3.1235356;
  double result;

  ck_assert_int_eq(solve_math_expression(expression, x, &result), false);
}
START_TEST(polish_notation_invalid_test_6) {
  char* expression = "sin12(x)";
  double x = 3.1235356;
  double result;

  ck_assert_int_eq(solve_math_expression(expression, x, &result), false);
}
START_TEST(polish_notation_invalid_test_7) {
  char* expression = "-sqrt)-1( + -2";
  double x = 3.1235356;
  double result;

  ck_assert_int_eq(solve_math_expression(expression, x, &result), false);
}
START_TEST(polish_notation_invalid_test_8) {
  char* expression = "sin()";
  double x = 3.1235356;
  double result;

  ck_assert_int_eq(solve_math_expression(expression, x, &result), false);
}
START_TEST(polish_notation_invalid_test_9) {
  char* expression = "sin(32) /(sin()";
  double x = 3.1235356;
  double result;

  ck_assert_int_eq(solve_math_expression(expression, x, &result), false);
}
START_TEST(polish_notation_invalid_test_10) {
  char* expression = "(10^2 + x - 10 + 20 - +)";
  double x = 3.1235356;
  double result;

  ck_assert_int_eq(solve_math_expression(expression, x, &result), false);
}
START_TEST(polish_notation_invalid_test_11) {
  char* expression = "-sqrt(0)+";
  double x = 3.1235356;
  double result;

  ck_assert_int_eq(solve_math_expression(expression, x, &result), false);
}
START_TEST(polish_notation_invalid_test_12) {
  char* expression = "2mod";
  double x = 3.1235356;
  double result;

  ck_assert_int_eq(solve_math_expression(expression, x, &result), false);
}
START_TEST(polish_notation_invalid_test_13) {
  char* expression = "(2+3+)";
  double x = 3.1235356;
  double result;

  ck_assert_int_eq(solve_math_expression(expression, x, &result), false);
}
START_TEST(polish_notation_invalid_test_14) {
  char* expression = "2+3+ *5";
  double x = 3.1235356;
  double result;

  ck_assert_int_eq(solve_math_expression(expression, x, &result), false);
}
START_TEST(polish_notation_invalid_test_15) {
  char* expression = "(10^x + 2) 10 12";
  double x = 3.1235356;
  double result;

  ck_assert_int_eq(solve_math_expression(expression, x, &result), false);
}
START_TEST(polish_notation_invalid_test_16) {
  char* expression = "(-sqrt(-1) / +ln(2.3) - (-cos(60)) * 3.7)";
  double x = 3.1235356;
  double result;

  ck_assert_int_eq(solve_math_expression(expression, x, &result), false);
}

Suite* create_polish_notation_suite() {
  Suite* suite = suite_create("polish notation tests");
  TCase* tc = tcase_create("polish notation tests");
  TCase* invalid_tc = tcase_create("polish notation invalid tests");

  tcase_add_test(tc, polish_notation_test_1);
  tcase_add_test(tc, polish_notation_test_2);
  tcase_add_test(tc, polish_notation_test_3);
  tcase_add_test(tc, polish_notation_test_4);
  tcase_add_test(tc, polish_notation_test_5);
  tcase_add_test(tc, polish_notation_test_6);
  tcase_add_test(tc, polish_notation_test_7);
  tcase_add_test(tc, polish_notation_test_8);
  tcase_add_test(tc, polish_notation_test_9);
  tcase_add_test(tc, polish_notation_test_10);
  tcase_add_test(tc, polish_notation_test_11);
  tcase_add_test(tc, polish_notation_test_12);
  tcase_add_test(tc, polish_notation_test_13);
  tcase_add_test(tc, polish_notation_test_14);
  tcase_add_test(tc, polish_notation_test_15);
  tcase_add_test(tc, polish_notation_test_16);
  tcase_add_test(tc, polish_notation_test_17);
  tcase_add_test(tc, polish_notation_test_18);
  tcase_add_test(tc, polish_notation_test_19);
  tcase_add_test(tc, polish_notation_test_20);
  tcase_add_test(tc, polish_notation_test_21);
  tcase_add_test(tc, polish_notation_test_22);
  tcase_add_test(tc, polish_notation_test_23);
  tcase_add_test(tc, polish_notation_test_24);
  tcase_add_test(tc, polish_notation_test_25);
  tcase_add_test(tc, polish_notation_test_26);
  tcase_add_test(tc, polish_notation_test_27);
  tcase_add_test(tc, polish_notation_test_28);
  tcase_add_test(tc, polish_notation_test_29);
  tcase_add_test(tc, polish_notation_test_30);

  tcase_add_test(invalid_tc, polish_notation_invalid_test_1);
  tcase_add_test(invalid_tc, polish_notation_invalid_test_2);
  tcase_add_test(invalid_tc, polish_notation_invalid_test_3);
  tcase_add_test(invalid_tc, polish_notation_invalid_test_4);
  tcase_add_test(invalid_tc, polish_notation_invalid_test_5);
  tcase_add_test(invalid_tc, polish_notation_invalid_test_6);
  tcase_add_test(invalid_tc, polish_notation_invalid_test_7);
  tcase_add_test(invalid_tc, polish_notation_invalid_test_8);
  tcase_add_test(invalid_tc, polish_notation_invalid_test_9);
  tcase_add_test(invalid_tc, polish_notation_invalid_test_10);
  tcase_add_test(invalid_tc, polish_notation_invalid_test_11);
  tcase_add_test(invalid_tc, polish_notation_invalid_test_12);
  tcase_add_test(invalid_tc, polish_notation_invalid_test_13);
  tcase_add_test(invalid_tc, polish_notation_invalid_test_14);
  tcase_add_test(invalid_tc, polish_notation_invalid_test_15);
  tcase_add_test(invalid_tc, polish_notation_invalid_test_16);

  suite_add_tcase(suite, tc);
  suite_add_tcase(suite, invalid_tc);

  return suite;
}
