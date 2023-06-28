#include "UsuarioController.h"

using namespace SistemaMonitoreoRemotoQuebradasController;
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO; /*Contiene la definicion de la clase File*/

UsuarioController::UsuarioController() {

}
List<Usuario^>^ UsuarioController::buscarTodos() {
	/*En esta lista vamos a colocar la información de las carreras que encontremos en el archivo de texto*/
	List<Usuario^>^ listaUsuarios = gcnew List<Usuario^>();
	array<String^>^ lineas = File::ReadAllLines("Usuarios.txt");
	String^ separadores = ";"; /*Aqui defino el caracter por el cual voy a separar la informacion de cada linea*/
	for each (String ^ lineaUsuarios in lineas) {
		array<String^>^ datos = lineaUsuarios->Split(separadores->ToCharArray());
		int codigo = Convert::ToInt32(datos[0]);
		int nivelAcceso = Convert::ToInt32(datos[1]);
		String^ nombre = datos[2];
		String^ apellido = datos[3];
		String^ password = datos[4];
		Usuario^ objUsuario = gcnew Usuario(codigo, nivelAcceso, nombre, apellido, password);
		listaUsuarios->Add(objUsuario);
	}
	return listaUsuarios;
}
List<Usuario^>^ UsuarioController::buscarXNombre(String^ nombreUsuario) {
	/*En esta lista vamos a colocar la información de las carreras que encontremos en el archivo de texto*/
	List<Usuario^>^ listaUsuarios = gcnew List<Usuario^>();
	array<String^>^ lineas = File::ReadAllLines("Usuarios.txt");
	String^ separadores = ";"; /*Aqui defino el caracter por el cual voy a separar la informacion de cada linea*/
	for each (String ^ lineaUsuarios in lineas) {
		array<String^>^ datos = lineaUsuarios->Split(separadores->ToCharArray());
		int codigo = Convert::ToInt32(datos[0]);
		int nivelAcceso = Convert::ToInt32(datos[1]);
		String^ nombre = datos[2];
		String^ apellido = datos[3];
		String^ password = datos[4];
		if (nombre->Contains(nombreUsuario)) {
			Usuario^ objUsuario = gcnew Usuario(codigo, nivelAcceso, nombre, apellido, password);
			listaUsuarios->Add(objUsuario);
		}

	}
	return listaUsuarios;
}
Usuario^ UsuarioController::buscarXCodigo(int codigoUsuario) {
	/*En esta lista vamos a colocar la información de las carreras que encontremos en el archivo de texto*/
	Usuario^ UsuarioRetornar = gcnew Usuario();
	List<Usuario^>^ ListaUsuariosEncontrados = gcnew List<Usuario^>();
	array<String^>^ lineas = File::ReadAllLines("Usuarios.txt");
	String^ separadores = ";"; /*Aqui defino el caracter por el cual voy a separar la informacion de cada linea*/
	for each (String ^ lineaQuebrada in lineas) {
		array<String^>^ datos = lineaQuebrada->Split(separadores->ToCharArray());
		int codigo = Convert::ToInt32(datos[0]);
		int nivelAcceso = Convert::ToInt32(datos[1]);
		String^ nombre = datos[2];
		String^ apellido = datos[3];
		String^ password = datos[4];
		if (codigo == codigoUsuario) {
			UsuarioRetornar->setCodigo(codigo);
			UsuarioRetornar->setNivelAcceso(nivelAcceso);
			UsuarioRetornar->setNombre(nombre);
			UsuarioRetornar->setApellido(apellido);
			UsuarioRetornar->setPassword(password);
			ListaUsuariosEncontrados->Add(UsuarioRetornar);
		}
	}
	switch (ListaUsuariosEncontrados->Count)
	{
	case 0:
		UsuarioRetornar->setCodigo(0);
		;//Indica que no se encontro ningun U. con ese codigo
		break;
	case 1:
		//Si solo se encontro una quebrada con ese codigo, retornar 
		break;
	default:
		UsuarioRetornar->setCodigo(-1);//Si se encuentra mas de una quebrada , se indica con -1 en el id
		break;
	}
	return UsuarioRetornar;
}
List<Usuario^>^ UsuarioController::buscarUsuarios(String^ nombreUsuario) {
	List<Usuario^>^ listaUsuariosEncontrados = gcnew List<Usuario^>();
	array<String^>^ lineas = File::ReadAllLines("Usuarios.txt");
	String^ separadores = ";"; /*Aqui defino el caracter por el cual voy a separar la informacion de cada linea*/
	for each (String ^ lineaUsuario in lineas) {
		array<String^>^ datos = lineaUsuario->Split(separadores->ToCharArray());
		int codigo = Convert::ToInt32(datos[0]);
		int nivelAcceso = Convert::ToInt32(datos[1]);
		String^ nombre = datos[2];
		String^ apellido = datos[3];
		String^ contraseña = datos[4];
		if (nombre->Contains(nombreUsuario)) {
			Usuario^ objUsuario = gcnew Usuario(codigo, nivelAcceso, nombre, apellido, contraseña);
			listaUsuariosEncontrados->Add(objUsuario);
		}
	}
	return listaUsuariosEncontrados;
}


