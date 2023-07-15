#include "NodoMonitoreo.h"

using namespace SistemaMonitoreoRemotoQuebradasModel;

NodoMonitoreo::NodoMonitoreo() {

}

NodoMonitoreo::NodoMonitoreo(int id, double ubicacionX, double ubicacionY, int idQuebrada, String^ fechaCreacion, SensorNivelAgua^ objSensorNiv, SensorTempNodo^ objSensorTem, SensorLluvia^ objSensorLlu, SensorInclinacion^ objSensorInc, SensorHumedad^ objSensorHum, SensorAcelerometro^ objSensorAce) {
	this->id = id;
	this->ubicacionX = ubicacionX;
	this->ubicacionY = ubicacionY;
	this->idQuebrada = idQuebrada;
	this->fechaCreacion = fechaCreacion;
	this->objSensorAce = objSensorAce;
	this->objSensorHum = objSensorHum;
	this->objSensorInc = objSensorInc;
	this->objSensorLlu = objSensorLlu;
	this->objSensorTem = objSensorTem;
	this->objSensorNiv = objSensorNiv;
}
NodoMonitoreo::NodoMonitoreo(int id, double ubicacionX, double ubicacionY, int idQuebrada, String^ COMPort, String^ fechaCreacion) {
	this->id = id;
	this->ubicacionX = ubicacionX;
	this->ubicacionY = ubicacionY;
	this->idQuebrada = idQuebrada;
	this->COMPort = COMPort;
	this->fechaCreacion = fechaCreacion;
}
int NodoMonitoreo::getId() {
	return this->id;
}
void NodoMonitoreo::setId(int id) {
	this->id = id;
}

double NodoMonitoreo::getPosicionX() {
	return this->ubicacionX;
}
void NodoMonitoreo::setPosicionX(double posicionX) {
	this->ubicacionX = posicionX;
}
double NodoMonitoreo::getPosicionY() {
	return this->ubicacionY;
}
void NodoMonitoreo::setPosicionY(double posicionY) {
	this->ubicacionY = posicionY;
}
int NodoMonitoreo::getQuebradaId() {
	return this->idQuebrada;
}
void NodoMonitoreo::setQuebradaId(int idQuebrada) {
	this->idQuebrada = idQuebrada;
}
String^ NodoMonitoreo::getCOMPort() {
	return this->COMPort;
}
void NodoMonitoreo::setCOMPort(String^ COMPort) {
	this->COMPort = COMPort;
}

String^ NodoMonitoreo::getFechaCreacion() {
	return this->fechaCreacion;
}
void NodoMonitoreo::setFechaCreacion(String^ fechaCreacion) {
	this->fechaCreacion = fechaCreacion;
}
Boolean NodoMonitoreo::getAlarmaEstado() {
	return this->alarmaActivada;
}
void NodoMonitoreo::setAlarmaEstado(Boolean alarmaActivada) {
	this->alarmaActivada = alarmaActivada;
}
SensorAcelerometro^ NodoMonitoreo::getSensorAcc() {
	return this->objSensorAce;
}
SensorHumedad^ NodoMonitoreo::getSensorHumedad() {
	return this->objSensorHum;
}
SensorInclinacion^  NodoMonitoreo::getSensorInc() {
	return this->objSensorInc;
}
SensorLluvia^  NodoMonitoreo::getSensorLluvia() {
	return this->objSensorLlu;
}
SensorNivelAgua^ NodoMonitoreo::getSensorNivelAgua() {
	return this->objSensorNiv;
}
SensorTempNodo^ NodoMonitoreo::getSensorTemperatura() {
	return this->objSensorTem;
}