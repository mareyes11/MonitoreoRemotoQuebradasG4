#include "UsuarioController.h"

using namespace SistemaMonitoreoRemotoQuebradasController;
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO; /*Contiene la definicion de la clase File*/

UsuarioController::UsuarioController() {
	this->objConexion = gcnew SqlConnection();
}

void UsuarioController::abrirConexion() {
	/*Cadena de conexion: Servidor de BD, usuario de BD, password BD, nombre de la BD*/
	this->objConexion->ConnectionString = "Server=200.16.7.140;DataBase=a20180282;User Id=a20180282;Password=XaJ2fSGG";
	this->objConexion->Open(); /*Apertura de la conexion a BD*/
}

void UsuarioController::cerrarConexion() {
	this->objConexion->Close(); /*Cierra la conexion a BD*/
}

List<Usuario^>^ UsuarioController::buscarTodos() {
	/*En esta lista vamos a colocar la información de las carreras que encontremos en el archivo de texto*/
	List<Usuario^>^ listaUsuarios = gcnew List<Usuario^>();
	array<String^>^ lineas = File::ReadAllLines("Usuarios.txt");
	String^ separadores = ";"; /*Aqui defino el caracter por el cual voy a separar la informacion de cada linea*/
	for each (String ^ lineaUsuarios in lineas) {
		array<String^>^ datos = lineaUsuarios->Split(separadores->ToCharArray());
		int codigo = Convert::ToInt32(datos[0]);
		int nivelAcceso = Convert::ToInt32(datos[1]);
		String^ nombre = datos[2];
		String^ apellido = datos[3];
		String^ password = datos[4];
		Usuario^ objUsuario = gcnew Usuario(codigo, nivelAcceso, nombre, apellido, password);
		listaUsuarios->Add(objUsuario);
	}
	return listaUsuarios;
}
List<Usuario^>^ UsuarioController::buscarXNombre(String^ nombreUsuario) {
	/*En esta lista vamos a colocar la información de las carreras que encontremos en el archivo de texto*/
	List<Usuario^>^ listaUsuarios = gcnew List<Usuario^>();
	array<String^>^ lineas = File::ReadAllLines("Usuarios.txt");
	String^ separadores = ";"; /*Aqui defino el caracter por el cual voy a separar la informacion de cada linea*/
	for each (String ^ lineaUsuarios in lineas) {
		array<String^>^ datos = lineaUsuarios->Split(separadores->ToCharArray());
		int codigo = Convert::ToInt32(datos[0]);
		int nivelAcceso = Convert::ToInt32(datos[1]);
		String^ nombre = datos[2];
		String^ apellido = datos[3];
		String^ password = datos[4];
		if (nombre->Contains(nombreUsuario)) {
			Usuario^ objUsuario = gcnew Usuario(codigo, nivelAcceso, nombre, apellido, password);
			listaUsuarios->Add(objUsuario);
		}

	}
	return listaUsuarios;
}
Usuario^ UsuarioController::buscarXCodigo(int codigoUsuario) {
	Usuario^ UsuarioRetornar = gcnew Usuario();
	abrirConexion();
	/*SqlCommand viene a ser el objeto que utilizare para hacer el query o sentencia para la BD*/
	SqlCommand^ objSentencia = gcnew SqlCommand();
	/*Aqui estoy indicando que mi sentencia se va a ejecutar en mi conexion de BD*/
	objSentencia->Connection = this->objConexion;
	/*Aqui voy a indicar la sentencia que voy a ejecutar*/
	objSentencia->CommandText = "select * from Usuario where codigo=" + codigoUsuario;
	/*Aqui ejecuto la sentencia en la Base de Datos*/
	/*Para Select siempre sera ExecuteReader*/
	/*Para select siempre va a devolver un SqlDataReader*/
	SqlDataReader^ objData = objSentencia->ExecuteReader();
	while (objData->Read()) {
		int codigo = safe_cast<int>(objData[0]);
		int nivelAcceso = safe_cast<int>(objData[1]);
		String^ nombre = safe_cast<String^>(objData[2]);
		String^ apellido = safe_cast<String^>(objData[3]);
		String^ password = safe_cast<String^>(objData[4]);
		UsuarioRetornar = gcnew Usuario(codigo, nivelAcceso, nombre, apellido, password);
	}
		cerrarConexion();
		return UsuarioRetornar;
}
List<Usuario^>^ UsuarioController::buscarUsuarios(String^ nombreUsuario) {
	List<Usuario^>^ listaUsuariosEncontrados = gcnew List<Usuario^>();
	array<String^>^ lineas = File::ReadAllLines("Usuarios.txt");
	String^ separadores = ";"; /*Aqui defino el caracter por el cual voy a separar la informacion de cada linea*/
	for each (String ^ lineaUsuario in lineas) {
		array<String^>^ datos = lineaUsuario->Split(separadores->ToCharArray());
		int codigo = Convert::ToInt32(datos[0]);
		int nivelAcceso = Convert::ToInt32(datos[1]);
		String^ nombre = datos[2];
		String^ apellido = datos[3];
		String^ contraseña = datos[4];
		if (nombre->Contains(nombreUsuario)) {
			Usuario^ objUsuario = gcnew Usuario(codigo, nivelAcceso, nombre, apellido, contraseña);
			listaUsuariosEncontrados->Add(objUsuario);
		}
	}
	return listaUsuariosEncontrados;
}


