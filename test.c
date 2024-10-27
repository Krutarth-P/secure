#include <stdio.h>
#include <stdlib.h>
    
int main() {
    const double item_price = 15.49;
    printf("The price of an item is $%.2f.\n", item_price);
    printf("Please specify how many items (no more than 10) you would like to purchase: ");
    int quantity = 0;
    int status = scanf("%d", &quantity);
    if (status != 1 || quantity > 10) {
        printf("Invalid input. Exiting the program.\n");
        exit(1);
    }
    printf("You will be charged %.2f.\n", item_price * quantity);
}
