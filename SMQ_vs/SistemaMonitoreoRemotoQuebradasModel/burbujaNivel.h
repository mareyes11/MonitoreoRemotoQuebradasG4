#pragma once
namespace SistemaMonitoreoRemotoQuebradasModel {

	using namespace System::Drawing;

	public ref class burbujaNivel {
	private:
		int inicioX;
		int inicioY;
		int ancho;
		int angX;
		int angY; //1 para Rectangulos y 2 para Elipse
		Color objColor;

	public:
		burbujaNivel();
		burbujaNivel(int inicioX, int inicioY, int ancho, int angX, int angY, Color objColor);
		int getInicioX();
		void setInicioX(int inicioX);
		int getInicioY();
		void setInicioY(int inicioY);
		int getAncho();
		void setAncho(int ancho);
		int getAngX();
		void setAngX(int angX);
		int getAngY();
		void setAngY(int angY);
		Color getColor();
		void setColor(Color objColor);
	};

}