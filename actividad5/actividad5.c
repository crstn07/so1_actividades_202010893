#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_function(void *arg) {
    printf("Ejecución del Hilo\n");
    pthread_exit(0);
}

int main() {
    pid_t pid;
    pthread_t tid;
    pthread_attr_t attr;

    printf("Proceso Principal\n");
    printf("Proceso Creado 1\n");
    pid = fork(); //FORK1: Se crea un proceso hijo (Hijo 1)

    if (pid == 0) { // Proceso Hijo 1
        printf("Proceso Creado 2\n");
        fork(); // FORK2: Se crea otro proceso hijo (Hijo 2)
        printf("Hilo Creado\n");
        pthread_attr_init(&attr);
        pthread_create(&tid, &attr, thread_function, NULL);
        pthread_join(tid, NULL);
    }

    printf("Proceso Creado 3\n");
    fork(); // FORK3: Se crea otro proceso hijo
    
    return 0;
}