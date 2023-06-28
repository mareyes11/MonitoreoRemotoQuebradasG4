#include "SensorLluvia.h"

using namespace SistemaMonitoreoRemotoQuebradasModel;

SensorLluvia::SensorLluvia() {

}

SensorLluvia::SensorLluvia(int id, int nodoAsociado, int ultimaLectura) {
	this->id = id;
	this->nodoAsociado = nodoAsociado;
	this->ultimaLectura = ultimaLectura;

}