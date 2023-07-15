#include "QuebradaController.h"

using namespace SistemaMonitoreoRemotoQuebradasController;
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO; /*Contiene la definicion de la clase File*/

QuebradaController::QuebradaController(){
	this->objConexion = gcnew SqlConnection();
}

void QuebradaController::abrirConexion() {
	/*Cadena de conexion: Servidor de BD, usuario de BD, password BD, nombre de la BD*/
	this->objConexion->ConnectionString = "Server=200.16.7.140;DataBase=a20180282;User Id=a20180282;Password=XaJ2fSGG";
	this->objConexion->Open(); /*Apertura de la conexion a BD*/
}

void QuebradaController::cerrarConexion() {
	this->objConexion->Close(); /*Cierra la conexion a BD*/
}

List<Quebrada^>^ QuebradaController::buscarTodasQuebradas() {
	List<Quebrada^>^ listaQuebradasEncontradas = gcnew List<Quebrada^>();
	abrirConexion();
	/*SqlCommand viene a ser el objeto que utilizare para hacer el query o sentencia para la BD*/
	SqlCommand^ objSentencia = gcnew SqlCommand();
	/*Aqui estoy indicando que mi sentencia se va a ejecutar en mi conexion de BD*/
	objSentencia->Connection = this->objConexion;
	/*Aqui voy a indicar la sentencia que voy a ejecutar*/
	objSentencia->CommandText = "select * from Quebrada;";
	/*Aqui ejecuto la sentencia en la Base de Datos*/
	/*Para Select siempre sera ExecuteReader*/
	/*Para select siempre va a devolver un SqlDataReader*/
	SqlDataReader^ objData = objSentencia->ExecuteReader();
	while (objData->Read()) {
		int codigo = safe_cast<int>(objData[0]);
		String^ nombre = safe_cast<String^>(objData[1]);
		double posX = safe_cast<float>(objData[2]);
		double posY = safe_cast<float>(objData[3]);
		double rad = safe_cast<float>(objData[4]);
		String^ fechaCreacion = safe_cast<String^>(objData[5]);
		Quebrada^ objQuebrada = gcnew Quebrada(codigo, nombre, posX, posY, rad, fechaCreacion);
		listaQuebradasEncontradas->Add(objQuebrada);
	}
	cerrarConexion();
	return listaQuebradasEncontradas;
}
Quebrada^ QuebradaController::buscarQuebradaXNombre(String^ nombreQuebrada) {
	Quebrada^ objQuebradaRetornar = gcnew Quebrada();
	abrirConexion();
	/*SqlCommand viene a ser el objeto que utilizare para hacer el query o sentencia para la BD*/
	SqlCommand^ objSentencia = gcnew SqlCommand();
	/*Aqui estoy indicando que mi sentencia se va a ejecutar en mi conexion de BD*/
	objSentencia->Connection = this->objConexion;
	/*Aqui voy a indicar la sentencia que voy a ejecutar*/
	objSentencia->CommandText = "select * from Quebrada where nombre = '" + nombreQuebrada + "';";
	/*Aqui ejecuto la sentencia en la Base de Datos*/
	/*Para Select siempre sera ExecuteReader*/
	/*Para select siempre va a devolver un SqlDataReader*/
	SqlDataReader^ objData = objSentencia->ExecuteReader();
	while (objData->Read()) {
		int codigo = safe_cast<int>(objData[0]);
		String^ nombre = safe_cast<String^>(objData[1]);
		double posX = safe_cast<float>(objData[2]);
		double posY = safe_cast<float>(objData[3]);
		double rad = safe_cast<float>(objData[4]);
		String^ fechaCreacion = safe_cast<String^>(objData[5]);
		objQuebradaRetornar = gcnew Quebrada(codigo, nombre, posX, posY, rad, fechaCreacion);
	}
	cerrarConexion();
	return objQuebradaRetornar;
}
Quebrada^ QuebradaController::buscarQuebradaXCodigo(int codigoQuebrada) {
	Quebrada^ objQuebradaRetornar = gcnew Quebrada();
	abrirConexion();
	/*SqlCommand viene a ser el objeto que utilizare para hacer el query o sentencia para la BD*/
	SqlCommand^ objSentencia = gcnew SqlCommand();
	/*Aqui estoy indicando que mi sentencia se va a ejecutar en mi conexion de BD*/
	objSentencia->Connection = this->objConexion;
	/*Aqui voy a indicar la sentencia que voy a ejecutar*/
	objSentencia->CommandText = "select * from Quebrada where codigo = " + codigoQuebrada + ";";
	/*Aqui ejecuto la sentencia en la Base de Datos*/
	/*Para Select siempre sera ExecuteReader*/
	/*Para select siempre va a devolver un SqlDataReader*/
	SqlDataReader^ objData = objSentencia->ExecuteReader();
	while (objData->Read()) {
		int codigo = safe_cast<int>(objData[0]);
		String^ nombre = safe_cast<String^>(objData[1]);
		double posX = safe_cast<float>(objData[2]);
		double posY = safe_cast<float>(objData[3]);
		double rad = safe_cast<float>(objData[4]);
		String^ fechaCreacion = safe_cast<String^>(objData[5]);
		objQuebradaRetornar = gcnew Quebrada(codigo, nombre, posX, posY, rad, fechaCreacion);
	}
	cerrarConexion();
	return objQuebradaRetornar;
}

