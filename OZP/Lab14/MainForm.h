//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TEdit *EdtCountOfElementsInPicture;
	TLabel *Label1;
	TGroupBox *GroupBox1;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TRadioButton *RadioButton3;
	TRadioButton *RadioButton4;
	TGroupBox *GroupBox2;
	TColorBox *ColorBox1;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *Edit2;
	TSpeedButton *SbtnEnterElInMas;
	TGroupBox *GroupBox3;
	TLabel *Label4;
	TEdit *Edit3;
	TLabel *Label5;
	TEdit *Edit4;
	TGroupBox *GroupBox4;
	TLabel *Label6;
	TLabel *Label7;
	TEdit *Edit5;
	TEdit *Edit6;
	TGroupBox *GroupBox5;
	TLabel *Label8;
	TLabel *Label9;
	TEdit *Edit7;
	TEdit *Edit8;
	TGroupBox *GroupBox6;
	TLabel *Label10;
	TEdit *Edit9;
	TLabel *Label11;
	TSpeedButton *SbtnCreatePicture;
	TLabel *Label12;
	TEdit *Edit1;
	TLabel *Label13;
	TEdit *Edit10;
	TLabel *Label14;
	TEdit *Edit11;
	TButton *Button1;
	void __fastcall RadioButton1Click(TObject *Sender);
	void __fastcall RadioButton2Click(TObject *Sender);
	void __fastcall RadioButton3Click(TObject *Sender);
	void __fastcall RadioButton4Click(TObject *Sender);
	void __fastcall SbtnCreatePictureClick(TObject *Sender);
	void __fastcall SbtnEnterElInMasClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
