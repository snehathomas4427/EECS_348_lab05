#include <stdio.h>

void monthly(float list[]){
    float min = list[0];
    float max = list[0];
    float avg = 0;

    printf("\nMonthly Sales Report for 2024\n");
    printf("Month      Sales\n");
    const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    for(int i = 0; i < 12; i++){
        printf("%-10s %.2f\n", months[i], list[i]);
        if (list[i] < min){
            min = list[i];
        }
        if (list[i] > max){
            max = list[i];
        }
    }

    printf("\nSales Summary Report: \n");
    printf("Minimum Sales: %.2f\n", min);
    printf("Maximum Sales: %.2f\n", max);
    printf("Average Sales: ");
}

void summary(float list[]){
    printf("\nSales Summary Report: \n");
    printf("Minimum Sales: ");
    printf("Maximum Sales: ");
    printf("Average Sales: ");
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

    fclose(file_ptr);
    return 0;

}