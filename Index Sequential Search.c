#include <stdio.h>
#include <conio.h>
int IndexSeqSearch(int a[], int n, int element);
void main(){
    int a[] = {1,2,3,4,5};
    int n = sizeof(a) / sizeof(a[0]);
    int element, pos, i;
    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\nEnter element to search: ");
    scanf("%d", &element);
    pos = IndexSeqSearch(a, n, element);
    if(pos == -1)
        printf("Element not found");
    else
        printf("Element found at %d position", pos + 1);
    getch();
}
int IndexSeqSearch(int a[], int n, int element){
    int i,j = 0,k, gap = 4;
    int index[100];
    for(i = 0; i < n; i+= gap){
        index[j++] = i;  //Now index has positions 0,4,....
    }
    if(index[j-1] == n-1)
        index[j++] = n-1;
    for(i = 0; i < j-1; i++){
        // We scan through the index array
        if(element >= a[index[i]] && element <= a[index[i+1]]){
            // We check if the element lies within a particular range of indexes
            for(k = index[i]; k <= index[i+1]; k++){
                // If it does, we perform Linear Search on those range of elements
                if(a[k] == element)
                    return k;
            }
        }
    }
    return -1;
}
