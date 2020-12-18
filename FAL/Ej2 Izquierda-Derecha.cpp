#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//Coste lineal al recorrer cada elemento del array y hacer operaciones de coste constante con ellos.
bool resuelve(vector<int> a, int p) {
	//invariant: a[i] < v && i <= p || a[i] > v && a[i] > p
	int v = 0;
	bool b = true;
	for (int i = 0; i < a.size(); i++) {
		if (i <= p) {
			if (a[i] > v) {
				v = a[i];
			}
		}
		else {
			if (a[i] <= v) {
				b = false;
			}
		}
	}
	return b;
}

void resuelveCaso() {
	int n, p, aux;
	cin >> n >> p;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		a.push_back(aux);
	}
	cout << (resuelve(a, p) ? "SI\n" : "NO\n");
	a.clear();
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