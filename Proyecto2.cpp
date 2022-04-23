#include <iostream>
#include <mysql.h>

using namespace std;

char serverdb[] = "localhost";
char userdb[] = "root";
char passworddb[] = "";
char database[] = "intituto";

MYSQL* connection;
string idAlumno;
string aux;
string alumnoNombre;
string alumnoCorreo;
string alumnoTelefono;
string alumnoGrado;
string alumnoSeccion;
string gradoNombre;
string jornadaGrado;
string curso1Grado;
string curso2Grado;
string curso3Grado;
string curso4Grado;
string seccionNombre;
string busqueda;
string busqueda2;
string cambio;
string nota1;
string nota2;
string nota3;
string nota4;
string sql;
const char* query;
int result;
int opc;

//Ingresar datos a la tabla de datos alumnos

	void ingresarAlumnos(){
	connection = mysql_init(0);
	if (connection) 
	{
		cout << "La biblioteca MySQL se ha iniciado correctamente" << endl;
		connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
		if (connection) 
		{
			cout << "Conexion exitosa a la base de datos" << endl;
			getline(cin, aux);
			cout << "Ingrese el nombre del alumno: ";
			getline(cin, alumnoNombre);
			cout << "Ingrese el correo del alumno: ";
			getline(cin, alumnoCorreo);
			cout << "Ingrese el telefono del alumno: ";
			getline(cin, alumnoTelefono);
			cout << "Ingrese el grado al que se asignara el alumno: ";
			getline(cin, alumnoGrado);
			cout << "Ingrese la seccion a la que se asignara el alumno: ";
			getline(cin, alumnoSeccion);
			sql = "INSERT INTO alumnos(nombre_alumno, correo_alumno, numero_alumno, grado_alumno, seccion_alumno) VALUES ('" + alumnoNombre + "', '" + alumnoCorreo + "', '" + alumnoTelefono + "', '" + alumnoGrado + "', '" + alumnoSeccion + "')";
			query = sql.c_str();
			result = mysql_query(connection, query);
			if (result == 0) 
			{
				cout << "El alumno fue agregado con exito";
			}
			else
			{
				cout << "No fue posible agregar al alumno " << mysql_error(connection) << endl;
			}
		}
		else 
		{
			cout << "No fue posible conectarse a la base de datos: " << mysql_error(connection) << endl;
		}
	}
	else 
	{
		cout << "No es posible iniciar la biblioteca de MySQL" << endl;
	}
}

//Ingresar datos a la tabla de datos grado

	void ingresarGrado(){
		
	connection = mysql_init(0);
	if (connection) 
	{
		cout << "La biblioteca MySQL se ha iniciado correctamente" << endl;
		connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
		if (connection) 
		{
			cout << "Conexion exitosa a la base de datos" << endl;
			getline(cin, aux);
			cout << "Ingrese el nuevo grado a agregar: ";
			getline(cin, gradoNombre);
			cout << "Ingrese el tipo de jornada en que se imparte este grado: ";
			getline(cin, jornadaGrado);
			sql = "INSERT INTO grado(nombre_grado, jornada_grado) VALUES ('" + gradoNombre + "', '" + jornadaGrado + "')";
			query = sql.c_str();
			result = mysql_query(connection, query);
			if (result == 0) 
			{
				cout << "El nuevo grado ha sido creado";
			}
			else
			{
				cout << "No fue posible crear el nuevo grado " << mysql_error(connection) << endl;
			}
		}
		else 
		{
			cout << "No fue posible conectarse a la base de datos: " << mysql_error(connection) << endl;
		}
	}
	else 
	{
		cout << "No es posible iniciar la biblioteca de MySQL" << endl;
	}
}


