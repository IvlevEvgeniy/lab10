#include <complex.h>
#include <iostream>
#include <math.h>

using namespace std;

class Complex {

public:

	friend Complex operator + (Complex& a1, Complex& b1);
	friend Complex operator - (Complex& a1, Complex& b1);
	friend Complex operator * (Complex& a1, Complex& b1);
	friend Complex operator / (Complex& a1, Complex& b1);
	friend Complex operator & (Complex& a1, Complex& b1);

	void ShowComplex();

public:

	Complex(void);

	Complex(double a1, double b1);

	~Complex(void);

	int n;

private:

	double re;
	double im;

};

Complex::Complex(void) {}

Complex::Complex(double a, double b) {

	re = a;
	im = b;

}

Complex::~Complex(void) {}

Complex operator + (Complex& a, Complex& b) {

	double re = a.re + b.re;
	double im = a.im + b.im;

	cout << "����� � �������������� ����� :" << re << " + " << im << "i" << endl;

	double f1 = sqrt(re * re + im * im);
	double f2 = re / f1;
	double f3 = im / f1;

	cout << "����� � ������������������ ����� :" ;
	cout << f1 << "(cos(" << f2 << ") + isin(" << f3 << "))" << endl;

	Complex t(re, im);

	return t;
}

Complex operator - (Complex& a, Complex& b) {

	double re = a.re - b.re;
	double im = a.im - b.im;

	cout << "��������� : " << re << " + " << im << "i" << endl;

	double f1 = sqrt(re * re + im * im);
	double f2 = re / f1;
	double f3 = im / f1;

	cout << "��������� � ������������������ ����� :" ;
	cout << f1 << "(cos(" << f2 << ") + isin(" << f3 << "))" << endl;

	Complex t(re, im);

	return t;
}

Complex operator * (Complex& a, Complex& b) {

	double re = a.re * b.re - a.im * b.im;
	double im = a.im * b.re + a.re * b.im;

	cout << "���������: " << re << " + " << im << "i" << endl;

	double f1 = sqrt(re * re + im * im);
	double f2 = re / f1;
	double f3 = im / f1;

	cout << "��������� � ������������������ ����� :";
	cout << f1 << "(cos(" << f2 << ") + isin(" << f3 << "))" << endl;

	Complex t(re, im);

	return t;
}

Complex operator / (Complex& a, Complex& b) {

	if (b.re * b.re + b.im * b.im == 0) {
		cout << "������� �� 0";
		exit(0);
	}
	else {
		double re = (a.re * b.re + a.im + b.im) / (b.re * b.re + b.im * b.im);
		double im = (a.im * b.re - a.re * b.im) / (b.re * b.re + b.im * b.im);

		cout << "������� : " << re << " + " << im << "i" << endl;

		double f1 = sqrt(re * re + im * im);
		double f2 = re / f1;
		double f3 = im / f1;

		cout << "������� � � ������������������ ����� :" ;
		cout << f1 << "(cos(" << f2 << ") + isin(" << f3 << "))" << endl;

		Complex t(re, im);

		return t;
	}
}

Complex operator &(Complex& a, Complex& b) {

	int n;

	cout << "������� ����� ������� :" << endl;
	cin >> n;

	double r = sqrt(a.re * a.re + a.im * a.im);
	double rn = pow(2, r);
	double f2 = n * a.re / rn;
	double f3 = n * a.im / rn;

	cout << "������������������ ����� ���������� � ������� :";
	cout << rn << "(cos(" << f2 << ") + isin(" << f3 << "))" << endl;

	Complex t(n, rn);

	return t;
}

void Complex::ShowComplex() {

	cout << "������� �����" << endl;

	cin >> re;
	cin >> im;

	cout << "�������������� ����� :" << re << " + " << im << "i" << endl;

	double z = sqrt(re * re + im * im);

	cout << "������ ����� :" << z << endl;
	cout << "������������������ ����� :" ;

	double f = re / z;
	double f1 = im / z;

	cout << z << "(cos(" << f << ") + isin(" << f1 << "))" << endl;

}

int main(void) {
	setlocale(LC_ALL, "Russian");

	Complex a;
	Complex b;
	Complex ob;

	a.ShowComplex();
	b.ShowComplex();

	a + b;
	a - b;
	a* b;
	a / b;
	a& b;

	return 0;

}
