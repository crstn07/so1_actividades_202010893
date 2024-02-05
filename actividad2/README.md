## Obtención de datos y comandos usados
- La variable **GITHUB_USER** almacena el usuario de la cuenta de github

- La variable **INFO** almacena el resultado de la consulta a la pagina https://api.github.com/users/$GITHUB_USER mediante el comando **curl**.
- La variable **USER** almacena el nombre de usuario, obtenido de la variable **INFO** despúes de filtrar la información con los comandos **grep -w** que filtra palabras completas, **awk '{print $2}'** que obtiene la segunda columna de lo obtenido con el comando anterior, **sed 's/'\"'//g'** que elimina todas las comillas dobles y **sed 's/'\,'//'** que elimina la coma.
- La variable **ID** almacena el numero de id de usuario, obtenido de la variable **INFO** despúes de filtrar la información con los mismos comandos descritos previamente.
- La variable **CREATED_AT** almacena la fecha de creación de la cuenta, obtenido de la variable **INFO** despúes de filtrar la información con los mismos comandos descritos previamente.
- La variable **FECHA** almacena la fecha de ejecución del script en formato "día-mes-año"
- Para crear el directorio: mkdir -p /tmp/$FECHA 
- Para crear el archivo vacio si no existe y si existiera solo actualizar la fecha de acceso y modificacion sin sobreescribirlo: touch "/tmp/$FECHA/saludos.log"
- Para añadir nueva información al final del archivo "saludos.log":  >> /tmp/$FECHA/saludos.log

## Creación del cronjob
Para consultar los cronjobs actuales ejecutar el comando:
```sh
crontab -l
```
Para crear un nuevo cronjob hay que ejecutar el comando:
```sh
crontab -e
```
y agregar la siguiente línea al final del archivo:
```
*/5 * * * * <full_path>/script.sh >/dev/null 2>&1
```
donde **full_path** es la ruta absoluta del directorio donde se encuentra el archivo **script.sh**. Lo que hace esta línea es indicar que se ejecutará cada 5 minutos el script indicado y  redirige tanto la salida estándar como la salida de error a **/dev/null**, por lo que no guarda ningún registro.