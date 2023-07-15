#include "SensorTempNodo.h"

using namespace SistemaMonitoreoRemotoQuebradasModel;

SensorTempNodo::SensorTempNodo() {

}
SensorTempNodo::SensorTempNodo(int id, int idNodo, double ultimaLectura_degC) {
	this->id = id;
	this->idNodo = idNodo;
	this->ultimaLectura_degC = ultimaLectura_degC;
}
int SensorTempNodo::getId() {
	return this->id;
}
void SensorTempNodo::setId(int id) {
	this->id = id;
}
int SensorTempNodo::getIdNodo() {
	return this->idNodo;
}
void SensorTempNodo::setIdNodo(int id) {
	this->idNodo = id;
}
void SensorTempNodo::setTemperatura(double temperaturaSensor) {
	this->ultimaLectura_degC = temperaturaSensor;
}
double SensorTempNodo::getTemperatura() {
	return this->ultimaLectura_degC;
}