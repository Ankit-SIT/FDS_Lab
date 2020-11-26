/* Ankit Das
   Infix to Postfix
   27th Oct 2020
*/

#include "charstack.h"
#define SIZE 100

int isOperand(char character) 
{ 
    return (character >= 'a' && character <= 'z') ||  
           (character >= 'A' && character <= 'Z'); 
} 

int precedence(char operator){
    if(operator == '^'){
        return 3;
    }

    else if(operator == '*' || operator == '/'){
        return 2;
    }

    else if(operator == '+' || operator == '-'){
        return 1;
    }
    return -1;
}

int isOperator(char character){
    if(character == '+' || character == '-' || character == '/' || character == '*' || character == '^')
        return 1;
    
    return -1;
} 


int infixToPostfix(char* expression) { 
    int i = 0, k = -1; 
    struct Stack* stack = newStack(strlen(expression));

    if(!stack){
        return -10;
    } 

    while(expression[i]) {  

        if (isOperand(expression[i])) {
            expression[++k] = expression[i]; 
        }

        else if (expression[i] == '(') {
            push(stack, expression[i]);
        }

        else if (expression[i] == ')') { 

            while (!isEmpty(stack) && peek(stack) != '(') { 
                expression[++k] = pop(stack);
            }

            if (!isEmpty(stack) && peek(stack) != '(') {
                return -100; // invalid expression
            }

            else {
                pop(stack);
            } 
        } 

        else if(isOperator(expression[i])) { // an operator is encountered 
            while (!isEmpty(stack) && precedence(expression[i]) <= precedence(peek(stack))) {
                expression[++k] = pop(stack);
            }

            push(stack, expression[i]); 
        }

        else{
            return -1;
        }
    i++;
    } 


    while (!isEmpty(stack)){ 
        expression[++k] = pop(stack ); 
    }
    
    expression[++k] = '\0'; 
} 
  
int main() 
{   
    char *expression = (char*)malloc(SIZE * sizeof(char));

    printf("ENTER INFIX EXPRESSION: ");
    fgets(expression,SIZE,stdin);
 
    if(infixToPostfix(expression) != -1){
       printf("POSTFIX: %s",expression);
    }

    else{
        printf("ERROR! INVALID EXPRESSION");
    }
    return 0; 
} 
