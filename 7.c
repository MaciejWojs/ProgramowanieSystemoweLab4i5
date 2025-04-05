#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

static void procedura_SIGUSR1(int sig_num) {
    printf("Przechwycono SIGUSR1\nRysowanie trojkata prostokatnego\n");
    int status = system("./trojkat.py 1");
    if (status != 0) {
        perror("Nie udało się wykonać skryptu './trojkat.py 1'");
    }

}
static void procedura_SIGUSR2(int sig_num) {
    printf("Przechwycono SIGUSR2\nRysowanie trojkata rownobocznego\n");
    int status = system("./trojkat.py 2");
    if (status != 0) {
        perror("Nie udało się wykonać skryptu './trojkat.py 2'");
    }
}
static void procedura_SIGINT(int sig_num) {
    printf("Przechwycono SIGINT\n");
    exit(EXIT_SUCCESS);
}

int main(void) {
    // Obsługa SIGUSR1
    if (signal(SIGUSR1, procedura_SIGUSR1) == SIG_ERR) {
        perror("Nie można ustawić procedury obsługi sygnału SIGUSR1");
        exit(EXIT_FAILURE);
    }

    // Obsługa SIGUSR2
    if (signal(SIGUSR2, procedura_SIGUSR2) == SIG_ERR) {
        perror("Nie można ustawić procedury obsługi sygnału SIGUSR2");
        exit(EXIT_FAILURE);
    }

    // Obsługa SIGINT
    if (signal(SIGINT, procedura_SIGINT) == SIG_ERR) {
        perror("Nie można ustawić procedury obsługi sygnału SIGINT");
        exit(EXIT_FAILURE);
    }

    printf("Czekam na sygnały...\n");
    for (;;) {
        pause();
    }
    return 0;
}