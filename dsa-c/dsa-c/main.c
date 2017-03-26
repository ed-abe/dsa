//
//  main.c
//  dsa-c
//
//  Created by Edwin Abraham on 3/24/17.
//  Copyright © 2017 Edwin Abraham. All rights reserved.
//

#include <stdio.h>
#include <curses.h>
#include <math.h>
#define ARR_MAX 100
#define REFRESH 1

int arrSize;

void quickSort(int arr[], int first, int last);
void bubbleSort(int arr[], int size);
void insertSort(int arr[], int size);
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int middle, int right);

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
    
    //    int array[ARR_MAX];
    int n;
    // int i;
    do{
        /*
         printf("\nEnter Integer Array (max count %d) : \t",ARR_MAX);
         
         for(i = 0; i <= ARR_MAX; i++){
         printf("> ");
         if (scanf("%d", &n) == -1)
         break;
         array[i] = n;
         }
         
         arrSize = i;
         */
        int array[]= {3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
        arrSize = 14;
        display(array);
        int n;
        do{
            printf("\n How would you like to sort it?");
            printf("\n1) Quick Sort\n2) Merge Sort\n3) Insertion Sort\n4) Bubble Sort\n5) New Array\n6) Exit\n");
            scanf("%d", &n);
            switch (n) {
                case 1:
                    quickSort(array, 0, arrSize);
                    printf("------------------------------------------\n");
                    break;
                case 2:
                    mergeSort(array, 0, arrSize);
                    break;
                case 3:
                    insertSort(array, arrSize+1);
                    break;
                case 4:
                    bubbleSort(array, arrSize+1);
                    break;
                    
                default:
                    break;
            }
            
        }while(n>4);
    }while(n!=6);
    return 0;
}
/*========================Merge Sort=================================================*/
/*
     Similar to mergesort - divide-and-conquer recursive algorithm
     Average running time O(NlogN)
     Worst-case running time O(N2)
     Basic idea: 
         1. Pick one element in the array, which will be the pivot.
         2. Make one pass through the array, called a partition step, re-arranging the entries so that:
            * the pivot is in its proper place.
            * entries smaller than the pivot are to the left of the pivot.
            * entries larger than the pivot are to its right.
         3. Recursively apply quicksort to the part of the array that is to the left of the pivot,
            and to the right part of the array.
     Here we don't have the merge step, at the end all the elements are in the proper order.
 */
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
/*========================Merge Sort=================================================*/
/*   
     Recursive algorithm.
     Runs in O(NlogN) worst-case running time.
     Basic idea: If we have two sorted arrays, we can merge them in linear time with N comparisons only.
     Given an array to be sorted, we can consider separately its left half and its right half, sort them and then merge them.
*/
void mergeSort(int arr[], int left, int right){
    printf("------------------------------------------>\n");
    display(arr);
    int middle;
    if (right > left)
    {
        middle = floor((left + right)/2);
        mergeSort(arr, left, middle);
        display(arr);
        mergeSort(arr, middle+1, right);
        display(arr);
        merge(arr, left, middle, right);
        display(arr);
        printf("------------------------------------------\n");
    }
    display(arr);
    printf("<------------------------------------------\n");
}
void merge(int arr[], int left, int middle, int right){
    int temp[arrSize];
    int l=left,r=middle+1;
    int i,j;
    for(i = left; l<=middle && r<=right ; i++){
        if(arr[l]<=arr[r]){
            temp[i]=arr[l];
            l++;
        }else{
            temp[i]=arr[r];
            r++;
        }
    }
    
    if(l>middle){
        j=r;
        while(i<=right){
            temp[i]=arr[j];
             j++; i++;
        }
    }else{
        j=l;
        while(j<=middle){
            temp[i]=arr[j];
            j++; i++;
        }
    }
    i=left;
    while(i<=right){
        arr[i]=temp[i]; i++;
    }
}

/*========================Bubble Sort=================================================*/
/*
     Bubble sort
     Runs in O(N^2) worst-case running time.
 */
void bubbleSort(int arr[], int size){
    printf("------------------------------------------\n");
    display(arr);
    int swapped = 1;
    int j = 0;
    int tmp;
    while (swapped) {
        swapped = 0;
        j++;
        printf("------------------------------------------\n");
        for (int i = 0; i < size - j; i++) {
            if (arr[i] > arr[i + 1]) {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                swapped = 1;
                display(arr);
            }
        }
    }
    printf("------------------------------------------\n");
}

/*========================Insert Sort=================================================*/
/*
 Insert sort
 Runs in O(N^2) worst-case running time.
 PRE: array of N elements (from 0 to N-1)
 POST: array sorted
 An array of one element only is sorted
 Assume that the first p elements are sorted.
 For j = p to N-1
 Take the j-th element and find a place for it among the first j sorted elements
 */

void insertSort(int arr[], int size){
    printf("------------------------------------------\n");
    display(arr);
    int i, j, tmp;
    for (i = 1; i < size; i++) {
        j = i;
        printf("------------------------------------------\n");
        display(arr);
        while (j > 0 && arr[j - 1] > arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
            display(arr);
        }
    }
    printf("------------------------------------------\n");
}
/*========================Selection Sort=================================================*/
/*
 Selection sort
 Runs in O(N^2) worst-case running time.
 */
void selectionSort(int arr[], int size) {
    int i, j, minIndex, tmp;
    printf("------------------------------------------\n");
    for (i = 0; i < size - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < size; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        if (minIndex != i) {
            tmp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = tmp;
        }
    }
    printf("------------------------------------------\n");
}
