#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
    printf("\n======= CALCULATOR IN C =======\n");
    
    ///////////////////////////////////////////////////////////////////////////
    // Get the first number from the user, and storying in an array of size 10.
    // it's possible to store store numbers with 9 digits without comma count.
    ///////////////////////////////////////////////////////////////////////////
    char first_number[10];
    printf("Enter the first number: ");
    fgets(first_number, sizeof(first_number), stdin);
    

    /////////////////////////////////////////////////////////////////
    // Showing the user the the possible mathematical operations
    // + addition,  '-' subtraction, '*' multiplication, '/' division
    // And asking for the user to choose one operator
    /////////////////////////////////////////////////////////////////
    printf("Please choose one of the mathematical operations below.\n");
    char operations[4] = {'+', '-', '*', '/'};
    int arr_size = sizeof(operations);
    for (int i = 0; i < arr_size; i++) { printf("%c\n", operations[i]); }
    char math_operator[3];
    printf("Operation: ");
    fgets(math_operator, sizeof(math_operator), stdin);


    //////////////////////////////////////////////////////////////////////////////////
    // Get the the secound number from the user, with the same rules of the first one.
    //////////////////////////////////////////////////////////////////////////////////
    char second_number[10];
    printf("Enter the secound number: ");
    fgets(second_number, sizeof(second_number), stdin);


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Removing "\n" from the end of the string if it exists, so that it is possible to convert 'char' to 'int'.
    // Converting 'char' to 'int'.
    // Creating two pointers to the memory location of the new numbers
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    first_number[strcspn(first_number, "\n")] = '\0';
    second_number[strcspn(second_number, "\n")] = '\0';
    int num_1 = (int) strtol(first_number, NULL, 10);
    int num_2 = (int) strtol(second_number, NULL, 10);
    int *ptr_1 = &num_1;
    int *ptr_2 = &num_2;  


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Checking if the operator entered by the user is a valid operator. 
    // If so, it will perform the requested calculation and display the result.
    // At the same time, we store the result in a 'result' variable in case the user wants to use it in future calculations, 
    // and we also handle possible errors such as: entering an invalid operator, or trying to divide by 0.
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    float result;
    switch (math_operator[0]) {
        case '+':
            result = (float) *ptr_1 + (float) *ptr_2;
            printf("Result: %.2f\n", result);
            break;
        case '-':
            result = (float) *ptr_1 - (float) *ptr_2;
            printf("Result: %.2f\n", result);
            break;
        case '*':
            result = (float) *ptr_1 * (float) *ptr_2;
            printf("Result: %.2f\n", result);
            break;
        case '/':
            if (*ptr_2 != 0) {
                result = (float) *ptr_1 / (float) *ptr_2;
                printf("Result: %.2f\n", result);
            } else { printf("Error: division by zero!\n"); }
            break;
        default:
            printf("Invalid operator!\n");
    }
}

