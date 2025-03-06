#include <stdio.h> 
#include <stdlib.h>
#include<string.h>

#define max 100

struct node {
    char advertisement[max];
    struct node *prev;
    struct node *next;
} *head, *tail;


struct node *CreateNode(char *ad)
{
	struct node *n;
	n=(struct node*)malloc(sizeof(struct node));
	if(n==NULL)
	{
		printf("memory not allocated");
		return NULL;
	}
		strcpy(n->advertisement, ad);
		n->next=NULL;
		n->prev=NULL;
	return n;
}

struct node *add()
{
  char ad[max];
  printf("Enter advertisement: ");
  scanf("%s", ad);
  struct node *newNode=CreateNode(ad);

  if(head==NULL)
  {
    head=newNode;
    printf("Advertisement added. \n");
    return head;
  }
  struct node *temp=head;
  while(temp->next !=NULL)
  {
    temp=temp->next;
  }
  temp->next=newNode;
  newNode->prev=temp;

  printf("Advertisement added. \n");
  tail=newNode;
  return head;
}

struct node *DisplayAd() {
    struct node *temp=head;
    if (head == NULL) 
    {
        printf("No advertisments. \n");
				return head;
    } 
    printf("%s \n", temp->advertisement);
    return head;
}

struct node *DisplayAdBeforeAfter() {
  int option;
  struct node *temp=head;

  if (!temp) {
        printf("No advertisements.\n");
        return head;
  }

  do   
  {  
    printf("\n1. Show next advertisement \n2. Show previous advertisemnt\n3. Exit\nEnter your choice: ");  
    scanf("%d", &option);
    
    switch(option)
    {
      case 1:
        if(temp->next == NULL)
        {
          printf("No advertisement ahead. \n");
        }
        else 
        {
          temp=temp->next;
          printf("%s ", temp->advertisement);
        }
        break;

      case 2:
        if(temp->prev == NULL)
        {
         printf("No advertisement behind. \n");
        }
        else
        {
          temp=temp->prev;
          printf("%s ", temp->advertisement);
        }
        break;

      case 3:
        return head;

      default:
        printf("enter valid choice \n");
    }
  }while(option != 3);
return head;
}

struct node *removeAd() {
    if (head == NULL) {
        printf("No advertisements to remove.\n");
        return NULL;
    }
    if (head->next == NULL) { 
        free(head);
        head = tail = NULL;
    } 
    else
    {
        struct node *temp = head;
        while(temp->next !=NULL)
        {
          temp=temp->next;
        }
        struct node *toDel=temp;
        temp=temp->prev;
        temp->next=NULL;
        toDel->prev=NULL;
        free(toDel);
    }
    printf("Advertisement removed.\n");
  return head;
}


int main() {
    head = NULL;
    tail = NULL;

    int choice, item;  
    do   
    {  
        printf("\n1. Add advertisement \n2. Remove advertisemnt\n3. Display\n4.Exit \nEnter your choice: ");  
        scanf("%d", &choice);  
        switch(choice)  
        {  
            case 1:   
                head=add();  
                break;  

            case 2:
                head=removeAd();
                break;

            case 3:  
                head=DisplayAd();
                head=DisplayAdBeforeAfter();
                
                break;

            case 4:
                exit(0);

            default:  
                printf("\nPlease enter a valid choice\n");  
        }  
    } while(choice != 4);  
}


