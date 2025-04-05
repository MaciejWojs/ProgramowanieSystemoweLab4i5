#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

void show_process_info() {
    pid_t pid = getpid();      // PID procesu
    pid_t ppid = getppid();    // PPID procesu
    uid_t uid = getuid();      // UID użytkownika
    uid_t euid = geteuid();    // EUID użytkownika

    // Wyświetlanie informacji o procesie
    printf("PID: %d\n", pid);
    printf("PPID: %d\n", ppid);
    printf("UID: %d\n", uid);
    printf("EUID: %d\n", euid);
}

int main(void) {
    show_process_info();
}