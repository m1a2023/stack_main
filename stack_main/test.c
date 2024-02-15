#include <stdio.h>
#include "stack.h"

int main() {
	
	stack* s = init_stack();
	push(s, 5);
	push(s, 3);
	push(s, 9);
	push(s, 1);

	push(s, 11);
	push(s, 7);
	push(s, 10);
	push(s, 19);

	push(s, 57);

	printf("size = %d\n", get_size(s));
	printf("quan = %d\n", get_quant(s));

	printf("%d\n", pop(s));
	printf("%d\n", pop(s));	
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));

}