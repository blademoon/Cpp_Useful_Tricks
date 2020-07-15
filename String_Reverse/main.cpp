#include <iostream>
#include <string>

using namespace std;

// Метод переварачивающий строку. Важный момент! Здесь мы перебираем все символы объекта типа string c
// конца строки до ее начала. Но начинаем мы не с самого конца строки, а с предпоследнего символа! Потому что последний символ в
// любом объекте типа string - символ конца строки! В объектах типа string 0 символ - это символ /000 - символ конца строки! Его
// нам нужно обрезать для этой задачи!

void Reverse(string & value) {
    string temp;
    for (int i = value.size()-1; i >= 0; --i) {
        temp += value[i];
    }
    value = temp;
}

int main()  {
    string test = "THIS IS string!";
    cout << "Your string before reverse: " << test << endl;
    Reverse(test);
    cout << "Your string after reverse: " << test << endl;
    return 0;
}
