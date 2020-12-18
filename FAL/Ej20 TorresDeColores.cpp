#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
const vector <string> colores = { "azul", "rojo", "verde" };

bool valido(const vector<int> &piezasAct, const vector<int> &piezasTot, int etapa, int tamanio, int mod, int verde) {
	if (piezasAct[mod] > piezasTot[mod]) {
		return false;
	}
	else if (etapa == 1 && piezasAct[1] != 1) {
		return false;
	}
	else if (piezasAct[1] + (piezasTot[1] - piezasAct[1]) <= piezasAct[0] + piezasAct[2] || piezasAct[1] + (tamanio - etapa) <= piezasAct[0] + piezasAct[2]) {
		return false;
	}
	else if (piezasAct[0] < piezasAct[2]) {
		return false;
	}
	else if (mod == verde) {
		return false;
	}
	return true;
}

void resolver(vector<vector<string>> &sol, vector<string> solActual, vector<int> piezasAct, const vector<int> &piezasTot,const int &tamanio, int etapa) {
	if (etapa == tamanio) {
		sol.push_back(solActual);
	}
	else {
		for (int i = 0; i < colores.size(); i++) {
			int verde = -1;
			if (etapa > 0 && solActual[solActual.size() - 1] == "verde") {
				verde = 2;
			}
			solActual.push_back(colores[i]);
			piezasAct[i]++;
			if (valido(piezasAct, piezasTot, etapa + 1, tamanio, i, verde)) {
				resolver(sol, solActual,piezasAct, piezasTot, tamanio, etapa + 1);
			}
			piezasAct[i]--;
			solActual.pop_back();
		}
	}
}

bool resuelveCaso() {
	vector <vector <string>> sol;
	vector <string> solAct;
	vector <int> piezas = { 0,0,0 }, piezasMax;
	int n, aux;
	cin >> n;
	if (!std::cin)
		return false;
	for (int i = 0; i < colores.size(); i++) {
		cin >> aux;
		piezasMax.push_back(aux);
	}

	resolver(sol,solAct,piezas,piezasMax, n, 0);
	if (sol.size() == 0) {
		cout << "SIN SOLUCION\n";
	}
	else {
		for (int i = 0; i < sol.size(); i++) {
			for (int k = 0; k < sol[i].size(); k++) {
				cout << sol[i][k] << " ";
			}
			cout << "\n";
		}
	}
	//Resolver problema
	//Escribir resultado
	return true;
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}