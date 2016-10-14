#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
char stack[MAX][MAX];
int top = -1;
void PrefixToPostfix(char [], char []);
void push(char c[]);
char *pop();
int main(){
    int i;
    char prefix[20], postfix[20];
    printf("Enter prefix expression:\n");
    scanf("%s", prefix);
    PrefixToPostfix(prefix, postfix);
    for(i = 0; i < strlen(postfix); i++){
        printf("%c", postfix[i]);
    }
    return 0;
}
void PrefixToPostfix(char prefix[20], char postfix[20]){
    int i;
    char c;
    char *op1, *op2;
    char temp[2];
    for(i = strlen(prefix)-1; i >= 0; i--){
        c = prefix[i];
        temp[0] = c;
        temp[1] = '\0';
        if(isdigit(c) || isalpha(c)){
            push(temp);
        }
        else{
            switch(c){
                case '+':
                case '-':
                case '/':
                case '*':
                    op1 = pop();
                    op2 = pop();
                    strcpy(postfix, op1);
                    strcat(postfix, op2);
                    strcat(postfix, temp);
                    push(postfix);
                    break;
                default:
                    printf("Invalid Expression");
                    exit(1);
            }
        }
    }
}
void push(char item[]){
    top = top+1;
    strcpy(stack[top], item);
}
char *pop(){
    char *temp;
    temp = stack[top];
    top = top-1;
    return temp;
}
