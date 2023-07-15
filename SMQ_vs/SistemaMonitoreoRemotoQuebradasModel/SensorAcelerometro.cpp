#include "SensorAcelerometro.h"

using namespace SistemaMonitoreoRemotoQuebradasModel;

SensorAcelerometro::SensorAcelerometro() {

}

SensorAcelerometro::SensorAcelerometro(int id, int nodoAsociado, double ultimaLecturaX, double ultimaLecturaY, double ultimaLecturaZ) {
	this->id = id;
	this->nodoAsociado = nodoAsociado;
	this->ultimaLecturaX = ultimaLecturaX;
	this->ultimaLecturaY = ultimaLecturaY;
	this->ultimaLecturaZ = ultimaLecturaZ;

}
int SensorAcelerometro::getId() {
	return this->id;
}
void SensorAcelerometro::setId(int id) {
	this->id = id;
}
int SensorAcelerometro::getIdNodo() {
	return this->nodoAsociado;
}
void SensorAcelerometro::setIdNodo(int id) {
	this->nodoAsociado = id;
}
void SensorAcelerometro::setAccX(double accX) {
	this->ultimaLecturaX = accX;
}
void SensorAcelerometro::setAccY(double accY) {
	this->ultimaLecturaY = accY;
}
void SensorAcelerometro::setAccZ(double accZ) {
	this->ultimaLecturaZ = accZ;
}
double SensorAcelerometro::getAccX() {
	return this->ultimaLecturaX;
}
double SensorAcelerometro::getAccY() {
	return this->ultimaLecturaY;
}
double SensorAcelerometro::getAccZ() {
	return this->ultimaLecturaZ;
}
