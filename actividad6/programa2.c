#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  pid_t child_pid;

  // Crear un proceso hijo
  child_pid = fork();

  if (child_pid == 0) {
    // El proceso hijo se convierte en un proceso zombie
    while (1) {
      sleep(1);
    }
  } else {
    // El proceso padre espera 60 segundos y luego termina
    sleep(60);
    exit(0);
  }

  return 0;
}
