#pragma once
#include <iostream>
using namespace std;
class Complex {
public:
	double re, im;
	//constructori
	Complex(double x = 0, double y = 0);
	Complex(const Complex&);
	explicit Complex(const char*);//constructor folosit la conversii din expresii de tipul "a+bi"
	//metode
	double modul(const Complex&);
	double argument();
	Complex sqrtc(const Complex&);
	double distanta(const Complex&, const Complex&);
	double getRe();
	void setRe(double);
	double getIm();
	void setIm(double);
	//supraincarcare operatori
	Complex operator+(const Complex&);
	Complex operator-(const Complex&);
	Complex operator*(const Complex&);
	Complex operator/(const Complex&);
	int operator==(const Complex&);
	int operator!=(const Complex&);
	Complex operator-();
	Complex operator~();//conjugat
	Complex& operator++();//prefix
	Complex operator++(int);//postfix
	Complex& operator+=(const Complex&);
	Complex& operator-=(const Complex&);
	Complex& operator*=(const Complex&);
	Complex& operator/=(const Complex&);
	operator double() const;//functie de conversie
	friend ostream& operator<<(ostream& os, const Complex&);
	friend istream& operator>>(istream& is, Complex&);
	friend class EcGr2;
};