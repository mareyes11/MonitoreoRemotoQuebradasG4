#pragma once

namespace SistemaMonitoreoRemotoQuebradasController
{
	using namespace System;
	using namespace System::Data::SqlClient;
	using namespace System::Collections::Generic;
	using namespace SistemaMonitoreoRemotoQuebradasModel;

	public ref class QuebradaController
	{
	private:	
		SqlConnection^ objConexion;
	public:
		QuebradaController();
		void abrirConexion();
		void cerrarConexion();
		List<Quebrada^>^ buscarTodasQuebradas();
		Quebrada^ buscarQuebradaXNombre(String^ nombreQuebrada);
		Quebrada^ buscarQuebradaXCodigo(int codigoQuebrada);
		List<Quebrada^>^ buscarQuebradasxNombxId(String^ nombreQuebrada, String^ codigoQuebrada);
		void eliminarQuebrada(int codigoQuebradaEliminar);
		void escribirArchivoQuebradas(List<Quebrada^>^ ListaQuebradas);
		void escribirArchivoQuebradaEditada(Quebrada^ QuebradaEditada);
		int getCodigoQuebradaDisponible(void);//Metodo que devuelve un codigo de quebrada disponible
	};


}