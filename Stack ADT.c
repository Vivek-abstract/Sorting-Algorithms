// This is not a working program. You just have to write all the functions.
//Here are all the functions required for implementing a STACK ADT
int isEmpty(){
    if(top == -1)
        return 1;
    else
        return 0;
}
int isFull(){
    if(top == MAX-1)
        return 1;
    else
        return 0;
}
void push(int a){
    if(isFull())
        printf("Stack Overflown!");
    else{
        top++;
        stack[top] = a;
    }
}
int pop(){
    if(isEmpty())
        printf("Stack Underflown!");
    else{
        int val = stack[top];
        top--;
        return val;
    }
}
int peek(){
    if(isEmpty())
        return -1;
    else
        return stack[top];
}
void display(){
    while(top != -1){
        printf("%d", pop());
    }
}
