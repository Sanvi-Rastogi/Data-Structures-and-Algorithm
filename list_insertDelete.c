#include <stdio.h> 
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int data) 
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (newNode==NULL)
    {
    	return NULL;
    	printf("node not created");
    }
    else
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


void traversallist(struct Node *head)
{
	printf("Linked List: ");
    struct Node *temp = head;
    
    while (temp!=NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}





struct Node *InsertStart(struct Node *head)
{
	int data;
		printf("enter the data to insert at start: ");
		scanf("%d", &data);
		struct Node *newNode=createNode(data);
		if(head==NULL)
		{
			head=newNode;
		}
		else
		{
			newNode->next=head;
			head=newNode;
		}	
  return head;
}


struct Node *InsertEnd(struct Node *head)
{
        int data;
		printf("enter the data to insert at end: ");
		scanf("%d", &data);
		struct Node *newNode=createNode(data);
        struct Node *temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newNode;	
  return head;
 }


struct Node *InsertAnywhere(struct Node *head, int position)
{
	struct Node *temp=head;
	
	int data;
	printf("enter the data: ");
	scanf("%d", &data);
	
	struct Node *newNode=createNode(data);
	
	for(int i=2; i<=position-1; i++)
	{
		if(temp==NULL) {
		break;
        }
		temp=temp->next;
	}
	if(temp!=NULL)
	{
		newNode->next=temp->next;
		temp->next=newNode;
	}
	else
	printf("unsuccessful");
return head;
}	



struct Node *DeleteStart(struct Node *head)
{
	struct Node *temp;
	temp=head;
	head=head->next;
	free(temp);
return head;
}


struct Node *DeleteEnd(struct Node *head)
{
    if (head == NULL) {
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node *temp = head, *toDel=head;
    while(toDel->next!=NULL)
    {
      temp=toDel;
      toDel=toDel->next;
    }
    temp->next=NULL;
    free(toDel);   
    return head;
}


struct Node *DeleteAnywhere(struct Node *head, int place)
{
  if (head == NULL) {
        return NULL;
    }

  struct Node *temp=head, *toDel=head;
  for(int i=1; i<place; i++)
  {
    temp=toDel;
    toDel=toDel->next;
  }
  temp->next=toDel->next;
  free(toDel);
  return head;
}


int main() 
{
    struct Node *head = NULL;
    int n;

    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    head = createlist(head, n);
    traversallist(head);

  
    head=InsertStart(head);
    traversallist(head);
    
    
    head=InsertEnd(head);
    traversallist(head);
    
    int position;
    printf("enter at which position element has to be inserted (except in the start): ");
    scanf("%d", &position);
    head=InsertAnywhere(head, position);
    traversallist(head);
    
    

    head=DeleteStart(head);
    printf("linked list after deleting an element from start is: \n");
    traversallist(head);

    head=DeleteEnd(head);
    printf("linked list after deleting an element from end is: \n");
    traversallist(head);

    int place;
    printf("enter position from where element has to be deleted: ");
    scanf("%d", &place);
    head=DeleteAnywhere(head, place);
    printf("linked list after deleting an element from end is: \n");
    traversallist(head);
    
return 0;
}
