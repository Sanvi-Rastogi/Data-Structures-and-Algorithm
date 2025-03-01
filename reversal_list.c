//reversal of list
#include<stdio.h>  
#include<stdlib.h>  

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node *createlist(struct Node *head, int n) {
    struct Node *temp = NULL, *newNode = NULL;

    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter element: ");
        scanf("%d", &data);

        newNode = createNode(data);

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return head;
}

void traversallist(struct Node *head) {
    printf("Linked List: ");
    struct Node *temp = head;

    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node *reversalList(struct Node *head) {
    struct Node *prev = NULL, *ptr = head, *next = NULL;

    while (ptr != NULL) {
        next = ptr->next;  
        ptr->next = prev;  
        prev = ptr;        
        ptr = next;
    }
    head = prev;  
    return head;
}


int main() {
    struct Node *head = NULL;
    int n;

    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    head = createlist(head, n);
    traversallist(head);

    printf("reversal of list \n");
    head=reversalList(head);
    traversallist(head);

    return 0;
}