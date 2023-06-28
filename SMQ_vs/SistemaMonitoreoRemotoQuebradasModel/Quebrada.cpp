#include "Quebrada.h"

using namespace SistemaMonitoreoRemotoQuebradasModel;

Quebrada::Quebrada() {
	//no hace nada , constructor
}

Quebrada::Quebrada(int codigo, String^ nombre, double posicionX, double posicionY, double radioExtension, String^ fechaCreacion) {
	this->codigo = codigo;
	this->nombre = nombre;
	this->posicionX = posicionX;
	this->posicionY = posicionY;
	this->radioExtension = radioExtension;
	this->fechaCreacion = fechaCreacion;
}
int Quebrada::getCodigo() {
	return this->codigo;
}
void Quebrada::setCodigo(int codigo) {
	this->codigo = codigo;
}
String^ Quebrada::getNombre() {
	return this->nombre;
}
void Quebrada::setNombre(String^ nombre) {
	this->nombre = nombre;
}
double Quebrada::getPosicionX() {
	return this->posicionX;
}
void Quebrada::setPosicionX(double posicionX) {
	this->posicionX = posicionX;
}
double Quebrada::getPosicionY() {
	return this->posicionY;
}
void Quebrada::setPosicionY(double posicionY) {
	this->posicionY = posicionY;
}
double Quebrada::getRadioExtension() {
	return this->radioExtension;
}
void Quebrada::setRadioExtension(double radioExtension) {
	this->radioExtension = radioExtension;
}
String^ Quebrada::getFechaCreacion() {
	return this->fechaCreacion;
}
void Quebrada::setFechaCreacion(String^ fechaCreacion) {
	this->fechaCreacion = fechaCreacion;
}