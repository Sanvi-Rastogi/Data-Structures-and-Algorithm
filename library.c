#include<stdio.h>
#include<stdlib.h> 
#include<string.h>

struct Node 
{
    struct Node *next;
    char title[30];
    char author[30];
    char publisher[30];
    int isbn;
};

struct Node *createnode()
{
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    if(newnode == NULL)
    {
        printf("Memory not allocated");
        return NULL;
    }
    printf("Enter title of book: ");
    scanf("%s",newnode->title);
    printf("Enter name of author: ");
    scanf("%s",newnode->author);
    printf("Enter name of publisher: ");
    scanf("%s",newnode->publisher);
    printf("Enter ISBN of book: ");
    scanf("%d",&newnode->isbn);

    newnode->next=NULL;
    return newnode;
}

struct Node *add(struct Node *head)
{
    struct Node *newnode = createnode();
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    struct Node *temp = head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    return head;
}

void search(struct Node *head)
{
    struct Node *ptr=head;
    int item, i=0, flag=1;
    if(ptr==NULL)
    {
        printf("No Books found \n");
        return;
    }
    printf("Enter ISBN of book to be searched: ");
    scanf("%d",&item);
    while(ptr!=NULL)
        {
            if(ptr->isbn == item)
            {
                printf("Book found, Book title: %s \n",ptr->title);
                flag=0;
            }
            i++;
            ptr=ptr->next;
        }
        if(flag==1)
            {
                printf("Book not found \n");
            }
}

void display(struct Node *head)
{
    if (head == NULL) {
        printf("No books available.\n");
        return;
    }
    printf("Books are: \n");
    struct Node *temp = head;
    while(temp!=NULL)
    {
        printf("%s \n",temp->title);
        temp=temp->next;
    }
    printf("\n");
}

struct Node *deleteBook(struct Node *head, int place)
{
    if (head == NULL) {
        printf("No books to delete.\n");
        return head;
    }
    struct Node *todel = head, *temp = head;
    if (place == 1)
    {
        head = head->next;
        free(temp);
        printf("Book deleted successfully.\n");
        return head;
    }
    for(int i=1 ; i<place ; i++)
    {
        temp=todel;
        todel=todel->next;
    }
    temp->next=todel->next;
    free(todel);

    return head;
}

int main()
{
    struct Node *head=NULL;
    int ch, place;

    while(1)
    {
        printf("\n1.Add a book\n2.Search for a book by ISBN\n3.Delete a book\n4.Display Books\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
            head = add(head);
            printf("Book added \n");
            break;
            case 2:
            search(head);
            break;
            case 3:
            display(head);
            printf("Enter position of book to be deleted: ");
            scanf("%d",&place);
            head=deleteBook(head, place);
            break;
            case 4:
            display(head);
            break;
            case 5:
            exit(0);
            break;
            default:
            printf("Enter valid choice \n");
        }

    }
    return 0;
}
