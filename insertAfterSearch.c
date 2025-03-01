//search for an element and insert a new node after it
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

struct node *insertAfterKey(struct node *ptr)
{
  struct node *temp=ptr->next;
  int data;
  printf("Enter element that you want to inssert: ");
  scanf("%d",&data);
  struct node *newNode=CreateNode(data);

  if(temp==NULL)
  {
    ptr->next=newNode;
    newNode->prev=temp;
    return head;
  }

  newNode->next=temp;
  newNode->prev=ptr;
  ptr->next=newNode;
  temp->prev=newNode;
  printf("Node added. \n");
  return head;
}

void search()
{
  struct node *ptr=head;
  if (ptr==NULL)
  {
    printf("list is empty \n");
    return;
  }
  int key, i=0, flag=1;
  printf("Enter element you want to search: ");   
  scanf("%d", &key);  
  while (ptr != NULL)  
  {  
    if(ptr->data == key)  
      {  
        printf("Item found at location %d \n", i + 1);  
        flag = 0;
        break;     
      }  
    i++;  
    ptr = ptr->next;  
  }  
  DisplayList();
  if(flag == 1)  
  {  
    printf("Item not found\n");  
    return;
  } 
else{
  head=insertAfterKey(ptr); 
} 
}


int main() {
    head = NULL;
    tail = NULL;
    int n;
    printf(" Input the number of nodes for doubly linked list : ");
    scanf("%d", &n);

    CreateList(n); 
    DisplayList(); 

    search();
    DisplayList(); 
    return 0;
}