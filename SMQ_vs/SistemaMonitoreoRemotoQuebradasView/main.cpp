#include "login.h" //Se incluye el archivo de la ventana

using namespace System; //EN de String
using namespace System::Windows::Forms;
using namespace SistemaMonitoreoRemotoQuebradasView;


void main(array <String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	login ventana; //Creando el obj ventana que se va ejecutar
	Application::Run(% ventana);

}

