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
		String^ fechaCreacion = safe_cast<String^>(objData[4]);
		NodoMonitoreo^ objNodo = gcnew NodoMonitoreo(codigo, posX, posY, idQuebrada, fechaCreacion);
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
		String^ fechaCreacion = safe_cast<String^>(objData[4]);
		objNodoRetornar = gcnew NodoMonitoreo(codigo, posX, posY, idQuebrada, fechaCreacion);
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
		String^ fechaCreacion = safe_cast<String^>(objData[4]);
		NodoMonitoreo^ objNodo = gcnew NodoMonitoreo(codigo, posX, posY, idQuebrada, fechaCreacion);
		listaNodosEncontrados->Add(objNodo);
	}
	cerrarConexion();
	return listaNodosEncontrados;
}

void NodosController::eliminarNodo(int idNodoEliminar) {
	List<NodoMonitoreo^>^ listaNodosTemp = buscarTodosNodos();
	for (int i = 0; i < listaNodosTemp->Count; i++) {
		NodoMonitoreo^ objNodo = listaNodosTemp[i];
		if (objNodo->getId() == idNodoEliminar) {
			listaNodosTemp->RemoveAt(i);
			break;
		}
	}
	escribirArchivoNodos(listaNodosTemp);
}
void NodosController::escribirArchivoNodos(List<NodoMonitoreo^>^ ListaNodos) {
	array<String^>^ lineasArchivo = gcnew array<String^>(ListaNodos->Count);
	for (int i = 0; i < ListaNodos->Count; i++) {
		NodoMonitoreo^ objNodo = ListaNodos[i];
		lineasArchivo[i] = objNodo->getId() + ";" + objNodo->getPosicionX() + ";" + objNodo->getPosicionY() + ";" + objNodo->getQuebradaId() + ";" + objNodo->getFechaCreacion();
	}
	File::WriteAllLines("Nodos.txt", lineasArchivo);
}
void NodosController::escribirArchivoNodoEditado(NodoMonitoreo^ NodoEditado) {
	List<NodoMonitoreo^>^ listaTodosNodos = buscarTodosNodos();
	array<String^>^ lineasArchivo = gcnew array<String^>(listaTodosNodos->Count);
	for (int i = 0; i < listaTodosNodos->Count; i++) {
		NodoMonitoreo^ objNodo = listaTodosNodos[i];
		if (objNodo->getId() == NodoEditado->getId()) {
			objNodo->setPosicionX(NodoEditado->getPosicionX());
			objNodo->setPosicionY(NodoEditado->getPosicionY());
			objNodo->setQuebradaId(NodoEditado->getQuebradaId());

		}
		lineasArchivo[i] = objNodo->getId() + ";" + objNodo->getPosicionX() + ";" + objNodo->getPosicionY() + ";" + objNodo->getQuebradaId() + ";" + objNodo->getFechaCreacion();
	}
	File::WriteAllLines("Nodos.txt", lineasArchivo);
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