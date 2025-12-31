#include<iostream>
#include<vector>
using namespace std;

struct Jugador{
	int id;
	string nombre;
	string posicion;
	int edad;
};

struct Equipo{
	int id;
	string nombre;
	string entrenador;
	vector<Jugador> jugadores;
};

void registrarEquipo(vector<Equipo>& equipos){
	Equipo nuevoEquipo;
	cout << "\n---Registrar Equipo---\n";
	cout << "ID: ";
	cin >> nuevoEquipo.id;
	cin.ignore();
	cout << "Nombre del equipo: ";
	getline(cin, nuevoEquipo.nombre);
	cout << "Entrenador: ";
	getline(cin, nuevoEquipo.entrenador);
	
	equipos.push_back(nuevoEquipo);
	cout << "\nEquipo registrado exitosamente.\n";
}

int buscarEquipoPorID(vector<Equipo> equipos, int idBuscar){
	for(int i = 0; i < equipos.size(); i++){
		if(equipos[i].id == idBuscar){
			return i; 
		}
	}
	return -1; 
}

void agregarJugador(vector<Equipo>& equipos){
	int idEquipo;
	cout << "\n---Agregar Jugador---\n";
	cout << "Ingrese el ID del equipo: ";
	cin >> idEquipo;
	cin.ignore();
	
	int posicion = buscarEquipoPorID(equipos, idEquipo);
	
	if(posicion != -1){
		Jugador nuevoJugador;
		cout << "\nEquipo encontrado: " << equipos[posicion].nombre << endl;
		cout << "\nDatos del jugador:\n";
		cout << "ID: ";
		cin >> nuevoJugador.id;
		cin.ignore();
		cout << "Nombre: ";
		getline(cin, nuevoJugador.nombre);
		cout << "Posicion: ";
		getline(cin, nuevoJugador.posicion);
		cout << "Edad: ";
		cin >> nuevoJugador.edad;
		
		equipos[posicion].jugadores.push_back(nuevoJugador);
		cout << "\nJugador agregado exitosamente al equipo.\n";
	} else {
		cout << "\nEquipo no encontrado.\n";
	}
}

void listarEquipos(vector<Equipo> equipos){
	if(equipos.size() == 0){
		cout << "\nNo hay equipos registrados.\n";
		return;
	}
	
	cout << "\n---Lista de Equipos---\n";
	for(int i = 0; i < equipos.size(); i++){
		cout << "\n--- Equipo ---" << (i + 1) << " ---\n";
		cout << "ID: " << equipos[i].id << endl;
		cout << "Nombre: " << equipos[i].nombre << endl;
		cout << "Entrenador: " << equipos[i].entrenador << endl;
		
		if(equipos[i].jugadores.size() == 0){
			cout << "Jugadores: Ninguno\n";
		} else {
			cout << "Jugadores (" << equipos[i].jugadores.size() << "):\n";
			for(int j = 0; j < equipos[i].jugadores.size(); j++){
				cout << "  " << j + 1 << ". " << equipos[i].jugadores[j].nombre 
				     << " - " << equipos[i].jugadores[j].posicion 
				     << " (" << equipos[i].jugadores[j].edad << " años)\n";
			}
		}
	}
}

void buscarEquipo(vector<Equipo> equipos){
	int idBuscar;
	cout << "\n---Buscar Equipo---\n";
	cout << "Ingrese el ID del equipo: ";
	cin >> idBuscar;
	
	int posicion = buscarEquipoPorID(equipos, idBuscar);
	
	if(posicion != -1){
		cout << "\nEquipo encontrado:\n";
		cout << "ID: " << equipos[posicion].id << endl;
		cout << "Nombre: " << equipos[posicion].nombre << endl;
		cout << "Entrenador: " << equipos[posicion].entrenador << endl;
		
		if(equipos[posicion].jugadores.size() == 0){
			cout << "Jugadores: Ninguno\n";
		} else {
			cout << "Jugadores (" << equipos[posicion].jugadores.size() << "):\n";
			for(int j = 0; j < equipos[posicion].jugadores.size(); j++){
				cout << "  " << (j + 1) << ". ID: " << equipos[posicion].jugadores[j].id
				     << " - " << equipos[posicion].jugadores[j].nombre 
				     << " - " << equipos[posicion].jugadores[j].posicion 
				     << " (" << equipos[posicion].jugadores[j].edad << " años)\n";
			}
		}
	} else {
		cout << "\nEquipo no encontrado.\n";
	}
}

