#pragma once

namespace SistemaMonitoreoRemotoQuebradasController
{
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace SistemaMonitoreoRemotoQuebradasModel;

	public ref class QuebradaController
	{
	private:	
		/*No suelen tener atributos -dado el esquema MVC planteado*/
	public:
		QuebradaController();
		List<Quebrada^>^ buscarTodasQuebradas();
		List<Quebrada^>^ buscarQuebradasXNombre(String^ nombreQuebrada);
		Quebrada^ buscarQuebradaXCodigo(int codigoQuebrada);
		List<Quebrada^>^ buscarQuebradasxNombxId(String^ nombreQuebrada, String^ codigoQuebrada);
		void eliminarQuebrada(int codigoQuebradaEliminar);
		void escribirArchivoQuebradas(List<Quebrada^>^ ListaQuebradas);
		void escribirArchivoQuebradaEditada(Quebrada^ QuebradaEditada);
		int getCodigoQuebradaDisponible(void);//Metodo que devuelve un codigo de quebrada disponible
	};


}