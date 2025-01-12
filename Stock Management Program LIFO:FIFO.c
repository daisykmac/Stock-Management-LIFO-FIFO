#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stock Structure
struct Stock {
    char name[20];
    int shares;
    float price;
};
//FIFO Function
float fifo_cost(struct Stock stocks[], int n, char name[], int shares) {
    float total_cost = 0;
    int remaining_shares = shares;
    for (int i = 0; i < n; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            if (remaining_shares >= stocks[i].shares) {
                total_cost += stocks[i].shares * stocks[i].price;
                remaining_shares -= stocks[i].shares;
            } else {
                total_cost += remaining_shares * stocks[i].price;
                break;
            }
        }
    }
    return total_cost;
}
//LIFO Function
float lifo_cost(struct Stock stocks[], int n, char name[], int shares) {
    float total_cost = 0;
    int remaining_shares = shares;
    for (int i = n - 1; i >= 0; i--) {
        if (strcmp(stocks[i].name, name) == 0) {
            if (remaining_shares >= stocks[i].shares) {
                total_cost += stocks[i].shares * stocks[i].price;
                remaining_shares -= stocks[i].shares;
            } else {
                total_cost += remaining_shares * stocks[i].price;
                break;
            }
        }
    }
    return total_cost;
}
//driver + menu
int main() {
    struct Stock stocks[1000]; //Max of 1000 Stocks
    int num_stocks = 0;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Enter a new stock\n");
        printf("2. Find the LIFO and FIFO price for a stock\n");
        printf("3. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the stock name: ");
            scanf("%s", stocks[num_stocks].name);
            printf("Enter the number of shares: ");
            scanf("%d", &stocks[num_stocks].shares);
            printf("Enter the purchase price: ");
            scanf("%f", &stocks[num_stocks].price);
            num_stocks++;
            printf("Stock added successfully!\n");
        } else if (choice == 2) {
            char name[20];
            int shares;
            printf("Enter the stock name being queried (capitolization senstive): ");
            scanf("%s", name);
            printf("Enter the number of shares in question: ");
            scanf("%d", &shares);
            float fifo = fifo_cost(stocks, num_stocks, name, shares);
            float lifo = lifo_cost(stocks, num_stocks, name, shares);
            printf("FIFO cost for %d shares of %s: %.2f\n", shares, name, fifo);
            printf("LIFO cost for %d shares of %s: %.2f\n", shares, name, lifo);
        } else if (choice == 3) {
            printf("Exiting the program.\n");
            break;
        } else {
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}