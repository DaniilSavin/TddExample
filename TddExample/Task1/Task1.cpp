// Task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "indexer.cpp"
#include <iostream>

using namespace std;

int main()
{
	double* array = new double[4]{ 1, 2, 3, 4 };
	indexer indexer1 = indexer(array, 4, 1, 2);

}
