#ifndef __STACK_H__
#define __STACK_H__

#include "../standard_libraries.h"

/*
 * Types
 */

typedef struct stack * Stack;

/*
 * Functions
 */

/**
 * @brief      Creates a new Stack.
 *
 * @return     The new Stack
 */
Stack new_stack();

/**
 * @brief      Destroy a Stack
 *
 * @param[in]  stack  The Stack to be destroyed.
 */
void destroy_stack(Stack* stack);

/**
 * @brief      Puts some data on top of the Stack.
 *
 * @param[in]  stack  The Stack.
 * @param[in]  data   The data.
 */
void stack_push(Stack stack, void* data);

/**
 * @brief      Gets and remove the data on top of the Stack.
 *
 * @param[in]  stack  Th Stack.
 *
 * @return     @c NULL if the Stack is empty. The data otherwise.
 */
void* stack_pop(Stack stack);

/**
 * @brief      Checks if the Stack is empty.
 *
 * @param[in]  stack  The Stack.
 *
 * @return     @c 0 if the Stack is not empty. Another @c int otherwise.
 */
int stack_is_empty(Stack stack);

#endif