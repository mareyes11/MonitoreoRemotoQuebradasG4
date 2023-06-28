#include "SensorNivelAgua.h"

using namespace SistemaMonitoreoRemotoQuebradasModel;

SensorNivelAgua::SensorNivelAgua() {

}

SensorNivelAgua::SensorNivelAgua(int id, int idNodo, double ultimaLectura_cm) {
	this->id = id;
	this->idNodo = idNodo;
	this->ultimaLectura_cm = idNodo;
}