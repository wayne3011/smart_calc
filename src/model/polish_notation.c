//
// Created by ackbarca on 02.02.24.
//
#include "polish_notation.h"

#define NOT_OPERATOR 1

void perform_binary_operator(const char *token, stack_double_t *stack, int *err,
                             double *operations_result) {
  *operations_result = NAN;
  double first_number = pop_double(stack);
  double second_number = pop_double(stack);
  if (first_number != first_number || second_number != second_number)
    (*err) = true;
  else {
    (*operations_result) =
        perform_operator(*token, first_number, second_number);
    if ((*operations_result) != (*operations_result))
      (*err) = true;
    else {
      push_double(stack, (*operations_result));
    }
  }
}

bool solve_notation(char *expression, double x, double *result) {
  stack_double_t stack;
  stack_double_init(&stack);
  int err = false;
  while (*expression != '\0' && !err) {
    char *end_token = strchr(expression, ' ');
    char *token = calloc(end_token - expression + 2, sizeof(char));
    strncpy(token, expression, end_token - expression + 1);
    expression += end_token - expression + 1;
    if (is_digit(*token)) {
      char *end_ptr;
      double num = strtod(token, &end_ptr);
      if (token == end_ptr)
        err = 1;
      else
        push_double(&stack, num);
    } else if (*token == 'x')
      push_double(&stack, x);
    else if (is_operator(*token)) {
      double operations_result;
      if (is_binary_operator(*token)) {
        perform_binary_operator(token, &stack, &err, &operations_result);
      } else if (is_unary_operator(*token)) {
        perform_unary_operator(token, &stack, &err, &operations_result);
      }
      if (operations_result != operations_result) err = true;
    }
    free(token);
  }
  if (!err && stack.root != NULL && stack.root->next == NULL)
    *result = stack.root->val;
  else
    err = true;
  delete_stack_double(&stack);
  return err ? false : true;
}

void perform_unary_operator(const char *token, stack_double_t *stack, int *err,
                            double *operations_result) {
  *operations_result = NAN;
  double first_number = pop_double(stack);
  if (first_number != first_number)
    (*err) = true;
  else {
    (*operations_result) = perform_operator(*token, first_number, 0.0);
    if ((*operations_result) != (*operations_result))
      (*err) = true;
    else {
      push_double(stack, (*operations_result));
    }
  }
}

int get_priority(char val) {
  int priority = 0;
  switch (val) {
    case '=':
    case '~':
      priority = 3;
      break;
    case 'c':
    case 's':
    case 't':
    case 'v':
    case 'd':
    case 'y':
    case 'q':
    case 'l':
    case 'n':
      priority = 1;
      break;
    case '^':
      priority = 2;
      break;
    case '*':
    case 'm':
    case '/':
      priority = 4;
      break;
    case '-':
    case '+':
      priority = 5;
      break;
    default:
      priority = -1;
      break;
  }
  return priority;
}

bool format_str(const char *expression, char *formatted_expression) {
  int exp_len = strlen(expression);

  int index = 0;
  bool err = false;
  for (int i = 0; i < exp_len && !err; ++i) {
    if (expression[i] != ' ' &&
        parse_operators(expression, formatted_expression, &index, &i) ==
            NOT_OPERATOR) {
      if (expression[i] == ')' || expression[i] == '(' ||
          is_digit(expression[i]) || expression[i] == '.' ||
          expression[i] == 'x') {
        formatted_expression[index] = expression[i];
        index++;
      } else
        err = true;
    }
  }
  for (size_t i = 0; i < strlen(formatted_expression) && !err; ++i) {
    if ((formatted_expression[i] == 'c' || formatted_expression[i] == 's' ||
         formatted_expression[i] == 't' || formatted_expression[i] == 'v' ||
         formatted_expression[i] == 'd' || formatted_expression[i] == 'y' ||
         formatted_expression[i] == 'q' || formatted_expression[i] == 'l' ||
         formatted_expression[i] == 'n') &&
        formatted_expression[i + 1] != '(')
      err = true;
  }
  if (!err) formatted_expression[index] = '\0';
  return err ? false : true;
}

int parse_operators(const char *expression, char *formatted_expression,
                    int *index, int *i) {
  if (expression[*i] == 'm' && strncmp(expression + *i, "mod", 3) == 0) {
    formatted_expression[*index] = 'm';
    *i += 2;
  } else if (expression[*i] == 'c' && strncmp(expression + *i, "cos", 3) == 0) {
    formatted_expression[*index] = 'c';
    *i += 2;
  } else if (expression[*i] == 's' && strncmp(expression + *i, "sin", 3) == 0) {
    formatted_expression[*index] = 's';
    *i += 2;
  } else if (expression[*i] == 't' && strncmp(expression + *i, "tan", 3) == 0) {
    formatted_expression[*index] = 't';
    *i += 2;
  } else if (expression[*i] == 'a' &&
             strncmp(expression + *i, "acos", 4) == 0) {
    formatted_expression[*index] = 'v';
    *i += 3;
  } else if (expression[*i] == 'a' &&
             strncmp(expression + *i, "asin", 4) == 0) {
    formatted_expression[*index] = 'd';
    *i += 3;
  } else if (expression[*i] == 'a' &&
             strncmp(expression + *i, "atan", 4) == 0) {
    formatted_expression[*index] = 'y';
    *i += 3;
  } else if (expression[*i] == 's' &&
             strncmp(expression + *i, "sqrt", 4) == 0) {
    formatted_expression[*index] = 'q';
    *i += 3;
  } else if (expression[*i] == 'l' && strncmp(expression + *i, "log", 3) == 0) {
    formatted_expression[*index] = 'l';
    *i += 2;
  } else if (expression[*i] == 'l' && strncmp(expression + *i, "ln", 2) == 0) {
    formatted_expression[*index] = 'n';
    *i += 1;
  } else if (expression[*i] == '-') {
    if ((*i) == 0 || (!is_digit(formatted_expression[(*index) - 1]) &&
                      formatted_expression[(*index) - 1] != 'x' &&
                      formatted_expression[(*index) - 1] != ')')) {
      formatted_expression[*index] = '~';
    } else
      formatted_expression[*index] = '-';
  } else if (expression[*i] == '+') {
    if ((*i) == 0 || (!is_digit(formatted_expression[(*index) - 1]) &&
                      formatted_expression[(*index) - 1] != 'x' &&
                      formatted_expression[(*index) - 1] != ')')) {
      formatted_expression[*index] = '=';
    } else
      formatted_expression[*index] = '+';
  } else if (expression[*i] == '+' || expression[*i] == '*' ||
             expression[*i] == '/' || expression[*i] == '^') {
    formatted_expression[*index] = expression[*i];
  } else
    return NOT_OPERATOR;

  (*index)++;
  return 0;
}

