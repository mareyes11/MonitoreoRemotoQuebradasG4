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
		int getId();
		void setId(int id);
		int getIdNodo();
		void setIdNodo(int id);
		void setTemperatura(double temperaturaSensor);
		double getTemperatura();
	};

}
