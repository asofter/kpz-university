#include "stdafx.h"
#include "Grupa.h"

Grupa::Grupa(void)
{
}

int Grupa::getRate() 
{
	return rand() % 12 + 1;
}

Grupa::~Grupa(void)
{
}
