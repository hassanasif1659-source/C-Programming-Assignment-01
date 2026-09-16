#include <stdio.h>

int main() {
    char vehicle_type;
    int battery_level;
    int req_charging_level;
    int p_duration;
    int peak, offpeak;
    float rate;
    int current_time;
    float final_cost;
    char membership;
    char disabled_priority;
    char available_station;
    
    // Additional variables
    int required_charging;
    float parking_cost;
    float charging_cost;
    float parking_discount = 0;
    float charging_discount = 0;
    int is_emergency = 0;
    
    
    printf("Enter your Vehicle Type (H for Hybrid and E for Electric): ");
    scanf(" %c", &vehicle_type);
    
    printf("Enter your Battery Level: ");
    scanf("%d", &battery_level);
    
    printf("Enter your Required Charging Level: ");
    scanf("%d", &req_charging_level);
    
    printf("Enter Parking Duration (hours): ");
    scanf("%d", &p_duration);
    
    printf("Enter Current time (24-hour format, e.g., 1400): ");
    scanf("%d", &current_time);
    
    printf("Do you have membership (Y/N): ");
    scanf(" %c", &membership);
    
    printf("Disabled Person Priority (Y/N): ");
    scanf(" %c", &disabled_priority);
    
    printf("Charging Station Available (Y/N): ");
    scanf(" %c", &available_station);
    
    
    if (available_station == 'N' || available_station == 'n') {
        if (vehicle_type == 'H' || vehicle_type == 'h') {
            printf("Charging unavailable - Parking only.\n");
        } else {
            printf("No charging slot available.\n");
        }
        return 0;
    }
    
    
    if (vehicle_type == 'E' || vehicle_type == 'e') {
        if (battery_level < 0 || battery_level > 100) {
            printf("Invalid battery level.\n");
            return 0;
        }
    }
    else if (vehicle_type == 'H' || vehicle_type == 'h') {
        if (battery_level >= 40 && battery_level <= 100) {
            printf("Vehicle does not qualify for EV charging.\n");
            return 0;
        }
    }
    else {
        printf("Invalid vehicle type.\n");
        return 0;
    }
    
    
    printf("Vehicle is eligible for charging.\n");
 
    required_charging = req_charging_level - battery_level;
    
    if (required_charging <= 0) {
        printf("No charging required.\n");
        return 0;
    }
    
    printf("Required charging: %d%%\n", required_charging);
    
   
    if (battery_level <= 15 && req_charging_level >= 80) {
        printf("Priority: Emergency Charging Priority\n");
        is_emergency = 1;
    }
    else if (disabled_priority == 'Y' || disabled_priority == 'y' || 
            ((membership == 'Y' || membership == 'y') && battery_level <= 30)) {
        printf("Priority: Priority Charging\n");
    }
    else {
        printf("Priority: Normal Charging\n");
    }
    
   
    if(current_time >= 1700 && current_time <= 2200){
        rate = 50.00;
        printf("Status: Peak hours\n");
    }
    else{
        rate = 35.00;
        printf("Status: Off-peak hours\n");
    }
 
    charging_cost = required_charging * rate;
    printf("Charging cost: Rs. %.2f\n", charging_cost);
    
    
    if (p_duration <= 2) {
        parking_cost = 200;
        printf("Parking charge: Rs. 200\n");
    }
    else if (p_duration > 2 && p_duration <= 5) {
        parking_cost = 400;
        printf("Parking charge: Rs. 400\n");
    }
    else {  
        parking_cost = 700;
        printf("Parking charge: Rs. 700\n");
    }
    
   
    if (membership == 'Y' || membership == 'y'){
        if (is_emergency == 0){  // Emergency ko charging discount nahi milta
            if(current_time >= 1700 && current_time <= 2200){
                charging_discount = charging_cost * 0.10;  // Peak 10%
                printf("Charging discount (Peak 10%%): Rs. %.2f\n", charging_discount);
            }
            else{
                charging_discount = charging_cost * 0.20;  // Off-peak 20%
                printf("Charging discount (Off-peak 20%%): Rs. %.2f\n", charging_discount);
            }
        }
        else{
            printf("No membership discount for Emergency Charging Priority.\n");
        }
    }
    

    if (disabled_priority == 'Y' || disabled_priority == 'y'){
        parking_discount = parking_cost;  // 100% off (free parking)
        printf("Disabled priority: Free parking (Rs. %.2f off)\n", parking_discount);
    }
    else if (membership == 'Y' || membership == 'y'){
        parking_discount = parking_cost * 0.20;  // 20% off
        printf("Membership parking discount (20%%): Rs. %.2f\n", parking_discount);
    }
    
    
    final_cost = (parking_cost - parking_discount) + (charging_cost - charging_discount);
    printf("\n FINAL BILL \n");
    printf("Vehicle Type: %c\n", vehicle_type);
    printf("Current Battery: %d%%\n", battery_level);
    printf("Required Charging: %d%%\n", required_charging);
    printf("Charging Cost: Rs. %.2f\n", charging_cost);
    printf("Parking Cost: Rs. %.2f\n", parking_cost);
    printf("Total Discount: Rs. %.2f\n", parking_discount + charging_discount);
    printf("Final Payable Amount: Rs. %.2f\n", final_cost);
    
   
    if(p_duration > 8){
        printf("Long-stay warning: Please relocate your vehicle after charging.\n");
    }
    else{
        printf("Standard parking duration.\n");
    }
    
    return 0;
}