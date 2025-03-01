//printing elements of doubly linked list in reverse order 
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

struct node *reverse() {
    struct node *current = head, *temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        
        current = current->prev;
    }

    if (temp != NULL) {
        head = temp->prev;
    }
return head;
}


int main() {
    head = NULL;
    tail = NULL;
    int n;
    printf(" Input the number of nodes for doubly linked list : ");
    scanf("%d", &n);

    head=CreateList(n); 
    DisplayList(); 

    head=reverse();
    DisplayList();
    return 0;
}