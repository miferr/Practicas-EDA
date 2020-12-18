
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int complementario(int n) {
	if (n % 10 == n) {
		return 9 - n;
	}
	int anterior = complementario(n/10);
	return ((anterior * 10) + (9 - n % 10));
}

int inverso(int n, int &pos) {
	if (n % 10 == n) {
		return n;
	}
	int anterior = inverso(n / 10, pos);
	pos++;
	n = n%10;
	for (int i = 0; i < pos; i++) {
		n *= 10;
	}
	return n + anterior;
}



void resuelveCaso() {
	int numero, pos = 0;
	cin >> numero;
	int c = complementario(numero);
	int i = inverso(num, pos);
	cout << i << "\n";
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