void UsuarioController::eliminarUsuario(int codigoEliminar) {
	List<Usuario^>^ listaUsuarios = buscarTodos();
	for (int i = 0; i < listaUsuarios->Count; i++) {
		Usuario^ objUsuario = listaUsuarios[i];
		if (objUsuario->getCodigo() == codigoEliminar) {
			listaUsuarios->RemoveAt(i);
			break;
		}
	}
	escribirArchivo(listaUsuarios);
}

void UsuarioController::escribirArchivo(List<Usuario^>^ listaUsuarios) {
	array<String^>^ lineasArchivo = gcnew array<String^>(listaUsuarios->Count);
	for (int i = 0; i < listaUsuarios->Count; i++) {
		Usuario^ objUsuario = listaUsuarios[i];
		lineasArchivo[i] = objUsuario->getCodigo() + ";" + objUsuario->getNivelAcceso() + ";" + objUsuario->getNombre() + ";" + objUsuario->getApellido() + ";" + objUsuario->getPassword();
	}
	File::WriteAllLines("Usuarios.txt", lineasArchivo);
}

int UsuarioController::existeUsuario(int codigo) {
	int existe = 0;
	List<Usuario^>^ listaUsuarios = buscarTodos();
	for (int i = 0; i < listaUsuarios->Count; i++) {
		Usuario^ objUsuario = listaUsuarios[i];
		if (objUsuario->getCodigo() == codigo) {
			existe = 1;
			break;
		}
	}
	return existe;
}

void UsuarioController::registrarUsuario(int codigo, int nivelAcceso, String^ nombre, String^ apellido, String^ contraseña) {
	List<Usuario^>^ listaUsuarios = buscarTodos();
	Usuario^ objUsuarioNuevo = gcnew Usuario(codigo, nivelAcceso, nombre, apellido, contraseña);
	listaUsuarios->Add(objUsuarioNuevo);
	escribirArchivo(listaUsuarios);
}

Usuario^ UsuarioController::buscarUsuario(int codigo) {
	Usuario^ objUsuario = gcnew Usuario();
	List<Usuario^>^ listaUsuarios = buscarTodos();
	for (int i = 0; i < listaUsuarios->Count; i++) {
		if (listaUsuarios[i]->getCodigo() == codigo) {
			objUsuario->setCodigo(listaUsuarios[i]->getCodigo());
			objUsuario->setNombre(listaUsuarios[i]->getNombre());
			objUsuario->setApellido(listaUsuarios[i]->getApellido());
			objUsuario->setPassword(listaUsuarios[i]->getPassword());
			objUsuario->setNivelAcceso(listaUsuarios[i]->getNivelAcceso());
			break;
		}
	}
	return objUsuario;
}

void UsuarioController::actualizarUsuario(int codigo, int nivelAcceso, String^ nombre, String^ apellido, String^ contraseña) {
	List<Usuario^>^ listaUsuarios = buscarTodos();
	for (int i = 0; i < listaUsuarios->Count; i++) {
		if (listaUsuarios[i]->getCodigo() == codigo) {
			listaUsuarios[i]->setNivelAcceso(nivelAcceso);
			listaUsuarios[i]->setNombre(nombre);
			listaUsuarios[i]->setApellido(apellido);
			listaUsuarios[i]->setPassword(contraseña);

		}
	}
	escribirArchivo(listaUsuarios);
}

List<Usuario^>^ UsuarioController::buscarUsuariosxNombrexId(String^ nombreBuscar, String^ codigoBuscar) {
	/*En esta lista vamos a colocar la información de las carreras que encontremos en el archivo de texto*/
	List<Usuario^>^ listaUsuariosEncontrados = gcnew List<Usuario^>();
	array<String^>^ lineas = File::ReadAllLines("Usuarios.txt");
	String^ separadores = ";"; /*Aqui defino el caracter por el cual voy a separar la informacion de cada linea*/
	for each (String ^ lineaUsuario in lineas) {
		array<String^>^ datos = lineaUsuario->Split(separadores->ToCharArray());
		int codigo = Convert::ToInt32(datos[0]);
		int nivelAcceso = Convert::ToInt32(datos[1]);
		String^ nombre = datos[2];
		String^ apellido = datos[3];
		String^ password = datos[4];
		if (nombre->Contains(nombreBuscar)) {
			Usuario^ objUsuario = gcnew Usuario(codigo, nivelAcceso, nombre, apellido, password);
			listaUsuariosEncontrados->Add(objUsuario);
		}
	}
	if (codigoBuscar != ("")) {
		List<Usuario^>^ listaUsuariosId = gcnew List<Usuario^>();
		for (int i = 0; i < listaUsuariosEncontrados->Count; i++) {
			if (Convert::ToString(listaUsuariosEncontrados[i]->getCodigo())->Contains(codigoBuscar)) {
				listaUsuariosId->Add(listaUsuariosEncontrados[i]);
				break;
			}
		}
		return listaUsuariosId;
	}
	else
		return listaUsuariosEncontrados;

}



