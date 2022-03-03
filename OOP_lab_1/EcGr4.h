#pragma once
#include <iostream>
#include "Complex.h"
using namespace std;
class EcGr4 {
protected:
	Complex x, a, b, c, d, e;
public:
	EcGr4(Complex x = 0, Complex a = 0, Complex b = 0, Complex c = 0, Complex d = 0, Complex e = 0);
	EcGr4(const EcGr4&);
	friend ostream& operator<<(ostream& os, const EcGr4&);
};