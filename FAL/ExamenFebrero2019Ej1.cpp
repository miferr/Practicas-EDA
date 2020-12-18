#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

int resolver(vector<bool> v, int k) {
	vector<int> posiciones;
	int max = v.size() + 1;
	bool encontrado = false;

	for (int i = 0; i < v.size(); i++) {
		if (v[i]) {
			posiciones.push_back(i);
			if (posiciones.size() == k) {
				if (max > posiciones.back() - posiciones.front() + 1) {
					max = posiciones.back() - posiciones.front() + 1;
				}
				encontrado = true;
				posiciones.erase(posiciones.begin());
			}
		}
	}
	return max;
}

bool resuelveCaso() {
	vector<bool> v;
	int n, k, aux;
	cin >> n;
	if (n == -1)
		return false;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		v.push_back(aux);
	}
	cin >> k;
	cout << resolver(v, k) << "\n";

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