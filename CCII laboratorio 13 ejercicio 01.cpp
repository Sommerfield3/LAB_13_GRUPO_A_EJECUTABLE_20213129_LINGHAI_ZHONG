/*1. Implementar un programa que maneje un arreglo de estructuras para almacenar
los nombres y las fechas de cumpleaños de sus n compañeros. Y debe mostrarse
por pantalla quienes cumplen años en este mes.*/
/*Apellidos y Nombres: Zhong Callasi, Linghai Joaquin*/
#include <iostream>
#include <time.h>
using namespace std;
struct cumple{
	int dia;
	int mes;
};
struct Datos{
	string nombres;
	struct cumple fecha;     
};
void CumplenEstemes(Datos lista[], int n, int mesActual, int FechaYear){
	cout<<"Los alumnos que cumplen años este mes son: "<<endl;
	for (int i=0;i<n;i++){
		if ((lista[i].fecha.mes)==mesActual){
			if (mesActual==2){
				if (lista[i].fecha.dia==29 && (FechaYear%4)==0){
					cout<<lista[i].nombres<<endl;
				}
				else if ((lista[i].fecha.dia)!=29){
					cout<<lista[i].nombres<<endl;
				}
			}
			else{
				cout<<lista[i].nombres<<endl;
			}
		}
	}
}
	
int main(int argc, char *argv[]) {
	int n;
	time_t t = time(NULL);
	tm* hoy = localtime(&t);
	int year=hoy->tm_year+1900; /*Usamos esto para la comprobación del día*/
	int month=hoy->tm_mon+1; 
	while (true){
		cout<<"Ingrese el número de alumnos a registrar en la lista: ";
		cin>>n;
		if (n>0){
			break;
		}
		else{
			cout<<"Ingrese un valor válido."<<endl;
		}
	}
	Datos *lista=new Datos[n];
	for (int j=0;j<n;j++){
		cout<<"Ingrese el nombre del alumno: ";
		getline(cin>>ws, lista[j].nombres);
		cin.clear();
		while (true){
			cout<<"Ingrese el mes (número) del cumpleaños: ";
			cin>>lista[j].fecha.mes;
			if ((lista[j].fecha.mes)<=12 && lista[j].fecha.mes>0){
				break;
			}
			else{
				cout<<"Valor de mes no válido."<<endl;
			}
		}
		while (true){
			cout<<"Ingrese el día del cumpleaños: ";
			cin>>lista[j].fecha.dia;
			if ((lista[j].fecha.mes)==2){
				if ((lista[j].fecha.dia)>0 && (lista[j].fecha.dia)<=29){
					break;
				}
				else{
					cout<<"Ingrese un día válido para el mes indicado. "<<endl;
				}
			}
			else if ((lista[j].fecha.mes)==4 || (lista[j].fecha.mes)==6 || (lista[j].fecha.mes)==9 || (lista[j].fecha.mes)==11){
				if ((lista[j].fecha.dia)>0 && (lista[j].fecha.dia)<=30){
					break;
				}
				else{
					cout<<"Ingrese un día válido para el mes indicado. "<<endl;
				}
			}
			else{
				if ((lista[j].fecha.dia)>0 && (lista[j].fecha.dia)<=31){
					break;
				}
				else{
					cout<<"Ingrese un día válido para el mes indicado. "<<endl;
				}
			}
		}
	}
	CumplenEstemes(lista,n,month,year);
	system("pause");
	delete [] lista;
	return 0;
}
