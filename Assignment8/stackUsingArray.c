/* Ankit Das
    Stack using Array
    26th Oct 2020
*/


#include<stdio.h>
#include<stdlib.h>

void show(int top){
    printf("\nTOP: %d\n",top);
}

void push(int *array, int *top, int element){
*(array + *top) = element;

printf("ELEMENT %d PUSHED TO STACK!",*(array + *top));
show(*top);
*top += 1;
}

int pop(int *array,int *top){
    int save = 0;

    *top -= 1;
    show(*top);
    save = *(array + *top);
    *(array + *top) = 0;

    return save;
}

void display(int *array,int n){
    int i = 0;
    while(i < n){
        printf("%d ",*(array + i));
        i++;
    }
}

int main(){
    static int n = 0;

    printf("ENTER SIZE: ");
    scanf("%d",&n);

    int *array = (int*)malloc(n * sizeof(int));
    int choice = 0;
    int top = 0;
    int element = 0;

    while(1){
        printf("\n\n-- MENU --");
        printf("\n1.PUSH");
        printf("\n2.POP");
        printf("\n3.DISPLAY");
        printf("\n4.EXIT");
        printf("\nENTER CHOICE: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                if(top == n){
                    printf("SizeError! Stack Overflow!");
                    break;
                }

                else{
                    printf("ENTER ELEMENT: ");
                    scanf("%d",&element);
                    push(array,&top,element);
                }

                break;
            
            case 2:
                if(top < 0){
                    printf("SizeError! Stack Underflow!");
                    break;
                }

                printf("ELEMENT %d POPPED!",pop(array,&top));
                break;
            
            case 3:
                show(top);
                display(array,n);
                break;

            case 4:
                return 0;
            }
    }

    return 0;
}
