#include "../standard_libraries.h"

/*
 * Types
 */

typedef struct stack_node * StackNode;

/*
 * Data Structures
 */

struct stack_node
{
  void* data;     // Pointer to the data.
  StackNode next; // Pointer to the next node.
};

/*
 * Functions
 */

/**
 * @brief      Creates a new @c StackNode.
 *
 * @param[in]  data  The pointer to the data.
 * @param[in]  next  The pointer to the next @c StackNode.
 *
 * @return     The new @c StackNode.
 */
StackNode new_stack_node(void* data, StackNode next);

/**
 * @brief      Destroy a @c StackNode
 *
 * @param[in]  stackNode  The pointer to the @c StackNode.
 */
void destroy_stack_node(StackNode* stackNode);