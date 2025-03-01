#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

void palindrome(struct stack *s, char *word)
{
  int i;
  for(i=0; word[i] != '\0'; i++)
  {
    push(s, word[i]);
  }
  char y[50];
  int j=0;
  while (s->top != -1) 
    {
        y[j] = pop(s);
        j++;
    }
    y[j] = '\0';
  if (strcmp(word, y) == 0)
  {
    printf("String is a palindrome \n");
    return;
  }
  printf("String is not a palindrome \n");
}

int main()
{
  struct stack *s=(struct stack*)malloc(sizeof(struct stack));
  initialize(s);

  char word[50];
  printf("Enter a string: ");
  scanf("%s", word);

  palindrome(s, word);
return 0;
}