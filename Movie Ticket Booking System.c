#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define numberOfMovie 3

struct Movie {
    char name[100];
    bool seat[5][5];
} movies[numberOfMovie];

void setMovieNameAndSeat();
void displayMovieName();
void displaySeat(int movieNumber);
void ticketBooking(int movieNumber, char seatNumber1, char seatNumber2);

int main() {
    setMovieNameAndSeat();
    int choice;

    while (1) {
        printf("\n"
               "=====Movie Ticket Booking System=====\n"
               " 1. Show All Movie.\n"
               " 2. Buy a Ticket.\n"
               " 3. Exit.\n"
               "\n"
               "Enter Your Choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            displayMovieName();
        } else if (choice == 2) {
            int movieNumber;
            char seatNumber1, seatNumber2;

            printf("\n"
                   "Enter Movie Number: ");
            scanf("%d", &movieNumber);
            getchar();

            displaySeat(movieNumber);

            printf("\n"
                   "Enter Seat Number (\"XX\" = Booked): ");
            scanf("%c%c", &seatNumber1, &seatNumber2);
            getchar();

            ticketBooking(movieNumber, seatNumber1, seatNumber2);
        } else if (choice == 3) {
            break;
        }
    }

    return 0;
}

void setMovieNameAndSeat() {
    strcpy(movies[0].name, "Avengers: Infinity War");
    strcpy(movies[1].name, "Captain Marvel");
    strcpy(movies[2].name, "Spider-Man: Homecoming");

    for (int i = 0; i < numberOfMovie; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                movies[i].seat[j][k] = 1;
            }
        }
    }
}

void displayMovieName() {
    printf("\n");
    for (int i = 0; i < numberOfMovie; i++) {
        printf("Movie Number %d: %s\n", i + 1, movies[i].name);
    }
    printf("\n");
}

void displaySeat(int movieNumber) {
    printf("\n");
    for (int j = 0; j < 5; j++) {
        for (int k = 0; k < 5; k++) {
            if (movies[movieNumber].seat[j][k]) {
                printf("%c%d ", 'A' + k, j + 1);
            } else {
                printf("XX ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void ticketBooking(int movieNumber, char seatNumber1, char seatNumber2) {
    int seatI, seatJ;

    switch (seatNumber1) {
        case 'A':
            seatI = 0;
            break;
        case 'B':
            seatI = 1;
            break;
        case 'C':
            seatI = 2;
            break;
        case 'D':
            seatI = 3;
            break;
        case 'E':
            seatI = 4;
    }

    switch (seatNumber2) {
        case '1':
            seatJ = 0;
            break;
        case '2':
            seatJ = 1;
            break;
        case '3':
            seatJ = 2;
            break;
        case '4':
            seatJ = 3;
            break;
        case '5':
            seatJ = 4;
    }

    movies[movieNumber].seat[seatJ][seatI] = 0;

    char name[100];
    char phoneNumber[20];

    printf("\nEnter Your Name: ");
    scanf(" %[^\n]s", name);

    printf("\nEnter Your Phone Number: ");
    scanf(" %[^\n]s", phoneNumber);

    printf("\n"
           "=============================================\n"
           " Name: \t\t%s\n"
           " Phone Number: \t%s\n"
           " Movie Name: \t%s\n"
           " Seat Number: \t%c%c\n"
           "=============================================\n"
           "\n"
            , name, phoneNumber, movies[movieNumber].name, seatNumber1, seatNumber2);
}