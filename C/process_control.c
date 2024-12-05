#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void handle_signal(int sig) {
    printf("Received signal %d\n", sig);
}

int main() {
    pid_t pid;
    int status;

    // Register signal handler for SIGUSR1
    signal(SIGUSR1, handle_signal);

    // Create a new process using fork()
    pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) created.\n", getpid());

        // Execute a new program using exec()
        execl("/bin/ls", "ls", "-l", (char *)NULL);

        // If exec() fails
        perror("execl");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        printf("Parent process (PID: %d) waiting for child process (PID: %d).\n", getpid(), pid);

        // Wait for the child process to change state
        if (wait(&status) == -1) {
            perror("wait");
            exit(EXIT_FAILURE);
        }

        if (WIFEXITED(status)) {
            printf("Child process exited with status %d.\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Child process was terminated by signal %d.\n", WTERMSIG(status));
        }

        // Send a signal to the child process (if it were still running)
        // In this example, the child process has already exited, so this is just for demonstration
        if (kill(pid, SIGUSR1) == -1) {
            perror("kill");
        } else {
            printf("Sent SIGUSR1 to child process (PID: %d).\n", pid);
        }
    }

    return 0;
}