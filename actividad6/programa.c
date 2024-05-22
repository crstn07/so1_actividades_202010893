#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Error al crear el proceso hijo\n");
        exit(1);
    } else if (pid == 0) {
        // Código del proceso hijo
        printf("Proceso hijo con PID %d\n", getpid());
        exit(0); // El hijo termina
    } else {
        // Código del proceso padre
        printf("Proceso padre con PID %d\n", getpid());
        sleep(60); // El padre espera 60 segundos
        printf("El proceso hijo ha terminado\n");
        exit(0);
    }

    return 0;
}



