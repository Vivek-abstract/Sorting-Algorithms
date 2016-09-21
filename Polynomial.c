#include <stdio.h>
#include <stdlib.h>
struct node{
    int c,e;
    struct node *next;
};
struct node *rfirst = NULL, *rlast = NULL;
struct node *create(struct node *p);
void add_poly(struct node *p1, struct node *p2);
void display(struct node *p);
int main()
{
    struct node *p1 = NULL, *p2 = NULL;
    printf("1st polynomial:\n");
    p1 = create(p1);
    printf("2nd polynomial:\n");
    p2 = create(p2);
    printf("First polynomial looks like:\n");
    display(p1);
    printf("Second polynomial looks like:\n");
    display(p2);
    add_poly(p1,p2);
    printf("Result of addition:\n");
    display(rfirst);
    return 0;
}
struct node *create(struct node *p){
    struct node *nn, *last = NULL;
    int coeff,exp;
    printf("Enter coeff and exp or enter -1 to stop: ");
    scanf("%d%d", &coeff,&exp);
    while(coeff != -1 || exp != -1){
        nn = (struct node *)malloc(sizeof(struct node));
        nn->c = coeff;
        nn->e = exp;
        nn->next = NULL;
        if(p == NULL){
            p = nn;
            last = nn;
        }else{
            last->next = nn;
            last = nn;
        }
        printf("Enter coeff and exp or enter -1 to stop: ");
        scanf("%d%d", &coeff,&exp);
    }
    return p;
};
void display(struct node *p){
    while(p != NULL){
        printf("(%d,%d) -> ", p->c, p->e);
        p = p->next;
    }
    printf("NULL\n");
}
void add_poly(struct node *p1, struct node *p2){
    while(p1!= NULL && p2 != NULL){
        if(p1->e == p2->e){
            insert(p1->c + p2->c, p1->e);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(p1->e > p2->e){
            insert(p1->c,p1->e);
            p1 = p1->next;
        }
        else{
            insert(p2->c, p2->e);
            p2 = p2->next;
        }
    }
    while(p1 != NULL){
        insert(p1->c, p1->e);
        p1 = p1->next;
    }
    while(p2 != NULL){
        insert(p2->c, p2->e);
        p2 = p2->next;
    }
}
void insert(int c, int e){
    struct node *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    nn->c = c;
    nn->e = e;
    nn->next = NULL;
    if(rfirst == NULL){
        rfirst = nn;
        rlast = nn;
    }else{
        rlast->next = nn;
        rlast = nn;
    }
}
