#include "burbujaNivel.h"

using namespace SistemaMonitoreoRemotoQuebradasModel;

burbujaNivel::burbujaNivel() {

}

burbujaNivel::burbujaNivel(int inicioX, int inicioY, int ancho, int angX, int angY, Color objColor) {
	this->inicioX = inicioX;
	this->inicioY = inicioY;
	this->ancho = ancho;
	this->angX = angX;
	this->angY = angY;
	this->objColor = objColor;
}

int burbujaNivel::getInicioX() {
	return this->inicioX;
}

void burbujaNivel::setInicioX(int inicioX) {
	this->inicioX = inicioX;
}

int burbujaNivel::getInicioY() {
	return this->inicioY;
}

void burbujaNivel::setInicioY(int inicioY) {
	this->inicioY = inicioY;
}

int burbujaNivel::getAncho() {
	return this->ancho;
}

void burbujaNivel::setAncho(int ancho) {
	this->ancho = ancho;
}

int burbujaNivel::getAngX() {
	return this->angX;
}

void burbujaNivel::setAngX(int angX) {
	this->angX = angX;
}

int burbujaNivel::getAngY() {
	return this->angY;
}

void burbujaNivel::setAngY(int angY) {
	this->angY = angY;
}

Color burbujaNivel::getColor() {
	return this->objColor;
}

void burbujaNivel::setColor(Color objColor) {
	this->objColor = objColor;
}