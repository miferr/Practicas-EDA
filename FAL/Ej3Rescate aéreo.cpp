#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



void resuelveCaso() {
	vector<int> v;
	int n, a, aux;
	cin >> n >> a;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		v.push_back(aux);
	}
	
	int max_ini = 0, max_fin = -1, ini = 0, fin = -1;
	bool contar = false;

	for (int i = 0; i < n; i++) {
		if (v[i] > a) {
			if (!contar) {
				contar = true;
				ini = i;
				fin = i;
			}
			else {
				fin = i;
			}
		}
		else {
			contar = false;
		}
		if (fin - ini > max_fin - max_ini) {
			max_ini = ini;
			max_fin = fin;
		}
	}
	if (fin - ini > max_fin - max_ini) {
		max_ini = ini;
		max_fin = fin;
	}

	cout << max_ini << " " << max_fin << "\n";
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
}