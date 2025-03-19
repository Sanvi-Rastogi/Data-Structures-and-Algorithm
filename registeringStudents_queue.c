#include <stdio.h>
#include <stdlib.h>

#define MAX 5  
 
struct Queue {
    int arr[MAX];
    int front, rear;
};

void initialise(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(struct Queue *q) {
    return (q->rear == MAX - 1);
}

int isEmpty(struct Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

void enqueue(struct Queue *q, int data) {
    if (isFull(q)) {
        printf("Queue is full. Cannot register more students.\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->arr[q->rear] = data;
}

int isRegistered(struct Queue *q, int rollNumber) {
    for (int i = q->front; i <= q->rear; i++) {
        if (q->arr[i] == rollNumber) {
            return 1; 
        }
    }
    return 0;
}

void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("No students registered.\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

void registerCourse(struct Queue *a, struct Queue *b, struct Queue *c, struct Queue *d, struct Queue *e, int rollNumber) {
    int selectedCourses = 0, courseCode;
    int registeredCourses[3] = {-1, -1, -1};
    
    printf("\n100 for Maths\n101 for Science\n102 for Computers\n103 for History\n104 for Arts\n");

    while (selectedCourses < 3) {
        printf("Enter course code for course %d: ", selectedCourses + 1);
        scanf("%d", &courseCode);

        int alreadyRegistered = 0;
        for (int i = 0; i < selectedCourses; i++) {
            if (registeredCourses[i] == courseCode) {
                alreadyRegistered = 1;
                break;
            }
        }

        if (alreadyRegistered) {
            printf("You have already registered for this course! Choose another.\n");
            continue;
        }

        if (courseCode == 100) {
            if (!isFull(a) && !isRegistered(a, rollNumber)) { enqueue(a, rollNumber); registeredCourses[selectedCourses++] = courseCode; printf("Registered in Maths.\n"); }
            else { printf("Maths is full or you are already registered! Choose another course.\n"); }
        } 
        else if (courseCode == 101) {
            if (!isFull(b) && !isRegistered(b, rollNumber)) { enqueue(b, rollNumber); registeredCourses[selectedCourses++] = courseCode; printf("Registered in Science.\n"); }
            else { printf("Science is full or you are already registered! Choose another course.\n"); }
        } 
        else if (courseCode == 102) {
            if (!isFull(c) && !isRegistered(c, rollNumber)) { enqueue(c, rollNumber); registeredCourses[selectedCourses++] = courseCode; printf("Registered in Computers.\n"); }
            else { printf("Computers is full or you are already registered! Choose another course.\n"); }
        } 
        else if (courseCode == 103) {
            if (!isFull(d) && !isRegistered(d, rollNumber)) { enqueue(d, rollNumber); registeredCourses[selectedCourses++] = courseCode; printf("Registered in History.\n"); }
            else { printf("History is full or you are already registered! Choose another course.\n"); }
        } 
        else if (courseCode == 104) {
            if (!isFull(e) && !isRegistered(e, rollNumber)) { enqueue(e, rollNumber); registeredCourses[selectedCourses++] = courseCode; printf("Registered in Arts.\n"); }
            else { printf("Arts is full or you are already registered! Choose another course.\n"); }
        } 
        else {
            printf("Invalid course code! Try again.\n");
        }
    }
}

int main() {
    struct Queue a, b, c, d, e;  
    initialise(&a);
    initialise(&b);
    initialise(&c);
    initialise(&d);
    initialise(&e);

    int choice, rollNumber;
    do {
        printf("\n1. Register for courses\n2. View course registrations\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &rollNumber);
                registerCourse(&a, &b, &c, &d, &e, rollNumber);
                break;

            case 2:
                printf("\nCourse Registrations:\n");
                printf("Maths: "); display(&a);
                printf("Science: "); display(&b);
                printf("Computers: "); display(&c);
                printf("History: "); display(&d);
                printf("Arts: "); display(&e);
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Enter a valid choice.\n");
        }
    } while (choice != 3);

    return 0;
}