//Ingresar datos a la tabla de notas

	void ingresarNotas(){
		
	connection = mysql_init(0);
	if (connection) 
	{
		cout << "La biblioteca MySQL se ha iniciado correctamente" << endl;
		connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
		if (connection) 
		{
			cout << "Conexion exitosa a la base de datos" << endl;	
			getline(cin, aux);		
			cout << "Ingrese id del alumno al que desea agregar una nota: ";
			getline(cin, idAlumno);
			cout << "Ingrese la nota (bimestral) del alumno: \n";
			getline(cin, nota1);
			cout<<"Ingrese la segunda nota (bimestral) de alumno (si no se ha cursado ingrese el valor '0'): \n";
			getline(cin, nota2);
			cout<<"Ingrese la tercera nota (bimestral) de alumno (si no se ha cursado ingrese el valor '0'): \n";
			getline(cin, nota3);
			cout<<"Ingrese la cuarta nota (bimestral) de alumno (si no se ha cursado ingrese el valor '0'): \n";
			getline(cin, nota4);
			sql = "INSERT INTO notas(nota_1, nota_2, nota_3, nota_4, id_alumno) VALUES ('" + nota1 + "', '" + nota2 + "', '" + nota3 + "', '" + nota4 + "', '" + idAlumno + "')";
			query = sql.c_str();
			result = mysql_query(connection, query);
			if (result == 0) 
			{
				cout << "Las notas fueron agregadas";
			}
			else
			{
				cout << "No fue posible agregar las notas " << mysql_error(connection) << endl;
			}
		}
		else 
		{
			cout << "No fue posible conectarse a la base de datos: " << mysql_error(connection) << endl;
		}
	}
	else 
	{
		cout << "No es posible iniciar la biblioteca de MySQL" << endl;
	}
}

//Buscar un alumno por medio del ID

	void buscarAlumno(){
		
	connection = mysql_init(0);
	if (connection) 
	{
		cout << "La biblioteca MySQL se ha iniciado correctamente" << endl;
		connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
		if (connection) 
		{
			MYSQL_ROW row;
			MYSQL_RES* data;
			getline(cin, aux);
			cout<<"Ingrese el id del alumno a buscar: ";
			getline(cin, busqueda);
			sql = "SELECT * FROM alumnos where id_alumno= '" + busqueda + "';";
			query = sql.c_str();
			result = mysql_query(connection, query);
			if (result == 0) 
			{
				cout << "Se han obtenido los datos de forma exitosa " << endl;
				data = mysql_store_result(connection);
				int countColumns = mysql_num_fields(data);
				while(row = mysql_fetch_row(data))
				{
					for (int i = 0; i < countColumns; i++)
					{
						cout <<""<< row[i]<<""<< "\t";
					}
					cout << endl;
				}
			}
			else
			{
				cout << "No fue posible obtener los registros " << mysql_error(connection) << endl;
			}
		}
		else 
		{
			cout << "No fue posible conectarse a la base de datos: " << mysql_error(connection) << endl;
		}
	}
	else 
	{
		cout << "No es posible iniciar la biblioteca de MySQL" << endl;
	}
}

//Buscar un grado por nombre o id?

	void buscarGrado(){
		
	connection = mysql_init(0);
	if (connection) 
	{
		cout << "La biblioteca MySQL se ha iniciado correctamente" << endl;
		connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
		if (connection) 
		{
			MYSQL_ROW row;
			MYSQL_RES* data;
			getline(cin, aux);
			cout<<"Ingrese el id del Grado a buscar: ";
			getline(cin, busqueda);
			sql = "SELECT * FROM grado where id_grado= '" + busqueda + "';";
			query = sql.c_str();
			result = mysql_query(connection, query);
			if (result == 0) 
			{
				cout << "Se han obtenido los datos de forma exitosa" << endl;
				data = mysql_store_result(connection);
				int countColumns = mysql_num_fields(data);
				while(row = mysql_fetch_row(data))
				{
					for (int i = 0; i < countColumns; i++)
					{
						cout <<"|"<< row[i]<<"|"<< "\t";
					}
					cout << endl;
				}
			}
			else
			{
				cout << "No fue posible obtener los registros " << mysql_error(connection) << endl;
			}
		}
		else 
		{
			cout << "No fue posible conectarse a la base de datos: " << mysql_error(connection) << endl;
		}
	}
	else 
	{
		cout << "No es posible iniciar la biblioteca de MySQL" << endl;
	}
}

//Borrar un alumno de la tabla alumnos

	void borrarAlumno(){
		
	connection = mysql_init(0);
	if (connection) 
	{
		cout << "La biblioteca MySQL se ha iniciado correctamente" << endl;
		connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
		if (connection) 
		{
			MYSQL_ROW row;
			MYSQL_RES* data;
			getline(cin, aux);
			cout<<"Ingrese el id del alumno a borrar: ";
			getline(cin, busqueda);
			sql = "DELETE FROM alumnos where id_alumno='" + busqueda + "';";
			query = sql.c_str();
			result = mysql_query(connection, query);
			if (result == 0) 
			{
				cout << "El alumno fue Eliminado con exito";
			}
			else
			{
				cout << "No fue posible Eliminar al alumno " << mysql_error(connection) << endl;
			}
		}
		else 
		{
			cout << "No fue posible conectarse a la base de datos: " << mysql_error(connection) << endl;
		}
	}
	else 
	{
		cout << "No es posible iniciar la biblioteca de MySQL" << endl;
	}
}

