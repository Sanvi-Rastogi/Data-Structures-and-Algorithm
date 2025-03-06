//search and menu creation
#include<stdio.h> 
#include<stdlib.h>  

struct node  
{  
    int data;  
    struct node *next;  
}; 

struct node *create( struct node *head, int item)  
{  
    struct node *ptr = (struct node *)malloc(sizeof(struct node)); 
    if(ptr == NULL)  
    {  
        printf("memory not allocated \n");  
    }  
    else  
    {  
        ptr->data = item;  
        ptr->next = head;  
        head = ptr; 
    }  
return head;
}  

void search(struct node *head)  
{  
    struct node *ptr=head;  
    int item, i = 0, flag = 1;    
    if(ptr == NULL)  
    {  
        printf("Empty List\n"); 
        return; 
    } 
        printf("Enter item which you want to search?\n");   
        scanf("%d", &item);  
        while (ptr != NULL)  
        {  
            if(ptr->data == item)  
            {  
                printf("Item found at location %d \n", i + 1);  
                flag = 0;     
            }  
            i++;  
            ptr = ptr->next;  
        }  
        if(flag == 1)  
        {  
            printf("Item not found\n");  
        }        
}  


int main ()  
{  
    struct node *head=NULL;
    int choice, item;  
    do   
    {  
        printf("\n1. Create\n2. Search\n3. Exit\nEnter your choice: ");  
        scanf("%d", &choice);  
        switch(choice)  
        {  
            case 1: 
                printf("\nEnter the item: ");  
                scanf("%d", &item);  
                head=create(head, item);  
                break;   
            case 2:  
                search(head);  
                break; 
            case 3:  
                break;    
            default:  
                printf("\nPlease enter a valid choice\n");  
        }  
    } while(choice != 3);  
    return 0;  
}  
