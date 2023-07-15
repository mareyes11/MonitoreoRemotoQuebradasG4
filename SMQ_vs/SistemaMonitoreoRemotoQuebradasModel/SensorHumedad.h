#pragma once

using namespace System;
using namespace System::Collections::Generic;

namespace SistemaMonitoreoRemotoQuebradasModel {

	public ref class SensorHumedad {
	private:
		int id;
		int nodoAsociado;
		int valorCal1 = 0;
		int valorCal2 = 1024;
		int rawLectura;
		double humedad;

	public:
		SensorHumedad();
		SensorHumedad(int id, int nodoAsociado, int rawLectura);
		int getId();
		void setId(int id);
		int getIdNodo();
		void setIdNodo(int id);
		void setRawLectura(int rawLectura);
		int getValorCal1();
		void setValorCal1(int valorCal1);
		int getValorCal2();
		void setValorCal2(int valorCal2);
		double getHumedad();
	};
}