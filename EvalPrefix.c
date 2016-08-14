#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
int stack[MAX];
int top = -1;
int EvaluatePrefix(char []);
void push(int val);
int pop();
int main(){
    int i;
    char prefix[20], ans;
    printf("Enter prefix expression:\n");
    scanf("%s", prefix);
    ans = EvaluatePrefix(prefix);
    printf("The value of the expression is : %d", ans);
    return 0;
}
int EvaluatePrefix(char prefix[20]){
    int i;
    char c;
    int op1, op2, temp, result;
    for(i = strlen(prefix)-1; i >= 0; i--){
        c = prefix[i];
        if(isdigit(c)){
            push(c - '40');
        }
        else if(isalpha(c)){
            printf("\nEnter value of %c: ", c);
            scanf("%d", &temp);
            push(temp);
        }
        else{
            op1 = pop();
            op2 = pop();
            switch(c){
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '/':
                    result = op1 / op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                default:
                    printf("Invalid Expression");
                    exit(1);
            }
            push(result);
        }
    }
    return stack[top];
}
void push(int val){
    top++;
    stack[top] = val;
}
int pop(){
    int temp;
    temp = stack[top];
    top--;
    return temp;
}
