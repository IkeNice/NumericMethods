// Метод прогонки ОДУ.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <iostream> 
#include <fstream>
using namespace std;

double eps, epsmax[100], A_nach, alpha1, alpha2, B_nach, beta1, beta2, y[100], al[100], bet[100], aa[100], bb[100], cc[100], x[100], ff[100];
int n;
const double pi = 3.141592653589793238463;
//1:	y''-y=x
//2:	y''-y=2x
//3:	y''+y=1
double f(double x)
{
	//return x;		
	//return 2 * x;
	return 1;
}

double p(double x)
{
	//return 0;
	//return 0;
	return 0;
}

double q(double x)
{
	//return -1;
	//return -1;
	return 1;
}

double yn(double x)
{
	//return (2 * exp(1)*sinh(x) / (exp(2) - 1)) - x;
	//return (sinh(x) / sinh(1)) - 2 * x;
	return -cos(x) - sin(x) + 1;
}

int main()
{
	double a, b, h;
	n = 10; // кол-во шагов
	alpha1 = 1;		alpha2 = 0;
	beta1 = 1;		beta2 = 0;
	/*
	//1
	a = 0;	b = 1;
	A_nach = 0;		B_nach = 0;
	
	//2
	a = 0;	b = 1;
	A_nach = 0;		B_nach = -1;
	*/
	//3
	a = 0;		b = pi / 2;
	A_nach = 0;		B_nach = 0;
	
	h = (b - a) / n;//шаг

	for (int i = 0; i <= n; i++)
	{
		x[i] = a + h * i;
		aa[i] = 1 - p(x[i])*h / 2;
		bb[i] = 1 + p(x[i])*h / 2;
		cc[i] = 2 - q(x[i])*h*h;
		ff[i] = h * h*f(x[i]);
	}

	al[1] = alpha2 / (alpha2 - alpha1 * h);
	bet[1] = -(A_nach*h) / (alpha2 - alpha1 * h);

	for (int i = 1; i <= n - 1; i++)//Прямой ход
	{
		al[i + 1] = bb[i] / (cc[i] - al[i] * aa[i]);
		bet[i + 1] = (aa[i] * bet[i] - ff[i]) / (cc[i] - al[i] * aa[i]);
	}
	y[n] = (beta2*bet[n] + B_nach * h) / (beta2 + h * beta1 - beta2 * al[n]);

	for (int i = n - 1; i >= 0; i--)//обратный ход
	{
		y[i] = al[i + 1] * y[i + 1] + bet[i + 1];
	}
	for (int i = 0; i < n + 1; i++)
		cout << "x[" << i << "]: " << x[i] << "    y[" << i << "]: " << y[i] << "    yn[" << i << "]: " << yn(x[i]) << endl;
	//вывод
	
	eps = abs(yn(x[0]) - y[0]);
	epsmax[0] = eps;
	
	ofstream foup("output3.txt");
	for (int i = 0; i <= n; i++)
	{
		eps = abs(yn(x[i]) - y[i]);
		if (eps > epsmax[i]) 
			epsmax[i] = eps;
		foup << x[i] << "      " << y[i] << "     " << yn(x[i]) << endl;
	}
	foup.close();
	
	system("pause");
	return 0;
}



