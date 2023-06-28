#pragma once
namespace SistemaMonitoreoRemotoQuebradasController
{
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace SistemaMonitoreoRemotoQuebradasModel;

	public ref class UsuarioController
	{
	private:
		/*No suelen tener atributos -dado el esquema MVC planteado*/
	public:
		UsuarioController();
		List<Usuario^>^ buscarTodos();
		List<Usuario^>^ buscarXNombre(String^ nombreUsuario);
		Usuario^ buscarXCodigo(int codigoUsuario);
		/*void eliminarQuebrada(int codigoUsuarioEliminar);
		void escribirArchivoUsuarios(List<Quebrada^>^ ListaQuebradas);
		void escribirArchivoUsuarioEditado(Quebrada^ QuebradaEditada);*/
		List<Usuario^>^ buscarUsuarios(String^ nombreUsuario);
		void eliminarUsuario(int codigoEliminar);
		void escribirArchivo(List<Usuario^>^ listaUsuarios);
		int existeUsuario(int codigo);
		void registrarUsuario(int codigo, int nivelAcceso, String^ nombre, String^ apellido, String^ contraseña);
		Usuario^ buscarUsuario(int codigo);
		void actualizarUsuario(int codigo, int nivelAcceso, String^ nombre, String^ apellido, String^ contraseña);
		List<Usuario^>^ buscarUsuariosxNombrexId(String^ nombreBuscar,String^ codigoBuscar);
	};


}