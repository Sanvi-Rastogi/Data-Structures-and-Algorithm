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

struct node *InsertStart(int value)
{
	struct node *newNode=CreateNode(value);
	if(head==NULL)
	{
		head=newNode;
	}
	else
	{
		newNode->next=head;
		head->prev=newNode;
		head=newNode;
	}
return head;
}

struct node *InsertEnd(int num)
{
	struct node *newNode=CreateNode(num);
	if(head==NULL)
	{
		head=newNode;
	}
	else
	{
		struct node *temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newNode;
		newNode->prev=temp;
	}
return head;
}

struct node *Insert(int x, int position) {
    struct node *newNode = CreateNode(x);
    
    if (position == 1) {
        return InsertStart(x);
    }

    struct node *temp = head;
    for (int i = 1; i < position - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    if (temp->next == NULL) { 
        return InsertEnd(x);
    }

    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

struct node *DeleteStart()
{
	if(head==NULL)
	{
		printf("The list is empty");
		return NULL;
	}
		struct node *toDel=head;
		head=head->next;
		head->prev=NULL;
		free(toDel);
return head;
}

struct node *DeleteEnd()
{
	if(head==NULL)
	{
		printf("The list is empty");
		return NULL;
	}
	if (head->next == NULL) 
	{ 
        free(head);
        head = NULL;
        return NULL;
  }
		struct node *toDel=head, *temp=head;
		while(toDel->next!=NULL)
		{
			temp=toDel;
			toDel=toDel->next;
		}
		temp->next=NULL;
		toDel->prev=NULL;
		free(toDel);
return head;
}

struct node *Delete(int place)
{
	struct node *temp=head, *tmp=head, *toDel=head;
		for(int i=2;i<=place;i++)
		{
			toDel=toDel->next;
			if(toDel==NULL)
				break;
		}
		temp=toDel->prev;
		tmp=toDel->next;

	temp->next=tmp;
	tmp->prev=temp;
	free(toDel);
return head;
}

int main() {
    int n;
    head = NULL;
    tail = NULL;
    printf("Doubly Linked List: \n");
    printf(" Input the number of nodes : ");
    scanf("%d", &n);

    CreateList(n); 
    DisplayList(); 
    
    printf("To insert element at the start of the list \n");
    int value;
    printf("enter value: ");
    scanf("%d",&value);
    head=InsertStart(value);
    DisplayList();
    
    printf("To insert element at the end of the list \n");
    int num;
    printf("enter value: ");
    scanf("%d",&num);
    head=InsertEnd(num);
    DisplayList();
    
    printf("To insert element anywhere in the list \n");
    int x, position;
    printf("enter position: ");
    scanf("%d",&position);
    printf("enter value: ");
    scanf("%d",&x);
    head=Insert(x, position);
    DisplayList();
    
    printf("\n\n");
    
    printf("To delete element from front \n");
    int y;
    printf("enter 1 for yes, 2 for no: ");
    scanf("%d",&y);
    if(y==1)
    {
    	head=DeleteStart();
    }
    DisplayList();
    
    printf("To delete element from end \n");
    printf("enter 1 for yes, 2 for no: ");
    scanf("%d",&y);
    if(y==1)
    {
    	head=DeleteEnd();
    }
    DisplayList();
    
    printf("To delete element from anywhere \n");
    printf("enter 1 for yes, 2 for no: ");
    scanf("%d",&y);
    if(y==1)
    {
    	int place;
    	printf("enter position from where element has to be deleted: ");
    	scanf("%d",&place);
    	head=Delete(place);
    }
    DisplayList();
    
    return 0;
}


