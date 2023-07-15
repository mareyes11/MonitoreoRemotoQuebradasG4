#include "SensorInclinacion.h"

using namespace SistemaMonitoreoRemotoQuebradasModel;

SensorInclinacion::SensorInclinacion() {

}

SensorInclinacion::SensorInclinacion(int id, int nodoAsociado, double ultimaLecturaX, double presionCero_hPa) {
	this->id = id;
	this->nodoAsociado = nodoAsociado;
	this->ultimaLecturaX = ultimaLecturaX;
	this->ultimaLecturaY = ultimaLecturaY;

}
int SensorInclinacion::getId() {
	return this->id;
}
void SensorInclinacion::setId(int id) {
	this->id = id;
}
int SensorInclinacion::getIdNodo() {
	return this->nodoAsociado;
}
void SensorInclinacion::setIdNodo(int id) {
	this->nodoAsociado = id;
}
void SensorInclinacion::setIncX(double incX) {
	this->ultimaLecturaX = incX;
}
void SensorInclinacion::setIncY(double incY) {
	this->ultimaLecturaY = incY;
}
double SensorInclinacion::getIncX() {
	return this->ultimaLecturaX;
}
double SensorInclinacion::getIncY() {
	return this->ultimaLecturaY;
}