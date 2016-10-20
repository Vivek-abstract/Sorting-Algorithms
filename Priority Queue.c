#include <stdio.h>
#include <conio.h>
#define MAX 10

int Q[MAX];
int f = -1, r = -1;

void enqueue(int num);
int dequeue();
void display();

// Program for Ascending Priority Queue. Smallest element has highest priority
int main(){
    int rpt = 1, num, choice;
    while(rpt != 0){
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("Enter choice: \n");
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
        scanf("%d", &rpt);
        system("cls");  //clrscr();
    }
    return 0;
}
void enqueue(int num){
    //Same as linear queue
    if(r == MAX -1){
        printf("Queue Overflow\n");
    } else {
        r++;
        Q[r] = num;
        // or Q[++r] = num if you wanna be flashy
        if(f == -1){
            f = 0;
        }
    }
}
int dequeue(){
    int min, i, pos = 0;
    if(f == -1 || f > r){
        return -1;
    } else {
        // We first find the minimum element
        min = Q[f];
        for(i = 1; i <= r; i++){
            if(Q[i] < min){
                min = Q[i];
                pos = i;
            }
        }
        // Now that the element is found we shift everyone to the left
        for(i = pos; i < r; i++){   // Note the <r
            Q[i] = Q[i+1];
        }
        r--;
        return min;
    }
}
void display(){
    int i;
    if(f == -1 || f > r){
        printf("Qeueue Empty!\n");
    } else {
        for(i = f; i <= r; i++){
            printf("%d ", Q[i]);
        }
        printf("\n");
    }
}
