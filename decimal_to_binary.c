#include <stdio.h>
#include <stdlib.h>

#define N 32  

struct stack {
    int data[N];
    int top;
};

void initStack(struct stack *s) {
    s->top = -1;
}

int isEmpty(struct stack *s) {
    return s->top == -1;
}

int isFull(struct stack *s) {
    return s->top == N - 1;
}

void push(struct stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow \n");
        exit(1);
    }
    s->data[++(s->top)] = value;
}

int pop(struct stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty \n");
        exit(1);
    }
    return s->data[(s->top)--];
}

int decimalToBinary(int decimal) {
	struct stack s;
	initStack(&s);
	
	if (decimal==0) {
		printf("the binary equivalent is 0");
		return 0;
	}
	while(decimal>0) {
		push(&s, decimal % 2);  
        	decimal = decimal / 2;
        }
        printf("Binary equivalent: ");
        while (!isEmpty(&s)) {
        	printf("%d", pop(&s));
        }
    printf("\n");
}

int main() {
	int decimal;
	printf("Enter a decimal number: ");
        scanf("%d", &decimal);

        decimalToBinary(decimal);
return 0;
}



