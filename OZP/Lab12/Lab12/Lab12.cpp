// Створити клас, для роботи з векторами. В класі реалізувати операцію множення 
// векторів вводу та виводу у потік. Створити масив векторів та присвоїти елементам 
// масиву результат відповідних операцій. Перевірити роботу програми. 
//

#include "stdafx.h"
#include <conio.h> 
#include <iomanip> 
#include<iostream>
#include <Windows.h>
using namespace std;
typedef int te; 

class Vector
{
public:
	te x,y,z;
	Vector(void);
	Vector(te ax, te ay, te az);
	Vector(te a);
	void setParams(te ax, te ay, te az);
	~Vector();
	te get_mod();

	friend double operator+( Vector &, Vector &);
	friend ostream & operator << ( ostream &,Vector &);
};

te Vector::get_mod() { 
	return x*x+y*y+z*z;
} 

Vector::Vector(void)
{
	x=y=z=0;
}
Vector::Vector(te ax, te ay, te az) {
		 x=ax; y=ay; z=az;
}
void Vector::setParams(te ax, te ay, te az) {
		 x=ax; y=ay; z=az;
}
Vector::Vector(te a)
{
	 x=y=z=a;
}

Vector::~Vector()
{
}

double operator*( Vector & a, Vector & b) 
{ 
 double tmp = a.x*b.x + a.y*b.y + a.z*b.z; 
 return tmp; 
}

ostream & operator << ( ostream & os, Vector & a){ 
 os<<"Vector("<<setw(2)<<a.x<<","<< 
 setw(2)<<a.y<<","<<setw(2)<<a.z 
 <<") mod="<<setw(4)<<a.get_mod()<<"\n"; 
 return os; 
}

int _tmain(int argc, _TCHAR* argv[])
{
	const int N = 3;

	Vector* v = new Vector[N];
    v[0].setParams(2,4,5);
	v[1].setParams(1,1,1);
	v[2].setParams(2,4,5);

    double res =v[0]*v[1]; 
	cout<<"Multiply result = "<<res<<endl; 

	system("pause");
	return 0;
}

