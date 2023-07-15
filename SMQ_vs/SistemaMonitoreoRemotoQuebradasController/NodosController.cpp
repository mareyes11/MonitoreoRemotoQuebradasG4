#include "NodosController.h"

using namespace SistemaMonitoreoRemotoQuebradasController;
//using namespace SistemaMonitoreoRemotoQuebradasModel;
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO; /*Contiene la definicion de la clase File*/

NodosController::NodosController() {
	this->objConexion = gcnew SqlConnection();
}

void NodosController::abrirConexion() {
	/*Cadena de conexion: Servidor de BD, usuario de BD, password BD, nombre de la BD*/
	this->objConexion->ConnectionString = "Server=200.16.7.140;DataBase=a20180282;User Id=a20180282;Password=XaJ2fSGG";
	this->objConexion->Open(); /*Apertura de la conexion a BD*/
}

void NodosController::cerrarConexion() {
	this->objConexion->Close(); /*Cierra la conexion a BD*/
}

List<NodoMonitoreo^>^ NodosController::buscarTodosNodos() {
	List<NodoMonitoreo^>^ listaNodosEncontrados = gcnew List<NodoMonitoreo^>();
	abrirConexion();
	/*SqlCommand viene a ser el objeto que utilizare para hacer el query o sentencia para la BD*/
	SqlCommand^ objSentencia = gcnew SqlCommand();
	/*Aqui estoy indicando que mi sentencia se va a ejecutar en mi conexion de BD*/
	objSentencia->Connection = this->objConexion;
	/*Aqui voy a indicar la sentencia que voy a ejecutar*/
	objSentencia->CommandText = "select * from Nodo;";
	/*Aqui ejecuto la sentencia en la Base de Datos*/
	/*Para Select siempre sera ExecuteReader*/
	/*Para select siempre va a devolver un SqlDataReader*/
	SqlDataReader^ objData = objSentencia->ExecuteReader();
	while (objData->Read()) {
		int codigo = safe_cast<int>(objData[0]);
		double posX = safe_cast<float>(objData[1]);
		double posY = safe_cast<float>(objData[2]);
		int idQuebrada = safe_cast<int>(objData[3]);
		String^ COMPort = safe_cast<String^>(objData[4]);
		String^ fechaCreacion = safe_cast<String^>(objData[5]);
		NodoMonitoreo^ objNodo = gcnew NodoMonitoreo(codigo, posX, posY, idQuebrada, COMPort, fechaCreacion);
		listaNodosEncontrados->Add(objNodo);
	}
	cerrarConexion();
	return listaNodosEncontrados;
}

NodoMonitoreo^ NodosController::buscarNodoXId(int id) {
	NodoMonitoreo^ objNodoRetornar = nullptr;
	abrirConexion();
	/*SqlCommand viene a ser el objeto que utilizare para hacer el query o sentencia para la BD*/
	SqlCommand^ objSentencia = gcnew SqlCommand();
	/*Aqui estoy indicando que mi sentencia se va a ejecutar en mi conexion de BD*/
	objSentencia->Connection = this->objConexion;
	/*Aqui voy a indicar la sentencia que voy a ejecutar*/
	objSentencia->CommandText = "select * from Nodo where id = " + id + ";";
	/*Aqui ejecuto la sentencia en la Base de Datos*/
	/*Para Select siempre sera ExecuteReader*/
	/*Para select siempre va a devolver un SqlDataReader*/
	SqlDataReader^ objData = objSentencia->ExecuteReader();
	while (objData->Read()) {
		int codigo = safe_cast<int>(objData[0]);
		double posX = safe_cast<float>(objData[1]);
		double posY = safe_cast<float>(objData[2]);
		int idQuebrada = safe_cast<int>(objData[3]);
		String^ COMPort = safe_cast<String^>(objData[4]);
		String^ fechaCreacion = safe_cast<String^>(objData[5]);
		objNodoRetornar = gcnew NodoMonitoreo(codigo, posX, posY, idQuebrada, COMPort, fechaCreacion);
	}
	cerrarConexion();
	return objNodoRetornar;
}

List<NodoMonitoreo^>^ NodosController::buscarNodoxIdQuebrada(int idQuebrada) {
	List<NodoMonitoreo^>^ listaNodosEncontrados = gcnew List<NodoMonitoreo^>();
	abrirConexion();
	/*SqlCommand viene a ser el objeto que utilizare para hacer el query o sentencia para la BD*/
	SqlCommand^ objSentencia = gcnew SqlCommand();
	/*Aqui estoy indicando que mi sentencia se va a ejecutar en mi conexion de BD*/
	objSentencia->Connection = this->objConexion;
	/*Aqui voy a indicar la sentencia que voy a ejecutar*/
	objSentencia->CommandText = "select * from Nodo where idQuebrada = " + idQuebrada + ";";
	/*Aqui ejecuto la sentencia en la Base de Datos*/
	/*Para Select siempre sera ExecuteReader*/
	/*Para select siempre va a devolver un SqlDataReader*/
	SqlDataReader^ objData = objSentencia->ExecuteReader();
	while (objData->Read()) {
		int codigo = safe_cast<int>(objData[0]);
		double posX = safe_cast<float>(objData[1]);
		double posY = safe_cast<float>(objData[2]);
		int idQuebrada = safe_cast<int>(objData[3]);
		String^ COMPort = safe_cast<String^>(objData[4]);
		String^ fechaCreacion = safe_cast<String^>(objData[5]);
		NodoMonitoreo^ objNodo = gcnew NodoMonitoreo(codigo, posX, posY, idQuebrada, COMPort, fechaCreacion);
		listaNodosEncontrados->Add(objNodo);
	}
	cerrarConexion();
	return listaNodosEncontrados;
}

