#pragma once


using namespace System::Collections::Generic;
using namespace System;
using namespace SistemaMonitoreoRemotoQuebradasModel;

namespace SistemaMonitoreoRemotoQuebradasController {
	public ref class SensoresNodoController {
	private:

	public:
		SensoresNodoController();
		NodoMonitoreo^ cargarDataSensoresNodo(String^ tramaDatos);

		SensorAcelerometro^ getSensorAccelerometro(int idNodo);
		SensorHumedad^ getSensorHumedad(int idNodo);
		SensorInclinacion^ getSensorInclinometro(int idNodo);
		SensorLluvia^ getSensorLluvia(int idNodo);
		SensorNivelAgua^ getSensorNivelAgua(int idNodo);
		SensorTempNodo^ getTemperaturaNodo(int idNodo);
	};
	
}