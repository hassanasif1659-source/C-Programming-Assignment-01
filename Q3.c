// A school processes the result for one student. The student has 5 subject marks, which must be summed and averaged. After computing the average, classify the student:

// Average of 80 or above is "Distinction",

// Average of 60 or above (but below 80) is "Pass",

// Average below 60 is "Fail".

// In addition, if the student has failed any single subject (a mark below 33), override the result to "Fail — Subject Deficiency", even if the average alone would otherwise pass.

// The program takes input for 1 student only, with 5 subject marks (each out of 100).

// Average = sum of the 5 marks divided by 5.

// Average of 80 or above → "Distinction".

// Average of 60 or above and below 80 → "Pass".

// Average below 60 → "Fail".

// Override rule: if any single subject mark is below 33, the result becomes "Fail — Subject Deficiency", even if the average is 60 or above.
#include <stdio.h>
int main(){
    int m1,m2,m3,m4,m5;
    int Obt_Marks ;
    float average ;
    printf("Enter Your English marks :\n");
    scanf("%d",&m1);
    printf("Enter Your maths marks :\n");
    scanf("%d",&m2);
    printf("Enter Your Physics marks :\n");
    scanf("%d",&m3);
    printf("Enter Your PST marks :\n");
    scanf("%d",&m4);
    printf("Enter Your Comp marks :\n");
    scanf("%d",&m5);
    Obt_Marks = (m1+m2+m3+m4+m5);
    printf("Obtained marks %d\n",Obt_Marks);
    average = (Obt_Marks/5);
    printf("Your average is %.2f\n",average);
       if(m1 < 33 || m2 < 33 || m3 < 33 || m4 < 33 || m5 < 33){
        printf("fail - Subject Deficiency");
        }  
        else if(average>=80 && average <= 100){
            printf("You gained a distinction");
        }
        else if(average >=60 && average < 80){
            printf("Pass");
        }
        
        else{
            printf("Fail");
        }
    }
