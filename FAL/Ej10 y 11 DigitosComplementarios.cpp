#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int complementario(int n) {
	if (n % 10 == n) {
		return 9 - n;
	}
	int r = complementario(n / 10);
	n = 9 - (n % 10);
	return (r * 10) + n;
}

int inversoComplementario(int n, int &pos) {
	if (n % 10 == n) {
		return 9 - n;
	}
	int r = inversoComplementario(n / 10, pos);
	n = 9 - (n % 10);
	pos++;
	for (int i = 0; i < pos; i++) {
		n *= 10;
	}
	return r + n;
}



void resuelveCaso() {
	int numero, pos = 0;
	cin >> numero;
	cout << complementario(numero) << " " << inversoComplementario(numero, pos) << "\n";
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