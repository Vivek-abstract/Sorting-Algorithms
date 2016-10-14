#include <stdio.h>
#include <conio.h>
#define MAX 10
int Q[MAX];
int f = -1, r = -1;

void create();
int isFull();
int isEmpty();
void enqueue(int num);
int dequeue();
void display();

int main(){
    int choice, num;

    while(choice != 0){
        printf("1. Create Queue\n");
        printf("2. Enqueue\n");
        printf("3. Dequeue\n");
        printf("4. Display\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                create();
                break;
            case 2:
                printf("Enter a number\n");
                scanf("%d", &num);
                enqueue(num);
                break;
            case 3:
                num = dequeue();
                if(num != -1)
                    printf("%d successfully removed from queue\n", num);
                else
                    printf("Queue Underflow\n");
                break;
            case 4:
                display();
                break;
        }
        printf("Do you want to continue? (1/0): ");
        scanf("%d", &choice);
        system("cls");  // Use clrscr() instead of this
    }
    return 1;
}
void create(){
    int num;

    printf("Enter data or enter -1 to stop: ");
    scanf("%d", &num);

    while(num != -1){
        enqueue(num);
        printf("Enter data or enter -1 to stop: ");
        scanf("%d", &num);
    }
}
int isFull(){
    if(r == MAX - 1){
        return 1;
    } else{
        return 0;
    }
}
int isEmpty(){
    if(f == -1 || f > r){
        return 1;
    } else {
        return 0;
    }
}
void enqueue(int num){
    if(isFull()){
        printf("Queue Overflow\n");
    } else {
        r++;
        Q[r] = num;
        if(f == -1){
            f = 0;
        }
    }
}
int dequeue(){
    if(isEmpty()){
        return -1;
    }
    return Q[f++];
}
void display(){
    int i;
    if(isEmpty())
        printf("Empty Queue\n");
    else{
        for(i = f; i <= r; i++){
            printf("%d ", Q[i]);
        }
        printf("\n");
    }
}
