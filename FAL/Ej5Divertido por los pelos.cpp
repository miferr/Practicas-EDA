/*#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


void resuelveCaso() {
	vector<int> v;
	int n, d, aux;
	cin >> d >> n;

	for (int i = 0; i < n; i++) {
		cin >> aux; 
		v.push_back(aux);
	}

	bool crecienteYDivertido = true;
	int daux = d, i = 1;

	while (crecienteYDivertido && i < n) {
		if (v[i] < v[i - 1]) {
			crecienteYDivertido = false;
		}
		else if (v[i] > v[i - 1] + 1) {
			crecienteYDivertido = false;
		}
		else if (v[i] == v[i - 1]) {
			daux--;
			if (daux == 0) {
				crecienteYDivertido = false;
			}
		}
		else { daux = d; }
		i++;
	}

	cout << (crecienteYDivertido ? "SI\n" : "NO\n");
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