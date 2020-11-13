/*
Ankit Das
13th November
File Operations in C
*/

#include<stdio.h>
#define FILE_NAME "d:\\Classwork\\Assignments\\FDSTH\\file.txt"

struct student{
    char firstName[20];
    char lastName[20];
    float marks[5];
};

struct student createStudent(){
    struct student temp;
    
    printf("ENTER FIRST NAME: ");
    scanf("%s",&temp.firstName);
    printf("ENTER LAST NAME: ");
    scanf("%s",&temp.lastName);
   
    printf("ENTER MARKS 1: ");
    scanf("%f",&temp.marks[0]);
    printf("ENTER MARKS 2: ");
    scanf("%f",&temp.marks[1]);
    printf("ENTER MARKS 3: ");
    scanf("%f",&temp.marks[2]);
    printf("ENTER MARKS 4: ");
    scanf("%f",&temp.marks[3]);
    printf("ENTER MARKS 5: ");
    scanf("%f",&temp.marks[4]);

    return temp;
}

void displayStudent(struct student current){
    printf("\n------------------");
    printf("\nFIRST NAME: %s",current.firstName);
    printf("\nLAST NAME: %s",current.lastName);
    printf("\nMARKS 1: %0.2f",current.marks[0]);
    printf("\nMARKS 2: %0.2f",current.marks[1]);
    printf("\nMARKS 3: %0.2f",current.marks[2]);
    printf("\nMARKS 4: %0.2f",current.marks[3]);
    printf("\nMARKS 5: %0.2f",current.marks[4]);
    printf("\n------------------\n");
}

void send2file(struct student current){
    FILE* file;
    if(file = fopen(FILE_NAME,"a")){
        fprintf(file,"\n------------------\n");
        fprintf(file,"FIRST NAME: %s\n",current.firstName);
        fprintf(file,"LAST NAME: %s\n",current.lastName);
        fprintf(file,"MARKS 1: %0.2f\n",current.marks[0]);
        fprintf(file,"MARKS 2: %0.2f\n",current.marks[1]);
        fprintf(file,"MARKS 3: %0.2f\n",current.marks[2]);
        fprintf(file,"MARKS 4: %0.2f\n",current.marks[3]);
        fprintf(file,"MARKS 5: %0.2f\n",current.marks[4]);
        fprintf(file,"------------------");
        fclose(file);
    }

    else{
        printf("ERROR! CANNOT OPEN FILE!");
    }
}

void showContent(){
    FILE *file;
    char buffer[1024];
    if(file = fopen(FILE_NAME,"r")){
        while(fgets(buffer,1024,file) != NULL){
            printf("%s",buffer);
        }
    if(feof(file)){
     printf("\n- END OF FILE -\n");
    }
    fclose(file);
   }
}

void clear(){
    FILE* file;
    if(file = fopen(FILE_NAME,"w")){
    fprintf(file,"");
    }

    printf("FILE %s CLEARED!\n",FILE_NAME);
    fclose(file);
}

int main(){
    int choice = 0;
    struct student temp;

    while(1){
        printf("\n-- MENU --");
        printf("\n1. ADD STUDENT");
        printf("\n2. SHOW FILE CONTENTS");
        printf("\n3. CLEAR FILE");
        printf("\n4. EXIT");
        printf("\n\nENTER CHOICE: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            temp = createStudent();
            printf("\n\n- ADDING ENTRY -");
            displayStudent(temp);
            send2file(temp);
            break;
        
        case 2:
            showContent();
            break;
        
        case 3:
            clear();
            break;
        
        case 4:
            return 0;

        default:
            printf("INVALID CHOICE! TRY AGAIN!");
            break;
        }
    }
}
