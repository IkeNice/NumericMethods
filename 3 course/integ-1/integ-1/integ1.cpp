// integ1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <math.h>
#include <iomanip>
#include <iostream>

using namespace std;

double func(double x)
{
	return 4/(1+x*x);
}

int main()
{
	double a, b, n, h;
	cin >> a >> b;
	cin >> n;
	h = (b - a) / n;
	double sum=0;
	double xi = a;
	for (double i = 0; i <n; i ++)
	{
		sum = sum + h*func(xi);
		xi = xi + h;
		//cout << i << " " << sum << endl;
	}
	cout << setprecision(15) <<sum << endl;
	system("pause");
    return 0;
}