List<Quebrada^>^ QuebradaController::buscarQuebradasxNombxId(String^ nombreQuebrada, String^ codigoQuebrada) {
	List<Quebrada^>^ listaQuebradasEncontradas = gcnew List<Quebrada^>();
	abrirConexion();
	/*SqlCommand viene a ser el objeto que utilizare para hacer el query o sentencia para la BD*/
	SqlCommand^ objSentencia = gcnew SqlCommand();
	/*Aqui estoy indicando que mi sentencia se va a ejecutar en mi conexion de BD*/
	objSentencia->Connection = this->objConexion;
	/*Aqui voy a indicar la sentencia que voy a ejecutar*/
	if (codigoQuebrada != ("")) {
		objSentencia->CommandText = "select * from Quebrada where codigo = " + codigoQuebrada + ";";
	}
	else objSentencia->CommandText = "select * from Quebrada where nombre like '" + nombreQuebrada + "%';";
	/*Aqui ejecuto la sentencia en la Base de Datos*/
	/*Para Select siempre sera ExecuteReader*/
	/*Para select siempre va a devolver un SqlDataReader*/
	SqlDataReader^ objData = objSentencia->ExecuteReader();
	while (objData->Read()) {
		int codigo = safe_cast<int>(objData[0]);
		String^ nombre = safe_cast<String^>(objData[1]);
		double posX = safe_cast<float>(objData[2]);
		double posY = safe_cast<float>(objData[3]);
		double rad = safe_cast<float>(objData[4]);
		String^ fechaCreacion = safe_cast<String^>(objData[5]);
		Quebrada^ objQuebrada = gcnew Quebrada(codigo, nombre, posX, posY, rad, fechaCreacion);
		listaQuebradasEncontradas->Add(objQuebrada);
	}
	cerrarConexion();
	return listaQuebradasEncontradas;
}
void QuebradaController::eliminarQuebrada(int codigoQuebradaEliminar) {
	abrirConexion();
	/*SqlCommand viene a ser el objeto que utilizare para hacer el query o sentencia para la BD*/
	SqlCommand^ objSentencia = gcnew SqlCommand();
	/*Aqui estoy indicando que mi sentencia se va a ejecutar en mi conexion de BD*/
	objSentencia->Connection = this->objConexion;
	/*Aqui voy a indicar la sentencia que voy a ejecutar*/
	objSentencia->CommandText = "delete from Quebrada where codigo = " + codigoQuebradaEliminar + ";";
	objSentencia->ExecuteNonQuery();
	cerrarConexion();
}

void QuebradaController::EditarQuebrada(Quebrada^ objQuebrada) {
	abrirConexion();
	/*SqlCommand viene a ser el objeto que utilizare para hacer el query o sentencia para la BD*/
	SqlCommand^ objSentencia = gcnew SqlCommand();
	/*Aqui estoy indicando que mi sentencia se va a ejecutar en mi conexion de BD*/
	objSentencia->Connection = this->objConexion;
	/*Aqui voy a indicar la sentencia que voy a ejecutar*/
	objSentencia->CommandText = "update Quebrada set nombre='" + objQuebrada->getNombre() + "', posicionX=" + objQuebrada->getPosicionX() + ", posicionY=" + objQuebrada->getPosicionY() + ", radioExtencion=" + objQuebrada->getRadioExtension() + ", fechaCreacion='" + objQuebrada->getFechaCreacion() + "' where codigo=" + objQuebrada->getCodigo();
	objSentencia->ExecuteNonQuery();
	cerrarConexion();
}

void QuebradaController::AgregarQuebrada(Quebrada^ objQuebrada) {
	abrirConexion();
	/*SqlCommand viene a ser el objeto que utilizare para hacer el query o sentencia para la BD*/
	SqlCommand^ objSentencia = gcnew SqlCommand();
	/*Aqui estoy indicando que mi sentencia se va a ejecutar en mi conexion de BD*/
	objSentencia->Connection = this->objConexion;
	/*Aqui voy a indicar la sentencia que voy a ejecutar*/
	objSentencia->CommandText = "insert into Quebrada(nombre, posicionX, posicionY, radioExtencion, fechaCreacion) values ('" + objQuebrada->getNombre() + "';" + objQuebrada->getPosicionX() + ";" + objQuebrada->getPosicionY() + ";" + objQuebrada->getRadioExtension() + ";'" + objQuebrada->getFechaCreacion() + "');";
	objSentencia->ExecuteNonQuery();
	cerrarConexion();
}

int QuebradaController::getCodigoQuebradaDisponible() {
	List<Quebrada^>^ listaQuebradasTemp = buscarTodasQuebradas();
	int codigoPrueba = 1;
	Boolean existeCodigo = false;
	do {
		for (int i = 0; i < listaQuebradasTemp->Count; i++) {
			if (codigoPrueba == listaQuebradasTemp[i]->getCodigo()) {
				existeCodigo = true;
			}
		}
		if (existeCodigo) {
			codigoPrueba++;
			existeCodigo = false;
		}
		else break;
			
	} while (!existeCodigo);
	
	return codigoPrueba;
}
