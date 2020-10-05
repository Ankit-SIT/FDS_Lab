#include<stdio.h>
#include<stdlib.h>

int binarySearch(int *array, int element)  // Search function
{
    int end = (sizeof(array) / sizeof(*array));
    int start = 0;
    int mid = 0;

    while(start <= end){
        mid = start + (end - start) / 2;
        printf("\nMID: %d = %d",mid,*(array + mid));

        if(element == *(array + mid)){
            return mid;
        }

        if(*(array + mid) < element){
            start = mid + 1;
        }
        
        else{
            end = mid - 1;
        }
  }

  return -1;
}

void display(int *array){
int i = 0;
 while(*(array + i)){
    printf("%d ",*(array + i));
    i++;
 }
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
          result = binarySearch(array,element);

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