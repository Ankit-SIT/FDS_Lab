/*
Ankit Das
25th October
Merge Sort
*/

#include <stdio.h> 
#include <stdlib.h> 

int pass = 0;
int n = 0;

void display(int Array[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", Array[i]); 
    printf("\n"); 
} 

void merge(int array[], int l, int m, int r) 
{ 
    int i, j, k; 
    int nLeft = m - l + 1; 
    int nRight = r - m; 

    int Left[nLeft], Right[nRight]; 
 
    // Copy left subarray to a temporary array
    for (i = 0; i < nLeft; i++) 
        Left[i] = array[l + i]; 

    // Copy right subarray to a temporary array
    for (j = 0; j < nRight; j++) 
        Right[j] = array[m + 1 + j]; 
 
    i = 0; 
    j = 0; 
    k = l;  

    // Sort array while both arrays haven't been exhausted
    while (i < nLeft && j < nRight) { 

        if (Left[i] <= Right[j]) { 
            array[k] = Left[i]; 
            i++; 
        } 

        else { 
            array[k] = Right[j]; 
            j++; 
        } 

        k++; 
    } 

    // add remaining elements to the array, if any
    while (i < nLeft) { 
        array[k] = Left[i]; 
        i++; 
        k++; 
    } 

    while (j < nRight) { 
        array[k] = Right[j]; 
        j++; 
        k++; 
    } 


} 

// entry point to sort function
void mergeSort(int array[], int leftIndex, int rightIndex) 
{   
    if (leftIndex < rightIndex) { 
        int midIndex = leftIndex + (rightIndex - leftIndex) / 2; 

        // call mergesort recursively for left subarray
        mergeSort(array, leftIndex, midIndex); 

        // call mergesort recursively for right subarray
        mergeSort(array, midIndex + 1, rightIndex); 
 
        // after creating subarrays, merge the array
        merge(array, leftIndex, midIndex, rightIndex);

        // print pass
        pass++;
        printf(" PASS %d: ",pass);
        display(array,n);
    } 
} 


int main() 
{   
    printf("ENTER SIZE: ");
    scanf("%d",&n);
    int* array = malloc(n * sizeof(int));

    int i = 0;
    for(i = 0; i < n; i++){
        scanf("%d",&array[i]);
    }
 
    printf("\nINITIAL: "); 
    display(array, n); 
    
    // perform sort
    mergeSort(array, 0, n - 1); 
 
    printf("\nSORTED: \n"); 
    display(array, n); 
    return 0; 
} 
