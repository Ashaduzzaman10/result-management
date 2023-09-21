#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int roll;
    float result;
} Student;

int main() {
    int numberOfStudent;

    // here input the  number of students
    printf("how much student in the class : ");
    scanf("%d", &numberOfStudent);

    // memory allocation for student using struc using an array
    Student *students = (Student *)malloc(numberOfStudent * sizeof(Student));

    if (students == NULL) {
        printf("Memory allocation failed.\n"); // handle the error
        return 1;
    }

    // here we provide student information
    for (int i = 0; i < numberOfStudent; i++) {
        printf("provide some information for student %d:\n", i + 1);

        // Input name and checking input validation 
        akash:
        printf("Name: ");
        scanf("%s", students[i].name);
        if((students[0].name[0]>='a' && students[0].name[0]<='z') || (students[0].name[0]>='A' && students[0].name[0]<='Z')) ;
        else
        {
            goto akash;
        }

        // Input roll
        akash1:
        printf("Roll: ");
        char check[3];
        scanf("%s", &check);
        int size = strlen(check);
        int done = 1;
        for(int j=0; j<size; j++)
        {
            if(check[j]>='0' && check[j]<='9') ;
            else
            {
                done = 0;
                break;
            }
        }
        if(done)
        {
            int roll = 0;
            for(int j=0; j<size; j++)
            {
                int a = check[j]-'0';
                if(j==0) roll = a;
                else
                {
                    roll *= 10;
                    roll += a;
                }
            }
            students[i].roll = roll;
        }
        else
        {
            goto akash1;
        }


  //take student result 
    while(1)
            {
                printf("Enter student  Result: ");
                char check[4];
                scanf("%s", &check);
                int size = strlen(check);
                int done = 1;
                int count = 0;
                for(int j=0; j<size; j++)
                {
                    if(check[j]>='0' && check[j]<='9') ;
                    else if(check[j]=='.') count++;
                    else
                    {
                        done = 0;
                        break;
                    }
                }
                if(done==1 && count==1)
                {
                    int result = 0;
                    for(int j=0; j<size; j++)
                    {
                        int a = check[j]-'0';
                        if(check[j]=='.') continue;
                        if(j==0) result = a;
                        else
                        {
                            result *= 10;
                            result += a;
                        }
                    }
                    double res = result/100.0;
                    students[i].result = res;
                    break;
                }
                else printf("Result is not valid\n");
            }
        }
    // creating file for those student based on th condition
    FILE *bonusFile = fopen("bonus_students.txt", "w"); // toper are store in bonus file
    FILE *normalFile = fopen("normal_students.txt", "w"); // normal  are store in normal file

    if (bonusFile == NULL || normalFile == NULL) {
        printf("Error creating files.\n"); // handling error for creating file
        return 1;
    }


    // based on the result here i categorize the student
    for (int i = 0; i < numberOfStudent; i++) {
        if (students[i].result >= 3.80) {
            fprintf(bonusFile, "Name: %s, Roll: %d, Result: %.2f\n", students[i].name, students[i].roll, students[i].result);
        } else {
            fprintf(normalFile, "Name: %s, Roll: %d, Result: %.2f\n", students[i].name, students[i].roll, students[i].result);
        }
    }

    // Close files
    fclose(bonusFile);
    fclose(normalFile);

    // Free allocated memory
    free(students);

    printf("Student information categorized successfully based on their result .\n");
    

    return 0;
}
// and finally closed the program