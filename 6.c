#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pid_t target_pid = atoi(argv[1]);

    // Wysłanie sygnału SIGINT do procesu o podanym PID
    if (kill(target_pid, SIGINT) == -1) {
        perror("Nie można wysłać sygnału");
        exit(EXIT_FAILURE);
    }

    printf("Wysłano sygnał SIGINT do procesu o PID %d\n", target_pid);

    return 0;
}