#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int resolver(vector<int> v, int i) {

	if (i == v.size() - 1) {
		return v[i];
	}

	int r = resolver(v, i + 1);
	return min(r, v[i]);
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

	cout << resolver(v, 0) << "\n";
	
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