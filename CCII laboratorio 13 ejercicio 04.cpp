/*4. Implemente un programa que maneje un arreglo de estructuras que solicite
nombre, sexo y sueldo de los empleados de una empresa y debe mostrar por
pantalla el menor y mayor sueldo.*/
/*Apellidos y Nombres: Zhong Callasi, Linghai Joaquin*/
#include <iostream>
#include <vector>
using namespace std;
struct empleados{
	string nombre;
	string sexo;
	float sueldo;
};
void menorMayorSueldo(vector<empleados> list);
int main(int argc, char *argv[]) {
	int cont=0;
	vector<empleados> lista(50);
	while(true){
		cout<<"Ingrese el nombre del empleado: ";
		getline(cin>>ws, lista[cont].nombre);
		cin.clear();
		int opc=0;
		while (true){
			cout<<"Sexo del empleado: "<<endl<<"1.Masculino"<<endl<<"2.Femenino"<<endl<<"Ingrese una opción (número): ";
			cin>>opc;
			if (opc==1){
				lista[cont].sexo="Masculino";
				break;
			}
			else if (opc==2){
				lista[cont].sexo="Femenino";
				break;
			}
			else{
				cout<<"Opción no válida. "<<endl;
			}
		}
		while (true){
			cout<<"Ingrese el sueldo (S/.) del empleado: ";
			cin>>lista[cont].sueldo;
			if (lista[cont].sueldo>=0){
				break;
			}
			else{
				cout<<"Valor no válido. "<<endl;
			}
		}
		opc=0;
		cout<<"¿Desea ingresar los datos de otro empleado más?"<<endl<<"1.Sí"<<endl<<"2.No"<<endl<<"Ingresar una opción (número): ";
		cin>>opc;
		if (opc==1){
			cont++;
		}
		else{
			break;
		}
		
	}
	menorMayorSueldo(lista);
	return 0;
}
void menorMayorSueldo(vector<empleados> list){
	empleados auxMax=list[0];
	for (int i=0;i<list.size();i++){
		if (auxMax.sueldo>=list[i].sueldo){
			auxMax=auxMax;
		}
		else{
			auxMax=list[i];
		}
	}
	empleados auxMin=list[0];
	for (int i=0;i<list.size();i++){
		if (auxMin.sueldo<=list[i].sueldo){
			auxMin=auxMin;
		}
		else{
			auxMin=list[i];
		}
	}
	cout<<"Empleado con el sueldo mínimo: "<<endl;
	cout<<"Nombre: "<<auxMin.nombre<<endl;
	cout<<"Sexo: "<<auxMin.sexo<<endl;
	cout<<"Sueldo: "<<auxMin.sueldo<<endl<<endl;
	cout<<"Empleado con el sueldo máximo: "<<endl;
	cout<<"Nombre: "<<auxMax.nombre<<endl;
	cout<<"Sexo: "<<auxMax.sexo<<endl;
	cout<<"Sueldo: "<<auxMax.sueldo<<endl;
	
}

