#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
static void procedura_SIGINT(int sig_num) {
    printf("Przechwycono SIGINT\n");
    exit(EXIT_SUCCESS);
}

int main(void) {

    if (signal(SIGINT, procedura_SIGINT) == SIG_ERR) {
        perror("Nie można ustawić procedury obsługi sygnału SIGINT");
        exit(EXIT_FAILURE);
    }

    printf("Czekam na sygnał SIGINT (Ctrl+C)\n");
    for (;;) {
        pause();
    }
    return 0;
}