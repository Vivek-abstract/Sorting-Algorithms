#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void QuickSort(int a[], int f, int l);
int Partition(int a[], int f, int l);
int main()
{
    int i;
    int a[] = {10,9,8,6,4,3,2,1,-5,-8,-32};
    int n = sizeof(a) / sizeof(a[0]);
    QuickSort(a,0,n-1);
    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
void QuickSort(int a[], int f, int l){
    if(f < l){
        int pindex = Partition(a, f, l);
        QuickSort(a, f, pindex-1);
        QuickSort(a, pindex+1, l);
    }
}
int Partition(int a[], int f, int l){
    int p = f, i, pivot = a[l], temp;
    for(i = f; i < l; i++){
        if(a[i] < pivot){
            temp = a[i];
            a[i] = a[p];
            a[p] = temp;
            p++;
        }
    }
    temp = a[p];
    a[p] = a[l];
    a[l] = temp;
    return p;
}
