#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

static void procedura_SIGTERM(int sig_num) {
    printf("Przechwycono SIGTERM\n\n");
    exit(EXIT_SUCCESS);
}

static void procedura_SIGINT(int sig_num) {
    printf("Przechwycono SIGINT\n\n");
    exit(EXIT_SUCCESS);
}

int main(void) {
    srand(time(NULL)); // Inicjalizacja generatora liczb losowych
    // Obsługa SIGTERM
    if (signal(SIGTERM, procedura_SIGTERM) == SIG_ERR) {
        perror("Nie można ustawić procedury obsługi sygnału SIGTERM");
        exit(EXIT_FAILURE);
    }

    // Obsługa SIGINT
    if (signal(SIGINT, procedura_SIGINT) == SIG_ERR) {
        perror("Nie można ustawić procedury obsługi sygnału SIGINT");
        exit(EXIT_FAILURE);
    }

    printf("Czekam na sygnały...\n");
    for (;;) {
        int random_number = rand() % 1000;
        printf("Wygenerowana liczba: %d\n", random_number);
        if (random_number % 100 == 0) {
            printf("Wygenerowano liczbę podzielną przez 100, wysyłam SIGTERM do samego siebie...\n");
            kill(getpid(), SIGTERM);
        }
    }
    return 0;
}