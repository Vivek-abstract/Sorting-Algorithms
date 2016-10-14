#include <stdio.h>
#include <stdlib.h>

// Only one or two functions will be asked I guess

struct node{
    int data;
    struct node *left, *right;
};

struct node *first, *last;

void insert_beg(int num);
void insert_at(int num);
void delete_beg();
void delete_at();
int search();
void display();

void create();

int main(){
    int choice, num, pos, rpt;

    printf("****Create Doubly Linked List****\n");
    create();
    system("cls");   //clrscr()

    do{
        printf("1. Insert At Beginning\n");
        printf("2. Insert At Location\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from Location\n");
        printf("5. Search a node\n");
        printf("6. Display\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter num: ");
                scanf("%d", &num);
                insert_beg(num);
                break;
            case 2:
                printf("Enter num: ");
                scanf("%d", &num);
                insert_at(num);
                break;
            case 3:
                delete_beg();
                break;
            case 4:
                delete_at();
                break;
            case 5:
                printf("Enter element to search: ");
                scanf("%d", &num);
                pos = search(num);
                if(pos != -1){
                    printf("Element found at position: %d\n", pos + 1);
                } else {
                    printf("Element not found\n");
                }
                break;
            case 6:
                display();
                break;
        }
        printf("Do you want to continue? (1/0): ");
        scanf("%d", &rpt);
        system("cls");
    } while(rpt != 0);
    return 0;
}
void insert_beg(int num){
    // This function and all other functions (except create()) assume list to be already created
    struct node *nn;
    if(first == NULL){
        printf("Empty Doubly Linked list\n");
    } else {
        nn = (struct node *)malloc(sizeof(struct node));
        nn -> data = num;
        nn -> left = NULL;
        nn -> right = first;
        first -> left = nn;
        first = nn;
    }
}
void insert_at(int num){
    struct node *nn, *p;
    int key, pos = 1;
    if(first == NULL){
        printf("Empty Doubly Linked list\n");
    } else {
        // Here we assume that the user is a common man and for him 1 is the location of first node

        printf("Enter location: ");
        scanf("%d", &key);

        p = first;
        while(pos != key && p != NULL ){
            pos++;
            p = p -> right;
        }
        // Now p is at the position where we want to insert
        if(pos == key){
            nn = (struct node *)malloc(sizeof(struct node));
            nn -> data = num;
            nn -> left = nn -> right = NULL;
            if(p != NULL){
                if(p == last){
                //Inserts node at second last position
                    last -> left -> right = nn;
                    nn -> left = last -> left;
                    nn -> right = last;
                } else if(p == first){
                //Inserts node before start
                    nn -> right = first;
                    first -> left = nn;
                    first = nn;
                } else {
                    p -> left -> right = nn;
                    nn -> left = p -> left;
                    nn -> right = p;
                    p -> left = nn;
                }
            } else {
            // When you want to insert at last position
                last -> right = nn;
                nn -> left = last;
                last = nn;
            }
        } else {
            printf("Invalid location\n");
        }
    }
}
void delete_beg(){
    struct node *free_me;
    if(first == NULL){
        printf("Empty Doubly Linked list\n");
    } else if(first -> right == NULL){
        // Only one node is present
        free(first);
        first = NULL;
    } else {
        free_me = first;
        first = first -> right;
        first -> left = NULL;
        free(free_me);
    }
}
void delete_at(int pos){
    int pos1 = 1, key;
    struct node *p;

    if(first == NULL){
        printf("Empty Doubly Linked list\n");
    } else {
        printf("Enter location: ");
        scanf("%d", &key);

        p = first;
        while(pos1 != key && p != NULL ){
            pos1++;
            p = p -> right;
        }
        // Now p is at the correct position
        if(pos1 == key && p != NULL){
            if(p == first){
                delete_beg();
            } else if(p == last){
                last = last -> left;
                last -> right = NULL;
                free(p);
            } else {
            // Now p is a node inside the LL
                p -> left -> right = p -> right;
                p -> right -> left = p -> left;
                free(p);
            }
        } else {
            printf("Invalid Location\n");
        }
    }
}
void display(){
    struct node *p;
    if(first == NULL){
        printf("Empty Doubly Linked list\n");
    } else {
        p = first;
        printf("NULL <- ");
        while(p != NULL){
            printf("%d <-> ", p -> data);
            p = p -> right;
        }
        printf("NULL\n");
    }
}
int search(int num){
    int pos = 0;
    struct node *p;

    if(first == NULL){
        return -1;
    } else {
        p = first;
        while(p != NULL){
            if(p -> data == num){
                return pos;
            }
            pos++;
            p = p -> right;
        }
        return -1;
    }
}
void create(){ //Ignore this function I guess
    struct node *nn;
    int num;

    printf("Enter data or enter -1 to exit: ");
    scanf("%d", &num);

    while(num != -1){
        nn = malloc(sizeof(struct node));
        nn -> data = num;
        nn -> left = nn -> right = NULL;
        if(first == NULL){
            first = nn;
            last = nn;
        } else {
            last -> right = nn;
            nn -> left = last;
            last = nn;
        }
        printf("Enter data or enter -1 to exit: ");
        scanf("%d", &num);
    }
}