void NodosController::eliminarNodo(int idNodoEliminar) {
	abrirConexion();
	/*SqlCommand viene a ser el objeto que utilizare para hacer el query o sentencia para la BD*/
	SqlCommand^ objSentencia = gcnew SqlCommand();
	/*Aqui estoy indicando que mi sentencia se va a ejecutar en mi conexion de BD*/
	objSentencia->Connection = this->objConexion;
	/*Aqui voy a indicar la sentencia que voy a ejecutar*/
	objSentencia->CommandText = "delete from Nodo where codigo = " + idNodoEliminar + ";";
	objSentencia->ExecuteNonQuery();
	cerrarConexion();
}

void NodosController::agregarNodo(NodoMonitoreo^ objNodo) {
	abrirConexion();
	/*SqlCommand viene a ser el objeto que utilizare para hacer el query o sentencia para la BD*/
	SqlCommand^ objSentencia = gcnew SqlCommand();
	/*Aqui estoy indicando que mi sentencia se va a ejecutar en mi conexion de BD*/
	objSentencia->Connection = this->objConexion;
	/*Aqui voy a indicar la sentencia que voy a ejecutar*/
	objSentencia->CommandText = "insert into Nodo(ubicacionX, ubicacionY, idQuebrada, COMPort, fechaCreacion) values (" + objNodo->getPosicionX() + "," + objNodo->getPosicionY() + "," + objNodo->getQuebradaId() + ",'" + objNodo->getCOMPort() + "','" + objNodo->getFechaCreacion() + "');";
	objSentencia->ExecuteNonQuery();
	cerrarConexion();
}

void NodosController::editarNodo(NodoMonitoreo^ NodoEditado) {
	abrirConexion();
	/*SqlCommand viene a ser el objeto que utilizare para hacer el query o sentencia para la BD*/
	SqlCommand^ objSentencia = gcnew SqlCommand();
	/*Aqui estoy indicando que mi sentencia se va a ejecutar en mi conexion de BD*/
	objSentencia->Connection = this->objConexion;
	/*Aqui voy a indicar la sentencia que voy a ejecutar*/
	objSentencia->CommandText = "update Nodo set ubicacionX=" + NodoEditado->getPosicionX() + ", ubicacionY=" + NodoEditado->getPosicionY() + ", idQuebrada=" + NodoEditado->getQuebradaId() + ", COMPort='" + NodoEditado->getCOMPort() + "', fechaCreacion='" + NodoEditado->getFechaCreacion() + "');";
	objSentencia->ExecuteNonQuery();
	cerrarConexion();
}

int NodosController::getIdDisponible() {
	List<NodoMonitoreo^>^ listaNodosTemp = buscarTodosNodos();
	int codigoPrueba = 1;
	Boolean existeCodigo = false;
	do {
		for (int i = 0; i < listaNodosTemp->Count; i++) {
			if (codigoPrueba == listaNodosTemp[i]->getId()) {
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
NodoMonitoreo^ NodosController::cargarDataSensores(String^ tramaDatos, NodoMonitoreo^ nodoACargar) {
	/*Salida datos serial : nodoID | incX_deg | incY_deg | accX_g | accY_g | accZ_g | tBMP_degC | pBMP_Pa | hSoil_raw | rain | alarm */
	array<String^>^ data;
	String^ separador = " ";
	data = tramaDatos->Split(separador->ToCharArray());
		int id = Convert::ToInt32(data[0]);
		double incX = Convert::ToDouble(data[1]);
		double incY = Convert::ToDouble(data[2]);
		double accX = Convert::ToDouble(data[3]);
		double accY = Convert::ToDouble(data[4]);
		double accZ = Convert::ToDouble(data[5]);
		double temp = Convert::ToDouble(data[6]);
		double presion = Convert::ToDouble(data[7]);
		int rawHumedad = Convert::ToInt32(data[8]);
		int lluvia = Convert::ToInt32(data[9]);
		Boolean alarma = Convert::ToInt32(data[10]);
		nodoACargar->setId(id);
		nodoACargar->getSensorInc()->setIncX(incX);
		nodoACargar->getSensorInc()->setIncY(incY);
		nodoACargar->getSensorAcc()->setAccX(accX);
		nodoACargar->getSensorAcc()->setAccY(accY);
		nodoACargar->getSensorAcc()->setAccZ(accZ);
		nodoACargar->getSensorTemperatura()->setTemperatura(temp);
		nodoACargar->getSensorNivelAgua()->setPresion_hPa(presion);
		nodoACargar->getSensorHumedad()->setRawLectura(rawHumedad);
		nodoACargar->getSensorLluvia()->setValor(lluvia);
		nodoACargar->setAlarmaEstado(alarma);
	return nodoACargar;
}