bool is_digit(char val) { return (('0' <= val && val <= '9') || val == 'i'); }

void extract_number(char **postfix_form, char **expression, bool *err) {
  char *end_num_ptr;
  strtod((*expression), &end_num_ptr);
  end_num_ptr--;
  if (*end_num_ptr == '.')
    (*err) = true;
  else {
    int num_length = end_num_ptr - (*expression) + 1;
    strncpy(*postfix_form, (*expression), num_length);
    (*expression) += num_length - 1;
    (*postfix_form) += num_length;
    **postfix_form = ' ';
    (*postfix_form)++;
  }
}

bool is_operator(char val) {
  return (val == 'm' || val == 'c' || val == 's' || val == 't' || val == 'v' ||
          val == 'd' || val == 'y' || val == 'q' || val == 'l' || val == 'n' ||
          val == '-' || val == '+' || val == '*' || val == '/' || val == '^' ||
          val == '~' || val == '=');
}
bool is_binary_operator(char val) {
  return (val == 'm' || val == '-' || val == '+' || val == '*' || val == '/' ||
          val == '^');
}
bool is_unary_operator(char val) {
  return (val == 'c' || val == 's' || val == 't' || val == 'v' || val == 'd' ||
          val == 'y' || val == 'q' || val == 'l' || val == 'n' || val == '~' ||
          val == '=');
}
void upload_stack_with_operator(stack_t *stack, char **postfix_form,
                                char oper) {
  while (stack->root != NULL &&
         get_priority(oper) >= get_priority(stack->root->val) &&
         stack->root->val != '(') {
    **postfix_form = pop(stack);
    (*postfix_form)++;
    **postfix_form = ' ';
    (*postfix_form)++;
  }
}

bool upload_stack_with_bracket(stack_t *stack, char **postfix_form) {
  while (stack->root != NULL && stack->root->val != '(') {
    **postfix_form = pop(stack);
    (*postfix_form)++;
    **postfix_form = ' ';
    (*postfix_form)++;
  }
  return pop(stack) ? true : false;
}

bool to_postfix_form(char *expression, char *postfix_form) {
  bool err = false;
  stack_t stack;
  stack_init(&stack);
  while (*expression != '\0' && !err) {
    if (is_digit(*expression)) {
      extract_number(&postfix_form, &expression, &err);
    } else if (*expression == 'x') {
      *postfix_form = 'x';
      postfix_form++;
      *postfix_form = ' ';
      postfix_form++;
    } else if (is_operator(*expression)) {
      if (stack.root == NULL || stack.root->val == '(' ||
          get_priority(*expression) < get_priority(stack.root->val))
        push(&stack, *expression);
      else {
        upload_stack_with_operator(&stack, &postfix_form, *expression);
        push(&stack, *expression);
      }
    } else if (*expression == '(')
      push(&stack, *expression);
    else if (*expression == ')')
      err = !upload_stack_with_bracket(&stack, &postfix_form);
    else
      err = true;
    expression++;
  }
  while (true) {
    *postfix_form = pop(&stack);
    if (*postfix_form == '(') err = true;
    if (*postfix_form == '\0') break;
    postfix_form++;
    *postfix_form = ' ';
    postfix_form++;
  }
  return err ? false : true;
}

double perform_operator(char oper, double first_number, double second_number) {
  double result;

  switch (oper) {
    case '=':
      result = first_number;
      break;
    case '~':
      result = -first_number;
      break;
    case 'c':
      result = cos(first_number);
      break;
    case 's':
      result = sin(first_number);
      break;
    case 't':
      result = tan(first_number);
      break;
    case 'v':
      result = acos(first_number);
      break;
    case 'd':
      result = asin(first_number);
      break;
    case 'y':
      result = atan(first_number);
      break;
    case 'q':
      result = sqrt(first_number);
      break;
    case 'l':
      result = log10(first_number);
      break;
    case 'n':
      result = log(first_number);
      break;
    case '^':
      result = pow(second_number, first_number);
      break;
    case '*':
      result = first_number * second_number;
      break;
    case 'm':
      result = (int)second_number % (int)first_number;
      break;
    case '/':
      result = second_number / first_number;
      break;
    case '-':
      result = second_number - first_number;
      break;
    case '+':
      result = first_number + second_number;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}