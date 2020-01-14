//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Aiguille.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
Image2->Picture->LoadFromFile("compteur.bmp");
float vitesse=Edit1->Text.ToDouble();
float Vmax=230;
float alpha=-(M_PI/3*Vmax)*vitesse+(-5*M_PI/6);
float Ampli=Image2->Height/2.9;
float X0=Image2->Height/2.0;
float Y0=Image2->Height/2.0;
Image2->Canvas->Pen->Color=0xff0000;
Image2->Canvas->Pen->Width=5;
Image2->Canvas->MoveTo(X0,Y0);
float X1=X0+Ampli*cos(alpha);
float Y1=Y0-Ampli*sin(alpha);
Image2->Canvas->LineTo(X1,Y1);
};

