#include<stdio.h>
#include<stdlib.h>

void Display(int arr[], int n) 
{ 
    int i = 0; 
    for (i = 0; i < n; i++){ 
        printf("%d ", arr[i]);
    }

    printf("\n"); 
}   

  
void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

void reset(int arr[],int n){
    int i = 0;

    while(i < n){
        scanf("%d",(arr + i));
        i++;
    }
}

void insertionSort(int arr[], int n) 
{ 
    int i = 0, j = 0, key = 0; 
    printf("\nINITIAL ARRAY: ");
    Display(arr,n);

    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
  
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        }

        arr[j + 1] = key;
        
        printf("PASS %d: ",i);
        Display(arr,n); 
    } 
}

void bubbleSort(int arr[], int n) 
{ 
   printf("\nINITIAL ARRAY: ");
   Display(arr,n);

   int i = 0, j = 0;  
   for (i = 0; i < n-1; i++)       
     
       for (j = 0; j < n-i-1; j++){  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 

        printf("PASS %d: ",i);
        Display(arr,n);

       }
}


void selectionSort(int arr[], int n) 
{ 
    int i = 0, j = 0, min = 0; 
    printf("\nINITIAL ARRAY: ");
    Display(arr,n);
    
   
    for (i = 0; i < n-1; i++) 
    {  
        min = i; 
        for (j = i + 1; j < n; j++){ 
          if (arr[j] < arr[min]){ 
            min = j; 
            }
        }

        swap(&arr[min], &arr[i]); 
        
        printf("PASS %d: ",i);
        Display(arr,n);

    } 
} 
 
int main(){
    static int n = 0;
    int i = 0 , choice = 0 , element = 0;
    int result = 0;

    printf("ENTER SIZE OF ARRAY: ");     // Initialization
    scanf("%d",&n);
    int *array = malloc(n*sizeof(int));
    printf("ENTER %d ELEMENTS: ",n);
    for(i = 0; i < n; i++){
        scanf("%d",(array + i));
    }

    while(1){                         // main loop
      printf("\n\n_____");
      printf("\nMENU");
      printf("\n1. INSERTION SORT");
      printf("\n2. SELECTION SORT");
      printf("\n3. BUBBLE SORT");
      printf("\n4. DISPLAY");
      printf("\n5. RESET");
      printf("\n6. EXIT");
      printf("\nENTER YOUR CHOICE: ");
      scanf("%d",&choice);
  
      switch (choice)
      {
      case 1:
          insertionSort(array,n);
          break;

      case 2:
          selectionSort(array,n);
          break;
      
      case 3:
          bubbleSort(array,n);
          break;
        
      case 4:
          Display(array,n);
          break;

      case 5:
          reset(array,n);
          break;

      case 6:
          return 0;
  
      default:
          printf("INVALID CHOICE! TRY AGAIN");
          break;
    }
   } 
}