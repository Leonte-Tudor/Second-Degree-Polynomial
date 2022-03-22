#include <iostream>
#include "Complex.h"
#include "EcGr2.h"
#include "EcGr4.h"
using namespace std;

Complex::Complex(double re, double im) {
    this->re = re;
    this->im = im;
}
Complex::Complex(const Complex& z) {
    re = z.re;
    im = z.im;
}
Complex::Complex(const char* str) {
    char* pos_plus = (char*)strrchr(str, '+');
    char* pos_minus = (char*)strrchr(str, '-');
    if (pos_plus == NULL) {
        re = strtod(str, &pos_minus);
        im = strtod(pos_minus, NULL);
    }
    else if (pos_minus == NULL) {
        re = strtod(str, &pos_plus);
        im = strtod(pos_plus, NULL);
    }
    else {
        re = strtod(str, (pos_plus > pos_minus ? &pos_plus : &pos_minus));
        im = strtod(pos_plus > pos_minus ? pos_plus : pos_minus, NULL);
    }
}
double Complex::modul(const Complex& z) {
    return sqrt(z.re * z.re + z.im * z.im);
}
double Complex::argument() {
    return atan2(im, re);
}
double distanta(const Complex& z1, const Complex& z2) {
    return sqrt((z1.re - z2.re) * (z1.re - z2.re) + (z1.im - z2.im) * (z1.im - z2.im));
}
double Complex::getRe() {
    return re;
}
void Complex::setRe(double re) {
    this->re = re;
}
double Complex::getIm() {
    return im;
}
void Complex::setIm(double im) {
    this->im = im;
}
Complex Complex::operator+(const Complex& c) {
    return Complex(re + c.re, im + c.im);
};
Complex Complex::operator-(const Complex& c) {
    return Complex(re - c.re, im - c.im);
};
Complex Complex::operator*(const Complex& z) {
    return Complex(re * z.re - im * z.im, re * z.im + im * z.re);
};
Complex Complex::operator/(const Complex& z) {
    double t = z.re * z.re + z.im * z.im;
    return Complex((re * z.re + im * z.im) / t,
        (im * z.re - re * z.im) / t);
};
int Complex::operator==(const Complex& z) {
    return re == z.re && im == z.im;
};
int Complex::operator!=(const Complex& z) {
    return re != z.re || im != z.im;
};
Complex Complex::operator-() {
    return Complex(-re, -im);
};
Complex Complex::operator~() {
    return Complex(re, -im);
};
Complex& Complex::operator++() {
    re++;
    return *this;
};
Complex Complex::operator++(int) {
    Complex t(*this);
    re++;
    return t;
};
Complex& Complex::operator+=(const Complex& z) {
    if (this != &z) {
        re += z.re;
        im += z.im;
    };
    return *this;
};
Complex& Complex::operator-=(const Complex& z) {
    if (this != &z) {
        re -= z.re;
        im -= z.im;
    };
    return *this;
};
Complex& Complex::operator*=(const Complex& z) {
    if (this != &z) {
        double t = re;
        re = re * z.re - im * z.im;
        im = t * z.im + im * z.re;
    };
    return *this;
};
Complex& Complex::operator/=(const Complex& z) {
    if (this != &z) {
        double t1 = re, t2 = z.re * z.re + z.im * z.im;
        re = (re * z.re + im * z.im) / t2;
        im = (im * z.re - t1 * z.im) / t2;
    };
    return *this;
};
Complex::operator double() const {
    return re;
};
ostream& operator<<(ostream& out, const Complex& z) {
    if (z.re == 0)out << z.im << (z.im ? "i" : "");
    else if (z.im == 0)out << z.re;
    else out << z.re << (z.im > 0 ? "+" : "") << z.im << "i";
    return out;
};
istream& operator>>(istream& in, Complex& z) {
    in >> z.re >> z.im;
    return in;
}; 

