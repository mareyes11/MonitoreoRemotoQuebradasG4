#include "SensorInclinacion.h"

using namespace SistemaMonitoreoRemotoQuebradasModel;

SensorInclinacion::SensorInclinacion() {

}

SensorInclinacion::SensorInclinacion(int id, int nodoAsociado, double ultimaLecturaX, double ultimaLecturaY) {
	this->id = id;
	this->nodoAsociado = nodoAsociado;
	this->ultimaLecturaX = ultimaLecturaX;
	this->ultimaLecturaY = ultimaLecturaY;

}