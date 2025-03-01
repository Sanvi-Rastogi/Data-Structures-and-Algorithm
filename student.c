#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
  char name[30];
  char department[10];
  int year;
  int rollNumber;
  struct node *next;
};

struct node *createNode()
{
  struct node *newNode=(struct node*)malloc(sizeof(struct node));
  if(newNode==NULL)
  {
    printf("memory not allocated \n");
    return NULL;
  }
  printf("Enter first name: ");
  scanf("%s",newNode->name);
  printf("Enter department: ");
  scanf("%s",newNode->department);
  printf("Enter year of admission: ");
  scanf("%d",&newNode->year);
  printf("Enter roll number: ");
  scanf("%d",&newNode->rollNumber);

  newNode->next=NULL;
  return newNode;
}

struct node *add(struct node *head)
{
  struct node *newNode=createNode();
  if(head==NULL)
  {
    head=newNode;
    return head;
  }

  struct node *temp=head;
  while(temp->next != NULL)
  {
    temp=temp->next;
  }
  temp->next=newNode;
  return head;
}

void listCSEstudents(struct node *head) {
    struct node *temp = head;
    int flag = 1;

    while (temp != NULL) {
  //     strcmp returns
	// •	0 if the two strings are equal.
	// •	A negative value (< 0) if the first string is lexicographically less than the second.
	// •	A positive value (> 0) if the first string is lexicographically greater than the second.
      if (strcmp(temp->department, "CSE") == 0) {
          printf("%s\n", temp->name);
          flag = 0;
      }
      temp = temp->next;
    }
    if (flag==1) {
        printf("No student in CSE department.\n");
    }
}

void listStudentsByYear(struct node *head, int year) {
    struct node *temp = head;
    int flag = 1;

    while (temp != NULL) {
        if (temp->year == year) {
            printf("%s\n", temp->name);
            flag = 0;
        }
        temp = temp->next;
    }

    if (flag==1) {
        printf("No student enrolled in year %d.\n", year);
    }
}


int main() {
    struct node *head = NULL;
    int choice, year;

    while (1) {
        printf("\n1. Add a student \n2. List all students studying in CSE department \n3. List all students enrolled in a given year \n4. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = add(head);
                printf("Student added.\n");
                break;
            case 2:
                listCSEstudents(head);
                break;
            case 3:
                printf("Enter year to search: ");
                scanf("%d", &year);
                listStudentsByYear(head, year);
                break;
            case 4:
                return 0;
            default:
                printf("Enter a valid choice.\n");
        }
    }

    return 0;
}