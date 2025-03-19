#include <stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct queue {
  struct node *front, *rear;
};

struct queue *initialise(){
  struct queue *q=(struct queue*)malloc(sizeof(struct queue));
  q->front=NULL;
  q->rear=NULL;
  return q;
}

int isEmpty(struct queue* q)
{
    if (q->front == NULL) {
        return 1;
    }
    return 0;
}

struct node *createNode(int data)
{
  struct node *newNode=(struct node*)malloc(sizeof(struct node));
  if(newNode==NULL)
  {
    printf("Memory not allocated. \n");
    return NULL;
  }
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void enqueue(struct queue *q, int data)
{
    struct node *new_node = createNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = new_node;
        return;
    }
    q->rear->next = new_node;
    q->rear = new_node;
}

int dequeue(struct queue *q)
{
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    int x = q->front->data;
    struct node *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return x;
}

int peek(struct queue *q)
{
   if(isEmpty(q)){
      return -1;
   }
   int x = q->front->data;
   return x;
}

void display(struct queue *q)
{
   if(isEmpty(q)){
      printf("Queue is empty. \n");
      return;
   }
   printf("Queue: ");
   struct node *temp=(q->front);
   while(temp!=NULL)
   {
     printf("%d ",temp->data);
     temp=temp->next;
   }
printf("\n");
}

int main()
{
    struct queue *q = initialise();
    int n;
    printf("enter number of elements in queue: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
    	int data;
    	printf("Enter data (in sorted order): ");
    	scanf("%d",&data);
    	enqueue(q, data);
    }
    display(q);
    
    int element;
    printf("Enter element to insert: ");
    scanf("%d",&element);
    
    struct queue *p = initialise();
    	while(peek(q) < element)
    	{
    		enqueue(p, dequeue(q));
    	}	
    	enqueue(p, element);
    	while(peek(q) > element && !isEmpty(q))
    	{
    		enqueue(p, dequeue(q));
    	}

    display(p);
  return 0;
}
