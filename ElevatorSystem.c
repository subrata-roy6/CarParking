//
// Created by SUBRATA on 17/10/2024.
//
#include<stdio.h>
#include <stdlib.h>
#define Max_floor 10
#define Max_Passenger 5

typedef enum {
    Idel,
    Move_up,
    Move_down,
    Door_open,
} ElevatorState;
typedef struct {
    int currentFloor;
    int TargetFloor;
    int Capacity;
    ElevatorState state;
}Elevator;
void Request_floor(Elevator *elevator);
void display_current_floor(Elevator *elevator);
void Open_Doors(Elevator *elevator);
void move_elevator(Elevator *elevator);
int GetvalidFloor();

int main() {
    Elevator elevator={ 1, -1 , Max_Passenger, Idel };
    int choice;
    while (1) {
        // Display menu
        printf("\nElevator System Menu:\n");
        printf("1. Request Elevator to Floor\n");
        printf("2. View Current Floor\n");
        printf("3. Exit Simulation\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                Request_floor(&elevator);
            break;
            case 2:
                display_current_floor(&elevator);
            break;
            case 3:
                printf("Exiting simulation...\n");
            exit(0);
            break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;

}
void Request_floor(Elevator *elevator) {
    int Request_floor;
    Request_floor == GetvalidFloor();

    if( Request_floor != elevator->currentFloor) {
        elevator->currentFloor = Request_floor;
        move_elevator(elevator);

    } else {
        printf("The floor is already Current floor %d\n", elevator->currentFloor);
    }
}
void move_elevator(Elevator *elevator) {
    if(elevator->TargetFloor > elevator->currentFloor) {
        elevator->currentFloor = elevator->TargetFloor;
        elevator->state = Move_up;
        printf("Moving up......\n");
    }
    else if(elevator->currentFloor > elevator->TargetFloor) {
        elevator->currentFloor = elevator->TargetFloor;
        elevator->state = Move_down;
        printf("Moving down.... \n");
    }
    while(elevator->currentFloor != elevator->TargetFloor) {
        if( elevator->state == Move_up ) {
            elevator->currentFloor ++;

        }
        else if(elevator->state == Move_down) {
            elevator->currentFloor --;
        }
        printf("Elevator at floor %d\n", elevator->currentFloor);
    }
    Open_Doors(elevator);
}

void Open_Doors(Elevator *elevator) {
    elevator->state = Door_open;
    printf("Elevator doors open at floor %d\n", elevator->currentFloor);
    elevator->state = Idel;
}
void display_current_floor(Elevator *elevator) {
    printf("The elevator is currently on floor %d\n", elevator->currentFloor);

}
int GetvalidFloor() {
    int floor;
    do {
        printf("Please enter the floor of the elevator:(1-%d)\n",Max_floor);
        scanf("%d",&floor);
        if(floor < 1 || floor > Max_floor ) {
            printf(" Invalid!  Please enter a number between 1-%d:\n", Max_floor);

        }
    }
    while(floor < 1 ||floor>Max_floor);
    return floor;
}
