#include "stack_node.h"

StackNode new_stack_node(void* data, StackNode next)
{
  StackNode stackNode = (StackNode) malloc(sizeof(struct stack_node));
  if(!stackNode) error(EXIT_FAILURE, 0, "Malloc error in function %s", __func__);
  stackNode->data = data;
  stackNode->next = next;
  return stackNode;
}

void destroy_stack_node(StackNode* stackNode)
{
  free(*stackNode);
  *stackNode = NULL;
}