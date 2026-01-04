#include <stdio.h>
#include <unistd.h>

void printArray(int arr[], int length, int l, int r, int pivot);
void swap(int arr[], int index1, int index2);
void sort(int arr[], int length);
int partition(int arr[], int length);
void printFound(int arr[], int length, int foundl, int foundr);

int main(void) {

int arr[] = {10,5,6,1,19,12,3,15,20,7,10,5,6,1,19,12,3,15,20};


sort(arr, 19);
 
printArray(arr, 19, -1, -1, -1);

}

void swap(int arr[], int index1, int index2) {
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
    //printf("swapped %d with %d\n", arr[index1], arr[index2]);
}

void sort(int* arr, int length) {
    if (length < 2) return;
    printf("\033[1;1H\033[K");
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
    printf("\033[1;14H\033[K");

    printf("pivot: | |\n");

    int r = length ;
    int l = -1;
    
    printArray(arr, length, l, r, pivot);

    while(1) {
        sleep(1);
        do {
            l++;
            printArray(arr, length, l , r, pivot);
            sleep(1);
        } while(arr[l] < pivot);
        printFound(arr, length, l, -1);
        
        printArray(arr, length, l , r, pivot);
        sleep(1);
        printf("\033[3;1H\033[K");

        do {
             r--;
            printArray(arr, length, l , r, pivot);
            sleep(1);
        } while(arr[r] > pivot);

        printFound(arr, length, l, r);
        
        printArray(arr, length, l , r, pivot);
        sleep(1);
        printf("\033[3;1H\033[K");

        if (l < r) {
            
            printArray(arr,length, l, r, pivot);
            printf("\033[2;1H\033[K");
            printf("swapping %d and %d\n", arr[l], arr[r]);
            sleep(1);
            printf("\033[2;1H\033[K");
            printf(" ");


            if (arr[l] != arr[r]) swap(arr, l, r);
           
            
        } else {
            printf("\033[3;1H\033[K");
            printf("crossed l: %d r: %d\n", arr[l], arr[r]);
            sleep(1);
            printf("\033[3;1H\033[K");
            printf(" ");
            printArray(arr,length, l, r, pivot);

            break;
        }
        
    }
    return r;
}


void printArray(int arr[], int length, int l, int r, int pivot) {
    printf("\033[4;1H\033[K");
    for(int i=0; i < length; i++) {
        if (i == l || i == r) {
                
            printf("(%d)", arr[i]);
            
        } else if (arr[i] == pivot) {
            printf("[%d]", arr[i]); 
        } else {
            printf(" %d ", arr[i]);
        }
    }
    printf("\n");

     fflush(stdout);
}

void printFound(int arr[], int length, int foundl, int foundr) {
    printf("\033[3;1H\033[K");
    for (int i = 0; i < length; i++) {
        if (i != foundl && i != foundr) {
            if (arr[i] < 10) {
                printf("   ");

            } else {
                printf("    ");
            }
            
        } else {
            if (arr[i] < 10) {

                printf(" ! ");
            } else {
                printf("  ! ");
            }
        }
    }
}
