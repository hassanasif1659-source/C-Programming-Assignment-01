// Question 1 Hotel Booking System

// A hotel processes booking requests for N guests. For each guest, take the season (Peak or Off-
// Peak) and room type (Standard, Deluxe, or Suite) as input, and apply nested pricing logic: Peak

// season charges a higher base rate per room type, and Off-Peak charges a lower rate. In addition, if
// a guest stays more than 7 nights, a long-stay discount applies regardless of season. Display the
// final price for each guest and the hotel's total revenue after all guests have been processed.
// • The loop runs for N guests (for example, N = 4).
// • Peak season rates: Standard = Rs. 5,000/night, Deluxe = Rs. 8,000/night, Suite = Rs.
// 12,000/night.
// • Off-Peak rates: Standard = Rs. 3,000/night, Deluxe = Rs. 5,000/night, Suite = Rs. 8,000/night.
// • If nights stayed exceed 7, apply a flat 15 percent long-stay discount to the total, regardless of
// season.
// • Total price = (rate × nights) − discount, where applicable.
// • Accumulate every guest's total into a running Hotel Total Revenue figure, displayed after the
// loop ends.

#include <stdio.h>
#include <string.h>

int main(){
    int N = 1 ;
    int Total_Rev;
    int Total ;
    int rate ;
    char season[10];
    char roomtype[12];
    int day;

    printf("Select the season (Peak or Off-Peak)");
    scanf("%s", season);

    printf("Select the roomtype(Standard,Deluxe or Suite)");
    scanf("%s", roomtype);

    printf("Enter Days For Night Stay");
    scanf("%d", &day);

    if (strcmp(season, "Peak") == 0) {
        if (strcmp(roomtype, "Standard") == 0) {
            rate = 5000;
        }
        else if (strcmp(roomtype, "Deluxe") == 0) {
            rate = 8000 ;
        }
        else if (strcmp(roomtype, "Suite") == 0) {
            rate = 12000 ; 
        }
    }
    else {
        if (strcmp(roomtype, "Standard") == 0) {
            rate = 3000;
        }
        else if (strcmp(roomtype, "Deluxe") == 0) {
            rate = 5000 ;
        }
        else if (strcmp(roomtype, "Suite") == 0) {
            rate = 8000 ; 
        }     
    }

    if (day > 7) {
        Total = (rate * day) * 85 / 100 ;
    }
    else {
        Total = rate * day ;
    }

    Total_Rev = Total;

    printf("Your roomtype is %s\n", roomtype);
    printf("Your season is %s\n", season);
    printf("Your Total Price of the guest is %d\n", Total);
    printf("The total revenue of the guest is %d\n", Total_Rev);

    return 0;
}