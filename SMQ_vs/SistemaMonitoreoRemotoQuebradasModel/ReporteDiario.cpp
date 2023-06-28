#include "ReporteDiario.h"

using namespace SistemaMonitoreoRemotoQuebradasModel;

ReporteDiario::ReporteDiario() {

}
ReporteDiario::ReporteDiario(String^ fecha, int codigoQuebrada) {
	this->fecha = fecha;
	this->codigoQuebrada = codigoQuebrada;
}
