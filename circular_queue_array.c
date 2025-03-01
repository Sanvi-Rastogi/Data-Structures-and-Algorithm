#include <stdio.h>
#include <stdlib.h>

#define MAX 30

struct Queue {
    int arr[MAX];
    int front, rear;
};

void initializeQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(struct Queue *q) {
    return ((q->rear + 1) % MAX == q->front);
}

int isEmpty(struct Queue *q) {
    return (q->front == -1);
}

void enqueue(struct Queue *q, int data) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", data);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0; 
    }
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = data;
    printf("Enqueued: %d\n", data);
}

void dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return;
    }
    int dequeuedValue = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } 
    else {
        q->front = (q->front + 1) % MAX;
    }
    printf("Dequeued: %d\n", dequeuedValue);
}


void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->arr[i]);
        if (i == q->rear) break; 
        i = (i + 1) % MAX;
    }
}

int main() {
    struct Queue q;
    initializeQueue(&q);

    int choice, data;
    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(&q, data);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Enter a valid choice!\n");
        }
    } while (choice != 4);

    return 0;
}