//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainForm.h"
#include "Clases.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

typedef MyFigure* pFigure;
enum elementtype {SOvalRectangle, SSquare, SEllipse, SArc};
elementtype et;
pFigure masiv[100];
int numfig;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
   //	Form1->Image1->Canvas->Rectangle(10,10,100,100);
   //Form1->Image1->Canvas->TextOutW()
   	MyOvalRectangle* ddr = new MyOvalRectangle(1,2,3,"324");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
	et = SOvalRectangle;
	GroupBox3->Visible = true;
	GroupBox4->Visible = false;
	GroupBox5->Visible = false;
	GroupBox6->Visible = false;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
	et = SEllipse;
	GroupBox4->Visible = true;
	GroupBox3->Visible = false;
	GroupBox5->Visible = false;
	GroupBox6->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton3Click(TObject *Sender)
{
	et = SArc;
	GroupBox5->Visible = true;
	GroupBox3->Visible = false;
	GroupBox4->Visible = false;
	GroupBox6->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton4Click(TObject *Sender)
{
	et = SSquare;
	GroupBox3->Visible = false;
	GroupBox4->Visible = false;
	GroupBox5->Visible = false;
	GroupBox6->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SbtnCreatePictureClick(TObject *Sender)
{
	int i;
	int SizeX, SizeY, x, y;
	SizeX = Image1->Width;
	SizeY = Image1->Height;
	TRect rect(0,0,SizeX,SizeY);
	Image1->Canvas->FillRect(rect);
	for(i=0;i<numfig;i++)
	{
		x = 25 + random(SizeX-50);
		y = 25 + random(SizeY-50);
		masiv[i]->MoveTo(x,y);
		masiv[i]->Draw(Image1->Canvas);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SbtnEnterElInMasClick(TObject *Sender)
{
	double d1,d2,d3,a;
	double a1,b1;
	int a2,b2,Z1,Z2;
	switch(et)
	{
		case SOvalRectangle :
			d1 = StrToFloat(Edit3->Text);
			d2 = StrToFloat(Edit4->Text);
			d3 = StrToFloat(Edit1->Text);
			masiv[numfig] = new MyOvalRectangle(d1,d2,d3,Edit2->Text);
			masiv[numfig]->SetColor(ColorBox1->Selected);
			numfig++;
		break;

		case SSquare :
			a = StrToFloat(Edit9->Text);
			masiv[numfig] = new MySquare(a,Edit2->Text);
			masiv[numfig]->SetColor(ColorBox1->Selected);
			numfig++;
		break;

		case SEllipse :
			a1 = StrToFloat(Edit5->Text);
			b1 = StrToFloat(Edit6->Text);
			masiv[numfig] = new MyEllipse(a1,b1,Edit2->Text);
			masiv[numfig]->SetColor(ColorBox1->Selected);
			numfig++;
		break;

		case SArc :
			a2 = StrToInt(Edit7->Text);
			b2 = StrToInt(Edit8->Text);
			Z1 = StrToInt(Edit10->Text);
			Z2 = StrToInt(Edit11->Text);
			masiv[numfig] = new MyArc(a2,b2,Z1,Z2,Edit2->Text);
			masiv[numfig]->SetColor(ColorBox1->Selected);
			numfig++;
		break;
	}
	Edit1->Text = IntToStr(numfig);
}
//---------------------------------------------------------------------------

