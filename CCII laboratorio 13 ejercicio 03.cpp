/*3. Implemente un programa que maneje un arreglo de estructuras que solicite el
nombre, edad y talla de 10 jugadores, debe mostrar por pantalla los que son
menores de 20 años y tienen una talla mayor a 1,70 mts de altura.*/
/*Apellidos y Nombres: Zhong Callasi, Linghai Joaquin*/
#include <iostream>
using namespace std;

struct personas{
	string nombre;
	int edad;
	float talla;
};
void menorMayorTalla(personas lista[]);
int main(int argc, char *argv[]) {
	personas lista[10];
	lista[0]={"Rodrigo Jesus, Barrionuevo Zarate",19,1.69};
	lista[1]={"Yorwin Patricio, Fernandez Apaza",23,1.79};
	lista[2]={"Carla Amanda, Rivera Tennenbaun",19,1.82};
	lista[3]={"Roberto Javier, Hurtado Postigo",22,1.66};
	lista[4]={"Octavio David, Kistampamf Ramos",23,1.68};
	lista[5]={"Ronaldo Guido, Zambrano Saenz",21,1.75};
	lista[6]={"Ana Julia, Cabastri Ju",20,1.77};
	lista[7]={"Felix Alonso, Renald Zegarra",24,1.79};
	lista[8]={"Pedro Narud, Torres Tirdeo",29,1.66};
	lista[9]={"Valentino Franco, Corsario Guisado",18,1.86};
	menorMayorTalla(lista);
	delete [] lista;
	return 0;
}
void menorMayorTalla(personas lista[]){
	cout<<"Los jugadores con menos de 20 años y con talla mayor a 1,70 mts son: "<<endl;
	for (int i=0;i<10;i++){
		if (lista[i].edad<20 && lista[i].talla>1.70){
			cout<<lista[i].nombre<<endl;
		}
	}
}
