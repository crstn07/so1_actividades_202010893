#!/bin/bash

GITHUB_USER="crstn07"
INFO="$(curl -s https://api.github.com/users/$GITHUB_USER)"
USER=$(echo "$INFO" | grep -w '"login"' | awk '{print $2}' | sed 's/'\"'//g' | sed 's/'\,'//')
ID=$(echo "$INFO" | grep -w '"id"' | awk '{print $2}' | sed 's/'\,'//')
CREATED_AT=$(echo "$INFO" | grep -w '"created_at"' | awk '{print $2}' | sed 's/'\"'//g' | sed 's/'\,'//')

echo "Hola $USER. User ID: $ID. Cuenta fue creada el: $CREATED_AT."

FECHA=`date +"%d-%m-%Y"`

mkdir -p /tmp/$FECHA && touch "/tmp/$FECHA/saludos.log"

echo "Hola $USER. User ID: $ID. Cuenta fue creada el: $CREATED_AT." >> /tmp/$FECHA/saludos.log

exit
