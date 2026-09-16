#include <stdio.h>

int main () {
    int q ;
    float p;
    float subtotal ;
    int discount_percentage;
    int tax_percentage ; 
    double final_bill ;
    double discounted_amount;
    printf ("Enter Quantity of Item :" );
    scanf("%d" , &q);
    printf ("Enter Price of Item :");
    scanf("%f" , &p);
    printf ("Enter discounted Percentage :");
    scanf("%d" , &discount_percentage);
    printf ("Enter tax Percentage :");
    scanf("%d" , &tax_percentage);
    if(p > 0 && q > 0 && discount_percentage >= 0 && discount_percentage <=100  && tax_percentage > 0 && tax_percentage<=100){
    
    subtotal = q * p ; 
    discounted_amount = subtotal - (subtotal * discount_percentage) / (100.0);
    final_bill = discounted_amount + (discounted_amount*tax_percentage)/(100.0);
        printf("Your Quantity of the item is %d\n" , q);
        printf("Your price of the item is %.1f\n" , p);
        printf("Your tax percentage is %d%%\n" , tax_percentage);
        printf("Your discounted percentage is %d%%\n" , discount_percentage);
        printf("Your subtotal is %.1f\n" , subtotal);
        printf("Your discounted amount is %.2lf\n", discounted_amount);
        printf("Your final bill is %.1lf\n" , final_bill);
    }
    else {
        printf("Invalid Amount");
        return 0 ; 
     }  

    }
