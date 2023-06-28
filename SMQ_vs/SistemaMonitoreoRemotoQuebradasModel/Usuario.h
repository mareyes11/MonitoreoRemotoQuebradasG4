#pragma once

using namespace System;
using namespace System::Collections::Generic;

namespace SistemaMonitoreoRemotoQuebradasModel {

	public ref class Usuario {
	private:
		int codigo;
		int nivelAcceso;
		String^ nombre;
		String^ apellido;
		String^ password;
		
	public:
		Usuario();
		Usuario(int codigo, int nivelAcceso, String^ nombre, String^ apellido, String^ password);

		int getCodigo();
		void setCodigo(int codigo);

		int getNivelAcceso();
		void setNivelAcceso(int nivel);

		String^ getNombre();
		void setNombre(String^ nombre);

		String^ getApellido();
		void setApellido(String^ apellido);

		String^ getPassword();
		void setPassword(String^ password);
	};
}