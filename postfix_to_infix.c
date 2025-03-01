#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack structure
typedef struct {
    char* items[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initialize(Stack* s) {
    s->top = -1;
}

// Function to check if stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(Stack* s, char* str) {
    if (s->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->items[++(s->top)] = str;
}

// Function to pop an element from the stack
char* pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return NULL;
    }
    return s->items[(s->top)--];
}

// Function to check if a character is an alphanumeric character
int isAlnum(char ch) {
    return (ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

// Function to compute string length manually
int strLength(char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Function to copy string manually
void strCopy(char* dest, char* src) {
    while ((*dest++ = *src++) != '\0');
}

// Function to concatenate strings manually
void strConcat(char* dest, char* src) {
    while (*dest) {
        dest++;
    }
    while ((*dest++ = *src++) != '\0');
}

// Function to convert postfix to infix
char* postfixToInfix(char* postfix) {
    Stack s;
    initialize(&s);
    
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isAlnum(postfix[i])) {
            char* operand = (char*)malloc(2 * sizeof(char));
            operand[0] = postfix[i];
            operand[1] = '\0';
            push(&s, operand);
        } else { // Operator
            char* op2 = pop(&s);
            char* op1 = pop(&s);
            
            if (!op1 || !op2) {
                printf("Invalid postfix expression\n");
                return NULL;
            }
            
            char* expr = (char*)malloc(strLength(op1) + strLength(op2) + 4);
            strCopy(expr, "(");
            strConcat(expr, op1);
            char opStr[2] = {postfix[i], '\0'};
            strConcat(expr, opStr);
            strConcat(expr, op2);
            strConcat(expr, ")");
            
            push(&s, expr);
        }
    }
    
    return pop(&s);
}

int main() {
    char postfix[MAX];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
    
    char* infix = postfixToInfix(postfix);
    if (infix) {
        printf("Infix expression: %s\n", infix);
        free(infix);
    }
    return 0;
}
