#include "stack.h"
#include <stdlib.h>

stack* init_stack() {
	stack* Stack = malloc(sizeof(stack *));

	Stack->size = 8;

	Stack->array = malloc(sizeof(void *) * Stack->size);

	Stack->offset = -1;
	Stack->quantity = 0;

	return Stack;
}

void grow(stack* Stack) {
	Stack->size += 8;
	
	stack* temp = malloc(sizeof(stack *));

	//temp->offset = Stack->offset;
	//temp->quantity = Stack->quantity;
	//temp->size = Stack->size + 8;
	temp->array = malloc(sizeof(void *) * Stack->size);

	for (int i = 0; i < Stack->size - 8; i++) {
		*(temp->array + i) = *(Stack->array + i);
	}
	
	free(Stack->array);
	Stack->array = temp->array;
}

void push(stack* Stack, void* object) {
	if (Stack->quantity < Stack->size) {
		Stack->offset++;
		*(Stack->array + Stack->offset) = object;
		Stack->quantity++;
	}
	else {
		grow(Stack);
		push(Stack, object);
	}
}

void* pop(stack* Stack) {
	if (!Stack->quantity) {
		return -1;
	}
	void* top = *(Stack->array + Stack->offset);

	if (!top) {
		return -1;
	}

	Stack->offset--;
	Stack->quantity--;

	return top;
}

void* peek(stack* Stack) {
	if (!Stack->quantity) {
		return -1;
	}
	return Stack->array[Stack->offset];
}

int get_size(stack* Stack) {
	return Stack->size;
}

int get_quant(stack* Stack) {
	return Stack->quantity;
}

void kill_stack(stack* Stack) {
	free(Stack->array);
	free(Stack);
}

/* void** stack */
/*
#include <stdlib.h>

void** array;

int max_size = 10;

int quantity = 0;

int offset = -1;

void init_stack() {
	array = (malloc(sizeof(void*) * max_size));

	if (!array) {
		return -1;
	}
}

void grow_stack() {
	max_size += 10;
	void** temporary = malloc(sizeof(void*) * max_size);

	for (int i = 0; i < max_size - 10; i++) {
		*(temporary + i) = *(array + i);
	}

	free(array);
	array = temporary;
}

void push(void* object) {
	if (quantity < max_size) {
		offset++;

		*(array + offset) = object;

		quantity++;
	}
	else {
		grow_stack();
		push(object);
	}
}

void* pop() {
	void* top = *(array + offset);

	if (!top) {
		return -1;
	}

	if (!isEmpty()) {
		return -1;
	}

	offset--;
	quantity--;
	
	return top;
}

void* peek() {
	return array[offset];
}

int isEmpty() {
	return quantity == 0;
}

int size() {
	return quantity;
}
*/

/* integer stack */
/*
#include "stack.h"

void push(struct Stack* stack, int value) {
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = value;
	node->next = 0;

	node->next = stack->top;
	stack->top = node;
}
int pop(struct Stack* stack) {
	if (!stack->top->data) {
		return -1;
	}
		
	struct Node* temporary = stack->top;
	stack->top = stack->top->next;

	free(temporary);
	}
	int peek(struct Stack* stack) {
		return stack->top->data;
	}
*/