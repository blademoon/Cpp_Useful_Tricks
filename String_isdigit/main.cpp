// Необходимо ей немного доработать, убрать отладочный вывод!

#include <iostream>
#include <string>
#include <vector>

using namespace std;


// Функция проверяющая состоит ли дата только из чисел и знака "-"
// http://www.cplusplus.com/reference/string/string/find_first_not_of/
bool isdigit(const string & test_string) {
    // Ищем в строке символы не относящиеся к числам
    size_t found = test_string.find_first_not_of("-0123456789");
    // Отладка! Если такой символ найден, то возвращяем ложь
    if (found!=std::string::npos) {
        cout << "The first non-numeric character is " << test_string[found];
        return false;
    } else {return true;}
}


int main () {
    vector <string> numbers = {"01", "0b","-10","-01","adb"};

    for (string & value : numbers) {
        cout << "Value " << value << " " << isdigit(value) << endl;
    }

    return 0;
}
