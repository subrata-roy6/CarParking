//
// Created by SUBRATA on 17/10/2024.
//

#include<stdio.h>
void DisplaySpaceAvailable();
void enterVehicle();
void exitVehicle();
void menu();
#define Max_Lavels 3
#define Spaces_PER_Level 5
int availableSpaces[Max_Lavels]={Spaces_PER_Level,Spaces_PER_Level,Spaces_PER_Level};
int main() {
    int choice;
    int running=1;
    while (running) {
        menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: enterVehicle(); break;
            case 2: exitVehicle(); break;
            case 3: DisplaySpaceAvailable(); break;
            case 4: running = 0;
            printf("Exiting simulation...\n");
            break;
            default:
                printf("Invalid option! Please try again.\n");
        }

    }
    return 0;
}
void DisplaySpaceAvailable() {
    for (int i = 0; i < Max_Lavels; i++) {
        printf("Level %d: %d spaces available\n", i + 1, availableSpaces[i]);
    }
}

void enterVehicle() {
    for (int i = 0; i < Max_Lavels; i++) {
        if (availableSpaces[i] > 0) {
            availableSpaces[i]--;
            printf("Vehicle parked on Level %d.\n", i + 1);
            return;
        }
    }
    printf("Parking lot is full!\n");
}
void exitVehicle() {
    for (int i = 0; i < Max_Lavels; i++) {
            if (availableSpaces[i] < Spaces_PER_Level) {
                availableSpaces[i]++;
                printf("Vehicle exited from Level %d.\n", i + 1);
                return;
            }
        }
        printf("Parking lot is empty!\n");
}
void menu() {
        printf("\nParking Lot Menu:\n");
        printf("1. Enter Vehicle\n");
        printf("2. Exit Vehicle\n");
        printf("3. View Available Spaces\n");
        printf("4. Exit Simulation\n");
    }

