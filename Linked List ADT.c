#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void create();
void insert_beg(int num);
void insert_end(int num);
void insert(int num);
void delete_beg();
void delete_end();
void delete();
void display();

struct node{
    int data;
    struct node *link;
};
// I use last pointer to avoid traversal
struct node *start = NULL, *last = NULL;

int main(){
    int num, choice = 1;
    while(choice != 0){
        printf("1. Create Linked List\n");
        printf("2. Insert at beginning\n");
        printf("3. Insert at end\n");
        printf("4. Insert after specific element\n");
        printf("5. Delete beginning\n");
        printf("6. Delete end\n");
        printf("7. Delete specific element\n");
        printf("8. Display\n");
        printf("Enter choice or enter 0 to exit: ");
        scanf("%d", &choice);
        switch(choice){
            case 0: // Optional
                exit(1);
            case 1:
                create();
                break;
            case 2:
                printf("Enter number: ");
                scanf("%d", &num);
                insert_beg(num);
                break;
            case 3:
                printf("Enter number: ");
                scanf("%d", &num);
                insert_end(num);
                break;
            case 4:
                printf("Enter number: ");
                scanf("%d", &num);
                insert_after(num);
                break;
            case 5:
                delete_beg();
                break;
            case 6:
                delete_end();
                break;
            case 7:
                printf("Enter element to delete: ");
                scanf("%d", &num);
                delete(num);
                break;
            case 8:
                display();
                break;
        }
        printf("Do you want to continue? (1/0): ");
        scanf("%d", &choice);
        system("cls");  // Use clrscr() instead of this
    }
    return 0;
}
void create(){
    int num;
    struct node *nn;

    printf("Enter data : ");
    scanf("%d", &num);

    while(num != -1){
        nn = (struct node *)malloc(sizeof(struct node));
        nn -> data = num;
        nn -> link = NULL;
        if(start == NULL){
            start = nn;
            last = nn;
        }
        else{
            last -> link = nn;
            last = nn;
        }
        printf("Enter data or enter -1 to stop: ");
        scanf("%d", &num);
    }
}
void insert_beg(int num){
    struct node *nn;
    if(start == NULL){
        printf("Empty Linked List\n");
    } else {
        nn = (struct node *)malloc(sizeof(struct node));
        nn -> data = num;
        nn -> link = start;
        start = nn;
    }
}
void insert_end(int num){
    struct node *nn;
    if(start == NULL){
        printf("Empty Linked List\n");
    } else {
        nn = (struct node *)malloc(sizeof(struct node));
        nn -> data = num;
        nn -> link = NULL;
        last -> link = nn;
        last = nn;
    }
}
void insert_after(int num){
    int key, flag = 0;
    struct node *p, *nn;
    if(start == NULL)
        printf("Empty Linked List\n");
    else{
        printf("Enter key: ");
        scanf("%d", &key);

        p = start;
        while(p != NULL){
            if(p -> data == key){
                nn = (struct node *)malloc(sizeof(struct node));
                nn -> data = num;
                nn -> link = p -> link;
                p -> link = nn;
                if(p == last)
                    last = nn;
                flag = 1;
                break;
            } else{
                p = p -> link;
            }
        }
        if(flag){
            printf("Element inserted successfully\n");
        } else {
            printf("Key not found\n");
        }
    }
}
void delete_beg(){
    struct node *p;
    if(start == NULL){
        printf("Empty Linked list\n");
    } else {
        p = start;
        start = start -> link;
        free(p);
        printf("Element deleted successfully\n");
    }
}
void delete_end(){
    struct node *p, *prev = NULL;
    if(start == NULL){
        printf("Empty Linked List\n");
    } else{
        p = start;
        while(p -> link != NULL){
            prev = p;
            p = p -> link;
        }
        if(p == start){
            start = start -> link;
            free(p);
        } else{
            last = prev;
            last -> link = NULL;
            free(p);
        }
        printf("Element deleted successfully\n");
    }
}
void delete(int num){
    struct node *p, *prev;
    int flag = 0;
    if(start == NULL)
        printf("Empty Linked List\n");
    else{
        p = start;
        while(p != NULL){
            if(p -> data == num){
                if(p == start){
                    start = start->link;
                    free(p);
                }else{
                    prev -> link = p -> link;
                    free(p);
                }
                flag = 1;
                break;
            } else {
                prev = p;
                p = p -> link;
            }
        }
        if(flag)
            printf("Element deleted successfully\n");
        else
            printf("Key not found\n");
    }
}
void display(){
    struct node *p;

    if(start == NULL)
        printf("Empty Linked List\n");
    else{
        p = start;
        while(p != NULL){
            printf("%d -> ", p -> data);
            p = p -> link;
        }
        printf("NULL\n");
    }
}
