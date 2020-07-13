// Полезный приём: Перебор типа STRING по буквам!
#include <iostream>
#include <string>

using namespace std;

int main() {
	string word = "THIS IS STRING";

    // Перебираем переменную типа string по буквам в цикле.
	for (char item : word) {
        cout << item << endl;
	}

	return 0;
}
