#pragma once

using namespace System;
using namespace System::Collections::Generic;

namespace SistemaMonitoreoRemotoQuebradasModel {

	public ref class SensorHumedad {
	private:
		int id;
		int nodoAsociado;
		double ultimaLectura;

	public:
		SensorHumedad();
		SensorHumedad(int id, int nodoAsociado, double ultimaLectura);
	};
}