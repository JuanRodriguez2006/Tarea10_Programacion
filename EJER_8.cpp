#include<iostream>
#include<vector>
using namespace std;

struct Estudiante{
	int id;
	string nombre;
	string carrera;
	float promedio;
};

void registrar(vector<Estudiante>& estudiantes){
	Estudiante nuevoEstudiante;
	cout<<"Registrar Estudiantes\n";
	cout<<"ID: ";
	cin>>nuevoEstudiante.id;
	cin.ignore();
	cout<<"Nombre:";
	getline(cin, nuevoEstudiante.nombre);
	cout<<"Carrera: ";
	getline(cin, nuevoEstudiante.carrera);
	cout<<"Promedio: ";
	cin>>nuevoEstudiante.promedio;
	
	estudiantes.push_back(nuevoEstudiante);
	cout<<"Estudiante agregado exitosamente.";
}

void listarEstudiantes(vector<Estudiante> estudiantes){
	if(estudiantes.size()==0){
		cout<<"\nNo hay estudiantes agregados.\n";
		return;
	}
	cout<<"\n Lista de estudiantes \n";
	for(int i=0;i<estudiantes.size();i++){	
		cout<<"\nEstudiante "<<i+1<<": \n";
		cout<<"ID: "<<estudiantes[i].id<<endl;
		cout<<"Nombre: "<<estudiantes[i].nombre<<endl;
		cout<<"Carrera: "<<estudiantes[i].carrera<<endl;
		cout<<"Promedio: "<<estudiantes[i].promedio<<endl;
	}
	
}

void buscarEstudiante(vector<Estudiante> estudiantes){
	int idBuscar;
	bool encontrado=false;
	cout<<"Buscar estudiante por Id:";
	cin>>idBuscar;
	cin.ignore();
	for(int i=0;i<estudiantes.size();i++){
		if(estudiantes[i].id==idBuscar){
			cout<<"Estudiante encontrado.\n";
			cout<<"Nombre: "<<estudiantes[i].nombre<<endl;
			cout<<"Carrera: "<<estudiantes[i].carrera<<endl;
			encontrado=true;
			break;
		}
	}
	if(!encontrado){
		cout<<"id invalido.\n";
	}
}

void actualizarEstudiante(vector<Estudiante>& estudiantes){
	int idBuscar;
	bool encontrado=false;
	cout<<"Buscar estudiante por Id:";
	cin>>idBuscar;
	cin.ignore();
	for(int i=0;i<estudiantes.size();i++){
		if(estudiantes[i].id==idBuscar){
			cout<<"Estudiante encontrado.\n";
			cout<<"Nombre: "<<estudiantes[i].nombre<<endl;
			cout<<"Carrera: "<<estudiantes[i].carrera<<endl;
			cout<<"\nIngrese el nuevo nombre:";
			getline(cin,estudiantes[i].nombre);
			cout<<"\nIngrese la nueva carrera: ";
			getline(cin, estudiantes[i].carrera);
			cout<<"\nIngrese el nuevo proemdio: ";
			cin>>estudiantes[i].promedio;
			cin.ignore();
			encontrado=true;
			break;
		}
	}
	if(!encontrado){
		cout<<"id invalido.\n";
	}
}

void eliminarEstudiante(vector<Estudiante>& estudiantes){
	int idBuscar;
	bool encontrado=false;
	cout<<"Buscar estudiante por ID: ";
	cin>>idBuscar;
	cin.ignore();
	
	for(int i=0;i<estudiantes.size();i++){
		if(estudiantes[i].id==idBuscar){
			cout<<"Estudiante encontrado\n";
			cout<<"Nombre: "<<estudiantes[i].nombre<<endl;
			cout<<"Carrera: "<<estudiantes[i].carrera<<endl;
			estudiantes.erase(estudiantes.begin()+i);
			cout<<"\nEstudiante elimiando exitosamente.\n";
			encontrado=true;
			break;
		}
	}
	if(!encontrado){
		cout<<"id invalido\n";
	}
}

vector<Estudiante> obtenerEstudiantesAprobados(vector<Estudiante> estudiantes){
	vector<Estudiante> aprobados;
	
	for (int i=0;i<estudiantes.size();i++){
		if(estudiantes[i].promedio>=14){
			aprobados.push_back(estudiantes[i]);
		}
	}
	return aprobados;
}

void mostrarAprobados(vector<Estudiante> estudiantes){
	vector<Estudiante> aprobados=obtenerEstudiantesAprobados(estudiantes);
	
	if(aprobados.size()==0){
		cout<<"\nNo hay estudiantes aprobados\n";
		return;
	}
	cout<<"Estudaintes aprobados\n";
	for(int i = 0; i < aprobados.size(); i++) {
        cout << "\nEstudiante " << (i + 1) << ":\n";
        cout << "  ID: " << aprobados[i].id << endl;
        cout << "  Nombre: " << aprobados[i].nombre << endl;
        cout << "  Carrera: " << aprobados[i].carrera << endl;
        cout << "  Promedio: " << aprobados[i].promedio << endl;	
	}
	cout << "\nTotal de aprobados: " << aprobados.size() << endl;
}
int main() {
    vector<Estudiante> estudiantes;
    int opcion;
    
    do {
        cout << "\n   SISTEMA DE GESTION DE ESTUDIANTES\n";
        cout << "1. Registrar estudiante\n";
        cout << "2. Listar estudiantes\n";
        cout << "3. Buscar estudiante\n";
        cout << "4. Actualizar estudiante\n";
        cout << "5. Eliminar estudiante\n";
        cout << "6. Mostrar estudiantes aprobados\n";
        cout << "7. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
				registrar(estudiantes);
                break;
            case 2:
				listarEstudiantes(estudiantes);
                break;
            case 3:
				buscarEstudiante(estudiantes);
                break;
            case 4:
				actualizarEstudiante(estudiantes);
                break;
            case 5:
				eliminarEstudiante(estudiantes);
                break;
            case 6:
				mostrarAprobados(estudiantes);
                break;
            case 7:
                cout << "\n¡Gracias por usar el sistema!\n";
                break;
            default:
                cout << "\nOpcion invalida. Intente de nuevo.\n";
        }
        
    } while(opcion != 7);
    
    return 0;
}
