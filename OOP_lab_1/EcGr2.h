#pragma once
#include <iostream>
#include "Complex.h"
#include "EcGr4.h"
using namespace std;
class EcGr2 {
protected:	
	Complex x, a, b, c;
public:
	EcGr2(Complex x = 0, Complex a = 0, Complex b = 0, Complex c = 0);
	EcGr2(const EcGr2&);
	Complex eval(const EcGr2&);
	Complex* solve(const EcGr2&);
	EcGr2 operator +(const EcGr2&);
	EcGr4 operator *(const EcGr2&);
	friend ostream& operator<<(ostream& os, const EcGr2&);
	friend istream& operator>>(istream& is, EcGr2&);
	friend class EcGr4;
};