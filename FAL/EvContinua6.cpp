/*#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool valido(const vector<int> &puestos, const vector<vector<int>> &vetos, int pos, int artista) {
	//SI LA POSICION YA ESTA OCUPADA
	if (puestos[pos] != -1) {
		return false;
	}
	//SI NO ERES EL PRIMERO, EL PUESTO DE DELANTE ESTA OCUPADO Y NO QUIERES TOCAR DETRAS SUYO
	else if (pos != 0 && puestos[pos - 1] != -1 && vetos[artista][puestos[pos - 1]] != 1) {
		return false;
	}
	//SI NO ERES EL ULTIMO, EL PUESTO DE DETRAS ESTA OCUPADO Y NO QUIERE TOCAR DETRAS TUYO
	else if (pos + 1 < puestos.size() && puestos[pos + 1] != -1 && vetos[puestos[pos + 1]][artista] != 1) {
		return false;
	}
	return true;
}

bool mereceLaPena(vector<int> puestos, int solAct, int poda, int solucion) {
	if (poda + solAct < solucion) {
		return false;
	}
	return true;
}

void resolver (int &solucion,int &solucionAct, vector<int> &puestos,const vector<vector<int>> &donaciones,const vector<vector<int>> &vetos, int etapa, int ultima, vector<int> maximoPorPosicion, int poda) {
	//SI SE HAN COLOCADO TODOS LOS ARTISTAS CORRECTAMENTE SE MIRA SI LAS DONACIONES PARA ESTA COLOCACION SON LAS MAYORES
	if (etapa == ultima) {
		if (solucionAct > solucion) {
			solucion = solucionAct;
		}
	}
	else {
			//PRUEBA TODAS LAS POSICIONES PARA CADA ARTISTA
			for (int i = 0; i < ultima; i++) {
				if (valido(puestos, vetos, etapa, i)) {
					//SUMA AL RESULTADO ACTUAL LAS DONACIONES DEL ARTISTA EN LA POSICION "I" Y LLAMA A LA FUNCION PARA EL SIGUIENTE ARTISTA
					solucionAct += donaciones[i][etapa];
					poda -= maximoPorPosicion[etapa];
					puestos[etapa] = i;
					if (mereceLaPena(puestos, solucionAct, poda, solucion)) {
						resolver(solucion, solucionAct, puestos, donaciones, vetos, etapa + 1, ultima, maximoPorPosicion, poda);
					}
						poda += maximoPorPosicion[etapa];
					puestos[etapa] = -1;
					solucionAct -= donaciones[i][etapa];
				}
				
				//COMPRUEBA SI LA POSICION ACTUAL ES VALIDA
			}
	}
}

void resolverCaso() {
	vector<vector<int>> donaciones, vetos;
	int n, aux, solucion = 0, solucionAct = 0, poda = 0; 
	cin >> n;
	vector<int> vsolAct (n, -1);
	vector<int> vpoda(n, 0);
	for (int i = 0; i < n; i++) {
		vector<int> vaux;
		for (int k = 0; k < n; k++) {
			cin >> aux;
			vaux.push_back(aux);
			if (aux > vpoda[k]) {
				vpoda[k] = aux;
			}
		}
		donaciones.push_back(vaux);
	}
	for (int i = 0; i < n; i++) {
		poda += vpoda[i];
	}
	for (int i = 0; i < n; i++) {
		vector<int> vaux;
		for (int k = 0; k < n; k++) {
			cin >> aux;
			vaux.push_back(aux);
		}
		vetos.push_back(vaux);
	}

	resolver(solucion,solucionAct, vsolAct, donaciones, vetos, 0, n, vpoda,  poda);
	if (solucion == 0) {
		cout << "NEGOCIA CON LOS ARTISTAS\n";
	}
	else {
		cout << solucion << "\n";
	}
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	unsigned int numCasos;
	std::cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		resolverCaso();
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}*/