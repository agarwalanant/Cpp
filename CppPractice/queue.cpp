#include<iostream>

using namespace std;

// Define node pointer
struct node {
    int data;
    node* next;
};

// Head and tail pointers
node* head;
node* tail;

// Functions
int menu();
void enqueue(node *& head, node *&tail, int data);
void dequeue(node *&head, node *& tail);
void front(node *& head);
bool isEmpty(node *& head);
int randomNumber(int min, int max);

//Main function
int main() {

    node* head;
    node* tail;

    head = NULL;
    tail = NULL;
    int choice;
    printf("Number is %d", randomNumber(0, 10));
    do {
        choice = menu();

        switch(choice) {
            case 1:
                int data;
                cout<<"Enter value to be stored in queue: ";
                cin>>data;
                enqueue(head,tail,data);
                break;
            case 2:
                dequeue(head,tail);
                break;
            case 3:
                front(head);
                break;
            case 4:
                printf("Not implemented");
                break;
            case 5:
                isEmpty(head);
                break;
            case -1:
                choice = -1;
                break;

            default: printf("\nEnter a valid choice!!");
        }
    } while(choice != -1);

    return 0;
}

//Menu function
int menu() {
    int ch;
    printf("\nStack");
    printf("\n1.Enqueue\n2.Dequeue\n3.Front element\n4.Is Full\n5.Is Empty\n6.Exit");
    printf("\nEnter your Choice:");
    scanf("%d",&ch);
    return ch;
}

//Enqueue element in stack
void enqueue(node *& head, node *&tail, int data) {
    if (head == NULL) {
        node* n= new node;

        n->data = data;
        n->next = NULL;

        head = n;
        tail = n;

    } else {
        node* n = new node;
        n->data = data;
        n->next = head;
        head = n;
    }
}

// Dequeue first element in a queue
void dequeue(node *&head, node *& tail) {
    if (head == NULL) {
        printf("\nThe queue is empty.");

    } else if (head == tail) {
        // Case when there is only 1 element in the stack
        printf("The value %d was dequeude", head->data);
        delete head;
        head = NULL;
        tail = NULL;

    } else {
        node* n = new node;
        n = tail;
        if(tail->next == NULL) {
            tail = head;
        } else {
            tail = tail->next;
        }

        printf("\nThe value %d was dequeued", n->data);
        delete n;
    }
}

//Show top-most element in stack
void front(node *& head) {
    if (head == NULL) {
        printf("\nThe queue if empty");

    } else {
        printf("\nFront number is %d", head->data);
    }
}

// Shows if the stack is empty
bool isEmpty(node *& head) {
    if(head == NULL) {
        printf("\nThe queue is empty");
        return true;

    } else {
        printf("\nThe queue is not empty");
        return false;
    }
}

int randomNumber(int min, int max) {
    static bool first = true;
    if ( first )
    {
        srand(time(NULL));
        first = false;
    }
    return min + rand() % (max - min);
}