/*2. Implementar un programa que maneje un arreglo de estructuras que calcule la
nota final del Ciencia de la Computación. El programa debe permitir el ingreso
de cualquier cantidad de alumnos y para cada alumno, se podrá ingresar nombre,
grupo, nota de la primera fase, segunda fase, tercera fase y proyecto final. El
porcentaje de cada ítem es 15%, 20%, 25% y 40% respectivamente.*/
/*Apellidos y Nombres: Zhong Callasi, Linghai Joaquin*/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
struct notas{
	float nota1;
	float nota2;
	float nota3;
	float notaProyectoFinal;
};
struct alumno{
	string nombres;
	string apellidos;
	int grupo;
	struct notas Notas;
};
float calcularNotaPromedioFinal(alumno);
void imprimirNotasFinales(vector<alumno> lista);
int main(int argc, char *argv[]) {
	int cant;
	while(true){
		cout<<"Ingrese la cantidad inicial de alumnos a ingresar: ";
		cin>>cant;
		if (cant>=0){
			break;
		}
		else{
			cout<<"Ingrese un valor valido. "<<endl;
		}
	}
	vector<alumno> lista(cant);
	for (int j=0;j<(lista.size());j++){
		cout<<"Ingrese los nombres del alumno: ";
		getline(cin>>ws, lista[j].nombres);
		cin.clear();
		cout<<"Ingrese los apellidos del alumno: ";
		getline(cin>>ws, lista[j].apellidos);
		cin.clear();
		while (true){
			cout<<"Ingrese el número del grupo al que pertenece el alumno: "; /*Lo de grupos se tomó como "grupos numerados"*/
			cin>>lista[j].grupo;
			if ((lista[j].grupo)>=0){
				break;
			}
			else{
				cout<<"Valor de grupo no válido."<<endl;
			}
		}
		while (true){
			cout<<"Ingrese la nota de la primera fase del alumno: ";
			cin>>lista[j].Notas.nota1;
			if ((lista[j].Notas.nota1)<=20 && lista[j].Notas.nota1>=0){
				break;
			}
			else{
				cout<<"Nota no válida."<<endl;
			}
		}
		while (true){
			cout<<"Ingrese la nota de la segunda fase del alumno: ";
			cin>>lista[j].Notas.nota2;
			if ((lista[j].Notas.nota2)<=20 && lista[j].Notas.nota2>=0){
				break;
			}
			else{
				cout<<"Nota no válida."<<endl;
			}
		}
		while (true){
			cout<<"Ingrese la nota de la tercera fase del alumno: ";
			cin>>lista[j].Notas.nota3;
			if ((lista[j].Notas.nota3)<=20 && lista[j].Notas.nota3>=0){
				break;
			}
			else{
				cout<<"Nota no válida."<<endl;
			}
		}
		while (true){
			cout<<"Ingrese la nota del proyecto final del alumno: ";
			cin>>lista[j].Notas.notaProyectoFinal;
			if ((lista[j].Notas.notaProyectoFinal)<=20 && lista[j].Notas.notaProyectoFinal>=0){
				break;
			}
			else{
				cout<<"Nota no válida."<<endl;
			}
		}
	}
	imprimirNotasFinales(lista);
	return 0;
}
float calcularNotaPromedioFinal(alumno alumn){
	float promedioFinal;
	float suma=(alumn.Notas.nota1*0.15)+(alumn.Notas.nota2*0.20)+(alumn.Notas.nota3*0.25)+(alumn.Notas.notaProyectoFinal*0.40);
	promedioFinal=(floor(((suma)*2)+0.5)/2.0);
	return promedioFinal;
}
void imprimirNotasFinales(vector<alumno> list){
	cout<<"Promedios finales: "<<endl;
	for (int i=0;i<(list.size());i++){
		cout<<"Alumno(a): "<<list[i].nombres<<", "<<list[i].apellidos<<endl;
		cout<<"Grupo: "<<list[i].grupo<<endl;
		cout<<"Promedio final: "<<calcularNotaPromedioFinal(list[i])<<endl<<endl;
	}
}
