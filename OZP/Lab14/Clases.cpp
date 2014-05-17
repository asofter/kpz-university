//---------------------------------------------------------------------------

#pragma hdrstop
#include <System.hpp>
#include <vcl.h>
#include "Clases.h"

void MyText::DrawText(TCanvas *canv,int mx,int my)
{
	canv->TextOutW(mx,my,text);
}

void MyCircle::DrawCircle(TCanvas *canv)
{
	canv->Ellipse(x-radius,y-radius,x+radius,y+radius);
}

void MyOvalRectangle::Draw(TCanvas *canv)
{
	//
	canv->Pen->Color = color;
	canv->RoundRect(x-d1/2, y-d1/2, x+d2/2, y+d2/2, d3/2, d3/2);
	if(d1<d2)
		radius = d1/2;
	else
		radius = d2/2;
	//DrawCircle(canv);
	DrawText(canv,x-2*d1/5,y-d1/4);
}

void MySquare::Draw(TCanvas *canv)
{
	//-- Square
	canv->Pen->Color = color;
	canv->Rectangle(x-a/2,y-a/2,x+a/2,y+a/2);
	radius = a/2;
	//DrawCircle(canv);
	DrawText(canv,x-2*a/5,y-a/4);
}

void MyEllipse::Draw(TCanvas *canv)
{
	//
	canv->Pen->Color = color;
	//canv->Ellipse(a+10, a-20, b+10, b-20);
	canv->Ellipse(150 - a / 2, 150 - b / 2, 150 + a / 2, 150 + b / 2);
	if(a<b)
		radius = a/2;
	else
		radius = b/2;
	//DrawCircle(canv);
	DrawText(canv, 150 - canv->TextWidth("ttt"),150);
}

void MyArc::Draw(TCanvas *canv)
{
	//
	canv->Pen->Color = color;
	canv->Arc(150 - a / 2, 150 - b / 2, 150 + a / 2, 150 + b / 2, 150, 150 - b / 2, 150 + a / 2, 150);
	if(a<b)
		radius = a/2;
	else
		radius = b/2;
	//DrawCircle(canv);
	DrawText(canv,x-2*a/5,y-a/4);
}

