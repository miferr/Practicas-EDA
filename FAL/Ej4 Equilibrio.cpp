/*#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



void resuelveCaso() {
	vector<int> v;
	int n, aux;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		v.push_back(aux);
	}

	int p = -1, equilibrio = 0;

	for (int i = 0; i < n; i++) {
		if (v[i] == 0) {
			equilibrio -= 1;
		}
		else if (v[i] == 1) {
			equilibrio += 1;
		}
		if (equilibrio == 0) {
			p = i;
		}
	}

	cout << p << "\n";
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