// made by ANKIT DAS
// on 15 July 2020
// ideally, compile using gcc 8 instead of Dev-C


#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int MAX = 0;

void display(int *array)
{    
     int i = 0;
     printf("\n");

     for(i = 0; i < MAX; i++)
      printf("%d ",*(array + i));
     
     printf("\n");
}

void insert(int *array, int n, int data)
{
    int i = 0;
    if( n > MAX + 1 || n < 1)
     printf("\nINVALID OPERATION!");
    
    else{
    for(i = MAX; i >= n - 1; i--)
     *(array + (i+1)) = *(array + i);
     
    *(array + (n - 1)) = data;
    MAX++;
    display(array);
    }
}

void delete(int *array,  int n)
{
   int i = 0;
   
    if( n > MAX || n < 0)
     printf("\nINVALID OPERATION");

    else{
    for(i = n; i < MAX; i++)
     *(array + (i - 1)) = *(array + i);
    
     *(array + MAX) = 0;
     MAX--;
     display(array);
    }
}

void Edelete(int *array, int element)      // wrapper function for delete, just finds the location            
{
    int i = 0;
    bool found = false;

    for(i = 0; i < MAX; i++)
     if(*(array + i) == element)
      {
        delete(array,i+1);
        found = true;
        break;
      }
        if(!found)
         printf("\nELEMENT NOT FOUND!");
}

void search(int *array, int n)
{
 if( n > MAX + 1 || n < 0)
     printf("\nINVALID OPERATION");   
 else
     printf("\nELEMENT AT %d is %d",n,*(array + (n - 1)));
 
 display(array);
}

void Esearch(int *array, int n)
{    
    bool found = false;
    int i = 0;

    for(i = 0; i <= MAX; i++)
     if(*(array + i) == n)
      {
       printf("\nELEMENT %d FOUND AT %d",n,i+1);
       found = true;
      }

    if(!found)
     printf("\nELEMENT NOT FOUND!");
    
    display(array);
}

void reverse(int *array)
{   
  int i = 0;
  int j = MAX - 1;
  int save = 0;

  while(i < j){
      array[i] = array[i] + array [j];
      array[j] = array[i] - array [j];
      array[i] = array[i] - array[j];

      i++;
      j--;
  }  

 display(array); 
}

void main()
{
     printf("ENTER INITIAL SIZE OF ARRAY: ");
     scanf("%d",&MAX);
     
     int i = 0;

     int *array = calloc(MAX,sizeof(int));    // dynamically allocate memory to a pointer

     for(i = 0; i <= MAX; i++)                // array initialization is required in case of dev-c. can be omitted if using gcc
     *(array + i) = 0;

     bool run = true; 
     int choice = 0, count = 0;
     int n = 0, data = 0;


     while(run){                               // while run is true, the program runs
     printf("\n\n-- MENU --");                 // MAIN MENU
     printf("\n1.INSERT AT POSITION");               
     printf("\n2.INSERT AT BEGINNING");
     printf("\n3.INSERT AT END");
     printf("\n4.DELETE AT POSITION");
     printf("\n5.DELETE BY ELEMENT");
     printf("\n6.SEARCH BY POSITION");
     printf("\n7.SEARCH BY ELEMENT");
     printf("\n8.REVERSE ARRAY");
     printf("\n9.EXIT");
     printf("\n\nENTER YOUR CHOICE:");
     scanf("%d", &choice);

     if(choice < 8)
      scanf("%d",&n);

     switch (choice)
     {
     case 1:
         scanf("%d",&data);
         insert(array,n,data);
         break;
     case 2:
         insert(array,1,n);
         break;
     case 3:
         insert(array,MAX+1,n);
         break;
     case 4:
         delete(array,n);
         break;
     case 5:
         Edelete(array,n);
         break;
     case 6:
         search(array,n);
         break;
     case 7:
         Esearch(array,n);
         break;
     case 8:
         reverse(array);
         break;
     case 9:
         run = false;
         break;
     
     default:
         printf("\nERROR! ENTER A VALID CHOICE");
         break;
     }
    }
    free(array);          // free allocated memory
}
