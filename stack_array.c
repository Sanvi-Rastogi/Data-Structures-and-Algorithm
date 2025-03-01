#include <stdio.h>
#include<stdlib.h>
#define max 50

 struct stack
{
    int a[max];
    int top;
};

void initialize(struct stack *s)
{
    s->top = -1;
}

void push(struct stack *s, int element)
{
    if(s->top == (max-1))
    {
        printf("Stack Overflow");
        return;
    }
        s->top++;
        s->a[s->top] = element;
}

int pop(struct stack *s)
{
    if(s->top == -1)
    {
        printf("Stack Underflow");
        return -1;
    }
        int x=s->a[s->top];
        s->top--;
        return x;
}

int peep(struct stack *s)
{
    if(s->top == -1)
    {
        printf("Stack Empty");
        return -1;
    }
        int x=s->a[s->top];
        return x;
}

int main()
{
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    initialize(s);
    int choice;
    while(1)
    {
    printf("\n1. Insert element in stack (push)\n");
    printf("2. Delete element in stack (pop)\n");
    printf("3. Display element in stack (peep)\n");
    printf("4. Exit\n");
    printf("Enter your choice:\n");
    scanf("%d",&choice);
    switch (choice)
    {
      case 1:
      {
          int element;
          printf("Enter element to insert in stack\n");
          scanf("%d",&element);
          push(s, element);
          break;
      }
      case 2:
      {
          int delete;
          delete = pop(s);
          printf("%d deleted from stack\n",delete);
          break;
      }
      case 3:
      {
         int topmost;
         topmost = peep(s);
         printf("topmost element in stack = %d\n",topmost);
         break;
      }
      case 4:
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
