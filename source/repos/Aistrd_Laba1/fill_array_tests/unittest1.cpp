#include "stdafx.h"
#include "CppUnitTest.h"
#include "C:\\Users\byval\\source\\repos\\Aistrd_Laba1\\Aistrd_Laba1\\Functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace fill_array_tests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(is_equal_eq_array_test)//Массивы одинаковые
		{
			int set_of_numbers[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			int height = 2, length = 3;

			int **array_1 = new int*[height];
			for (int i = 0; i < height; i++)
				array_1[i] = new int[length];

			int **array_2 = new int*[height];
			for (int i = 0; i < height; i++)
				array_2[i] = new int[length];

			for (int i = 0; i < height; i++) {
				for (int j = 0; j < length; j++) {
					array_1[i][j] = set_of_numbers[j + i * length];
					array_2[i][j] = set_of_numbers[j + i * length];
				}
			}
			Assert::IsTrue(is_equal(array_1, height, length, array_2, height, length));
		}
		TEST_METHOD(is_equal_diff_elem_test)//Массивы имеют различные элементы
		{
			int set_of_numbers_1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			int set_of_numbers_2[] = { 1, 2, 3, 4, 6, 5, 7, 8, 9, 10 };
			int height = 2, length = 3;

			int **array_1 = new int*[height];
			for (int i = 0; i < height; i++)
				array_1[i] = new int[length];

			for (int i = 0; i < height; i++) {
				for (int j = 0; j < length; j++) {
					array_1[i][j] = set_of_numbers_1[j + i * length];
				}
			}

			int **array_2 = new int*[height];
			for (int i = 0; i < height; i++)
				array_2[i] = new int[length];

			for (int i = 0; i < height; i++) {
				for (int j = 0; j < length; j++) {
					array_2[i][j] = set_of_numbers_2[j + i * length];
				}
			}
			Assert::IsFalse(is_equal(array_1, height, length, array_2, height, length));
		}
		TEST_METHOD(is_equal_diff_height_test)//Массивы имеют разное количество строк
		{
			int set_of_numbers[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			const int height_1 = 2, length_1 = 3;
			const int height_2 = 3, length_2 = 3;

			int **array_1 = new int*[height_1];
			for (int i = 0; i < height_1; i++)
				array_1[i] = new int[length_1];

			for (int i = 0; i < height_1; i++) {
				for (int j = 0; j < length_1; j++) {
					array_1[i][j] = set_of_numbers[j + i * length_1];
				}
			}

			int **array_2 = new int*[height_2];
			for (int i = 0; i < height_2; i++)
				array_2[i] = new int[length_2];

			for (int i = 0; i < height_2; i++) {
				for (int j = 0; j < length_2; j++) {
					array_2[i][j] = set_of_numbers[j + i * length_2];
				}
			}
			Assert::IsFalse(is_equal(array_1, height_1, length_1, array_2, height_2, length_2));
		}
		TEST_METHOD(is_equal_diff_length_test)//Массивы имеют разные длины строк
		{
			int set_of_numbers[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			const int height_1 = 2, length_1 = 3;
			const int height_2 = 2, length_2 = 2;

			int **array_1 = new int*[height_1];
			for (int i = 0; i < height_1; i++)
				array_1[i] = new int[length_1];

			for (int i = 0; i < height_1; i++) {
				for (int j = 0; j < length_1; j++) {
					array_1[i][j] = set_of_numbers[j + i * length_1];
				}
			}

			int **array_2 = new int*[height_2];
			for (int i = 0; i < height_2; i++)
				array_2[i] = new int[length_2];

			for (int i = 0; i < height_2; i++) {
				for (int j = 0; j < length_2; j++) {
					array_2[i][j] = set_of_numbers[j + i * length_2];
				}
			}
			Assert::IsFalse(is_equal(array_1, height_1, length_1, array_2, height_2, length_2));
		}
		TEST_METHOD(usual_rectangle_fill_array_test)//Проверка заполнения небольшого прямоугольного массива
		{
			int set_of_numbers[] = { 1, 2, 3, 6, 5, 4 };
			int height = 2, length = 3;

			int **array_1 = new int*[height];
			for (int i = 0; i < height; i++)
				array_1[i] = new int[length];

			for (int i = 0; i < height; i++) {
				for (int j = 0; j < length; j++) {
					array_1[i][j] = set_of_numbers[j + i * length];
				}
			}

			int **array_2 = new int*[height];
			for (int i = 0; i < height; i++)
				array_2[i] = new int[length];

			int size = height * length;
			int start = 1;
			fill_array(array_2, height, length, start, size);
			Assert::IsTrue(is_equal(array_1, height, length, array_2, height, length));
		}
		TEST_METHOD(usual_square_fill_array_test)//Проверка заполнения небольшого квадратного массива
		{
			int set_of_numbers[] = { 1, 2, 3, 8, 9, 4, 7, 6, 5 };
			int height = 3, length = 3;

			int **array_1 = new int*[height];
			for (int i = 0; i < height; i++)
				array_1[i] = new int[length];

			for (int i = 0; i < height; i++) {
				for (int j = 0; j < length; j++) {
					array_1[i][j] = set_of_numbers[j + i * length];
				}
			}

			int **array_2 = new int*[height];
			for (int i = 0; i < height; i++)
				array_2[i] = new int[length];

			int size = height * length;
			int start = 1;
			fill_array(array_2, height, length, start, size);
			Assert::IsTrue(is_equal(array_1, height, length, array_2, height, length));
		}
		TEST_METHOD(one_row_fill_array_test)//Проверка заполнения массива из одной строки
		{
			int set_of_numbers[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
			int height = 1, length = 9;

			int **array_1 = new int*[height];
			for (int i = 0; i < height; i++)
				array_1[i] = new int[length];

			for (int i = 0; i < height; i++) {
				for (int j = 0; j < length; j++) {
					array_1[i][j] = set_of_numbers[j + i * length];
				}
			}

			int **array_2 = new int*[height];
			for (int i = 0; i < height; i++)
				array_2[i] = new int[length];

			int size = height * length;
			int start = 1;
			fill_array(array_2, height, length, start, size);
			Assert::IsTrue(is_equal(array_1, height, length, array_2, height, length));
		}
		TEST_METHOD(one_column_fill_array_test)//Проверка заполнения массива из одного столбца
		{
			int set_of_numbers[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			int height = 9, length = 1;

			int **array_1 = new int*[height];
			for (int i = 0; i < height; i++)
				array_1[i] = new int[length];

			for (int i = 0; i < height; i++) {
				for (int j = 0; j < length; j++) {
					array_1[i][j] = set_of_numbers[j + i * length];
				}
			}

			int **array_2 = new int*[height];
			for (int i = 0; i < height; i++)
				array_2[i] = new int[length];

			int size = height * length;
			int start = 1;
			fill_array(array_2, height, length, start, size);
			Assert::IsTrue(is_equal(array_1, height, length, array_2, height, length));
		}
		TEST_METHOD(square_2x2_fill_array_test)//Проверка заполнения квадратного массива размером 2 на 2 (погранично малый случай)
		{
			int set_of_numbers[] = { 1, 2, 4, 3};
			int height = 2, length = 2;

			int **array_1 = new int*[height];
			for (int i = 0; i < height; i++)
				array_1[i] = new int[length];

			for (int i = 0; i < height; i++) {
				for (int j = 0; j < length; j++) {
					array_1[i][j] = set_of_numbers[j + i * length];
				}
			}

			int **array_2 = new int*[height];
			for (int i = 0; i < height; i++)
				array_2[i] = new int[length];

			int size = height * length;
			int start = 1;
			fill_array(array_2, height, length, start, size);
			Assert::IsTrue(is_equal(array_1, height, length, array_2, height, length));
		}
		TEST_METHOD(one_elem_fill_array_test)//Проверка заполнения массива из одного элемента
		{
			int set_of_numbers[] = { 1};
			int height = 1, length = 1;

			int **array_1 = new int*[height];
			for (int i = 0; i < height; i++)
				array_1[i] = new int[length];

			for (int i = 0; i < height; i++) {
				for (int j = 0; j < length; j++) {
					array_1[i][j] = set_of_numbers[j + i * length];
				}
			}

			int **array_2 = new int*[height];
			for (int i = 0; i < height; i++)
				array_2[i] = new int[length];

			int size = height * length;
			int start = 1;
			fill_array(array_2, height, length, start, size);
			Assert::IsTrue(is_equal(array_1, height, length, array_2, height, length));
		}
	};
}