//Borrar un grado de la tabla grado

	void borrarGrado(){
	
	connection = mysql_init(0);
	if (connection) 
	{
		cout << "La biblioteca MySQL se ha iniciado correctamente" << endl;
		connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
		if (connection) 
		{
			MYSQL_ROW row;
			MYSQL_RES* data;
			getline(cin, aux);
			cout<<"Ingrese el id del grado a borrar: ";
			getline(cin, busqueda);
			sql = "DELETE FROM grado where id_grado='" + busqueda + "';";
			query = sql.c_str();
			result = mysql_query(connection, query);
			if (result == 0) 
			{
				cout << "El grado fue Eliminado de la base de datos con exito";
			}
			else
			{
				cout << "No fue posible Eliminar al grado de la base de datos " << mysql_error(connection) << endl;
			}
		}
		else 
		{
			cout << "No fue posible conectarse a la base de datos: " << mysql_error(connection) << endl;
		}
	}
	else 
	{
		cout << "No es posible iniciar la biblioteca de MySQL" << endl;
	}		
}
	
//Modificar datos de un alumno en tabla alumnos

	void modificarDatosAlumno(){
		
			cout << "¿Que dato del alumno desea modificar? \n";
			cout<<"1-- Modificar el nombre del alumno \n";
			cout<<"2-- Modificar el correo del alumno \n";
			cout<<"3-- Modificar el numero telefonico del alumno \n";
			cout<<"4-- Modificar el grado al que el alumno pertenece \n";
			cout<<"5-- Modificar la seccion a la que el alumno pertenece \n";
			cin>>opc;
			switch(opc){
				case 1:{
					connection = mysql_init(0);
					if (connection) 
					{
						cout << "La biblioteca MySQL se ha iniciado correctamente" << endl;
						connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
						if (connection) 
						{
							MYSQL_ROW row;
							MYSQL_RES* data;
							getline(cin, aux);
							cout<<"Ingrese el id del alumno al cual desea modificar el nombre: "<<endl;
							getline(cin,busqueda);
							cout<<"Ingrese el nuevo nombre del alumno: ";
							getline(cin, cambio);
							sql = "UPDATE alumnos SET nombre_alumno= '" + cambio + " ' where id_alumno= '" + busqueda + "';";
							query = sql.c_str();
							result = mysql_query(connection, query);
							if (result == 0) 
							{
								cout << "Los datos del alumno fueron actualizados con exito";
							}
							else
							{
								cout << "No fue posible Actualizar los datos del alumno en la base de datos " << mysql_error(connection) << endl;
							}			
						}
						else 
						{
							cout << "No fue posible conectarse a la base de datos: " << mysql_error(connection) << endl;
						}
						}
						else 
						{
							cout << "No es posible iniciar la biblioteca de MySQL" << endl;
					}
					break;
				}
				case 2:{
						connection = mysql_init(0);
						if (connection) 
						{
							cout << "La biblioteca MySQL se ha iniciado correctamente" << endl;
							connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
							if (connection) 
							{
								MYSQL_ROW row;
								MYSQL_RES* data;
								getline(cin, aux);
								cout<<"Ingrese el id del alumno al cual desea modificar el correo: "<<endl;
								getline(cin,busqueda);
								cout<<"Ingrese el nuevo correo del alumno: ";
								getline(cin, cambio);
								sql = "UPDATE alumnos SET correo_alumno= '" + cambio + " ' where id_alumno= '" + busqueda + "';";
								query = sql.c_str();
								result = mysql_query(connection, query);
								if (result == 0) 
								{
									cout << "Los datos del alumno fueron actualizados con exito";
								}
								else
								{
									cout << "No fue posible Actualizar los datos del alumno en la base de datos " << mysql_error(connection) << endl;
								}			
							}
							else 
							{
								cout << "No fue posible conectarse a la base de datos: " << mysql_error(connection) << endl;
							}
						}
						else 
						{
							cout << "No es posible iniciar la biblioteca de MySQL" << endl;
						}
					break;
				}
				case 3:{
						connection = mysql_init(0);
						if (connection) 
						{
							cout << "La biblioteca MySQL se ha iniciado correctamente" << endl;
							connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
							if (connection) 
							{
								MYSQL_ROW row;
								MYSQL_RES* data;
								getline(cin, aux);
								cout<<"Ingrese el id del alumno al cual desea modificar el numero telefonico: "<<endl;
								getline(cin,busqueda);
								cout<<"Ingrese el nuevo numero telefonico del alumno: ";
								getline(cin, cambio);
								sql = "UPDATE alumnos SET numero_alumno= '" + cambio + " ' where id_alumno= '" + busqueda + "';";
								query = sql.c_str();
								result = mysql_query(connection, query);
								if (result == 0) 
								{
									cout << "Los datos del alumno fueron actualizados con exito";
								}
								else
								{
									cout << "No fue posible Actualizar los datos del alumno en la base de datos " << mysql_error(connection) << endl;
								}			
							}
							else 
							{
								cout << "No fue posible conectarse a la base de datos: " << mysql_error(connection) << endl;
							}
						}
						else 
						{
							cout << "No es posible iniciar la biblioteca de MySQL" << endl;
						}
					break;
				}
				case 4:{
						connection = mysql_init(0);
						if (connection) 
						{
							cout << "La biblioteca MySQL se ha iniciado correctamente" << endl;
							connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
							if (connection) 
							{
								MYSQL_ROW row;
								MYSQL_RES* data;
								getline(cin, aux);
								cout<<"Ingrese el id del alumno al cual desea modificar el grado: "<<endl;
								getline(cin,busqueda);
								cout<<"Ingrese el nuevo grado del alumno: ";
								getline(cin, cambio);
								sql = "UPDATE alumnos SET grado_alumno= '" + cambio + " ' where id_alumno= '" + busqueda + "';";
								query = sql.c_str();
								result = mysql_query(connection, query);
								if (result == 0) 
								{
									cout << "Los datos del alumno fueron actualizados con exito";
								}
								else
								{
									cout << "No fue posible Actualizar los datos del alumno en la base de datos " << mysql_error(connection) << endl;
								}			
							}
							else 
							{
								cout << "No fue posible conectarse a la base de datos: " << mysql_error(connection) << endl;
							}
						}
						else 
						{
							cout << "No es posible iniciar la biblioteca de MySQL" << endl;
						}
					break;
				}
				case 5:{
						connection = mysql_init(0);
						if (connection) 
						{
							cout << "La biblioteca MySQL se ha iniciado correctamente" << endl;
							connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
							if (connection) 
							{
								MYSQL_ROW row;
								MYSQL_RES* data;
								getline(cin, aux);
								cout<<"Ingrese el id del alumno al cual desea modificar la seccion: "<<endl;
								getline(cin,busqueda);
								cout<<"Ingrese la nueva seccion del alumno: ";
								getline(cin, cambio);
								sql = "UPDATE alumnos SET seccion_alumno= '" + cambio + " ' where id_alumno= '" + busqueda + "';";
								query = sql.c_str();
								result = mysql_query(connection, query);
								if (result == 0) 
								{
									cout << "Los datos del alumno fueron actualizados con exito";
								}
								else
								{
									cout << "No fue posible Actualizar los datos del alumno en la base de datos " << mysql_error(connection) << endl;
								}			
							}
							else 
							{
								cout << "No fue posible conectarse a la base de datos: " << mysql_error(connection) << endl;
							}
						}
						else 
						{
							cout << "No es posible iniciar la biblioteca de MySQL" << endl;
						}
					break;
				}
				default:{
					cout<<"Ha elegido una opcion inexistente...\n";
					system("pause");
					break;
				}
			}				
}

