// LUразложение.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

double a[50][50], L[50][50], U[50][50];

int main()
{
	int n;
	int i, j;
	double sum = 0;

	/*
	cout << "n= ";
	cin >> n;
	cout << endl;
	
	// ввод матрицы
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}
	cout << "matrix: " << endl;

	// вывод матрицы
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << a[i][j] << "\t";
		cout << endl;
	}
	cout << endl;
	*/

	ifstream file_in("input1.txt");
	if (!file_in.is_open())
		cout << "file not open" << endl;
	else {
		file_in >> n;
		cout << "n = " << n << endl;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				file_in >> a[i][j];
				cout.width(3);
				cout << a[i][j];
			}
			cout << endl;

		}
	}
	// вычисление матриц L и U
	
	// проверка
	int flag = 1;
	for (int i = 0; i < n; ++i)
		if (a[i][i] == 0)
			flag = 0;
	
	if (flag)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				U[0][i] = a[0][i];
				L[i][0] = a[i][0] / U[0][0];
				double sum = 0;
				for (int k = 0; k < i; k++)
				{
					sum += L[i][k] * U[k][j];
				}
				U[i][j] = a[i][j] - sum;
				
				if (i > j)
				{
					L[j][i] = 0;
				}
				else
				{
					sum = 0;
					for (int k = 0; k < i; k++)
					{
						sum += L[j][k] * U[k][i];
					}
					L[j][i] = (a[j][i] - sum) / U[i][i];
				}
			}
		}
		cout << "matrix L: " << endl;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
				cout << L[i][j] << "\t";
			cout << endl;
		}
		cout << endl;

		cout << "matrix U: " << endl;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
				cout << U[i][j] << "\t";
			cout << endl;
		}
		cout << endl;

		// вычислеение определителя
		double detA = 1;
		for (int i = 0; i < n; ++i)
			detA = detA*U[i][i];

		cout << "detA= " << detA << endl;
	}

	else cout << "incorrect value" << endl;

	system("pause");
    return 0;
}

