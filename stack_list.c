#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};


struct Stack
{
    struct Node* top;
};


struct Stack* CREATE()
{
    struct Stack* S = (struct Stack*)malloc(sizeof(struct Stack));
    S->top = NULL; 
    return S;
}


int IsEmpty(struct Stack* S)
{
    if (S->top == NULL)
    {
        return 1;
    }
    return 0;
}


int IsFull(struct Stack* S)
{
    return 0; 
}


void PUSH(struct Stack* S, int x)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed. Stack overflow.\n");
        return;
    }
    newNode->data = x;
    newNode->next = S->top; 
    S->top = newNode; 
    printf("Pushed %d onto the stack.\n", x);
}


void POP(struct Stack* S)
{
    int x=IsEmpty(S);
    if (x==1)
    {
        printf("Stack empty. \n");
        return;
    }
    struct Node* temp = S->top; 
    int poppedValue = temp->data;
    S->top = S->top->next; 
    free(temp); 
    printf("Popped %d from the stack.\n", poppedValue);
}


int Top(struct Stack* S)
{
    int x=IsEmpty(S);
    if (x==1)
    {
        printf("Stack is empty. \n");
        return -1; 
    }
    return S->top->data;
}


void Display(struct Stack* S)
{
    int x=IsEmpty(S);
    if (x==1)
    {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = S->top;
    printf("Stack contents (top to bottom): ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main()
{
   
    struct Stack* S = CREATE(); 
    while(1)
    {
        int ch;
        printf("1.Insert an element at the top of stack\n");
        printf("2.Delete the top element of the stack\n");
        printf("3.Check if Stack is full\n");
        printf("4.Check if Stack is empty\n");
        printf("5.Display the top element of the stack\n");
        printf("6.Display the elements of the stack\n");
        printf("7.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
            {
                int ele;
                printf("Enter element to insert\n");
                scanf("%d",&ele);
                PUSH(S,ele);
                break;
            }
            case 2:
            {
                printf("Top element: %d\n", Top(S));
                POP(S);
                break;
            }
            case 3:
            {
               int x=IsFull(S);
               if(x==0)
               {
                printf("stack is not full \n");
                break;
               }
               printf("stack is full \n");
               break;
            }
            case 4:
            {
               int x=IsEmpty(S);
               if(x==1) 
               {
                printf("stack is empty \n");
                break;
               }
               printf("stack is not empty \n");
               break;
            }
            case 5:
            {
                printf("Top element: %d\n", Top(S));
                break;
            }
            case 6:
            {
                Display(S);
                break;
            }
            case 7:
            {
                printf("Exiting...\n");
                return 0;
            }
            default:
            {
               printf("Invalid Input!\n");
               break;
            }  
        }
    }
    return 0;
}
