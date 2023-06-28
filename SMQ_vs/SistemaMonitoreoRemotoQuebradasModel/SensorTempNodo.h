#pragma once


namespace SistemaMonitoreoRemotoQuebradasModel {
	public ref class SensorTempNodo {
	private:
		int id;
		int idNodo;
		double ultimaLectura_degC;
	public:
		SensorTempNodo();
		SensorTempNodo(int id, int idNodo, double ultimaLectura_degC);
	};
}
