#pragma once

using namespace System;
using namespace System::Collections::Generic; //Espacio de nombres donde esta List

namespace SistemaMonitoreoRemotoQuebradasModel {

	public ref class Quebrada {
	private:
		int codigo;
		String^ nombre;
		double posicionX;
		double posicionY;
		double radioExtension;
		String^ fechaCreacion;

	public:
		Quebrada();
		Quebrada(int codigo, String^ nombre, double posicionX, double posicionY, double radioExtension, String^ fechaCreacion);

		int getCodigo();
		void setCodigo(int codigo);

		String^ getNombre();
		void setNombre(String^ nombre);

		double getPosicionX();
		void setPosicionX(double posicionX);

		double getPosicionY();
		void setPosicionY(double posicionY);

		double getRadioExtension();
		void setRadioExtension(double radioExtension);

		String^ getFechaCreacion();
		void setFechaCreacion(String^ fechaCreacion);
	};
}