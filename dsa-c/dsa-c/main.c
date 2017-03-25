//
//  main.c
//  dsa-c
//
//  Created by Edwin Abraham on 3/24/17.
//  Copyright © 2017 Edwin Abraham. All rights reserved.
//

#include <stdio.h>
#define ARR_MAX 100
#define REFRESH 0

int arrSize;

void quickSort(int arr[], int first, int last);
void swap(int index1, int index2, int array[]){
    int temp;
    temp = array[index1];
    array[index1]= array[index2];
    array[index2] = temp;
}
void display(int arr[]){
    for(int i=0;i<arrSize;i++)
        printf(" %2d",arr[i]);
    if(REFRESH){
        printf("\r");
    }else{
        printf("\n");
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int array[]= {3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
    arrSize = 14;
    display(array);
    int n, i;
    do{
//        printf("\nEnter Integer Array (max count %d) : \t",ARR_MAX);
        
//        for(i = 0; i <= ARR_MAX; i++){
//            printf("> ");
//            if (scanf("%d", &n) == -1)
//                break;
//            array[i] = n;
//        }
        
//        arrSize = i;
        do{
            printf("\n How would you like to sort it?");
            printf("\n1) Quick Sort\n2) Merge Sort\n3) Insertion Sort\n4) Bubble Sort\n5) New Array\n6) Exit\n");
            scanf("%d", &n);
            switch (n) {
                case 1:
                    quickSort(array,0,arrSize);
                    break;
                    
                default:
                    
                    break;
            }
        }while(n>4);
    }while(n!=6);
    return 0;
}

void quickSort(int arr[], int first, int last) {
    printf("------------------------------------------\n");
    display(arr);
    int pivot,j,i;
    
    if(first<last){
        pivot=first;
        i=first;
        j=last;
        
        while(i<j){
            while(arr[i]<=arr[pivot]&&i<last)
                i++;
            while(arr[j]>arr[pivot])
                j--;
            if(i<j){
                swap(i, j, arr);
                printf(">");
                display(arr);
                
            }
        }
        
        swap(pivot, j, arr);
        display(arr);
        printf("------------------------------------------\n");
        quickSort(arr,first,j-1);
        quickSort(arr,j+1,last);
        
    }
}
