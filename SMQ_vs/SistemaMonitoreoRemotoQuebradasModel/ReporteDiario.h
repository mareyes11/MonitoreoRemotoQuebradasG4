#pragma once
using namespace System;

namespace SistemaMonitoreoRemotoQuebradasModel {
	public ref class ReporteDiario {
	private:
		String^ fecha;
		int codigoQuebrada;

	public:
		ReporteDiario();
		ReporteDiario(String^ fecha, int codigoQuebrada);

	};

}
