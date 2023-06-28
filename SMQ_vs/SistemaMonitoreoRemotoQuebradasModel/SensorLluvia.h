#pragma once

using namespace System;
using namespace System::Collections::Generic;

namespace SistemaMonitoreoRemotoQuebradasModel {

	public ref class SensorLluvia {
	private:
		int id;
		int nodoAsociado;
		int ultimaLectura;

	public:
		SensorLluvia();
		SensorLluvia(int id, int nodoAsociado, int ultimaLectura);
	};
}