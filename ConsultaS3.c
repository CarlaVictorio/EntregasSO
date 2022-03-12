#include <my_global.h>
#include <mysql.h>
#include <string.h>
#include <stlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	
	MYSQL *conn;
	int err;
	//Almacenar resultados de consultas
	MYSQL_RES * resultado;
	MYSQL_ROW row;
	//Creamos una conexión al servidor MYSQL
	conn = mysql_init(NULL);
	if (conn==NULL){
		printf("Error al crear la conexión: %u %s \n",mysql_errno(conn),mysql_error(conn));
		exit(1);
	}
	//Inicializamos la conexión
	conn=mysql_real_connect(conn,"localhost","root","mysql","Juego",0,NULL,0);
	if(conn==NULL){
		printf("Error al inicializar la conexion: %u %s \n", mysql_errno(conn), mysql_error(conn));
		exit(1);
	}
	//Empieza la consulta: Dime el id de Pedro
	int id;
	char consulta [80];
	strcpy (consulta, "SELECT Jugador.id FROM Jugador WHERE Jugador.username='Pedro'");
	
	err=mysql_query(conn, consulta);
	if (err!=0){
		printf ("Error al consultar datos de la base %u %s\n", mysql_errno(conn),mysql_error(conn));
		exit(1);
	}
	//Recogemos el resultado de la consulta 
	resultado = mysql_store_result(conn);
	//Obtenemos 1a fila 
	row=mysql_fetch_row(resultado);
	if(row==NULL)
		printf("No se han obtenido datos en la consulta \n");
	else
		printf("El id de Pedro es: %d \n",row[0]);
	mysql_close(conn);
	exit(0);
}

