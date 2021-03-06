#include <stdio.h>
#include <stdlib.h>
int ISearch(int a[], int n, int element);
int main(){
    int a[] = {1,2,3,4,5};
    int element, pos;
    int n = sizeof(a) / sizeof(a[0]);

    printf("Enter element to search: ");
    scanf("%d", &element);

    pos = ISearch(a, n, element);

    if(pos != -1)
        printf("Element found at %d position", pos + 1);
    else
        printf("Element not found");
    return 0;
}
int ISearch(int a[], int n, int element){
    int f = 0, l = n-1, mid;
    while(f < l){
        //Note this:
        mid = f + (l - f) * ((element - a[f]) / (a[l] - a[f]));

        if(a[mid] == element)
            return mid;
        else if(a[mid] < element)
            f = mid + 1;
        else if(a[mid] > element)
            l = mid - 1;
    }
    return -1;
}

