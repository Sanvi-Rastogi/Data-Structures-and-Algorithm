//find sum of odd and even numbers in the doubly linked linked list 
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
} *head, *tail;


struct node *CreateNode(int data)
{
	struct node *n;
	n=(struct node*)malloc(sizeof(struct node));
	if(n==NULL)
	{
		printf("memory not allocated");
		return NULL;
	}
		n->data=data;
		n->next=NULL;
		n->prev=NULL;
	return n;
}

struct node *CreateList(int n) 
{
    int data;
    printf(" Input data for node 1 : ");
    scanf("%d", &data);
		struct node *newNode=CreateNode(data);

		if (newNode == NULL) return NULL;
    head=newNode;
    tail = head; 

    for (int i=2; i<=n; i++) 
    {
      printf(" Input data for node %d : ", i);
      scanf("%d", &data);
			struct node *newNode=CreateNode(data);

			if (newNode == NULL) return head;
                    
			newNode->prev = tail;
      tail->next = newNode;
      tail = newNode;
    } 
  return head;
}

void DisplayList() {
    struct node *temp=head;
    if (head == NULL) 
    {
        printf("List is empty. \n");
				return;
    } 
        printf("The list is: ");

        while (temp != NULL) 
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
}

int checkEvenOdd(int data)
{
  if(data%2 == 0)
  {
    return 0;
  }
  return 1;
}

void sum()
{
  int sumEven=0, sumOdd=0;
  struct node *ptr=head;
  while(ptr!=NULL)
  {
    int k=checkEvenOdd(ptr->data);
    if(k==0)
    {
      sumEven= sumEven + ptr->data;
    }
    else
    {
      sumOdd= sumOdd + ptr->data;
    }
    ptr=ptr->next;
  } 
  printf("Sum of even elements in the list is: %d \n", sumEven);
  printf("Sum of odd elements in the list is: %d \n", sumOdd);
}

int main()
{
  head = NULL;
  tail = NULL;
  int n;
  printf(" Input the number of nodes for doubly linked list : ");
  scanf("%d", &n);

  CreateList(n); 
  DisplayList(); 

  sum();
return 0;
}