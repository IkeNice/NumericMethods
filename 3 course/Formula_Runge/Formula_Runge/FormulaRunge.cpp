// FormulaRunge.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <iomanip>
#include <fstream>

using namespace std;

double func(double x)
{
	//return x*x*x; // [0;1] +0.1
	//return x + sin(x); // [-1;1] +0.2
	return atan(x) + 2*log(x); //[1;2] +0.1
}
double proiz(double x)
{
	//return 3 * x*x;
	//return 1 + cos(x);
	return 1 / (1 + x*x) + 2 / x;
}
double aprox(double x, double h)
{
	return (func(x + h) - func(x - h)) / (2 * h);
}

double left_aprox(double x, double h)
{
	return (func(x) - func(x - h)) / h;
}

int main()
{
	//setlocale(LC_ALL, "Russian");
	double a, b, result;
	double res;
	double fh = 0, fkh = 0;
	double h; //= 0.5;
	cout << "Vvedite otrezok: ";//"Введите отрезок: ";
	cin >> a >> b;
	cout << "Vvedite shag: ";//"Введите шаг";
	cin >> h;
	/*
	ofstream fout1("output1.txt");
	ofstream fout2("output2.txt");
	ofstream fout3("output3.txt");
	*/
	ofstream fout4("output4.txt");
	for (double i = a; i <= b; i = i + h)
	{
		/*
		fh = aprox(i, h);
		fkh = aprox(i, 2 * h);
		*/
		//cout << "point: " << i << endl;
		
		//cout << "first: " << left_aprox(i, h) << endl;
		//fout1 << left_aprox(i, h) << endl;

		fh = left_aprox(i, h);
		fkh = left_aprox(i, 2 * h);
		result = fh + (fh - fkh) / (pow(2, 2) - 1);
		//cout << "second: " << setprecision(15) << result << endl;
		//fout2 << result << endl;

		//cout << "tochn proizvodnaya: " << proiz(i) << endl;
		//fout3 << proiz(i) << endl;
		//cout << endl;

		fout4 << left_aprox(i, h) << " " << result << " " << proiz(i) << endl;
	}
	/*
	fout1.close();
	fout2.close();
	fout3.close();
	*/
	fout4.close();
	system("pause");
	return 0;
}