//Modificar los datos de un grado en tabla grados

	void modificarDatosGrado(){
		
		cout << "¿Que dato del grado desea modificar? \n";
			cout<<"1-- Modificar el nombre del grado \n";
			cout<<"2-- Modificar la jordana del grado \n";
			cin>>opc;
			switch(opc){
				case 1:{
					connection = mysql_init(0);
					if (connection) 
					{
						cout << "La biblioteca MySQL se ha iniciado correctamente" << endl;
						connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
						if (connection) 
						{
							MYSQL_ROW row;
							MYSQL_RES* data;
							getline(cin, aux);
							cout<<"Ingrese el id del grado al cual desea modificar el nombre: "<<endl;
							getline(cin,busqueda);
							cout<<"Ingrese el nuevo nombre del grado: ";
							getline(cin, cambio);
							sql = "UPDATE grado SET nombre_grado= '" + cambio + " ' where id_grado= '" + busqueda + "';";
							query = sql.c_str();
							result = mysql_query(connection, query);
							if (result == 0) 
							{
								cout << "Los datos del grado fueron actualizados con exito";
							}
							else
							{
								cout << "No fue posible Actualizar los datos del grado en la base de datos " << mysql_error(connection) << endl;
							}			
						}
						else 
						{
							cout << "No fue posible conectarse a la base de datos: " << mysql_error(connection) << endl;
						}
						}
						else 
						{
							cout << "No es posible iniciar la biblioteca de MySQL" << endl;
					}
					break;
				}
				case 2:{
						connection = mysql_init(0);
						if (connection) 
						{
							cout << "La biblioteca MySQL se ha iniciado correctamente" << endl;
							connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
							if (connection) 
							{
								MYSQL_ROW row;
								MYSQL_RES* data;
								getline(cin, aux);
								cout<<"Ingrese el id del grado al que quiere cambiar el tipo de jornada: "<<endl;
								getline(cin,busqueda);
								cout<<"Ingrese el nuevo tipo de jornada del grado: ";
								getline(cin, cambio);
								sql = "UPDATE grado SET jornada_grado= '" + cambio + " ' where id_grado= '" + busqueda + "';";
								query = sql.c_str();
								result = mysql_query(connection, query);
								if (result == 0) 
								{
									cout << "Los datos del grado fueron actualizados con exito";
								}
								else
								{
									cout << "No fue posible Actualizar los datos del grado en la base de datos " << mysql_error(connection) << endl;
								}			
							}
							else 
							{
								cout << "No fue posible conectarse a la base de datos: " << mysql_error(connection) << endl;
							}
						}
						else 
						{
							cout << "No es posible iniciar la biblioteca de MySQL" << endl;
						}
					break;
				}
				default:{
					cout<<"Ha elegido una opcion inexistente...\n";
					system("pause");
					break;
				}
			}			

}
	
		
//Listar los Alumnos de un grado

	void listarAlumnosGrado(){
		
	connection = mysql_init(0);
	if (connection) 
	{
		cout << "La biblioteca MySQL se ha iniciado correctamente" << endl;
		connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
		if (connection) 
		{
			MYSQL_ROW row;
			MYSQL_RES* data;
			getline(cin, aux);
			cout<<"Ingrese el nombre del grado al cual desea ver sus alumnos: ";
			getline(cin, busqueda);
			sql = "SELECT * FROM alumnos where grado_alumno='" + busqueda + "';";
			query = sql.c_str();
			result = mysql_query(connection, query);
			if (result == 0) 
			{
				cout << "Se han obtenido los datos de forma exitosa " << endl;
				data = mysql_store_result(connection);
				int countColumns = mysql_num_fields(data);
				while(row = mysql_fetch_row(data))
				{
					for (int i = 0; i < countColumns -1; i++)
					{
						cout <<"|"<< row[i]<<"|"<< "\t";
					}
					cout << endl;
				}
			}
			else
			{
				cout << "No fue posible obtener los registros " << mysql_error(connection) << endl;
			}
		}
		else 
		{
			cout << "No fue posible conectarse a la base de datos: " << mysql_error(connection) << endl;
		}
	}
	else 
	{
		cout << "No es posible iniciar la biblioteca de MySQL" << endl;
	}
}
		

