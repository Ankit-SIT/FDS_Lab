/* 
   Ankit Das
   Structures without Pointers
*/

#include<stdio.h>
#include<string.h>

struct Student{
    char name[30];
    char class[10];
    int totalMarks;
    char grade;
};


char calculateGrade(int marks){
    if(marks > 90){
        return 'A';
    }

    else if(marks <= 90 && marks > 70){
        return 'B';
    }

    else if(marks <= 70 && marks > 50){
        return 'C';
    }
    
    else if(marks <= 50 && marks > 33){
        return 'D';
    }

    else{
        return 'F';
    }

return 'F';
}

struct Student add(char name[30],char class[10],int marks){
    struct Student s;
    strcpy(s.name,name);
    strcpy(s.class,class);
    s.totalMarks = marks;
    s.grade = calculateGrade(s.totalMarks);
    return s;
}


void delete(struct Student s[100], int i, int size){
    if(size == 0){
        printf("CANNOT DELETE!");
        printf("SizeError: EMPTY ARRAY!");
    }

    else{
        printf("Deleting [%d] with name %s",i,s[i].name);       
        while(i < size){
            s[i] = s[i + 1];
            i++;
        }
    }

}

void show(struct Student s[100],int size){
    int i = 0;

    while(i < size){
        printf("\n\n-----");
        printf("\nNAME- %s",s[i].name);
        printf("CLASS- %s",s[i].class);
        printf("MARKS- %d",s[i].totalMarks);
        printf("\nGRADE- %c",s[i].grade);
        i++;
    }
}



int main(){
   struct Student s[100];
   char name[30];
   char class[10];
   int marks = 0;
   int size = 0;
   int i = 0;
   int choice = 0;
   char temp;

 while(1){
   printf("\n\nMENU\n");
   printf("\n1.ADD STUDENT RECORD");
   printf("\n2.DELETE STUDENT RECORD");
   printf("\n3.SHOW RECORDS");
   printf("\n4.EXIT\n");
   printf("\nENTER YOUR CHOICE: ");
   scanf("%d",&choice);
   
   switch(choice){
       case 1:
            if(size == 99){
                printf("CANNOT ADD ANY MORE ELEMENTS!\n");
                printf("SizeError: ARRAY FULL!");
            }
            
            else{
                scanf("%c",&temp);
                fflush(stdin);
                printf("ENTER NAME: ");
                fgets(name,30,stdin);
                
                fflush(stdin);
                printf("ENTER CLASS: ");
                fgets(class,30,stdin);

                printf("ENTER MARKS: ");
                scanf("%d",&marks);  
                s[size] = add(name,class,marks);
                size++;
            }
            break;
        
       case 2:
            printf("ENTER DELETION INDEX[STARTS WITH 0]:");
            scanf("%d",&i);
            delete(s,i,size);
            size--;
            break;
       
       case 3:
            show(s,size);
            break;
      
       case 4:
            return 0;
        
       default:
            printf("INVALID CHOICE! TRY AGAIN");
            break;
    }
   }

 // code never reaches here
 return 0; 
}
