#include<iostream>
using namespace std;

struct Vehiculo{
	string marca;
	string modelo;
	int anio;
};

void ingresarVehiculo(Vehiculo& v){
	cout<<"Ingreso de un nuevo vehiculo\n";
	cout<<"Marca: ";
	getline(cin, v.marca);
	cout<<"Modelo: ";
	getline(cin, v.modelo);
	cout<<"Anio: ";
	cin>>v.anio;
	cin.ignore();
}

void mostrarVehiculos(Vehiculo vehiculos[],int contador){
	cout<<"Lista de vehiculos\n";
	for(int i=0;i<contador;i++){
		cout<<"\n Vehiculo"<<i+1<<":\n";
		cout<<"Marca: "<<vehiculos[i].marca<<endl;
		cout<<"Modelo: "<<vehiculos[i].modelo<<endl;
		cout<<"Anio: "<<vehiculos[i].anio<<endl;
	}
}

int main(){
	
	Vehiculo vehiculos[5];
	int opc;
	int contador=0;
    do{
        cout << "\n=== Menu ===\n";
        cout << "1. Ingresar vehiculo\n";
        cout << "2. Mostrar vehiculos\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opc;
        cin.ignore();
        
        if(opc == 1){
            if(contador < 5){
                ingresarVehiculo(vehiculos[contador]);
                contador++;
                cout << "Vehiculo ingresado exitosamente!\n";
            } else {
                cout << "Ya se han ingresado los 5 vehiculos.\n";
            }
        } else if(opc == 2){
            if(contador > 0){
                mostrarVehiculos(vehiculos, contador);
            } else {
                cout << "No hay vehiculos registrados.\n";
            }
        } else if(opc == 3){
            cout << "Saliendo del programa...\n";
        } else {
            cout << "Opcion invalida.\n";
        }
    } while(opc != 3);
    
    return 0;
}
