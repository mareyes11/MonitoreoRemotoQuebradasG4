#include "AlertaFueraVN.h"

using namespace SistemaMonitoreoRemotoQuebradasModel;

AlertaFueraVN::AlertaFueraVN() {

}

AlertaFueraVN::AlertaFueraVN(int codigo, int idNodo, int idSensor, String^ fecha) {
	this->codigo = codigo;
	this->idNodo = idNodo;
	this->idSensor = idSensor;
	this->fecha = fecha;

}