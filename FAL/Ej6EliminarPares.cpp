#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool resuelveCaso() {

	vector<int> v;
	int n, aux;
	cin >> n;

	if (n == -1)
		return false;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		v.push_back(aux);
	}

	for (int i = 0; i < v.size(); i++) {
		if (v[i] % 2 != 0){
			v.erase(v.begin() + i--);
		}
	}

	for (int e : v) {
		cout << e << " ";
	}
	cout << "\n";

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