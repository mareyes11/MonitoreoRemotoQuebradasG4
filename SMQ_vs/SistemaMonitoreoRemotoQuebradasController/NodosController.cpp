#include "NodosController.h"

using namespace SistemaMonitoreoRemotoQuebradasController;
//using namespace SistemaMonitoreoRemotoQuebradasModel;
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO; /*Contiene la definicion de la clase File*/

NodosController::NodosController() {

}
List<NodoMonitoreo^>^ NodosController::buscarTodosNodos() {
	/*En esta lista vamos a colocar la información de las carreras que encontremos en el archivo de texto*/
	List<NodoMonitoreo^>^ listaNodosEncontrados = gcnew List<NodoMonitoreo^>();
	array<String^>^ lineas = File::ReadAllLines("Nodos.txt");
	String^ separadores = ";"; /*Aqui defino el caracter por el cual voy a separar la informacion de cada linea*/
	for each (String ^ lineaNodos in lineas) {
		array<String^>^ datos = lineaNodos->Split(separadores->ToCharArray());
		int idNodo = Convert::ToInt32(datos[0]);
		double ubicacionX = Convert::ToDouble(datos[1]);
		double ubicacionY = Convert::ToDouble(datos[2]);
		int idQuebrada = Convert::ToInt32(datos[3]);
		String^ comPort = datos[4];
		String^ fechaCreacion = datos[5];
		NodoMonitoreo^ objNodo = gcnew NodoMonitoreo(idNodo, ubicacionX, ubicacionY, idQuebrada, comPort, fechaCreacion);
		listaNodosEncontrados->Add(objNodo);
	}
	return listaNodosEncontrados;
}

NodoMonitoreo^ NodosController::buscarNodoXId(int id) {
	List<NodoMonitoreo^>^ listaNodosTemp = buscarTodosNodos();
	NodoMonitoreo^ objNodo = gcnew NodoMonitoreo();
	objNodo->setId(-1);
	for (int i = 0; i < listaNodosTemp->Count; i++) {
		if (listaNodosTemp[i]->getId() == id) {
			/*Aqui lo encontre*/
			objNodo->setId(listaNodosTemp[i]->getId());
			objNodo->setPosicionX(listaNodosTemp[i]->getPosicionX());
			objNodo->setPosicionY(listaNodosTemp[i]->getPosicionY());
			objNodo->setQuebradaId(listaNodosTemp[i]->getQuebradaId());
			objNodo->setCOMPort(listaNodosTemp[i]->getCOMPort());
			objNodo->setFechaCreacion(listaNodosTemp[i]->getFechaCreacion());
			break;
		}
	}
	return objNodo;
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
		lineasArchivo[i] = objNodo->getId() + ";" + objNodo->getPosicionX() + ";" + objNodo->getPosicionY() + ";" + objNodo->getQuebradaId() + ";" + objNodo->getCOMPort() + ";" + objNodo->getFechaCreacion();
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
			objNodo->setCOMPort(NodoEditado->getCOMPort());
			objNodo->setQuebradaId(NodoEditado->getQuebradaId());

		}
		lineasArchivo[i] = objNodo->getId() + ";" + objNodo->getPosicionX() + ";" + objNodo->getPosicionY() + ";" + objNodo->getQuebradaId() + ";"+ objNodo->getCOMPort() + ";"+ objNodo->getFechaCreacion();
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