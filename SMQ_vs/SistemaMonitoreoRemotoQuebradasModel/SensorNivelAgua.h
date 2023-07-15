#pragma once

using namespace System;

namespace SistemaMonitoreoRemotoQuebradasModel {

	public ref class SensorNivelAgua {
	private:
		int id;
		int idNodo;
		double presionCero_hPa;
		double presion_hPa;
		double columnaAgua_cm;

	public:
		SensorNivelAgua();
		SensorNivelAgua(int id, int idNodo, double presionCero_hPa);
		int getId();
		void setId(int id);
		int getIdNodo();
		void setIdNodo(int id);
		void setPresionCero_hPa(double presionCero_hPa);
		void setPresion_hPa(double presion_hPa);
		double getPresion_hPa();
		double getColumnaAgua_cm();
	};
}