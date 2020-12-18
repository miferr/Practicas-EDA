#include <iostream>
#include <fstream>
using namespace std;

bool resolver(int n, int &suma, int &digitos) {
	bool b;
	if (n / 10 == 0) {
		suma += n;
		digitos++;
		return true;
	}
	b = resolver(n / 10, suma, digitos);
	suma += n % 10;
	digitos++;
	int r = suma/digitos;
	if (r*digitos != suma) {
		return false;
	}
	return b;

}

bool resuelveCaso() {

	int n; 
	cin >> n;
	if (n == 0)
		return false;
	int suma = 0, digitos = 0;
	cout << (resolver(n, suma , digitos) ? "SI\n"  : "NO\n");

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