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