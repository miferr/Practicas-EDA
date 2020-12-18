//Miguel Ferreras Chumillas
/*
#include <iostream>
#include <fstream>
using namespace std;



void resuelveCaso() {
	int n, valles = 0, picos = 0, act, ant, sig;
	cin >> n;
	if (n < 2) {
		cin >> act;
		cout << picos << " " << valles << "\n";
	}
	else {
		cin >> ant;
		cin >> act;
		for (int i = 0; i < n - 2; i++) {
			cin >> sig;
			if (act < ant) {
				if (act < sig) {
					valles++;
				}
			}
			else if (act > ant) {
				if (act > sig) {
					picos++;
				}
			}
			ant = act;
			act = sig;
		}
		cout << picos << " " << valles << "\n";
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
		resuelveCaso();
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}*/