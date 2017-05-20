#include "stdafx.h"  //________________________________________ Logaritmo.cpp
#include "Logaritmo.h"

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE, LPTSTR cmdLine, int cmdShow) {
	Logaritmo app;
	return app.BeginDialog(IDI_Logaritmo, hInstance);
}

void Logaritmo::Window_Open(Win::Event& e)
{
	
}

void Logaritmo::btCalcular_Click(Win::Event& e)
{
	wstring texto;
	Sys::Format(texto, L"Producto\r\tDelta\r\tLn(X)\r\tError\r\n");
	tbxSalida.Text += texto;
	Sys::Format(texto, L"______________________________\r\n");
	tbxSalida.Text += texto;
	double x = tbxEntrada.DoubleValue;
	double y = (x-1)/x;
	double producto = 1.0;
	double delta = 0.0;
	double ln = 0.0;
	double error = 0.0001;
	for (int i = 1; error >= 0.0001; i++)
	{
		producto = producto*y;
		delta = producto/i;
		ln = ln + delta;
		error = delta / ln;
		Sys::Format(texto, L"%.6f\r\t%.6f\r\t%.6f\r\t%.6f\r\n", producto, delta, ln, error);
		tbxSalida.Text += texto;
	}
}

