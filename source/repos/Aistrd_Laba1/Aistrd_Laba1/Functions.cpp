#include "pch.h"
#include "Functions.h"
#include <iostream>

using namespace std;

void check_input_positive_value(int &value) {//Проверка ввода с проверкой на неотрицательность
	while (cin.fail() || value < 0) {
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "Введите корректное значение: ";
		cin >> value;
	}
	std::cin.ignore(32767, '\n');
}

void check_input(int &value) {//Проверка ввода
	while (cin.fail()) {
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "Введите корректное значение: ";
		cin >> value;
	}
	std::cin.ignore(32767, '\n');
}

void fill_array(int ** const array, const int height, const int length, const int start, const int count_of_elem) {//Заполнение массива
	int counter_of_elem = 0;//Счетчик элементов массива
	int current_value = start;//Текущее присваиваемое значение 
	int number_of_string = 0, number_of_column = 0;
	for (int lap = 1; counter_of_elem < count_of_elem; lap++) {
		while (counter_of_elem < count_of_elem && number_of_column < length - (lap - 1)) {//Строка слева направо
			array[number_of_string][number_of_column] = current_value;
			current_value++;
			number_of_column++;
			counter_of_elem++;
		}
		number_of_column--;
		number_of_string++;
		while (counter_of_elem < count_of_elem && number_of_string < height - (lap - 1)) {//Столбец сверху вниз
			array[number_of_string][number_of_column] = current_value;
			current_value++;
			number_of_string++;
			counter_of_elem++;
		}
		number_of_string--;
		number_of_column--;
		while (counter_of_elem < count_of_elem && number_of_column >= (lap - 1)) {//Строка слева направо
			array[number_of_string][number_of_column] = current_value;
			current_value++;
			number_of_column--;
			counter_of_elem++;
		}
		number_of_column++;
		number_of_string--;
		while (counter_of_elem < count_of_elem && number_of_string >= lap) {//Столбец сверху вниз
			array[number_of_string][number_of_column] = current_value;
			current_value++;
			number_of_string--;
			counter_of_elem++;
		}
		number_of_string++;
		number_of_column++;
	}
}

void show_array(const int * const* array, const int height, const int length) {//Вывод массива в консоль
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < length; j++) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
}

bool is_equal(int ** const array_1, const int height_1, const int length_1, int ** const array_2, const int height_2, const int length_2) {//Сравнение двух массивов
	if (height_1 != height_2 || length_1 != length_2) {
		return false;
	}
	for (int i = 0; i < height_1; i++) {
		for (int j = 0; j < length_1; j++) {
			if (array_1[i][j] != array_2[i][j]) {
				return false;
			}
		}
	}
	return true;
}