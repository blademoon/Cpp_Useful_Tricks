// Полезный приём: Преобразование строки типа STRING в нижний регистр
#include <iostream>
#include <string>

using namespace std;

string string_to_lower(const string & value) {
    string result = "";             // Временная переменная для хранения результата

    // Перебираем переменную типа string по буквам в цикле.
	for (char item : value) {
        result += tolower(item);
	}
    return result;
}

int main() {
	string word = "THIS IS STRING for TEST";
    string result1 = string_to_lower(word);

	cout << "INPUT string: " << word << endl;
	cout << "RESULT string: " << result1 << endl;

	return 0;
}