//Listar Alumnos de una seccion

void listarAlumnosSeccion(){
		
	connection = mysql_init(0);
	if (connection) 
	{
		cout << "La biblioteca MySQL se ha iniciado correctamente" << endl;
		connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
		if (connection) 
		{
			MYSQL_ROW row;
			MYSQL_RES* data;
			getline(cin, aux);
			cout<<"Ingrese el nombre de la Seccion por el cual quiere ver a los alumnos: ";
			getline(cin, busqueda);
			sql = "SELECT * FROM alumnos where seccion_alumno='" + busqueda + "';";
			query = sql.c_str();
			result = mysql_query(connection, query);
			if (result == 0) 
			{
				cout << "Se han obtenido los datos de forma exitosa" << endl;
				data = mysql_store_result(connection);
				int countColumns = mysql_num_fields(data);
				while(row = mysql_fetch_row(data))
				{
					for (int i = 0; i < countColumns; i++)
					{
						cout <<"|"<< row[i]<<"|"<< "\t";
					}
					cout << endl;
				}
			}
			else
			{
				cout << "No fue posible obtener los registros " << mysql_error(connection) << endl;
			}
		}
		else 
		{
			cout << "No fue posible conectarse a la base de datos: " << mysql_error(connection) << endl;
		}
	}
	else 
	{
		cout << "No es posible iniciar la biblioteca de MySQL" << endl;
	}	
}

