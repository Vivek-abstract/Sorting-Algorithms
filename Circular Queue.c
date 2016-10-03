#include <stdio.h>
#include <conio.h>
#define MAX 5
int CQ[MAX];
int f = -1, r = -1, count = 0;

//Only write functions I guess

void enqueue(int num){
    if(count == MAX){
        printf("Queue Overflow\n");
    } else {
        r = (r + 1) % MAX;
        CQ[r] = num;
        count++;
        if(f == -1){
            f = 0;
        }
    }
}
int dequeue(){
    int num;
    if(count == 0){
        return -1;
    } else {
        num = CQ[f];
        f = (f + 1) % MAX;
        count--;
        return num;
    }
}
void display(){
    int i;
    if(count == 0){
        printf("Queue is Empty\n");
    } else if(f <= r){
        for(i = f; i <= r; i++){
            printf("%d ", CQ[i]);
        }
    } else {
        for(i = f; i < MAX; i++){
            printf("%d ", CQ[i]);
        }
        for(i = 0; i <= r; i++){
            printf("%d ", CQ[i]);
        }
    }
    printf("\n");
}
int main(){
    int choice = 1, num;

    while(choice != 0){
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("Enter a choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter number: ");
                scanf("%d", &num);
                enqueue(num);
                break;
            case 2:
                num = dequeue();
                if(num != -1){
                    printf("%d was deleted from the queue\n", num);
                } else {
                    printf("Queue Underflow\n");
                }
                break;
            case 3:
                display();
                break;
        }
        printf("Do you want to continue? (1/0): ");
        scanf("%d", &choice);
        system("cls");
    }
    return 1;
}
