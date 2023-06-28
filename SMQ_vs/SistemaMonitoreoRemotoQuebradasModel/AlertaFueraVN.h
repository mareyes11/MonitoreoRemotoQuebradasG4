#pragma once

using namespace System;
using namespace System::Collections::Generic;

namespace SistemaMonitoreoRemotoQuebradasModel {

	public ref class AlertaFueraVN {
	private:
		int codigo;
		int idNodo;
		int idSensor;
		String^ fecha;

	public:
		AlertaFueraVN();
		AlertaFueraVN(int codigo, int idNodo, int idSensor, String^ fecha);
	};
}
