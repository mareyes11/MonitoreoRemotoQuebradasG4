#pragma once
namespace SistemaMonitoreoRemotoQuebradasController
{
	using namespace System;
	using namespace System::Data::SqlClient;
	using namespace System::Collections::Generic;
	using namespace SistemaMonitoreoRemotoQuebradasModel;

	public ref class UsuarioController
	{
	private:
		SqlConnection^ objConexion;
	public:
		UsuarioController();
		void abrirConexion();
		void cerrarConexion();
		List<Usuario^>^ buscarTodos();
		Usuario^ buscarXCodigo(int codigoUsuario);
		void eliminarUsuario(int codigoEliminar);
		int existeUsuario(int codigo);
		void registrarUsuario(int codigo, int nivelAcceso, String^ nombre, String^ apellido, String^ contraseña);
		void actualizarUsuario(int codigo, int nivelAcceso, String^ nombre, String^ apellido, String^ contraseña);
		List<Usuario^>^ buscarUsuariosxApellidoxId(String^ apellidoBuscar,String^ codigoBuscar);
	};


}