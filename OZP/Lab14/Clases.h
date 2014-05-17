//---------------------------------------------------------------------------

#ifndef ClasesH
#define ClasesH
#include <math.h>
#include <stdlib.h>
using namespace std;


class MyFigure
{
	protected:
		int x,y;
		TColor color;
		//TBrush fcolor;
	public :
		void SetColor(TColor c)
		{
			color=c;
		}
		void MoveTo(int ix, int iy )
		{
			x=ix;
			y=iy;
		};
		virtual void Draw(TCanvas *canv) = 0;
		//virtual void Rotate(double angle) = 0;
};

//---------- Text----------------
class MyText : public MyFigure
{
		AnsiString text;
	public :
		MyText(AnsiString te)
		{
			text =te;
		};
		virtual void Draw(TCanvas *canv) = 0;
		void DrawText(TCanvas *canv, int x, int y);
};

//---------------Circle ---------------
class MyCircle : public MyText
{
	protected:
		double radius;
		//void SetRadius(double r) {radius = r;};
	public :
		MyCircle(AnsiString te) : MyText(te) {};
		virtual void Draw(TCanvas *canv) = 0;
		void DrawCircle(TCanvas *canv);
};

//------------------------------------------------------/
class MyOvalRectangle : public MyCircle
{
		 double d1,d2,d3;
	public :
		MyOvalRectangle(double _d1, double _d2, double _d3, AnsiString s)
		: MyCircle(s), d1(_d1), d2(_d2), d3(_d3) {};
		void Draw(TCanvas *canv);
		void MoveTo(int ix, int iy )
		{
			MyFigure::MoveTo(ix,iy );
		}
};

//------------------------------------------------------/
class MySquare : public MyCircle
{
		double a;
	public :
		MySquare(double _a, AnsiString s)
		: MyCircle(s),a(_a) {};
		void Draw(TCanvas *canv);
		void MoveTo(int ix, int iy )
		{
			MyFigure::MoveTo(ix,iy );
		}
};

//------------------------------------------------------/
class MyEllipse : public MyCircle
{
		double a, b;
	public :
		MyEllipse(double _a, double _b, AnsiString s)
		: MyCircle(s),a(_a), b(_b){};
		void Draw(TCanvas *canv);
		void MoveTo(int ix, int iy )
		{
			MyFigure::MoveTo(ix,iy );
		}
};

//------------------------------------------------------/
class MyArc : public MyCircle
{
		double a,b,c,d;
	public :
		MyArc(double _a, double _b, double _c, double _d, AnsiString s)
		: MyCircle(s),a(_a), b(_b), c(_c), d(_d){};
		void Draw(TCanvas *canv);
		void MoveTo(int ix, int iy )
		{
			MyFigure::MoveTo(ix,iy );
		}
};
//---------------------------------------------------------------------------
#endif
