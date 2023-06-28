#pragma once

using namespace System;
using namespace System::Collections::Generic;

namespace SistemaMonitoreoRemotoQuebradasModel {

	public ref class SensorInclinacion{
	private:
		int id;
		int nodoAsociado;
		double ultimaLecturaX;
		double ultimaLecturaY;

	public:
		SensorInclinacion();
		SensorInclinacion(int id, int nodoAsociado, double ultimaLecturaX, double ultimaLecturaY);
	};
}