void eliminarJugador(vector<Equipo>& equipos){
	int idEquipo, idJugador;
	cout << "\n---Eliminar Jugador---\n";
	cout << "Ingrese el ID del equipo: ";
	cin >> idEquipo;
	
	int posEquipo = buscarEquipoPorID(equipos, idEquipo);
	
	if(posEquipo != -1){
		cout << "Equipo: " << equipos[posEquipo].nombre << endl;
		cout << "Ingrese el ID del jugador a eliminar: ";
		cin >> idJugador;
		
		bool encontrado = false;
		for(int j = 0; j < equipos[posEquipo].jugadores.size(); j++){
			if(equipos[posEquipo].jugadores[j].id == idJugador){
				cout << "\nJugador encontrado: " << equipos[posEquipo].jugadores[j].nombre << endl;
				equipos[posEquipo].jugadores.erase(equipos[posEquipo].jugadores.begin() + j);
				cout << "Jugador eliminado exitosamente.\n";
				encontrado = true;
				break;
			}
		}
		
		if(!encontrado){
			cout << "\nJugador no encontrado en este equipo.\n";
		}
	} else {
		cout << "\nEquipo no encontrado.\n";
	}
}

vector<Equipo> filtrarPorEntrenador(vector<Equipo> equipos, string entrenadorBuscar){
	vector<Equipo> filtrados;
	
	for(int i = 0; i < equipos.size(); i++){
		if(equipos[i].entrenador == entrenadorBuscar){
			filtrados.push_back(equipos[i]);
		}
	}
	
	return filtrados;
}

void mostrarPorEntrenador(vector<Equipo> equipos){
	string entrenadorBuscar;
	cout << "\n---Filtrar por Entrenador---\n";
	cout << "Ingrese el nombre del entrenador: ";
	cin.ignore();
	getline(cin, entrenadorBuscar);
	
	vector<Equipo> filtrados = filtrarPorEntrenador(equipos, entrenadorBuscar);
	
	if(filtrados.size() == 0){
		cout << "\nNo hay equipos dirigidos por " << entrenadorBuscar << ".\n";
		return;
	}
	
	cout << "\nEquipos dirigidos por " << entrenadorBuscar << ":\n";
	for(int i = 0; i < filtrados.size(); i++){
		cout << "\n" << (i + 1) << ". " << filtrados[i].nombre 
		     << " (ID: " << filtrados[i].id << ")\n";
		cout << "   Jugadores: " << filtrados[i].jugadores.size() << endl;
	}
	cout << "\nTotal: " << filtrados.size() << " equipo(s).\n";
}

void eliminarEquipo(vector<Equipo>& equipos){
	int idBuscar;
	cout << "\n---Eliminar Equipo---\n";
	cout << "Ingrese el ID del equipo: ";
	cin >> idBuscar;
	
	int posicion = buscarEquipoPorID(equipos, idBuscar);
	
	if(posicion != -1){
		cout << "\nEquipo encontrado: " << equipos[posicion].nombre << endl;
		cout << "Entrenador: " << equipos[posicion].entrenador << endl;
		cout << "Jugadores: " << equipos[posicion].jugadores.size() << endl;
		
		equipos.erase(equipos.begin() + posicion);
		cout << "\nEquipo eliminado exitosamente (junto con todos sus jugadores).\n";
	} else {
		cout << "\nEquipo no encontrado.\n";
	}
}

int main(){
	vector<Equipo> equipos;
	int opcion;
	
	do{
		cout << "\n--   SISTEMA DE GESTION DE EQUIPOS --\n";
		cout << "1. Registrar equipo\n";
		cout << "2. Agregar jugador a un equipo\n";
		cout << "3. Listar equipos con sus jugadores\n";
		cout << "4. Buscar equipo por ID\n";
		cout << "5. Eliminar jugador de un equipo\n";
		cout << "6. Filtrar equipos por entrenador\n";
		cout << "7. Eliminar equipo completo\n";
		cout << "8. Salir\n";
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		
		switch(opcion){
			case 1:
				registrarEquipo(equipos);
				break;
			case 2:
				agregarJugador(equipos);
				break;
			case 3:
				listarEquipos(equipos);
				break;
			case 4:
				buscarEquipo(equipos);
				break;
			case 5:
				eliminarJugador(equipos);
				break;
			case 6:
				mostrarPorEntrenador(equipos);
				break;
			case 7:
				eliminarEquipo(equipos);
				break;
			case 8:
				cout << "\n¡Gracias por usar el sistema!\n";
				break;
			default:
				cout << "\nOpcion invalida. Intente de nuevo.\n";
		}
		
	} while(opcion != 8);
	
	return 0;
}
