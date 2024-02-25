## Creación del script *`actividad3.sh`*
El script imprime un saludo y la fecha actual infinitamente con una pausa de un segundo:

```bash
#!/bin/bash

while true
do
  echo 'Hola, la fecha actual es:' $(date +"%d/%m/%Y")
  sleep 1
done
```

Cambiar los permisos de ejecución del archivo mediante el comando:
```bash
sudo chmod a+x actividad3.sh
```
## Crear el archivo *`actividad3.service`*
Se crea el archivo **actividad3.service** en el directorio: **/lib/systemd/system/** con el siguiente contenido:

```
[Unit]
Description=SO1 Actividad 3

[Service]
User=cristian
ExecStart=/home/cristian/Documentos/so1_actividades_202010893/actividad3/actividad3.sh

[Install]
WantedBy=multi-user.target
```

Es recomendable cambiar los persmisos del archivo a 777 mediante el comando: 
```bash
sudo chmod 777 actividad3.service
```

## Administrar el servicio

Comandos para administrar el servicio:
- Habilitar el servicio para poder utilizarlo.
```bash
sudo systemctl enable actividad3.service
```

- Iniciar el servicio después de habilitarlo.

```bash
sudo systemctl start actividad3.service
```

- Detener el servicio.

```bash
sudo systemctl stop actividad3.service
```

## Ver los logs
Para ver los logs del servicio se puede usar el siguiente comando, que muestra las 20 líneas más recientes:
```bash
journalctl -u actividad3.service -n 20
```
Si se desean ver los logs completos se puede usar el siguiente comando:
```bash
journalctl -u actividad3.service
```