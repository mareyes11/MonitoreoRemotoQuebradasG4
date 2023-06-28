#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace SistemaMonitoreoRemotoQuebradasModel;

namespace SistemaMonitoreoRemotoQuebradasController
{
	

	public ref class NodosController
	{
	private:
		/*No suelen tener atributos -dado el esquema MVC planteado*/
		
	public:
		NodosController();
		List<NodoMonitoreo^>^ buscarTodosNodos();
		NodoMonitoreo^ buscarNodoXId(int id);
		void eliminarNodo(int idNodoEliminar);
		void escribirArchivoNodos(List<NodoMonitoreo^>^ ListaNodos);
		void escribirArchivoNodoEditado(NodoMonitoreo^ NodoEditado);
		int getIdDisponible(void);//Metodo que devuelve un codigo de quebrada disponible
	};


}