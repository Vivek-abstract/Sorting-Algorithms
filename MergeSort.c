#include<stdio.h>
#include<conio.h>
void merge_sort(int a[], int f, int l);
void merge(int a[], int f, int mid, int l);
void main(){
    int a[] = {10,9,8,7,6,6,5,4,3,2,3,1};
    int n = sizeof(a) / sizeof(a[0]);
    int i;
    merge_sort(a, 0, n-1);
    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}
void merge_sort(int a[], int f, int l){
    int mid;
    if(f < l){
        mid = (f + l) / 2;
        merge_sort(a, f, mid);
        merge_sort(a, mid + 1, l);

        merge(a, f, mid, l);
    }
}
void merge(int a[], int f, int mid, int l){
    int i = f, j = mid + 1, k = 0, b[100];
    while(i <= mid && j <= l){
        if(a[i] <= a[j])
            b[k++] = a[i++];
        else if(a[i] > a[j])
            b[k++] = a[j++];
    }
    while(i <= mid)
        b[k++] = a[i++];
    while(j <= l)
        b[k++] = a[j++];
    for(i = f, k = 0; i <= l; i++, k++){
        a[i] = b[k];
    }
}
