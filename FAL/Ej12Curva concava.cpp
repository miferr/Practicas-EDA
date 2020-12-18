#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int resolver(vector<int> v, int ini, int fin) {
	int p = (fin + ini) / 2;
	if (ini == fin) {
		return v[p];
	}
	else if (v[p] < v[p + 1]) {
		return v[p];
	}
	else if (ini == p) {
		if (v[p] > v[p + 1]) {
			return v[p + 1];
		}
	}
	else if (v[p] < v[ini]) {
		ini = p + 1;
	}
	else if (v[p] > v[fin]) {
		fin = p;
	}
	return resolver(v, ini, fin);
}

bool resuelveCaso() {
	vector<int> v;
	int n, aux;
	cin >> n;

	if (!std::cin)
		return false;

	for (int i = 0; i < n; i++) {
		cin >> aux;
		v.push_back(aux);
	}

	cout << resolver(v, 0, n - 1) << endl;
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