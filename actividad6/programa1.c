#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main() {
    pid_t child_pid;

    child_pid = fork(); // Crear un proceso hijo

    if (child_pid < 0) {
        perror("Error en fork");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) { // Proceso hijo
        printf("Soy el proceso hijo.\n");
        // El proceso hijo no hace nada y termina inmediatamente
        exit(EXIT_SUCCESS);
    } else { // Proceso padre
        // Esperar un poco antes de terminar
        sleep(60); // El proceso padre espera 60 segundos antes de terminar

        // El proceso padre termina sin esperar a que el hijo termine
        printf("Proceso padre terminando.\n");
        exit(EXIT_SUCCESS);
    }

    return 0;
}
