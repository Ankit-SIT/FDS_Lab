#include<stdio.h>
#include<stdlib.h> 

enum bool {false,true};

void display(int *array){
int i = 0;
 while(*(array + i)){
    printf("%d ",*(array + i));
    i++;
 }
}
  
enum bool linearSearch(int *array, int n ,int element) 
{ 
    enum bool found = false;

    int i = 0;
    for (i = 0; i < n; i++){
        if (array[i] == element){
            printf("\nELEMENT %d FOUND AT [%d]",element,i);
            found = true;
        }
    }    
    return found; 
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
          if(linearSearch(array,n,element)){
              continue;
          }
          else{
              printf("\nELEMENT %d NOT FOUND!",element);
          };
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
