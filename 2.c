#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

static void procedura_SIGTERM(int sig_num) {
    printf("Przechwycono SIGTERM\n");
    exit(EXIT_SUCCESS);
}

static void procedura_SIGINT(int sig_num) {
    printf("Przechwycono SIGINT\n");
    exit(EXIT_SUCCESS);
}

int main(void) {
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

    // Przywrócenie domyślnego zachowania dla SIGPROF
    if (signal(SIGPROF, SIG_DFL) == SIG_ERR) {
        perror("Nie można przywrócić domyślnej obsługi sygnału SIGPROF");
        exit(EXIT_FAILURE);
    }

    // Ignorowanie SIGHUP
    if (signal(SIGHUP, SIG_IGN) == SIG_ERR) {
        perror("Nie można ustawić ignorowania sygnału SIGHUP");
        exit(EXIT_FAILURE);
    }

    printf("Czekam na sygnały...\n");
    for (;;) {
        pause();
    }
    return 0;
}