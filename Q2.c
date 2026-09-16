// Question 02 Elevator Simulation
// An elevator starts at the ground floor and receives a list of floor requests, processed one at a time
// in a loop. For each request, compare it to the elevator's current floor: if the requested floor is higher,
// print "Moving Up"; if lower, print "Moving Down"; if the same, print "Doors Opening." Update
// the current floor after each stop.
// • The elevator starts at Floor 0.
// • The loop processes a list of N floor requests (for example, N = 5 requests: 3, 1, 5, 2, 2).
// • Requested floor greater than current floor → "Moving Up".
// • Requested floor less than current floor → "Moving Down".
// • Requested floor equal to current floor → "Doors Opening".
// • Update the current floor to the requested floor after each stop.
#include <stdio.h>
int main(){
    int floor ;
    int currentfloor = 0 ;
    printf("Enter on which floor you want to go \n:") ; 
    scanf("%d" , &floor);
    if (floor < currentfloor ){
        printf("Moving Down\n");
    }
    else if (floor > currentfloor ){
        printf("Moving Up\n");
    }
    else {
        printf("Doors Opening\n");
    }
    currentfloor = floor ; 
    printf("Now Your Floor is %d\n" ,currentfloor);
}