void UsuarioController::eliminarUsuario(int codigoEliminar) {
	List<Usuario^>^ listaUsuarios = buscarTodos();
	for (int i = 0; i < listaUsuarios->Count; i++) {
		Usuario^ objUsuario = listaUsuarios[i];
		if (objUsuario->getCodigo() == codigoEliminar) {
			listaUsuarios->RemoveAt(i);
			break;
		}
	}
	escribirArchivo(listaUsuarios);
}

void UsuarioController::escribirArchivo(List<Usuario^>^ listaUsuarios) {
	array<String^>^ lineasArchivo = gcnew array<String^>(listaUsuarios->Count);
	for (int i = 0; i < listaUsuarios->Count; i++) {
		Usuario^ objUsuario = listaUsuarios[i];
		lineasArchivo[i] = objUsuario->getCodigo() + ";" + objUsuario->getNivelAcceso() + ";" + objUsuario->getNombre() + ";" + objUsuario->getApellido() + ";" + objUsuario->getPassword();
	}
	File::WriteAllLines("Usuarios.txt", lineasArchivo);
}

int UsuarioController::existeUsuario(int codigo) {
	int existe = 0;
	List<Usuario^>^ listaUsuarios = buscarTodos();
	for (int i = 0; i < listaUsuarios->Count; i++) {
		Usuario^ objUsuario = listaUsuarios[i];
		if (objUsuario->getCodigo() == codigo) {
			existe = 1;
			break;
		}
	}
	return existe;
}

void UsuarioController::registrarUsuario(int codigo, int nivelAcceso, String^ nombre, String^ apellido, String^ contraseña) {
	List<Usuario^>^ listaUsuarios = buscarTodos();
	Usuario^ objUsuarioNuevo = gcnew Usuario(codigo, nivelAcceso, nombre, apellido, contraseña);
	listaUsuarios->Add(objUsuarioNuevo);
	escribirArchivo(listaUsuarios);
}

Usuario^ UsuarioController::buscarUsuario(int codigo) {
	Usuario^ objUsuario = gcnew Usuario();
	List<Usuario^>^ listaUsuarios = buscarTodos();
	for (int i = 0; i < listaUsuarios->Count; i++) {
		if (listaUsuarios[i]->getCodigo() == codigo) {
			objUsuario->setCodigo(listaUsuarios[i]->getCodigo());
			objUsuario->setNombre(listaUsuarios[i]->getNombre());
			objUsuario->setApellido(listaUsuarios[i]->getApellido());
			objUsuario->setPassword(listaUsuarios[i]->getPassword());
			objUsuario->setNivelAcceso(listaUsuarios[i]->getNivelAcceso());
			break;
		}
	}
	return objUsuario;
}

void UsuarioController::actualizarUsuario(int codigo, int nivelAcceso, String^ nombre, String^ apellido, String^ contraseña) {
	List<Usuario^>^ listaUsuarios = buscarTodos();
	for (int i = 0; i < listaUsuarios->Count; i++) {
		if (listaUsuarios[i]->getCodigo() == codigo) {
			listaUsuarios[i]->setNivelAcceso(nivelAcceso);
			listaUsuarios[i]->setNombre(nombre);
			listaUsuarios[i]->setApellido(apellido);
			listaUsuarios[i]->setPassword(contraseña);

		}
	}
	escribirArchivo(listaUsuarios);
}

List<Usuario^>^ UsuarioController::buscarUsuariosxApellidoxId(String^ apellidoBuscar, String^ codigoBuscar) {
	/*En esta lista vamos a colocar la información de las carreras que encontremos en el archivo de texto*/
	List<Usuario^>^ listaUsuariosEncontrados = gcnew List<Usuario^>();
	abrirConexion();
	/*SqlCommand viene a ser el objeto que utilizare para hacer el query o sentencia para la BD*/
	SqlCommand^ objSentencia = gcnew SqlCommand();
	/*Aqui estoy indicando que mi sentencia se va a ejecutar en mi conexion de BD*/
	objSentencia->Connection = this->objConexion;
	/*Aqui voy a indicar la sentencia que voy a ejecutar*/
	objSentencia->CommandText = "select * from Usuario where codigo like '" + codigoBuscar + "%' and apellido like '" + apellidoBuscar + "%';";
	/*Aqui ejecuto la sentencia en la Base de Datos*/
	/*Para Select siempre sera ExecuteReader*/
	/*Para select siempre va a devolver un SqlDataReader*/
	SqlDataReader^ objData = objSentencia->ExecuteReader();
	while (objData->Read()) {
		int codigo = safe_cast<int>(objData[0]);
		int nivelAcceso = safe_cast<int>(objData[1]);
		String^ nombre = safe_cast<String^>(objData[2]);
		String^ apellido = safe_cast<String^>(objData[3]);
		String^ password = safe_cast<String^>(objData[4]);
		Usuario^ objUsuario = gcnew Usuario(codigo, nivelAcceso, nombre, apellido, password);
		listaUsuariosEncontrados->Add(objUsuario);
	}
	cerrarConexion();
		return listaUsuariosEncontrados;

}



