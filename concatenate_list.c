#include <stdio.h> 
#include <stdlib.h>

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
        } 
        else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return head;
}

void traversallist(struct Node *head) {
    printf("Linked List: ");
    struct Node *temp = head;

    while (temp!=NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node *concatenate(struct Node *head, struct Node *head1)
{
  if (head == NULL) return head1;
  if (head1 == NULL) return head;
  struct Node *temp=head;
  while (temp->next!=NULL) {
        temp = temp->next;
    }
  temp->next=head1;
return head;
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
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    int n, m;

    printf("Enter the number of elements in list 1: ");
    scanf("%d", &n);
    head1 = createlist(head1, n);
    traversallist(head1);

    printf("\nEnter the number of elements in list 2: ");
    scanf("%d", &m);
    head2 = createlist(head2, m);
    traversallist(head2);

    printf("\nConcatenated string is: ");
    head1=concatenate(head1, head2);
    traversallist(head1);

    printf("\nReversed concatenated list is: ");
    head1=reversalList(head1);
    traversallist(head1);

    return 0;
}
