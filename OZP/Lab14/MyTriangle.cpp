//---------------------------------------------------------------------------

#pragma hdrstop

#include "MyTriangle.h"

MyTriangle::MyTriangle(double _a)
{
    a=_a;
}

void MyTiangle::Draw(TCanvas *canv)
{
	canv->Pen->Color = clBlack;
	canv->Rectangle(x-a/2,y-a/2,x+a/2,y+a/2);
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
