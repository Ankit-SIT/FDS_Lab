/*
Ankit Das
Oct. 2020

Binary Search done Recursively
*/

#include<stdio.h> 
#include<stdlib.h>

void display(int *array){
int i = 0;
while(*(array + i)){
    printf("%d ",*(array + i));
    i++;
}
}


int binarySearch(int arr[], int left, int right, int element) 
{ 
    if (right >= left) { 
        int mid = left + (right - left) / 2;
        printf("\nMID: %d = %d",mid,*(arr + mid));
   
        if (arr[mid] == element) 
            return mid; 

        if (arr[mid] > element) 
            return binarySearch(arr, left, mid - 1, element); 
 
        return binarySearch(arr, mid + 1, right, element); 
    } 
    return -1; 
} 
  
int main(){
    static int n = 0;
    int i = 0 , choice = 0 , element = 0;
    int result = 0;

    printf("ENTER SIZE OF ARRAY: ");     // Initialization
    scanf("%d",&n);
    int *array = malloc(n*sizeof(int));
    printf("ENTER %d ELEMENTS IN SORTED ORDER: ",n);
    for(i = 0; i < n; i++){
        scanf("%d",(array + i));
    }

    while(1){                         // main loop
      printf("\n\n_____");
      printf("\nMENU");
      printf("\n1. SEARCH");
      printf("\n2. DISPLAY");
      printf("\n3. EXIT");
      printf("\nENTER YOUR CHOICE: ");
      scanf("%d",&choice);
  
      switch (choice)
      {
      case 1:
          printf("ENTER QUERY: ");
          scanf("%d",&element);
          result = binarySearch(array,0,n,element);

          if(result != -1){
              printf("\nELEMENT %d FOUND AT [%d]",*(array + result),result);
          }

          else{
              printf("\nELEMENT %d NOT FOUND!",element);
          }

          break;

      case 2:
          display(array);
          break;
      
      case 3:
          return 0;
  
      default:
          printf("INVALID CHOICE! TRY AGAIN");
          break;
    }
   } 
}
