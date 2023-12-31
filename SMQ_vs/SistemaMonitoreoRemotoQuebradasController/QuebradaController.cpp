#include "QuebradaController.h"

using namespace SistemaMonitoreoRemotoQuebradasController;
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO; /*Contiene la definicion de la clase File*/

QuebradaController::QuebradaController(){

}
List<Quebrada^>^ QuebradaController::buscarTodasQuebradas() {
	/*En esta lista vamos a colocar la información de las carreras que encontremos en el archivo de texto*/
	List<Quebrada^>^ listaQuebradasEncontradas = gcnew List<Quebrada^>();
	array<String^>^ lineas = File::ReadAllLines("Quebradas.txt");
	String^ separadores = ";"; /*Aqui defino el caracter por el cual voy a separar la informacion de cada linea*/
	for each (String ^ lineaQuebrada in lineas) {
		array<String^>^ datos = lineaQuebrada->Split(separadores->ToCharArray());
		int codigo = Convert::ToInt32(datos[0]);
		String^ nombre = datos[1];
		double ubicacionX = Convert::ToDouble(datos[2]);
		double ubicacionY = Convert::ToDouble(datos[3]);
		double radioExtension = Convert::ToDouble(datos[4]);
		String^ fechaCreacion = datos[5];
		Quebrada^ objQuebrada = gcnew Quebrada(codigo, nombre, ubicacionX, ubicacionY, radioExtension, fechaCreacion);
		listaQuebradasEncontradas->Add(objQuebrada);
	}
	return listaQuebradasEncontradas;
}
List<Quebrada^>^ QuebradaController::buscarQuebradasXNombre(String^ nombreQuebrada) {
	/*En esta lista vamos a colocar la información de las carreras que encontremos en el archivo de texto*/
	List<Quebrada^>^ listaQuebradasEncontradas = gcnew List<Quebrada^>();
	array<String^>^ lineas = File::ReadAllLines("Quebradas.txt");
	String^ separadores = ";"; /*Aqui defino el caracter por el cual voy a separar la informacion de cada linea*/
	for each (String^ lineaQuebrada in lineas) {
		array<String^>^ datos = lineaQuebrada->Split(separadores->ToCharArray());
		int codigo = Convert::ToInt32(datos[0]);
		String^ nombre = datos[1];
		double ubicacionX = Convert::ToDouble(datos[2]);
		double ubicacionY = Convert::ToDouble(datos[3]);
		double radioExtension = Convert::ToDouble(datos[4]);
		String^ fechaCreacion = datos[5];
		if (nombre->Contains(nombreQuebrada)) {
			Quebrada^ objQuebrada = gcnew Quebrada(codigo, nombre, ubicacionX, ubicacionY, radioExtension, fechaCreacion);
			listaQuebradasEncontradas->Add(objQuebrada);
		}
	}
	return listaQuebradasEncontradas;
}
Quebrada^ QuebradaController::buscarQuebradaXCodigo(int codigoQuebrada) {
	/*En esta lista vamos a colocar la información de las carreras que encontremos en el archivo de texto*/
	Quebrada^ QuebradaRetornar = gcnew Quebrada();
	List<Quebrada^>^ listaQuebradasEncontradas = gcnew List<Quebrada^>();
	array<String^>^ lineas = File::ReadAllLines("Quebradas.txt");
	String^ separadores = ";"; /*Aqui defino el caracter por el cual voy a separar la informacion de cada linea*/
	for each (String^ lineaQuebrada in lineas) {
		array<String^>^ datos = lineaQuebrada->Split(separadores->ToCharArray());
		int codigo = Convert::ToInt32(datos[0]);
		String^ nombre = datos[1];
		double ubicacionX = Convert::ToDouble(datos[2]);
		double ubicacionY = Convert::ToDouble(datos[3]);
		double radioExtension = Convert::ToDouble(datos[4]);
		String^ fechaCreacion = datos[5];
		if (codigo == codigoQuebrada) {
			Quebrada^ objQuebrada = gcnew Quebrada(codigo, nombre, ubicacionX, ubicacionY, radioExtension, fechaCreacion);
			listaQuebradasEncontradas->Add(objQuebrada);
		}
	}
	switch (listaQuebradasEncontradas->Count)
	{
	case 0:
		QuebradaRetornar->setCodigo(0);//Indica que no se encontro ninguna Q. con ese codigo
		break;
	case 1:
		QuebradaRetornar = listaQuebradasEncontradas[0];//Si solo se encontro una quebrada con ese codigo, se carga al obj a retornar
		break;
	default:
		QuebradaRetornar->setCodigo(-1);//Si se encuentra mas de una quebrada , se indica con -1 en el id
		break;
	}
	return QuebradaRetornar;
}
List<Quebrada^>^ QuebradaController::buscarQuebradasxNombxId(String^ nombreQuebrada, String^ codigoQuebrada) {
	/*En esta lista vamos a colocar la información de las carreras que encontremos en el archivo de texto*/
	List<Quebrada^>^ listaQuebradasEncontradas = gcnew List<Quebrada^>();
	array<String^>^ lineas = File::ReadAllLines("Quebradas.txt");
	String^ separadores = ";"; /*Aqui defino el caracter por el cual voy a separar la informacion de cada linea*/
	for each (String ^ lineaQuebrada in lineas) {
		array<String^>^ datos = lineaQuebrada->Split(separadores->ToCharArray());
		int codigo = Convert::ToInt32(datos[0]);
		String^ nombre = datos[1];
		double ubicacionX = Convert::ToDouble(datos[2]);
		double ubicacionY = Convert::ToDouble(datos[3]);
		double radioExtension = Convert::ToDouble(datos[4]);
		String^ fechaCreacion = datos[5];
		if (nombre->Contains(nombreQuebrada)) {
			Quebrada^ objQuebrada = gcnew Quebrada(codigo, nombre, ubicacionX, ubicacionY, radioExtension, fechaCreacion);
			listaQuebradasEncontradas->Add(objQuebrada);
		}
	}
	if (codigoQuebrada != ("")) {
		List<Quebrada^>^ listaQuebradasId = gcnew List<Quebrada^>();
		for (int i = 0; i < listaQuebradasEncontradas->Count; i++) {
			if (Convert::ToString(listaQuebradasEncontradas[i]->getCodigo()) == codigoQuebrada) {
				listaQuebradasId->Add(listaQuebradasEncontradas[i]);
				break;
			}
		}
		return listaQuebradasId;
	}
	else
		return listaQuebradasEncontradas;
}
void QuebradaController::eliminarQuebrada(int codigoQuebradaEliminar) {
	List<Quebrada^>^ listaQuebradasTemp = buscarTodasQuebradas();
	for (int i = 0; i < listaQuebradasTemp->Count; i++) {
		Quebrada^ objQuebrada = listaQuebradasTemp[i];
		if (objQuebrada->getCodigo() == codigoQuebradaEliminar) {
			listaQuebradasTemp->RemoveAt(i);
			break;
		}
	}
	escribirArchivoQuebradas(listaQuebradasTemp);
}
void QuebradaController::escribirArchivoQuebradas(List<Quebrada^>^ ListaQuebradas) {
	array<String^>^ lineasArchivo = gcnew array<String^>(ListaQuebradas->Count);
	for (int i = 0; i < ListaQuebradas->Count; i++) {
		Quebrada^ objQuebrada = ListaQuebradas[i];
		lineasArchivo[i] = objQuebrada->getCodigo() + ";" + objQuebrada->getNombre() + ";" + objQuebrada->getPosicionX() +";" + objQuebrada->getPosicionY() + ";" + objQuebrada->getRadioExtension() + ";" +objQuebrada->getFechaCreacion();
	}
	File::WriteAllLines("Quebradas.txt", lineasArchivo);
}
void QuebradaController::escribirArchivoQuebradaEditada(Quebrada^ QuebradaEditada) {
	List<Quebrada^>^ listaTodasQuebradas = buscarTodasQuebradas();
	array<String^>^ lineasArchivo = gcnew array<String^>(listaTodasQuebradas->Count);
	for (int i = 0; i < listaTodasQuebradas->Count; i++) {
		Quebrada^ objQuebrada = listaTodasQuebradas[i];
		if (objQuebrada->getCodigo() == QuebradaEditada->getCodigo()) {
			objQuebrada->setNombre(QuebradaEditada->getNombre());
			objQuebrada->setPosicionX(QuebradaEditada->getPosicionX());
			objQuebrada->setPosicionY(QuebradaEditada->getPosicionY());
			objQuebrada->setRadioExtension(QuebradaEditada->getRadioExtension());
		}
		lineasArchivo[i] = objQuebrada->getCodigo() + ";" + objQuebrada->getNombre() + ";" + objQuebrada->getPosicionX() + ";" + objQuebrada->getPosicionY() + ";" + objQuebrada->getRadioExtension() + ";" + objQuebrada->getFechaCreacion();
	}
	File::WriteAllLines("Quebradas.txt", lineasArchivo);
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
