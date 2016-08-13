#include<stdio.h>
void selection_sort(int a[], int n){
    //    O(n^2)
    int i, start, minpos, temp;
    for(start = 0; start < n; start++){
        minpos = start;
        for(i = start + 1; i < n; i++){
            if(a[i] < a[minpos])
                minpos = i;
        }
        temp = a[start];
        a[start] = a[minpos];
        a[minpos] = temp;
    }
}
void main(){
    int i, a[100], n;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    selection_sort(a, n);
    printf("Sorted array is:\n");
    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}