//Listar Alumnos por grado Y seccion

void listarAlumnosGradoSeccion(){
		
	connection = mysql_init(0);
	if (connection) 
	{
		cout << "La biblioteca MySQL se ha iniciado correctamente" << endl;
		connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
		if (connection) 
		{
			MYSQL_ROW row;
			MYSQL_RES* data;
			getline(cin, aux);
			cout<<"Ingrese el nombre del grado por el cual quiere ver a los alumnos: ";
			getline(cin, busqueda);
			cout<<"Ingrese el nombre de la Seccion por el cual quiere ver a los alumnos: ";
			getline(cin, busqueda2);
			sql = "SELECT * FROM alumnos where grado_alumno= '" + busqueda + "' and seccion_alumno='" + busqueda2 + "';";
			query = sql.c_str();
			result = mysql_query(connection, query);
			if (result == 0) 
			{
				cout << "Se han obtenido los datos de forma exitosa" << endl;
				data = mysql_store_result(connection);
				int countColumns = mysql_num_fields(data);
				while(row = mysql_fetch_row(data))
				{
					for (int i = 0; i < countColumns; i++)
					{
						cout <<"|"<< row[i]<<"|"<< "\t";
					}
					cout << endl;
				}
			}
			else
			{
				cout << "No fue posible obtener los registros " << mysql_error(connection) << endl;
			}
		}
		else 
		{
			cout << "No fue posible conectarse a la base de datos: " << mysql_error(connection) << endl;
		}
	}
	else 
	{
		cout << "No es posible iniciar la biblioteca de MySQL" << endl;
	}	
}



int main() {

    do{
    system("cls");
    
	cout<<"Bienvenido a la aplicacion de C++ para ingreso de datos con interfaz a una base de datos \n";
	cout<<"Eliga una de las siguienes opciones \n";
	cout<<"1--- Agregar un nuevo alumno \n";
	cout<<"2--- Agregar un nuevo grado \n";
	cout<<"3--- Agregar una nota a un alumno \n";
	cout<<"4--- Buscar un alumno \n";
	cout<<"5--- Buscar un grado \n";
	cout<<"6--- Borrar un alumno \n";	
	cout<<"7--- Borrar un grado  \n";
	cout<<"8--- Modificar los datos de un alumno \n";
	cout<<"9--- Modificar los datos de un grado \n";
	cout<<"10-- Listar los alumnos de un grado \n";
	cout<<"11-- Listar los alumnos de una seccion \n";
	cout<<"12-- Listar alumnos por grado y seccion \n";
	cout<<"13-- Salir \n";
	cin>>opc;


	switch(opc){
		case 1:{
		    system("cls");
		    ingresarAlumnos();
		    system ("pause");
			break;
		}
		case 2:{
		    system("cls");
		    ingresarGrado();
		    system ("pause");
			break;
		}
		case 3:{
		    system("cls");
		    ingresarNotas();
		    system ("pause");
			break;
		}
		case 4:{
		    system("cls");
		    buscarAlumno();
		    system ("pause");
			break;
		}
		case 5:{
		    system("cls");
		    buscarGrado();
		    system ("pause");
			break;
		}
		case 6:{
		    system("cls");
		    borrarAlumno();
		    system ("pause");
			break;
		}
		case 7:{
		    system("cls");
		    borrarGrado();
		    system ("pause");
			break;
		}
		case 8:{
		    system("cls");
		    modificarDatosAlumno();
		    system ("pause");
			break;
		}
		case 9:{
		    system("cls");
		    modificarDatosGrado();
		    system ("pause");
			break;
		}
		case 10:{
		    system("cls");
		    listarAlumnosGrado();
		    system ("pause");
			break;
		}
		case 11:{
			system("cls");
		    listarAlumnosSeccion();
		    system ("pause");
			break;
		}
		case 12:{
		    system("cls");
		    listarAlumnosGradoSeccion();
		    system ("pause");
			break;
		}
		case 13:{
		    cout<<"\n\n\tHa elegido salir...\n\n\t\t"; system ("pause");
			break;
		}
		default:{
		    cout<<"\n\n\tHa elegido una opcion inexistente...\n\n\t\t";
		    system ("pause");
			break;
		}
	}

	}while(opc!=13);
	system("cls");
	return 0;
}
