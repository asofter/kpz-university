#include "stdafx.h"
#include "Student.h"

Student::Student(void)
{
}

int Student::getRate() 
{
	return rand() % 12 + 1;
}

Student::~Student(void)
{
}
