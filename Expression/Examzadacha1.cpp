// Examzadacha1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Expression.h"
#include "Const.h"
#include "Var.h"
#include "Sum.h"
#include "Product.h"

using namespace std;

int main()
{
	Const one(15);

	Var two("Variable two", 25);

	Sum sum(one, two);
	sum.print();
	cout << "\n";
	cout << sum.value() << "\n";


	Sum sum2(one, sum);
	sum2.print();
	cout << "\n";
	cout << sum2.value() << "\n";

	Const three(2);
	Product product1(three, sum2);

	product1.print();
	cout << "\n";
	cout << product1.value() << "\n";

	/*
	Product product2(product1);
	product2.print();
	cout << "\n";
	cout << product2.value() << "\n";
	*/

    return 0;
}

