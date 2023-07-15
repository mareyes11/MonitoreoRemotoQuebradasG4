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
	List<Usuario^>^ listaUsuariosEncontrados = gcnew List<Usuario^>();
	abrirConexion();
	/*SqlCommand viene a ser el objeto que utilizare para hacer el query o sentencia para la BD*/
	SqlCommand^ objSentencia = gcnew SqlCommand();
	/*Aqui estoy indicando que mi sentencia se va a ejecutar en mi conexion de BD*/
	objSentencia->Connection = this->objConexion;
	/*Aqui voy a indicar la sentencia que voy a ejecutar*/
	objSentencia->CommandText = "select * from Usuario";
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

void UsuarioController::eliminarUsuario(int codigoEliminar) {
	abrirConexion();
	/*SqlCommand viene a ser el objeto que utilizare para hacer el query o sentencia para la BD*/
	SqlCommand^ objSentencia = gcnew SqlCommand();
	/*Aqui estoy indicando que mi sentencia se va a ejecutar en mi conexion de BD*/
	objSentencia->Connection = this->objConexion;
	/*Aqui voy a indicar la sentencia que voy a ejecutar*/
	objSentencia->CommandText = "delete from Usuario where codigo=" + codigoEliminar + ";";
	objSentencia->ExecuteNonQuery();
	cerrarConexion();
}

int UsuarioController::existeUsuario(int codigo) {
	int existe = 0;
	abrirConexion();
	/*SqlCommand viene a ser el objeto que utilizare para hacer el query o sentencia para la BD*/
	SqlCommand^ objSentencia = gcnew SqlCommand();
	/*Aqui estoy indicando que mi sentencia se va a ejecutar en mi conexion de BD*/
	objSentencia->Connection = this->objConexion;
	/*Aqui voy a indicar la sentencia que voy a ejecutar*/
	objSentencia->CommandText = "select * from Usuario where codigo = " + codigo + ";";
	/*Aqui ejecuto la sentencia en la Base de Datos*/
	/*Para Select siempre sera ExecuteReader*/
	/*Para select siempre va a devolver un SqlDataReader*/
	SqlDataReader^ objData = objSentencia->ExecuteReader();
	while (objData->Read()) {
		existe = 1;
		break;
	}
	cerrarConexion();
	return existe;
}

void UsuarioController::registrarUsuario(int codigo, int nivelAcceso, String^ nombre, String^ apellido, String^ contraseña) {
	abrirConexion();
	/*SqlCommand viene a ser el objeto que utilizare para hacer el query o sentencia para la BD*/
	SqlCommand^ objSentencia = gcnew SqlCommand();
	/*Aqui estoy indicando que mi sentencia se va a ejecutar en mi conexion de BD*/
	objSentencia->Connection = this->objConexion;
	/*Aqui voy a indicar la sentencia que voy a ejecutar*/
	objSentencia->CommandText = "insert into Usuario(codigo, nivelAcceso, nombre, apellido, password) values (" + codigo + "," + nivelAcceso + ",'" + nombre + "','" + apellido + "','" + contraseña + "');";
	objSentencia->ExecuteNonQuery();
	cerrarConexion();
}

void UsuarioController::actualizarUsuario(int codigo, int nivelAcceso, String^ nombre, String^ apellido, String^ contraseña) {
	abrirConexion();
	/*SqlCommand viene a ser el objeto que utilizare para hacer el query o sentencia para la BD*/
	SqlCommand^ objSentencia = gcnew SqlCommand();
	/*Aqui estoy indicando que mi sentencia se va a ejecutar en mi conexion de BD*/
	objSentencia->Connection = this->objConexion;
	/*Aqui voy a indicar la sentencia que voy a ejecutar*/
	objSentencia->CommandText = "update Usuario set codigo=" + codigo + ", nivelAcceso=" + nivelAcceso + ", nombre='" + nombre + "', apellido='" + apellido + "', password='" + contraseña + "' where codigo=" + codigo;
	objSentencia->ExecuteNonQuery();
	cerrarConexion();
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



