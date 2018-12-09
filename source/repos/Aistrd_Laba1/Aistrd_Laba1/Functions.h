#pragma once

void check_input(int & value);//Проверка ввода
void check_input_positive_value(int &value);//Проверка ввода с проверкой на неотрицательность
void fill_array(int ** const array, const int height, const int length, const int start, const int count_of_elem);//Заполнение массива
void show_array(const int * const* array, const int height, const int length);//Вывод массива в консоль
bool is_equal(int ** const array_1, const int length_1, const int height_1, int ** const array_2, const int length_2, const int height_2);//Сравнение двух массивов