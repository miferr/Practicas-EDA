#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct equidiagonal {
	bool b;
	int i;
};

equidiagonal resolver(vector<vector<int>> v, int fila, int columna, int tamanio) {
	if (tamanio == 1) {
		return { true, v[fila][fila] };
	}
	else if (tamanio == 2) {
		if (v[fila][columna] * v[fila + 1][columna - 1] != v[fila + 1][columna] * v[fila][columna - 1]) {
			return {false, 0};
		}
		return { true, v[fila][columna] * v[fila + 1][columna - 1] };
	}

	equidiagonal si = resolver(v, fila, fila + 1, tamanio /2);
	equidiagonal sd = resolver(v, fila, columna, tamanio / 2);
	equidiagonal ii = resolver(v, columna/2 + 1, fila + 1, tamanio / 2);
	equidiagonal id = resolver(v, columna/2 + 1, columna, tamanio / 2);

	if (si.i * id.i != sd.i * ii.i) {
		return { false, 0 };
	}

	return {si.b && sd.b && ii.b && id.b ,si.i * id.i};

}

void resolverCaso() {
	int n, aux;
	vector<vector<int>> v;

	cin >> n; 

	for (int i = 0; i < n; i++) {
		vector<int> vAux;
		for (int i = 0; i < n; i++) {
			cin >> aux;
			vAux.push_back(aux);
		}
		v.push_back(vAux);
	}

	equidiagonal r = resolver(v, 0, v.size() - 1, v.size());
	if (!r.b) {
		cout << "NO\n";
	}
	else {
		cout << "SI " << r.i << "\n";
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
}