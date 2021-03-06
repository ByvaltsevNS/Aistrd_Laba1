// Aistrd_Laba1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>
#include "Functions.h"

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);

	int count_of_string, count_of_column, starting_value, count_of_elem;

	cout << "Здравствуйте!" << endl;
	cout << "Введите количество строк, из которых будет состоять ваш будущий массив: ";
	cin >> count_of_string;
	check_input_positive_value(count_of_string);
	cout << "Введите количество столбцов, из которых будет состоять ваш будущий массив: ";
	cin >> count_of_column;
	check_input_positive_value(count_of_column);
	cout << "Введите стартовое значение: ";
	cin >> starting_value;
	check_input(starting_value);

	count_of_elem = count_of_column * count_of_string;

	int **array = new int*[count_of_string];//Создание массива
	for (int i = 0; i < count_of_string; i++)
		array[i] = new int[count_of_column];

	fill_array(array, count_of_string, count_of_column, starting_value, count_of_elem);//Заполнение массива
	show_array(array, count_of_string, count_of_column);//Вывод массива в консоль

	for (int i = 0; i < count_of_string; i++)//Удаление массива
		delete[] array[i];
	delete[] array;

	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
