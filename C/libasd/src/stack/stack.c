#include "stack.h"
#include "stack_node.h"

/*
 * Data Structures
 */

struct stack
{
  StackNode first;
};

/*
 * Functions
 */

Stack new_stack()
{
  Stack stack = (Stack) malloc(sizeof(struct stack));
  if(!stack) error(EXIT_FAILURE, 0, "Malloc error in function %s", __func__);
  stack->first = NULL;
  return stack;
}

void destroy_stack(Stack* stack)
{
  if (!*stack) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  while((*stack)->first) stack_pop(*stack);
  free(*stack);
  *stack = NULL;
}

void stack_push(Stack stack, void* data)
{
  if (!stack) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  stack->first = new_stack_node(data, stack->first);
}

void* stack_pop(Stack stack)
{
  if (!stack) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  if(stack_is_empty(stack)) return NULL;
  void* data = stack->first->data;
  StackNode temp = stack->first;
  stack->first = stack->first->next;
  destroy_stack_node(&temp);
  return data;
}

int stack_is_empty(Stack stack)
{
  if (!stack) error(EXIT_FAILURE, EINVAL, "Error in function %s", __func__);
  return stack->first == NULL;
}