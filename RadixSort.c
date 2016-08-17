#include <stdio.h>
#include <stdlib.h>
void Radixsort(int a[], int n);
int largest(int a[], int n);
int main(){
    int i;
    int a[] = {87,56,98,43,24,75,32};

    //Radix sort doesn't sort negative numbers

    int n = sizeof(a) / sizeof(a[0]);
    Radixsort(a,n);
    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
void Radixsort(int a[], int n){
    int pass, maxd, r, div = 1, bucket[20][20], count[10], i, j, k;
    maxd = largest(a,n);

    for(pass = 1; pass <= maxd; pass++){

        for(i = 0; i < 10; i++){
            count[i] = 0;
        }
        for(i = 0; i < n; i++){
            r = (a[i]/div) % 10;
            bucket[r][count[r]] = a[i];
            count[r]++;
        }
        k = 0;
        for(i = 0; i < 10; i++){
            for(j = 0; j < count[i]; j++){
                a[k++] = bucket[i][j];
            }
        }
        div *= 10;
    }
}
int largest(int a[], int n){
    int i, large = a[0], digits = 0;
    for(i = 1; i < n; i++){
        if(a[i] > large)
            large = a[i];
    }
    while(large != 0){
        digits++;
        large /= 10;
    }
    return digits;
}
