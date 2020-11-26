/* Ankit Das
   Decimal to Binary using Stack
   26th Oct 2020
*/

#include "intstack.h"
#include<stdlib.h>

#define SIZE 32

int main(){
    int top = 0;
    int decimal = 0;
    int remainder = 0;

    int *stack = (int*) malloc(SIZE * sizeof(int));
    printf("ENTER DECIMAL: ");
    scanf("%d",&decimal);

    while(decimal)
        {
                remainder = decimal % 2;
                push(stack,remainder,&top);
                decimal/=2;
        }
    
    printf("RESULT: "); 
    while(top)
     printf("%d", pop(stack,&top));
    
    printf("\n");
    
    return 0;
}
