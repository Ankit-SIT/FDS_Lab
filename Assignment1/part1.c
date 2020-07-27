/*
Ankit Das
CS A1
19070122023
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int sum(int a, int b)
{
    return a + b;
}

int reverse(int a){  
    int rev = 0;
    while(a!=0)
    {
        rev = (rev * 10) + a % 10;
        a = a / 10;
    }   
    return rev;
}

float average(int n){   
    int i = 0;
    int* numbers =  calloc(n,sizeof(int));
    int sum = 0;

    while(i < n)
    {
     printf("number[%d]: ",i+1);
     scanf("%d",&numbers[n]);
     sum += numbers[n];
     i++;
    }
     return sum / n;
}

void triangle(int n){    
 for(int i = 1; i <= n; i++) 
     printf("%d ",i*(i+1)/2);  
}

void inWord(){  
 int n = 0;
 scanf("%d",&n);                                
 int digits = (int)log10(n);                    // find the number of digits
 n  = reverse(n);                               // reverse the digits
 digits = digits - ((int)log10(n));             // this eliminates trailing zeros

 while(n){
    switch(n % 10)
    {      
    case 0:
        printf("ZERO ");
        break;
        
    case 1:
        printf("ONE ");
        break;
    
    case 2:
        printf("TWO ");
        break;
        
    case 3:
        printf("THREE ");
        break;
        
    case 4:
        printf("FOUR ");
        break;
        
    case 5:
        printf("FIVE ");
        break;
        
    case 6:
        printf("SIX ");
        break;
        
    case 7:
        printf("SEVEN ");
        break;
        
    case 8:
        printf("EIGHT ");
        break;
    
    case 9:
        printf("NINE ");
        break;
 
    default:
        printf("ERROR! INVALID INPUT");
        break; 
    }
    n /= 10;                       
  }                                                // once done printing all digits
  
  while(digits){                                   // print all remaining zeros
      printf("ZERO ");
      digits--;
  }
}


void main(){
     int choice = 0, run = 1;
     int a = 0, b = 0;
     
    while(run)
    {
     printf("\n--MENU--\n");
     printf("1. SUM OF TWO NUMBERS\n");
     printf("2. REVERSE OF NUMBER\n");
     printf("3. AVERAGE OF NUMBERS\n");
     printf("4. TRIANGLE SERIES\n");
     printf("5. NUMBER IN WORDS\n");
     printf("6. EXIT\n");
     printf("ENTER CHOICE: ");
     scanf("%d",&choice);

     switch (choice)
     {
     case 1:
         printf("\nEnter two numbers: ");
         scanf("%d %d",&a,&b);
         printf("\n%d + %d = %d",a,b,sum(a,b));
         break;
     case 2:
         printf("\nEnter a number: ");
         scanf("%d",&a);
         printf("\nReverse of %d = %d",a,reverse(a));
         break;
     case 3:
         printf("\nEnter number of inputs: ");
         scanf("%d",&a);
         printf("\n Average = %0.3f",average(a));
         break;
     case 4:
         printf("\nEnter a number: ");
         scanf("%d",&a);
         printf("\nSeries = ");
         triangle(a);
         break;
     case 5:
         printf("Enter a number: ");
         inWord();
         break;
        
     case 6:
         printf("sure\n");
         run = 0;
         break;
     
     default:
         printf("ERROR! ENTER A VALID INPUT!");
         break;
     }
   }
}
