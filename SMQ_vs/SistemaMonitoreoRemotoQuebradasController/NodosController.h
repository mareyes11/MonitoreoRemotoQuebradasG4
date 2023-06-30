#pragma once

namespace SistemaMonitoreoRemotoQuebradasController
{
	using namespace System;
	using namespace System::Data::SqlClient;
	using namespace System::Collections::Generic;
	using namespace SistemaMonitoreoRemotoQuebradasModel;

	public ref class NodosController
	{
	private:
		SqlConnection^ objConexion;
	public:
		NodosController();
		void abrirConexion();
		void cerrarConexion();
		List<NodoMonitoreo^>^ buscarTodosNodos();
		NodoMonitoreo^ buscarNodoXId(int id);
		List<NodoMonitoreo^>^ buscarNodoxIdQuebrada(int idQuebrada);
		void eliminarNodo(int idNodoEliminar);
		void escribirArchivoNodos(List<NodoMonitoreo^>^ ListaNodos);
		void escribirArchivoNodoEditado(NodoMonitoreo^ NodoEditado);
		int getIdDisponible(void);//Metodo que devuelve un codigo de quebrada disponible
	};


}