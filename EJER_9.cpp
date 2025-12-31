#include<iostream>
#include<vector>
using namespace std;

struct Pelicula{
	int id;
	string titulo;
	string director;
	bool enCartelera;
};

void registrarPelicula(vector<Pelicula>& peliculas){
	Pelicula nuevaPelicula;
	cout << "\n---Registrar Pelicula---\n";
	cout << "ID: ";
	cin >> nuevaPelicula.id;
	cin.ignore();
	cout << "Titulo: ";
	getline(cin, nuevaPelicula.titulo);
	cout << "Director: ";
	getline(cin, nuevaPelicula.director);
	
	int opcion;
	cout << "Estado (1=En cartelera / 2=Fuera de cartelera): ";
	cin >> opcion;
	nuevaPelicula.enCartelera = (opcion == 1);
	
	peliculas.push_back(nuevaPelicula);
	cout << "\nPelicula registrada exitosamente.\n";
}

void listarPeliculas(vector<Pelicula> peliculas){
	if(peliculas.size() == 0){
		cout << "\nNo hay peliculas registradas.\n";
		return;
	}
	
	cout << "\n---Lista de Peliculas---\n";
	for(int i = 0; i < peliculas.size(); i++){
		cout << "\nPelicula " << (i + 1) << ":\n";
		cout << "  ID: " << peliculas[i].id << endl;
		cout << "  Titulo: " << peliculas[i].titulo << endl;
		cout << "  Director: " << peliculas[i].director << endl;
		cout << "  Estado: " << (peliculas[i].enCartelera ? "En cartelera" : "Fuera de cartelera") << endl;
	}
}


void buscarPelicula(vector<Pelicula> peliculas){
	int idBuscar;
	bool encontrado = false;
	cout << "\n---Buscar Pelicula---\n";
	cout << "Ingrese el ID de la pelicula: ";
	cin >> idBuscar;
	cin.ignore();
	
	for(int i = 0; i < peliculas.size(); i++){
		if(peliculas[i].id == idBuscar){
			cout << "\nPelicula encontrada:\n";
			cout << "  ID: " << peliculas[i].id << endl;
			cout << "  Titulo: " << peliculas[i].titulo << endl;
			cout << "  Director: " << peliculas[i].director << endl;
			cout << "  Estado: " << (peliculas[i].enCartelera ? "En cartelera" : "Fuera de cartelera") << endl;
			encontrado = true;
			break;
		}
	}
	
	if(!encontrado){
		cout << "\nID invalido.\n";
	}
}

void cambiarEstado(vector<Pelicula>& peliculas){
	int idBuscar;
	bool encontrado = false;
	cout << "\n---Cambiar Estado---\n";
	cout << "Ingrese el ID de la pelicula: ";
	cin >> idBuscar;
	cin.ignore();
	
	for(int i = 0; i < peliculas.size(); i++){
		if(peliculas[i].id == idBuscar){
			cout << "\nPelicula encontrada: " << peliculas[i].titulo << endl;
			cout << "Estado actual: " << (peliculas[i].enCartelera ? "En cartelera" : "Fuera de cartelera") << endl;
			
			peliculas[i].enCartelera = !peliculas[i].enCartelera;
			
			cout << "Nuevo estado: " << (peliculas[i].enCartelera ? "En cartelera" : "Fuera de cartelera") << endl;
			cout << "\nEstado cambiado exitosamente.\n";
			encontrado = true;
			break;
		}
	}
	
	if(!encontrado){
		cout << "\nID invalido.\n";
	}
}

void eliminarPelicula(vector<Pelicula>& peliculas){
	int idBuscar;
	bool encontrado = false;
	cout << "\n---Eliminar Pelicula---\n";
	cout << "Ingrese el ID de la pelicula: ";
	cin >> idBuscar;
	cin.ignore();
	
	for(int i = 0; i < peliculas.size(); i++){
		if(peliculas[i].id == idBuscar){
			cout << "\nPelicula encontrada:\n";
			cout << "  Titulo: " << peliculas[i].titulo << endl;
			cout << "  Director: " << peliculas[i].director << endl;
			
			peliculas.erase(peliculas.begin() + i);
			cout << "\nPelicula eliminada exitosamente.\n";
			encontrado = true;
			break;
		}
	}
	
	if(!encontrado){
		cout << "\nID invalido.\n";
	}
}

vector<Pelicula> filtrarPorEstado(vector<Pelicula> peliculas, bool estado){
	vector<Pelicula> filtradas;
	
	for(int i = 0; i < peliculas.size(); i++){
		if(peliculas[i].enCartelera == estado){
			filtradas.push_back(peliculas[i]);
		}
	}
	
	return filtradas;
}

void mostrarPorEstado(vector<Pelicula> peliculas){
	int opcion;
	cout << "\n---Filtrar por Estado---\n";
	cout << "1. En cartelera\n";
	cout << "2. Fuera de cartelera\n";
	cout << "Seleccione una opcion: ";
	cin >> opcion;
	
	bool estado = (opcion == 1);
	vector<Pelicula> filtradas = filtrarPorEstado(peliculas, estado);
	
	if(filtradas.size() == 0){
		cout << "\nNo hay peliculas " << (estado ? "en cartelera" : "fuera de cartelera") << ".\n";
		return;
	}
	
	cout << "\nPeliculas " << (estado ? "en cartelera" : "fuera de cartelera") << ":\n";
	for(int i = 0; i < filtradas.size(); i++){
		cout << "\nPelicula " << (i + 1) << ":\n";
		cout << "  ID: " << filtradas[i].id << endl;
		cout << "  Titulo: " << filtradas[i].titulo << endl;
		cout << "  Director: " << filtradas[i].director << endl;
	}
	cout << "\nTotal: " << filtradas.size() << " pelicula(s).\n";
}

int main(){
	vector<Pelicula> peliculas;
	int opcion;
	
	do{
		cout << "\n   SISTEMA DE CATALOGO DE PELICULAS\n";
		cout << "1. Registrar pelicula\n";
		cout << "2. Listar peliculas\n";
		cout << "3. Buscar pelicula por ID\n";
		cout << "4. Cambiar estado\n";
		cout << "5. Eliminar pelicula\n";
		cout << "6. Filtrar por estado\n";
		cout << "7. Salir\n";
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		
		switch(opcion){
			case 1:
				registrarPelicula(peliculas);
				break;
			case 2:
				listarPeliculas(peliculas);
				break;
			case 3:
				buscarPelicula(peliculas);
				break;
			case 4:
				cambiarEstado(peliculas);
				break;
			case 5:
				eliminarPelicula(peliculas);
				break;
			case 6:
				mostrarPorEstado(peliculas);
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
