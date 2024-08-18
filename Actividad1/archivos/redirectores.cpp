#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv) {

	// Esto Es un script en cpp para probar los redirectores
	// Compilamos el codigo:
	// g++ -o redirector redirector.cpp &&./redirector

	// Los redirectores también pueden ser utilizados para redireccionar la salida de errores y la entrada estandar
	// Por ejemplo:
	// g++ -o redirector redirector.cpp &&./redirector 2> error_log.txt 1> output.txt
	
	// En este caso, los errores se almacenarán en el archivo error

	cout << "[+] Esto es una salida estandar (stdout)" << endl;
	
	cerr << "[-] Esto es una salida de error (stderr)" << endl;

	// Los redirectores también pueden ser utilizados para redireccionar la entrada estandar
	// Por ejemplo:
	// g++ -o redirector redirector.cpp &&./redirector < input.txt

	string input;

	cout << "[+] Ingresa frase: "; cin >> input;

	return 0;
}