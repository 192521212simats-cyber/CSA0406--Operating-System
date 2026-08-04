#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();   // Create a new process

    if (pid < 0) {
        printf("Process creation failed.\n");
    }
    else if (pid == 0) {
        // Child process
        printf("Child Process\n");
        printf("PID  : %d\n", getpid());
        printf("PPID : %d\n", getppid());
    }
    else {
        // Parent process
        printf("Parent Process\n");
        printf("PID  : %d\n", getpid());
        printf("PPID : %d\n", getppid());
    }

    return 0;
}
