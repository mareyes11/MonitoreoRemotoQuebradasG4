#include "SensorTempNodo.h"

using namespace SistemaMonitoreoRemotoQuebradasModel;

SensorTempNodo::SensorTempNodo() {

}
SensorTempNodo::SensorTempNodo(int id, int idNodo, double ultimaLectura_degC) {
	this->id = id;
	this->idNodo = idNodo;
	this->ultimaLectura_degC = ultimaLectura_degC;
}