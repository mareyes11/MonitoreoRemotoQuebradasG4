#include "SensorHumedad.h"

using namespace SistemaMonitoreoRemotoQuebradasModel;

SensorHumedad::SensorHumedad() {

}

SensorHumedad::SensorHumedad(int id, int nodoAsociado, int rawLectura) {
	this->id = id;
	this->nodoAsociado = nodoAsociado;
	this->rawLectura = rawLectura;

}
int SensorHumedad::getId() {
	return this->id;
}
void SensorHumedad::setId(int id) {
	this->id = id;
}
int SensorHumedad::getIdNodo() {
	return this->nodoAsociado;
}
void SensorHumedad::setIdNodo(int id) {
	this->nodoAsociado = id;
}
void SensorHumedad::setRawLectura(int rawLectura) {
	this->rawLectura = rawLectura;
}
int SensorHumedad::getValorCal1() {
	return this->valorCal1;
}
void SensorHumedad::setValorCal1(int valorCal1) {
	this->valorCal1 = valorCal1;
}
int SensorHumedad::getValorCal2() {
	return this->valorCal2;
}
void SensorHumedad::setValorCal2(int valorCal2) {
	this->valorCal2 = valorCal2;
}
double SensorHumedad::getHumedad() {
	float humedadCalibrada = 100.0 / (valorCal2 - valorCal1) * (rawLectura - valorCal2) + 100.0;
	if (humedadCalibrada > 100) humedadCalibrada = 100;
	if (humedadCalibrada < 0) humedadCalibrada = 0;
	return humedadCalibrada;
}