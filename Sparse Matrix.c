#include <stdio.h>
#include <stdlib.h>
#define MAX 100

//DRY principle
typedef struct{
    int row, col, val;
    struct node *next;
}node;

node *start, *last;
int a[MAX][MAX];

void insert(int i, int j, int val);
void display();

int main()
{
    int i, j, m, n, c = 0;
    struct node *nn;

    printf("Enter m and n: ");
    scanf("%d%d", &m, &n);
    for(i = 0; i < m; i++){
        printf("Enter values of row %d: ", i + 1);
        for(j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
            if(a[i][j] != 0){
                //Non zero node
                c++;
            }
        }
    }

    //This is the header node
    start = (node *)malloc(sizeof(node));
    start -> row = m;
    start -> col = n;
    start -> val = c;
    start -> next = NULL;
    last = start;

    //Now we create the linked list
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(a[i][j] != 0){
                insert(i, j, a[i][j]);
            }
        }
    }
    printf("The linked list representation of the sparse matrix is:\n");
    display();
}
void insert(int i, int j, int val){
    node *nn;
    nn = (node *)malloc(sizeof(node));
    nn -> row = i;
    nn -> col = j;
    nn -> val = val;
    nn -> next = NULL;
    last -> next = nn;
    last = nn;
}
void display(){
    node *p;
    p = start;
    while(p != NULL){
        printf("(%d,%d,%d) -> ", p -> row, p -> col, p -> val);
        p = p -> next;
    }
    printf("NULL");
}