EcGr2::EcGr2(Complex x, Complex a, Complex b, Complex c) {
    this->x = x;
    this->a = a;
    this->b = b;
    this->c = c;
}
EcGr2::EcGr2(const EcGr2& p) {
    x = p.x;
    a = p.a;
    b = p.b;
    c = p.c;
}
ostream& operator<<(ostream& out, const EcGr2& p) {
    Complex z(0, 0);
    if (p.x == z)out << p.c;
    else out << ((Complex)p.x * p.x * p.a) << (p.b.re > 0 ? "+":"") << ((Complex)p.b * p.x) << (p.c.re > 0 ? "+" : "") << ((Complex)p.c);
    return out;
};
istream& operator>>(istream& in, EcGr2& p) {
    in >> p.x;
    return in;
};
Complex EcGr2::eval(const EcGr2& p) {
    return ((Complex)p.x * p.x * p.a) + ((Complex)p.x * p.b) + ((Complex)p.c);
};
Complex Complex::sqrtc(const Complex& z) {
    Complex i(0, 1);
    return (Complex)sqrt((modul(z) + z.re) / 2) +  i * (Complex)(z.im / abs(z.im) * sqrt((modul(z) - z.re) / 2));
}
Complex* EcGr2::solve(const EcGr2& p) {
    Complex* x, delta;
    x = new (nothrow) Complex[4];
    Complex i(0, 1),z(0,0),patru(4,0),doi(2,0);
    delta = (((Complex)p.b * p.b) - ((Complex)patru * p.a * p.c));
    if (delta == z)
        x[0]= ((Complex)(z-p.b) + delta.Complex::sqrtc(delta)) / ((Complex)doi * p.a);
    else {
        x[0] = ((Complex)(z-p.b) + delta.Complex::sqrtc(delta)) / ((Complex)doi * p.a);
        x[1] = ((Complex)(z-p.b) - delta.Complex::sqrtc(delta)) / ((Complex)doi * p.a);
        x[2] = delta; }
    return x;
};
EcGr2 EcGr2::operator +(const EcGr2& p) {
    return EcGr2((p.x),(a + p.a) , (b + p.b) , (c+p.c));
};
EcGr4 EcGr2::operator *(const EcGr2& p) {
    return EcGr4((p.x), (a * p.a), (a * p.b + b * p.a), (a * p.c + b * p.b + c * p.a), (b * p.c + c * p.b), (c * p.c));
};
EcGr4::EcGr4(Complex x, Complex a, Complex b, Complex c, Complex d, Complex e) {
    this->x = x;
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    this->e = e;
}
EcGr4::EcGr4(const EcGr4& p) {
    x = p.x;
    a = p.a;
    b = p.b;
    c = p.c;
    d = p.d;
    e = p.e;
}
ostream& operator<<(ostream& out, const EcGr4& p) {
    Complex z(0, 0);
    if (p.x == z)out << p.c;
    else out << ((Complex)p.x * p.x * p.x * p.x * p.a) << (p.b.re > 0 ? "+" : "") << ((Complex)p.b * p.x * p.x * p.x)
             << (p.c.re > 0 ? "+" : "") << ((Complex)p.c * p.x * p.x) << (p.d.re > 0 ? "+" : "") << ((Complex)p.d * p.x)
             << (p.e.re > 0 ? "+" : "") << ((Complex)p.e);
    return out;
};


int main()
{
    Complex x ,a(3, 1), b(2, 1), c(1, 1), d(1, 1), e(2, 1), f(3, 1);
    //a = (Complex)"3+1i"; b = (Complex)"2+1i"; c = (Complex)"1+1i";
    cout << a+b;
    cin >> x;
    EcGr2 P1(x, a, b, c), P2(x, d, e, f);
    cout << P1<<endl;
    cout << P2 << endl;
    cout << "Evaluarea pentru x=" << x << ":" << endl << P1.EcGr2::eval(P1) << endl;
    cout << "P1+P2=" << P1 + P2 << endl;
    cout << "P1*P2=" << P1 * P2 << endl;
    cout << "Solutiile P1:" << endl
         << "x1=" << P1.EcGr2::solve(P1)[0] << endl
         << "x2=" << P1.EcGr2::solve(P1)[1] <<endl
         << "delta=" << P1.EcGr2::solve(P1)[2]<<endl;
    cout << "Solutiile P2:" << endl
        << "x1=" << P2.EcGr2::solve(P2)[0] << endl
        << "x2=" << P2.EcGr2::solve(P2)[1] << endl
        << "delta=" << P2.EcGr2::solve(P2)[2] << endl;
}

