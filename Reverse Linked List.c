#include <stdio.h>
#include <stdlib.h>

void create();
void display();
void reverse();

struct node{
    int data;
    struct node *link;
};

struct node *start = NULL;

int main(){
    printf("******Create Linked List******\n");
    create();
    printf("The list is:\n");
    display();
    reverse();
    printf("The reversed list is:\n");
    display();
    return 0;
}
void create(){
    int num;
    struct node *nn, *p;

    printf("Enter data : ");
    scanf("%d", &num);

    while(num != -1){
        nn = (struct node *)malloc(sizeof(struct node));
        nn -> data = num;
        nn -> link = NULL;
        if(start == NULL){
            start = nn;
        }
        else{
            p = start;
            while(p -> link != NULL){
                p = p -> link;
            }
            p -> link = nn;
        }
        printf("Enter data or enter -1 to stop: ");
        scanf("%d", &num);
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
void reverse(){
    struct node *p, *q;
    if(start == NULL){
        printf("Empty Linked list");
    } else if(start -> link == NULL){
        // Checks if only node is present in linked list
        return;
    } else {
        p = start -> link;
        q = p -> link;
        start -> link = NULL;

        while(q != NULL){
            p->link = start;
            start = p;
            p = q;
            q = q -> link;
        }
        p -> link = start;
        start = p;
    }
}
