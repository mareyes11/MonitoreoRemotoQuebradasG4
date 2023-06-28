#include "Usuario.h"

using namespace SistemaMonitoreoRemotoQuebradasModel;

Usuario::Usuario() {

}

Usuario::Usuario(int codigo, int nivelAcceso, String^ nombre, String^ apellido, String^ password) {
	this->codigo = codigo;
	this->nivelAcceso = nivelAcceso;
	this->nombre = nombre;
	this->apellido = apellido;
	this->password = password;

}
int Usuario::getCodigo() {
	return this->codigo;
}
void Usuario::setCodigo(int codigo) {
	this->codigo = codigo;
}
int Usuario::getNivelAcceso() {
	return this->nivelAcceso;
}
void Usuario::setNivelAcceso(int nivel) {
	this->nivelAcceso = nivel;
}
String^ Usuario::getNombre() {
	return this->nombre;
}
void Usuario::setNombre(String^ nombre) {
	this->nombre = nombre;
}
String^ Usuario::getApellido() {
	return this->apellido;
}
void Usuario::setApellido(String^ apellido) {
	this->apellido = apellido;
}
String^ Usuario::getPassword() {
	return this->password;
}
void Usuario::setPassword(String^ password) {
	this->password = password;
}
