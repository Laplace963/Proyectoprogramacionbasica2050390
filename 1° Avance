#include <iostream>
#include <string>

using namespace std;

int main()
{
	int opcion, respuesta;
	float precio, PreU, impuesto=1.16, total;
	string articulo, Desc, genero, clas, consola;

	cout << "Ingrese la opci�n deseada" << endl;
	cout << "1.- Alta de articulos" << endl;
	cout << "2.- Mod. articulos" << endl;
	cout << "3.- Baja de articulos" << endl;
	cout << "4.- Lista de articulos" << endl;
	cout << "5.- Limpiar pantalla" << endl;
	cout << "6.- Salir" << endl;
	cin >> opcion;
	switch (opcion)
	{
	case 1:
		cout << "Ingrese los datos del articulo" << endl;
		cout << "Nombre del articulo: ";
		getline(cin,articulo);
		cout << "Genero: ";
		getline(cin,genero);
		cout << "Clasificacion: ";
		getline(cin,clas);
		cout << "Descripcion:" << endl;
		getline(cin,Desc);
		cout << "Consola: ";
		getline(cin,consola);
		cout << "Precio Unitario: ";
		cin >> PreU;
		precio = PreU * impuesto;
		cout << endl << "Desea dar de alta otro articulo?" << endl << "1.- Si" << endl << "2.- No" << endl;
		cin >> respuesta;
		if (respuesta == 1)
		{
			return main();
		}
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		system("cls");
	case 6:
		exit(1);
	default:
		break;
	}
	return main();
}
