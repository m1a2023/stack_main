#ifndef STACK_H
#define STACK_H

typedef struct stack {
	void** array;
	int offset;
	int quantity;
	int size;
} stack;

stack* init_stack();

void grow(stack *);

void push(stack *, void *);

void* pop(stack *);

void* peek(stack *);

int get_size(stack *);

int get_quant(stack *);

void kill_stack(stack *);

#endif 

/* void** stack */
/*
#ifndef STACK_H
#define STACK_H

void init_stack();
void grow_stack();
void push(void*);
void* pop();
void* peek();
int isEmpty();
int size();

#endif
*/

/* integer stack */
/*
#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
struct Node {
	int data;
	struct Node* next;
};
struct Stack {
	struct Node* top;
};
void push(struct Stack*, int);
int pop(struct Stack*);
int peek(struct Stack*);

#endif
*/