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

 
void inWord(int num){

 int div, n;
 int flag, digit, pos, len;

 if(num == 0) {
 printf("Zeron\n");
 }
 
 if(num > 99999) {
 printf("please enter a number between 0 and 100000\n\n");
 }
 
 len = 0;
 div = 1;
 n = num;
 
 while ( n > 9 ) {                     // find length of number
 n /= 10;
 div = div * 10;
 len++;
 }
 
 len++;
 pos = len;
 
 while ( num != 0 ) {
  digit = num / div;   // get individual digits
  num = num % div;
  div = div / 10;

 switch(pos) {
            case 2:                        // 2 digit number
            case 5:                        // 5 digit number
                if ( digit == 1 )
                flag = 1;
                else {
                    flag = 0;
                    switch(digit) {
                        case 2: printf("twenty ");break;
                        case 3: printf("thirty ");break;
                        case 4: printf("forty ");break;
                        case 5: printf("fifty ");break;
                        case 6: printf("sixty ");break;
                        case 7: printf("seventy ");break;
                        case 8: printf("eighty ");break;
                        case 9: printf("ninty ");
                        }
                    }
            break;
            case 1:                              // 1 or 4 digit number
            case 4:
                if (flag == 1) {
                    flag = 0;
                    switch(digit) {
                    case 0 : printf("ten ");break;
                    case 1 : printf("eleven ");break;
                    case 2 : printf("twelve ");break;
                    case 3 : printf("thirteen ");break;
                    case 4 : printf("fourteen ");break;
                    case 5 : printf("fifteen ");break;
                    case 6 : printf("sixteen ");break;
                    case 7 : printf("seventeen ");break;
                    case 8 : printf("eighteen ");break;
                    case 9 : printf("nineteen ");
                    }
                }   
            
                else {
                    switch(digit) {
                    case 1 : printf("one ");break;
                    case 2 : printf("two ");break;
                    case 3 : printf("three ");break;
                    case 4 : printf("four ");break;
                    case 5 : printf("five ");break;
                    case 6 : printf("six ");break;
                    case 7 : printf("seven ");break;
                    case 8 : printf("eight ");break;
                    case 9 : printf("nine ");
                }
            } 
            
            if (pos == 4) 
                printf("thousand ");
            break;
            
            case 3:                           // three digit number
                if (digit > 0) {
                    switch(digit) {
                    case 1 : printf("one ");break;
                    case 2 : printf("two ");break;
                    case 3 : printf("three ");break;
                    case 4 : printf("four ");break;
                    case 5 : printf("five ");break;
                    case 6 : printf("six ");break;
                    case 7 : printf("seven ");break;
                    case 8 : printf("eight ");break;
                    case 9 : printf("nine ");
                }
            printf("hundred ");
            }
            break;
        }
        pos--;
        }

    if (pos == 4 && flag == 0)   
        printf("thousand");

    else if (pos == 4 && flag == 1)
        printf("ten thousand");
            
    if (pos == 1 && flag == 1)
        printf("ten ");
 }  

void main(){
     int choice = 0, run = 1;
     int a = 0, b = 0;
     
    while(run)
    {
     printf("--MENU--\n");
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
         scanf("%d",&a);
         inWord(a);
         break;
        
     case 6:
         printf("sure\n");
         run = 0;
         break;
     
     default:
         printf("ERROR! ENTER A VALID INPUT!");
         break;
     }
    printf("\n\n");
   }
}
