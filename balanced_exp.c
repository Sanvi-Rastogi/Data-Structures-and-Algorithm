#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define N 100

struct stack {
    char data[N];
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

void push(struct stack *s, char c) {
    if (isFull(s)) {
        printf("Stack Overflow \n");
        exit(1);
    }
    s->data[++(s->top)] = c;
}

char pop(struct stack *s) {
    if (isEmpty(s)) {
        return '\0';  
    }
    return s->data[(s->top)--];
}

int isParenthesis(char c) {
    return (c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}');
}

int isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') || (opening == '[' && closing == ']') || (opening == '{' && closing == '}');
}

int isBalanced(char *expression) {
    struct stack s;
    initStack(&s);

    for (int i = 0; expression[i] != '\0'; i++) {
        char c = expression[i];

        if (c == '(' || c == '[' || c == '{') {
            push(&s, c);
        } 
        
        else if (c == ')' || c == ']' || c == '}') {
            if (isEmpty(&s)) {
                printf("Closing bracket found without opening bracket. \n");
                return 0;
            }
            char top = pop(&s);
            if (!isMatchingPair(top, c)) {
                printf("Parentheses do not match \n");
                return 0;
            }
        }
    }
    return isEmpty(&s);
}

int main() {
    char expression[N];

    printf("Enter an expression: ");
    scanf("%s", expression);

    if (isBalanced(expression)) {
        printf("The expression is balanced.\n");
    } 
    else {
        printf("The expression is not balanced.\n");
    }
return 0;
}


