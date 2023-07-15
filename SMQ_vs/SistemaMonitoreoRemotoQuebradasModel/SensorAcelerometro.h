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
		int getId();
		void setId(int id);
		int getIdNodo();
		void setIdNodo(int id);
		void setAccX(double accX);
		void setAccY(double accY);
		void setAccZ(double accZ);
		double getAccX();
		double getAccY();
		double getAccZ();
	};
}