#include "SensorHumedad.h"

using namespace SistemaMonitoreoRemotoQuebradasModel;

SensorHumedad::SensorHumedad() {

}

SensorHumedad::SensorHumedad(int id, int nodoAsociado, double ultimaLectura) {
	this->id = id;
	this->nodoAsociado = nodoAsociado;
	this->ultimaLectura = ultimaLectura;

}