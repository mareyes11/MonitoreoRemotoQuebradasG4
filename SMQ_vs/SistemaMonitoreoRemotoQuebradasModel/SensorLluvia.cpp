#include "SensorLluvia.h"

using namespace SistemaMonitoreoRemotoQuebradasModel;

SensorLluvia::SensorLluvia() {

}

SensorLluvia::SensorLluvia(int id, int nodoAsociado, int ultimaLectura) {
	this->id = id;
	this->nodoAsociado = nodoAsociado;
	this->ultimaLectura = ultimaLectura;

}
int SensorLluvia::getId() {
	return this->id;
}
void SensorLluvia::setId(int id) {
	this->id = id;
}
int SensorLluvia::getIdNodo() {
	return this->nodoAsociado;
}
void SensorLluvia::setIdNodo(int id) {
	this->nodoAsociado = id;
}
void SensorLluvia::setValor(int lluvia) {
	this->ultimaLectura = lluvia;
}
int SensorLluvia::getValor() {
	return this->ultimaLectura;
}