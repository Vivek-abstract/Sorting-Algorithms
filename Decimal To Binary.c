#include <stdio.h>
#define MAX 100
void Binary(int n);
int stack[MAX];
int top = -1;
int main(){
    int n, b;
    printf("Enter n: ");
    scanf("%d", &n);
    Binary(n);
    return 0;
}
void Binary(int n){
    int r;
    while(n > 0){
        stack[++top] = n % 2;
        n /= 2;
    }
    while(top != -1){
        printf("%d", stack[top--]);
    }
}
