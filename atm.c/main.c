#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 50 // Maximum buffer size for input validation
#define ATM_PIN 6969       // Assuming ATM pin is 6969
#define INITIAL_AMOUNT 35000.00 // Initial balance in Rs.

// Function prototypes
void checkBalance(float balance);
void withdrawCash(float *balance);
void depositCash(float *balance);
void transferCash(float *balance);

int main() {
    // Initialize variables
    float balance = INITIAL_AMOUNT; // Initial balance
    int inputPin;
    char option;
    char buffer[MAX_BUFFER_SIZE];

    printf("Welcome to the ATM\n");

    // Take ATM pin as input
    printf("Enter your ATM pin (4 digits): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &inputPin);

    // Validate pin
    if(inputPin != ATM_PIN) {
        printf("Invalid pin. Exiting...\n");
        return 0;
    }

    // Main loop for ATM transactions
    while(1) {
        printf("\nChoose an option:\n");
        printf("1. Check Balance\n");
        printf("2. Withdraw Cash\n");
        printf("3. Deposit Cash\n");
        printf("4. Transfer Cash\n");
        printf("5. Exit\n");

        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%c", &option);

        switch(option) {
            case '1':
                checkBalance(balance);
                break;
            case '2':
                withdrawCash(&balance);
                break;
            case '3':
                depositCash(&balance);
                break;
            case '4':
                transferCash(&balance);
                break;
            case '5':
                printf("Thank you for using the ATM. Goodbye! come again.\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}

// Function to check balance
void checkBalance(float balance) {
    printf("Your current balance is: Rs. %.2f\n", balance);
}

// Function to withdraw cash
void withdrawCash(float *balance) {
    float amount;
    char buffer[MAX_BUFFER_SIZE];

    printf("Enter the withdraw amount: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%f", &amount);

    if(amount > 0 && amount <= *balance) {
        *balance -= amount;
        printf("Withdrawal is  successful. Remaining balance: Rs. %.2f\n", *balance);
    } else {
        printf("Invalid amount or insufficient balance.\n");
    }
}

// Function to deposit cash
void depositCash(float *balance) {
    float amount;
    char buffer[MAX_BUFFER_SIZE];

    printf("Enter the deposit amount: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%f", &amount);

    if(amount > 0) {
        *balance += amount;
        printf("Deposit is  successful. New balance: Rs. %.2f\n", *balance);
    } else {
        printf("Invalid amount.\n");
    }
}

// Function to transfer cash
void transferCash(float *balance) {
    float amount;
    char buffer[MAX_BUFFER_SIZE];

    printf("Enter the amount to transfer: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%f", &amount);

    if(amount > 0 && amount <= *balance) {
        *balance -= amount;
        printf("Transfer successful. Remaining balance: Rs. %.2f\n", *balance);
    } else {
        printf("Invalid amount or insufficient balance.\n");
    }
}
