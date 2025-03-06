#include<stdio.h>
#include<stdlib.h>
 
#define max 50

struct Queue {
    int arr[max];
    int front, rear;
};

void initializeQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(struct Queue *q) {
  if(q->rear==max-1)
  {
    return 1;
  }
return 0;
}

int isEmpty(struct Queue *q) {
  if(q->front == -1 || q->front > q->rear)
  {
    return 1;
  }
return 0;
}

void enqueue(struct Queue *q, int data) {
  if(isFull(q))
  {
    printf("Queue is full! \n");
    return;
  }
  if (isEmpty(q)) {
        q->front++;
    }
  q->rear++;
  q->arr[q->rear] = data;
}

void dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! \n");
        return;
    }
    int dequeuedValue = q->arr[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    printf("Dequeued: %d \n", dequeuedValue);
}

void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! \n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
}

int main() {
    struct Queue *q=(struct Queue*)malloc(sizeof(struct Queue));
    initializeQueue(q);

    int choice, data;
    do{
      printf("\n1. Enqueue \n2. Dequeue \n3. Display \n4. Exit \n");
      scanf("%d",&choice);

      switch(choice)
      {
        case 1: 
          printf("Enter data: ");
          scanf("%d",&data);
          enqueue(q, data);
          break;
        case 2: 
          dequeue(q);
          break;
        case 3:
          display(q);
          break;
        case 4:
          exit(0);
        default:
          printf("Enter a valid choice. \n");
      }
    }while(choice!=4);
return 0;
}
