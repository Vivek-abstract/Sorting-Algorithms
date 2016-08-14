#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void ShellSort(int a[], int n);
int main()
{
    int i;
    int a[] = {7,54,2,4,6,7,54,3,2,45,7,9,-6,23};
    int n = sizeof(a) / sizeof(a[0]);
    ShellSort(a, n);
    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
void ShellSort(int a[], int n){
    int i, j, temp, gap;
    for(gap = n/2; gap >= 1; gap /= 2){
        for(i = gap; i < n; i++){
            temp = a[i];
            for(j = i-gap; j >= 0 && temp < a[j]; j-=gap){
                a[j+gap] = a[j];
            }
            a[j+gap] = temp;
        }
    }
}
