#include<iostream>
using namespace std;

void ingresarNivel(int tableta[][6], int filas){
	cout<<"---Ingreso de niveles de dulzura---\n";
	for(int i=0;i<filas;i++){
		for(int j=0;j<6;j++){
			do{
				cout<<"Ingrese el nivel de dulzura: [" << i << "][" << j << "] (1-9): ";
				cin>>tableta[i][j];
				if(tableta[i][j]<1 || tableta[i][j]>9){
					cout<<"Error : debe ser entre 1 y 9\n";
				}
			}while(tableta[i][j]<1 || tableta[i][j]>9);
		}
	}
}

float calcularProm(int tableta[][6],int filas){
	int suma=0;
	int totalCeldas= filas * 6;
	for(int i=0;i<filas;i++){
		for(int j=0;j<6;j++){
			suma+=tableta[i][j];
		}
	}
	return (float)suma/totalCeldas;
}

void mostrarTableta(int tableta[][6], int filas){
	cout<<"Tableta de chocolate\n";
	for(int i=0;i<filas;i++){
		for(int j=0;j<6;j++){
			cout<<tableta[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	
	int tableta[4][6];
	
	//ingresar nivel
	ingresarNivel(tableta, 4);
	
	//mostrar tableta
	mostrarTableta(tableta, 4);
	
	//promedio
	float promedio= calcularProm(tableta, 4);
	cout<<"El nivel de dulzura promedio es: "<<promedio;
return 0;
}
