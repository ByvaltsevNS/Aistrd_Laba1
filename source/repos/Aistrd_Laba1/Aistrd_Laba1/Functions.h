#pragma once

void check_input(int & value);//�������� �����
void check_input_positive_value(int &value);//�������� ����� � ��������� �� �����������������
void fill_array(int ** const array, const int height, const int length, const int start, const int count_of_elem);//���������� �������
void show_array(const int * const* array, const int height, const int length);//����� ������� � �������
bool is_equal(int ** const array_1, const int length_1, const int height_1, int ** const array_2, const int length_2, const int height_2);//��������� ���� ��������