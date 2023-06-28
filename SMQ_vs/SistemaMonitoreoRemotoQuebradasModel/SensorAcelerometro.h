#pragma once

using namespace System;
using namespace System::Collections::Generic;

namespace SistemaMonitoreoRemotoQuebradasModel {

	public ref class SensorAcelerometro {
	private:
		int id;
		int nodoAsociado;
		double ultimaLecturaX;
		double ultimaLecturaY;
		double ultimaLecturaZ;

	public:
		SensorAcelerometro();
		SensorAcelerometro(int id, int nodoAsociado, double ultimaLecturaX, double ultimaLecturaY, double ultimaLecturaZ);
	};
}