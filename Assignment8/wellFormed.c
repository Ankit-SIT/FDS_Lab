#include "charstack.h"
#include<stdlib.h>

#define SIZE 100

enum bool{ false, true };
char *stack;
int top;

enum bool match(char x, char y){
    if(x == '{' && y == '}'){
        return true;
    }

    if(x == '(' && y == ')'){
        return true;
    }
    
    if(x == '[' && y == ']'){
        return true;
    }

return false;    
}

enum bool isWellFormed(char* expression){
    int i = 0;

    while(expression[i]){
        if(expression[i] == '{' || expression[i] == '[' || expression[i] == '('){
             push(stack,expression[i],&top);
        }

        if(expression[i] == '}' || expression[i] == ')' || expression[i] == ']'){
            if(top == 0){
                return false;
            }

            if(!match(pop(stack,&top),expression[i])){
                return false;
            }
        }
        i++;
    }

    if(top == 0){
        return true;
    }

    else{
        return false;
    }
}

int main(){
    stack = (char*)malloc(SIZE * sizeof(char));
    char *expression = (char*)malloc(SIZE * sizeof(char));

    printf("ENTER EXPRESSION: ");
    fgets(expression,SIZE,stdin);

    if(isWellFormed(expression)){
        printf("EXPRESSION %sIS WELL FORMED! \n",expression);
    }
    
    else{
        printf("EXPRESSION %sIS NOT WELL FORMED! \n",expression);
    }
    return 0;
}
