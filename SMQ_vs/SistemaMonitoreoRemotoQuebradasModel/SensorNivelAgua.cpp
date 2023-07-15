#include "SensorNivelAgua.h"

using namespace SistemaMonitoreoRemotoQuebradasModel;

SensorNivelAgua::SensorNivelAgua() {

}

SensorNivelAgua::SensorNivelAgua(int id, int idNodo, double presionCero_hPa) {
	this->id = id;
	this->idNodo = idNodo;
	this->presionCero_hPa = presionCero_hPa;
}
int SensorNivelAgua::getId() {
	return this->id;
}
void SensorNivelAgua::setId(int id) {
	this->id = id;
}
int SensorNivelAgua::getIdNodo() {
	return this->idNodo;
}
void SensorNivelAgua::setIdNodo(int id) {
	this->idNodo = id;
}
void SensorNivelAgua::setPresionCero_hPa(double presionCero_hPa) {
	this->presionCero_hPa = presionCero_hPa;
}
void SensorNivelAgua::setPresion_hPa(double presion_hPa) {
	this->presion_hPa = presion_hPa;
}

double SensorNivelAgua::getPresion_hPa() {
	return this->presion_hPa;
}
double SensorNivelAgua::getColumnaAgua_cm() {
	double columnaAgua = ((presion_hPa - presionCero_hPa) / 0.098)/100;
	if (columnaAgua < 0) columnaAgua = 0;
	return this->columnaAgua_cm;
}