#include <stdio.h>

int a[20][20], n, visited[20];
char name[20];
int stack[20], top = -1;

void DFS(int v);

int main(){
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        printf("Enter name of vertex %d: ", i);
        scanf(" %c", &name[i]);  //Note the space before %c
    }

    printf("Enter the adjacency matrix: ");
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            scanf("%d", &a[i][j]);
        }
    }

    for(i = 1; i <= n; i++){
        visited[i] = 0;
    }
    for(i = 1; i <= n; i++){
        if(visited[i] == 0){
            DFS(i);
        }
    }
    return 0;
}
void DFS(int v){
    int j;
    stack[++top] = v;
    visited[v] = 1;

    while(top != -1){
        v = stack[top--];
        printf("%c ->", name[v]);
        for(j = 1; j <= n; j++){
            if(a[v][j] && visited[j] == 0){
                stack[++top] = j;
                visited[j] = 1;
            }
        }
    }
}
