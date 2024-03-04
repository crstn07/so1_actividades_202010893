#!/bin/bash

pipe_p1="pipe1"
pipe_p2="pipe2"
verde='\033[0;32m'
reset='\033[0m'

# Función para limpiar los pipes al finalizar
cleanup() {
    rm -f "$pipe_p1" "$pipe_p2"
    exit 0
}

trap cleanup EXIT # Se ejecuta la función cleanup al finalizar el script

# Subproceso para la lectura del participante 2
(while true; do
    if read -r mensaje < "$pipe_p2"; then
        echo ""
        echo -e "$verde>Mensaje de P1: $mensaje"
        echo -e "$reset-Ingresa tu mensaje P2: "
    fi
done) &

# Bucle principal para enviar mensajes al participante 1
while true; do
    read -p "-Ingresa tu mensaje P2: " mensaje
    echo "$mensaje" > "$pipe_p1"
done
