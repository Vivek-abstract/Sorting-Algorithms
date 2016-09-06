#include <stdio.h>
#include <string.h>
#include <conio.h>

#define MAX 100
char stack[MAX];
int top = -1;

int isPallindrome(char a[]);
int main(){
    char str[100];
    printf("Enter string: ");
    gets(str);
    if(isPallindrome(str))
        printf("%s is a Pallindrome!", str);
    else
        printf("%s is not a Pallindrome.", str);
    return 1;
}
int isPallindrome(char a[]){
    int i,n;
    char rev[100];
    n = strlen(a);
    for(i = 0; i < n; i++){
        stack[++top] = a[i];
    }
    for(i = 0; i < n; i++){
        rev[i] = stack[top--];
    }
    rev[i] = '\0';           // The cherry on the cake xD
    if(strcmp(a,rev) == 0)   // Or use strcasecmp if you're case sensitive
        return 1;
    else
        return 0;
}

//Hope anyone doesn't have aibohphobia!
