/*#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


char resolver(vector<char> v, int i, char ini) {
	if (i == v.size()) {
		return (char)(int)ini + i;
	}
	else if ((int)v[i] != (int)ini + i) {
		return (char)(int)ini + i;
	}

	char r = resolver(v, i + 1, ini);
	return r;
}

void resuelveCaso() {
	vector<char> v;
	
	int n;
	char ini, fin, aux;
	cin >> ini >> fin;

	n = (int)fin - (int)ini;

	for (int i = 0; i < n; i++) {
		cin >> aux;
		v.push_back(aux);
	}

	cout << resolver(v, 0, ini) << "\n";
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