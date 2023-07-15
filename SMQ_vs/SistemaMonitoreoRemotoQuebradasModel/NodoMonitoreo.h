#pragma once
#include "SensorNivelAgua.h"
#include "SensorTempNodo.h"
#include "SensorLluvia.h"
#include "SensorInclinacion.h"
#include "SensorHumedad.h"
#include "SensorAcelerometro.h"


using namespace System;
using namespace System::Collections::Generic;

namespace SistemaMonitoreoRemotoQuebradasModel {

	public ref class NodoMonitoreo {
	private:
		int id;
		double ubicacionX;
		double ubicacionY;
		int idQuebrada;
		Boolean alarmaActivada = false;
		String^ COMPort;
		String^ fechaCreacion;
		SensorNivelAgua^ objSensorNiv = gcnew SensorNivelAgua();
		SensorTempNodo^ objSensorTem = gcnew SensorTempNodo();
		SensorLluvia^ objSensorLlu = gcnew SensorLluvia;
		SensorInclinacion^ objSensorInc = gcnew SensorInclinacion();
		SensorHumedad^ objSensorHum = gcnew SensorHumedad();
		SensorAcelerometro^ objSensorAce = gcnew SensorAcelerometro();


	public:
		NodoMonitoreo();
		NodoMonitoreo(int id, double ubicacionX, double ubicacionY, int idQuebrada, String^ fechaCreacion,  SensorNivelAgua^ objSensorNiv, SensorTempNodo^ objSensorTem, SensorLluvia^ objSensorLlu, SensorInclinacion^ objSensorInc, SensorHumedad^ objSensorHum, SensorAcelerometro^ objSensorAce);
		NodoMonitoreo(int id, double ubicacionX, double ubicacionY, int idQuebrada, String^ COMPort, String^ fechaCreacion);

		int getId();
		void setId(int id);

		double getPosicionX();
		void setPosicionX(double posicionX);

		double getPosicionY();
		void setPosicionY(double posicionY);

		int getQuebradaId();
		void setQuebradaId(int idQuebrada);

		String^ getCOMPort();
		void setCOMPort(String^ COMPort);

		String^ getFechaCreacion();
		void setFechaCreacion(String^ fechaCreacion);

		Boolean getAlarmaEstado();
		void setAlarmaEstado(Boolean alarmaActivada);

		SensorAcelerometro^ getSensorAcc();
		SensorHumedad^ getSensorHumedad();
		SensorInclinacion^ getSensorInc();
		SensorLluvia^ getSensorLluvia();
		SensorNivelAgua^ getSensorNivelAgua();
		SensorTempNodo^ getSensorTemperatura();
	};
}