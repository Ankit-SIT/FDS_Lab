/*
Ankit Das
20th August 2020
Matrix Operations
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int** read_matrix(int m, int n){                    // creates and assign values to m x n order matrix
    int i = 0, j = 0;
    int **mat = (int**)malloc(m*sizeof(int*));
    for(i = 0 ; i < m ; i++){
        mat[i] = (int*)malloc(sizeof(int)*n);
    }

    printf("ENTER %d VALUES:\n",m*n);
    for(i = 0 ; i < m ; i++){
        for(j = 0; j < n; j++){
            scanf("%d",&mat[i][j]);
        }
    }
    return mat;
}

void print_matrix(int m, int n, int **matrix){      // prints matrix in normal form
    int i = 0, j = 0;
    for(i = 0 ; i < m ; i++){
        for(j = 0; j < n; j++){
            //printf("%d",matrix[i*m + j]);
            printf("[ %d ]",matrix[i][j]);
        }
        printf("\n");
    }
}

int** add(int m, int n, int** matrix){
    int i = 0, j = 0;
    int** temp = read_matrix(m,n);
    for(i = 0 ; i < m ; i++){
        for(j = 0; j < n; j++){
        temp[i][j] = temp[i][j] + matrix[i][j];
        }
    }
return temp;
}

int** subtract(int m, int n, int** matrix){
    int i = 0, j = 0;
    int** temp = read_matrix(m,n);
    for(i = 0 ; i < m ; i++){
        for(j = 0; j < n; j++){
        temp[i][j] = abs(temp[i][j] - matrix[i][j]);
        }
    }
return temp;
}

int** multiply(int m, int *n, int** matrix){
    int r = 0, c = 0, i = 0, j = 0, k = 0;
    printf("ENTER SIZE OF MATRIX:");
    scanf("%d %d",&r,&c);
    
    if(*n == r){
    int **second;
    second = read_matrix(r,c);

    int **result = (int**)malloc(m*sizeof(int*));
        for(i = 0 ; i < m ; i++){
            result[i] = (int*)malloc(sizeof(int)*c);
        };

    int sum = 0;

    for(i = 0; i < m; i++){
        for(j = 0; j < c; j++){
            result[i][j] = 0;
            for(k = 0; k < *n; k++){
                sum = sum + matrix[i][k] * second[k][j];
            }
            result[i][j] = sum;
            sum = 0;
        }
        sum = 0;
    }
    
    *n = c;
    return result;
    }

    else{
        printf("SizeError! Cannot Multiply!");
        return matrix;
    }
}

void greatest_of_row(int m, int n, int** matrix){
    int i = 0, j = 0, max = 0;
    for(i = 0;i < m; i++){
        max = 0;
        for(j = 0; j < n; j++){
           if(max < matrix[i][j]){
               max = matrix[i][j];
           }
        }
        printf("MAX OF ROW %d : %d\n",i,max);
    }
}

void major_trace(int m, int n, int** matrix){
    if(m == n){
    int i = 0, j = 0, sum = 0;
        for(i = 0;i < m; i++){
            sum += matrix[i][i];
        }
    printf("TRACE : %d\n",sum);
    }
    else{
        printf("SizeError! Matrix is not Square!");
    }
}

int** to_sparse(int *m, int *n, int **matrix){                // converts normal form to sparse form and returns a new matrix
    int i = 0, j = 0 , k = 0, size = 0;
    for(i = 0; i < *m; i++){
        for(j = 0; j < *n; j++){
            if(matrix[i][j] != 0){
                size++;
            }
        }
    }
    
    int **sparseMatrix = (int**)malloc(3 * sizeof(int*));
    for(i = 0; i < 3; i++){
        sparseMatrix[i] = (int*)malloc(sizeof(int)*size);
    }
    
    for(i = 0; i < *m; i++){
        for(j = 0; j < *n; j++){
            if(matrix[i][j] != 0){
                sparseMatrix[0][k] = i;
                sparseMatrix[1][k] = j;
                sparseMatrix[2][k] = matrix[i][j];
                k++;
            }
        }
    }
*m = 3;
*n = size;
return sparseMatrix;
}

int** add_sparse(int *m, int *n, int** matrix){                               // wrapper function to add sparse matrices
    int **temp = add(*m,*n,matrix);
    temp = to_sparse(m,n,temp);
    return temp;
}

void print_sparse(int size, int **sparseMatrix){                              // prints sparse matrix
    int i = 0, j = 0;
    for(i = 0; i < 3; i++){
        switch(i){
            case 0:
            printf("ROW- ");
            break;
            
            case 1:
            printf("COL- ");
            break;
            
            case 2:
            printf("VAL- ");
            break;
        }
        for( j = 0; j < size ; j++){
            printf("%d ", sparseMatrix[i][j]);
        }
        printf("\n");
    }
}

int** transpose(int size, int** matrix){
    int i = 0;
    int **temp = (int**)malloc(3 * sizeof(int*));
    for(i = 0; i < 3; i++){
        temp[i] = (int*)malloc(sizeof(int)*size);
    }
    
    for(i = 0; i< size; i++){
        temp[0][i] = matrix[1][i];
        temp[1][i] = matrix[0][i];
        temp[2][i] = matrix[2][i];
    }
    return temp;
}
 

void main(){                                                            // Driver Menu
int **matrix;
int **sparse;

int m = 0,n = 0,choice = 0;
int tr = 0, tc = 0;
bool run = true;

printf("ENTER SIZE OF MATRIX: ");
scanf("%d %d",&m,&n);
matrix = read_matrix(m,n);

while(run){
printf("\n\nMENU\n");
printf("1. ADD A MATRIX\n");
printf("2. SUBTRACT A MATRIX\n");
printf("3. MULTIPLY A MATRIX\n");
printf("4. FIND GREATEST OF ROW\n");
printf("5. FIND TRACE\n");
printf("6. CREATE SPARSE REPRESENTATION\n");
printf("7. ADD SPARSE\n");
printf("8. TRANSPOSE\n");
printf("9. DISPLAY REGULAR\n");
printf("10. DISPLAY SPARSE\n");
printf("11. EXIT\n");
printf("ENTER YOUR CHOICE:");
scanf("%d",&choice);

switch(choice){
    case 1:
    matrix = add(m,n,matrix);
    break;

    case 2:
    matrix = subtract(m,n,matrix);
    break;

    case 3:
    matrix = multiply(m,&n,matrix);
    break;

    case 4:
    greatest_of_row(m,n,matrix);
    break;

    case 5:
    major_trace(m,n,matrix);
    break;

    case 6:
    tr = m;
    tc = n;
    sparse = to_sparse(&tr,&tc,matrix);\
    printf("Sparse Matrix generated successfully!\n\n");
    break;

    case 7:
    tr = m;
    tc = n;
    sparse = add_sparse(&tr,&tc,matrix);
    printf("Sparse Matrix Updated!\n\n");
    break;

    case 8:
    sparse = transpose(tc,sparse);
    printf("Sparse Matrix has been transposed!\n\n");
    break;

    case 9:
    print_matrix(m,n,matrix);
    break;

    case 10:
    print_sparse(tc,sparse);
    break; 

    case 11:
    run = false;
    break;
    }   
}
}
    
