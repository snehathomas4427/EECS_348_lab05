#include <stdio.h>
#include <string.h>

void monthly(float list[]){
    float min = list[0];
    float max = list[0];
    float avg = 0;
    float sum = 0;
    const char *min_month = "January"; //creating a pointer min_month and setting it equal to the string literal January
    const char *max_month = "January"; //creating a pointer min_month and setting it equal to the string literal January

    printf("\nMonthly Sales Report for 2024\n");
    printf("\nMonth      Sales\n");
    const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    // Iterate through the sales data for each month
    for(int i = 0; i < 12; i++){
        printf("%-10s %.2f\n", months[i], list[i]);
        sum += list[i];
        // Update min sales and the corresponding month
        if (list[i] < min) {
            min = list[i];
            min_month = months[i]; //changing what the pointer min_month points to
        }
        // Update max sales and the corresponding month
        if (list[i] > max) {
            max = list[i];
            max_month = months[i]; //changing what the pointer max_month points to
        }
    }
    //print sales summary report
    printf("\nSales Summary Report: \n");
    printf("\nMinimum Sales: %.2f (%s)\n", min, min_month); 
    printf("Maximum Sales: %.2f (%s)\n", max, max_month);
    printf("Average Sales: %.2f\n", sum/12);
}

void six_month_average(float list[]){
    const char *months[] = {"January-June", "February-July", "March-August", "April-September", "May-October", "June-November", "July-December"};
    printf("\nSix-Month moving average report: \n");
    int count = 0; //keeps track of all 7 six month cycles
    int start = 0; // Start index for the six-month window
    int stop = 6; // end index for the six-month window

    while (count < 7){
        float sum = 0;
        
        for(int i = start; i < stop; i++){
            sum += list[i];
        }
        //moves the window one month forward
        start ++;
        stop ++;

        float avg = sum/6;
        printf("\n%-15s %10.2f", months[count], avg);
        
        avg = 0;
        count ++;
    }
    printf("\n");
}

void sales_htl(float list[]){ //sales highest to lowest
    const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    const char *sorted_months[12];
    float sorted_sales[12];
    
    int count = 0;
    printf("\nSales Report (Highest to Lowest): \n");
    printf("\nMonth      Sales\n");
    
    while (count<12){
        float max = -1;
        int max_index = -1;
        // Iterate through the sales data for each month to find the month with the highest sales
        for(int i = 0; i < 12; i++){ 
            if (list[i] > max) {
                max = list[i];
                max_index = i;
            }
        }
        // Store the highest sales and corresponding month in sorted arrays
        sorted_sales[count] = max;
        sorted_months[count] = months[max_index];
        list[max_index] = -1; // Mark this month's sales as processed
        count++;
    }

    for(int i = 0; i < 12; i++){ //prints output of sales from highest to lowest
        printf("%-10s $%.2f\n", months[i], sorted_sales[i]);
    }

} 

int main(){
    // creating pointer to the file
    FILE *file_ptr;

    char name[100];
    char ch;
    float sales[12]= {0};
    int i = 0;

    printf("Enter filename: ");
    scanf("%s", name); //Arrays are already pointers to their first element so no need to do &name.
    file_ptr = fopen(name, "r"); //opens the file to read

    //fscanf returns 1 if a float is successfully read from the file.
    //&sales[i]: The & op gives address of sales[i], allowing fscanf to write the read value into sales[i]
    while (i < 12 && fscanf(file_ptr, "%f", &sales[i]) == 1) {
    i++; // Increment the index after successful read
    }

    monthly(sales);
    six_month_average(sales);
    sales_htl(sales);

    fclose(file_ptr);
    return 0;

}