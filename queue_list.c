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

void enqueue(struct queue* q, int new_data)
{
    struct node *new_node = createNode(new_data);
    if (q->rear == NULL) {
        q->front = q->rear = new_node;
        return;
    }
    q->rear->next = new_node;
    q->rear = new_node;
}

void dequeue(struct queue* q)
{
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return;
    }
    struct node *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

void getFront(struct queue* q)
{
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("%d is the front element of the queue. \n",q->front->data);
}

void getRear(struct queue* q)
{
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("%d is the last element of the queue. \n",q->rear->data);
}

void display(struct queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! \n");
        return;
    }
    printf("Queue: ");
    struct node *temp=(q->front);
    while(temp!=NULL)
    {
      printf("%d ",temp->data);
      temp=temp->next;
    }
}

void freeQueue(struct queue *q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
    free(q);
}

int main()
{
    struct queue *q = initialise();

    int choice, data;
    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Get front element \n5. Get rear element \n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(q, data);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                getFront(q);
                break;
            case 5:
                getRear(q);
                break;
            case 6:
                freeQueue(q);
                exit(0);
            default:
                printf("Enter a valid choice!\n");
        }
    } while (choice != 6);
  return 0;
}