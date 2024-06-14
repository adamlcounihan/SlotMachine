#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define START_MONEY 1.00
#define TURN_COST 0.20
#define TWO_OF_A_KIND_BONUS 0.50
#define THREE_OF_A_KIND_BONUS 1.00
#define THREE_SEVENS_BONUS 5.00

void print_instructions() {
    printf("--Welcome to the fruit machine--\n");
    printf("Rules:\n");
    printf("~ You start with %.2f \n", START_MONEY);
    printf("~ Each turn costs %.2f \n", TURN_COST);
    printf("~ Two of same num = +%.2f\n", TWO_OF_A_KIND_BONUS);
    printf("~ Three of same num = +%.2f\n", THREE_OF_A_KIND_BONUS);
    printf("~ Three Sevens = +%.2f \n", THREE_SEVENS_BONUS);
    printf("~ Three Nines = Lose all money\n");
    printf("--------------------------------\n");
}

int get_user_input() {
    int play;
    printf("\nWould you like to roll? (1=yes,2=no)");
    scanf("%d", &play);
    while(play != 1 && play != 2) {
        printf("Invalid input. Please enter 1 for yes or 2 for no.\n");
        scanf("%d", &play);
    }
    return play;
}

int main () {
    srand(time(NULL));
    double money = START_MONEY;
    int play;

    print_instructions();

    while (money > TURN_COST) {
        play = get_user_input();

        if (play == 1) {
            money -= TURN_COST;
            printf("Money now %.2f\n", money);

            int num1 = rand() % 9 + 1;
            int num2 = rand() % 9 + 1;
            int num3 = rand() % 9 + 1;

            printf("\n\n%d,%d,%d\n", num1, num2, num3);

            if(num1 == num2 && num2 == num3) {
                switch(num1) {
                    case 7:
                        printf("\nThree 7s! (+5)\n");
                        money += THREE_SEVENS_BONUS;
                        break;
                    case 9:
                        printf("\nThree 9s (Lose all Money)\n");
                        money = 0;
                        break;
                    default:
                        printf("\n3 of a kind! (+1)\n");
                        money += THREE_OF_A_KIND_BONUS;
                        break;
                }
            } else if(num1 == num2 || num2 == num3 || num1 == num3) {
                printf("\nTwo of a kind! (+50p)\n");
                money += TWO_OF_A_KIND_BONUS;
            } else {
                printf("\nYou won nothing\n");
            }
            printf("Money now %.2f\n", money);
        } else {
            printf("\nLeaving machine with %.2f", money);
            return 0;
        }
    }
    printf("\nYou do not have enough money to play. Game Ending.");
    return 0;
}


