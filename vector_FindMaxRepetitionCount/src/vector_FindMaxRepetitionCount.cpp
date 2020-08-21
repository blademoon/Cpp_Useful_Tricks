 // Полезный приём: Подсчёт максимального кол-во повторений в векторе.

#include <iostream>
#include <map>
#include <vector>
#include <tuple>

using namespace std;


enum class Lang {
  DE, FR, IT
};

struct Region {
  string std_name;
  string parent_std_name;
  map <Lang, string> names;
  int64_t population;
};

// Переопределим оператор "<" для работы словаря с объектами типа Region
bool operator < (const Region & lhs, const Region & rhs) {

	return tie(lhs.std_name,lhs.parent_std_name,lhs.names,lhs.population) <
	  tie(rhs.std_name,rhs.parent_std_name,rhs.names,rhs.population);
}

// Напишите функцию FindMaxRepetitionCount, принимающую базу регионов и определяющую, какое максимальное количество повторов
// (число вхождений одного и того же элемента) она содержит. Две записи (объекты типа Region) считаются различными, если они
// отличаются хотя бы одним полем.
// Если все записи уникальны, считайте максимальное количество повторов равным 1. Если записи отсутствуют, верните 0.
// Гарантируется, что типа int достаточно для хранения ответа.

int FindMaxRepetitionCount(const vector <Region> & regions) {

	// Если записи отсутствуют, верните 0. Гарантируется, что типа int достаточно для хранения ответа.
	if (regions.size() == 0) {return 0;}

	int result = 0;	// Счётчик повторов.

	// Для решения задачи по подсчёту кол-ва встреченных в БД повторов будем использовать свойство словаря -
	// При добавлении в словарь уникального элемента будем добавлен новый элемент,
	// Если же такой элемент уже есть в словаре, то его счётчик увеличится на 1.

	// Словарь со счётчиками повторов для каждого уникального элемента.
	map <Region, int> repetition_count;

	for (const Region& region : regions) {
		// В результат будет сохраняться максимальное из двух значений, самого результата
		// и увеличеного на 1 (префиксный инкремент) счётчика для соотвествующего региона из словаря repetition_count.
		result = max(result, ++repetition_count[region]);
	}

	return result;
}


int main() {
  cout << FindMaxRepetitionCount({
      {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      },
  }) << endl;

  cout << FindMaxRepetitionCount({
      {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Toulouse",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          31
      },
  }) << endl;

  return 0;
}
