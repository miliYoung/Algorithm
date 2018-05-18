#ifndef _STACK_H
#define _STACK_H

#include <stdlib.h>
#include "list.h"

typedef list stack;

#define stack_init list_init

#define stack_destroy list_destroy

#define stack_size list_size

#define stack_peek(stack) (stack)->head == NULL? NULL:(stack)->head->data

int stack_push(Stack* stack, void* data);

int stack_pop(Stack* stack, void** data);

#endif