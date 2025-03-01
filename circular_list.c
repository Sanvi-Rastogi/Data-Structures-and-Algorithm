#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct  Node *Create(struct Node *head, int n)
{
    for(int i=1;i<=n;i++)
    {
    	int data;
    	printf("enter value for position %d: ",i);
    	scanf("%d",&data);
    	struct Node *newNode = createNode(data);
    	if (head == NULL) 
    	{
        	head = newNode;
        	newNode->next = head;
   	}
    	else 
    	{
        	struct Node *temp = head;
        	while (temp->next != head) 
        	{
            		temp = temp->next;
        	}
        	temp->next = newNode;
        	newNode->next = head;
    	}
    }
return head;
}

struct Node *insertAtBeginning(struct Node *head)
{
    int data;
    printf("enter value: ");
    scanf("%d",&data);
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    }
    else {
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
return head;
}

struct Node *insertAtEnd(struct Node *head)
{
    int data;
    printf("enter value: ");
    scanf("%d",&data);
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    }
    else {
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
return head;
}

struct Node *insertAtPosition(struct Node *head, int position)
{
    int data;
    printf("enter value: ");
    scanf("%d",&data);
    struct Node *newNode = createNode(data);
    if (head == NULL && position == 0) {
        head = newNode;
        newNode->next = head;
    }
    else if (position == 0) {
        insertAtBeginning(head);
    }
    else {
        struct Node *temp = head;
        int i = 0;
        while (i < position-1) {
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
return head;
}

struct Node *deleteFromBeginning(struct Node *head)
{
    if (head == NULL) {
        return NULL;
    }
    else if (head->next == head) {
        free(head);
        head = NULL;
    }
    else {
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = (head)->next;
        struct Node *toDelete = head;
        head = head->next;
        free(toDelete);
    }
return head;
}

struct Node *deleteFromEnd(struct Node *head)
{
    if (head == NULL) {
        return NULL;
    }
    else if (head->next == head) {
        free(head);
        head = NULL;
        return head;
    }
    else {
        struct Node *secondLast = head;
        while (secondLast->next->next != head) {
            secondLast = secondLast->next;
        }
        struct Node *last = secondLast->next;
        secondLast->next = head;
        free(last);
        return head;
    }
}

struct Node *deleteAtPosition(struct Node *head, int position)
{
    if (head == NULL) {
        return NULL;
    }
    else if (position == 0) {
        deleteFromBeginning(head);
        return head;
    }
    else {
        struct Node *temp = head;
        int i = 0;
        while (i < position - 1) {
            temp = temp->next;
            i++;
        }
        struct Node *toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
        return head;
    }
}

void traverse(struct Node *head)
{
    if (head == NULL) {
        return;
    }
    struct Node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}


int main()
{
    struct Node *head = NULL;
    int n;
    printf("enter the number of elements in circular list: ");
    scanf("%d",&n);
    head=Create(head, n);
    
    printf("Circular Linked List: ");
    traverse(head);
    
    printf("to insert at start: ");
    head=insertAtBeginning(head);
    printf("Circular Linked List after insertion at front: ");
    traverse(head);
    
    printf("to insert at last: ");
    head=insertAtEnd(head);
    printf("Circular Linked List after insertion at last: ");
    traverse(head);
    
    int position;
    printf("enter position where element has to be inserted: ");
    scanf("%d",&position);
    head=insertAtPosition(head, position);
    printf("Circular Linked List after insertion at desired position: ");
    traverse(head);
    
    printf("deleting from start");
    head=deleteFromBeginning(head);
    traverse(head);
    
    printf("deleting from end");
    head=deleteFromEnd(head);
    traverse(head);
    
    int place;
    printf("enter position from where element has to be deleted: ");
    scanf("%d",&place);
    head=deleteAtPosition(head, place);
    traverse(head);
    
    return 0;
}

