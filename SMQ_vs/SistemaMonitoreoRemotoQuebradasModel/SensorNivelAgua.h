#pragma once

using namespace System;

namespace SistemaMonitoreoRemotoQuebradasModel {

	public ref class SensorNivelAgua {
	private:
		int id;
		int idNodo;
		double ultimaLectura_cm;

	public:
		SensorNivelAgua();
		SensorNivelAgua(int id, int idNodo, double ultimaLectura_cm);
	};
}