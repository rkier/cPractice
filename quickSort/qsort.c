#include <stdio.h>

void printArray(int arr[], int length, int l, int r);
void swap(int arr[], int index1, int index2);
void sort(int arr[], int length);
int partition(int arr[], int length);

int main(void) {

int arr[] = {10,5,6,1,19,12,3,15,20,7,10,5,6,1,19,12,3,15,20};


sort(arr, 19);
printArray(arr, 19, -1, -1);

}

void swap(int arr[], int index1, int index2) {
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
    //printf("swapped %d with %d\n", arr[index1], arr[index2]);
}

void sort(int* arr, int length) {
    if (length < 2) return;
    printf("length: %d\n", length);

    int split = partition(arr, length);

    int length1 = split + 1;
    int length2 = length - length1;


    if (length1 > 1 && length1 != length) {
        sort(&arr[0], length1);
    }
    if (length2 > 1 && length2 != length) {
        sort(&arr[split + 1], length2);
    }

}

int partition(int arr[], int length) {
    int pivot = arr[length/2];
    
    printf("pivot: %d\n", pivot);

    int r = length -1;
    int l = 0;
    printArray(arr, length, l, r);

    while(l < r) {

        while(arr[l] <= pivot && l < length -1) l++;
        while(arr[r] > pivot && r > 0) r--;

        if (l < r) {
            printArray(arr,length, l, r);
            printf("swapping %d and %d\n", arr[l], arr[r]);
            if (arr[l] != arr[r]) swap(arr, l, r);
            printArray(arr,length, l, r);
            l++;
            r--;
        } else {
            printf("crossed l: %d r: %d\n", arr[l], arr[r]);
        }
        printArray(arr, length, l, r);
    }
    return r;
}


void printArray(int arr[], int length, int l, int r) {
    for(int i=0; i < length; i++) {
        if (i == l || i == r) {
            printf("(%d) ", arr[i]);
        } else {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}
