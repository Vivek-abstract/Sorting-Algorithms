#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void InsertionSort(int a[], int n);
int main()
{
    int i;
    int a[] = {10,9,8,7,6,5,4,3,2,1,0,-7,-100};
    int n = sizeof(a) / sizeof(a[0]);
    InsertionSort(a, n);
    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
void InsertionSort(int a[], int n){
    int i, j, temp;
    for(i = 1; i < n; i++){
        temp = a[i];
        for(j = i-1; j >= 0 && temp < a[j]; j--){
            a[j+1] = a[j];
        }
        a[j+1] = temp;
    }
}
