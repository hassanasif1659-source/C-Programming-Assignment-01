// Q5 so lengthy
#include <stdio.h>
int main(){
    char Vehicle_type;
    int c = 0;    //car parked
    int b = 0;    // bike parked
    int v = 0 ;   // van parked
    int r = 0;    // rejected vehicles
    char assigned_zone ;
    char user_category;
    char emergency_vehicle ;
    int expected_vehicles ;
    char parking_permit;
    int space_required ; 
    int Zone_A_spaces = 20 ;
    int Zone_B_spaces = 40 ;
    int Zone_C_spaces = 15 ;
    int A_occupied = 0 ;
    int B_occupied = 0 ;
    int C_occupied = 0 ;
    int i ;


    printf("Enter Expectd Vehicles \n");
    scanf("%d" , &expected_vehicles);


    for ( i  = 1 ; i <= expected_vehicles ; i++){
     printf("Enter Vehicle Type(C/B/V)\n");
    scanf( " %c" , &Vehicle_type);
    printf("Enter user category(F/S/G)\n");
    scanf(" %c" , &user_category);
    printf("Enter permit(Y/N)\n");
    scanf(" %c" , &parking_permit);
    printf("Enter Emergency Vehicle(Y/N)\n");
    scanf(" %c" , &emergency_vehicle);



    if(user_category == 'S' || user_category == 'G' || user_category == 'F'){
        printf("This category available\n");
        if(Vehicle_type == 'B' || Vehicle_type == 'C' || Vehicle_type == 'V'){
            printf("Yes this vehicle is available\n");
            if(parking_permit == 'Y' || emergency_vehicle == 'Y'){
                printf("All Information Valid\n");
                 if(Vehicle_type =='C'){
                    space_required = 1;
                    printf("Space required : %d\n" ,space_required);
                }
                else if(Vehicle_type == 'B'){
                    space_required = 1 ;
                    printf("Space required : %d\n" ,space_required);
                }
                else if (Vehicle_type == 'V' ){
                    space_required = 2 ;
                    printf("Space required : %d\n" ,space_required);
                }



                if(user_category == 'F'){
                    assigned_zone = 'A';
                    if(A_occupied + space_required <= Zone_A_spaces ){
                        A_occupied = A_occupied + space_required ;
                        if(Vehicle_type == 'C') 
                        c = c + 1;
                        else if(Vehicle_type == 'B') 
                        b = b + 1;
                        else if(Vehicle_type == 'V') 
                        v = v + 1;
                        printf("Allowed\n");
                        printf("Assigned Zone %c\n" ,assigned_zone);
                        printf("Occupied space %d\n" ,A_occupied);
                        printf("Remaining Space is %d\n" , Zone_A_spaces - A_occupied );
                    }
                    else{
                        printf("No available space in Zone %c\n", assigned_zone);
                        r = r + 1;
                    }
                }
                else if(user_category == 'S'){
                    assigned_zone = 'B';
                    if(B_occupied + space_required <= Zone_B_spaces ){
                         B_occupied = B_occupied + space_required ;
                        if(Vehicle_type == 'C')
                         c = c + 1;
                        else if(Vehicle_type == 'B') 
                        b = b + 1;
                        else if(Vehicle_type == 'V') 
                        v = v + 1;
                    printf("Allowed\n");
                    printf("Assigned Zone %c\n", assigned_zone);
                    printf("Occupied space %d\n", B_occupied);
                    printf("Remaining Space is %d\n", Zone_B_spaces - B_occupied);
                    }
                    else{
                        if(Vehicle_type == 'V' && C_occupied + 2 <= Zone_C_spaces){
                    assigned_zone = 'C';
                    C_occupied = C_occupied + 2;
                    v = v + 1;
                    printf("Allowed in Zone C \n");
                    printf("Assigned Zone %c\n", assigned_zone);
                    printf("Occupied space %d\n", C_occupied);
                    printf("Remaining Space is %d\n", Zone_C_spaces - C_occupied);
                    }
                    else{
                        printf("No available space in Zone %c\n", assigned_zone);
                        r = r + 1;
                    }
                }
                }
                    else if(user_category == 'G'){
                    assigned_zone = 'C';
                    if(C_occupied + space_required <= Zone_C_spaces ){
                         C_occupied = C_occupied + space_required ;
                        if(Vehicle_type == 'C') 
                        c = c + 1;
                        else if(Vehicle_type == 'B') 
                        b = b + 1;
                        else if(Vehicle_type == 'V') 
                        v = v + 1;
                        printf("Allowed\n");
                        printf("Assigned Zone %c\n", assigned_zone);
                    printf("Occupied space %d\n", C_occupied);
                    printf("Remaining Space is %d\n", Zone_C_spaces - C_occupied);
                    }
                    else{
                       printf("No available space in Zone %c\n", assigned_zone);
                       r = r + 1;
                    }
                }
            }
            else{
                printf("Not allowed\n");
                r = r + 1;
            }
        }
        else{
            printf("No this vehicle not allowed\n");
            r = r + 1;
        }
    }
    else{
        printf("not available this category\n");
        r = r + 1;
    }
    }

    printf("Parked Cars: %d\n", c);
    printf("Parked Bikes: %d\n", b);
    printf("Parked Vans: %d\n", v);
    printf("Rejected Vehicles: %d\n", r);

    return 0;
}