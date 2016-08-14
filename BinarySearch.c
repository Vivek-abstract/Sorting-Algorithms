#include <stdio.h>
#include <stdlib.h>
int BinarySearch(int a[], int n, int element){
    int f = 0, l = n-1, mid;
    while(f <= l){
        mid = (f + l ) / 2;
        if(a[mid] == element)
            return mid;
        else if(a[mid] < element)
            f = mid + 1;
        else if(a[mid] > element)
            l = mid - 1;
    }
    return -1;
}
int main(){
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int element = 1;
    int n = sizeof(a) / sizeof(a[0]);
    int pos = BinarySearch(a, n, element);
    if(pos != -1)
        printf("Element found at %d position", pos + 1);
    else
        printf("Element not found");
    return 0;
}
