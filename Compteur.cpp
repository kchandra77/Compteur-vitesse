//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Compteur.h"
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
void __fastcall TForm1::ClientSocket1Connect(TObject *Sender, TCustomWinSocket *Socket)
 {
	//ShowMessage("Connexion");
 }
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)

	{
	if(ClientSocket1->Active == false)
	{
		//Indiquer l'adresse IP
		ClientSocket1->Host = Edit1->Text;
		//Indiquer le port
		ClientSocket1->Port = Edit2->Text.ToInt();
		//lancer la connexion au serveur
		ClientSocket1->Active = true;
	}
	else
	{
		ClientSocket1->Active = false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ClientSocket1Disconnect(TObject *Sender, TCustomWinSocket *Socket)

{
   //ShowMessage("Déconnexion");
	Button1->Caption = "Connexion";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ClientSocket1Read(TObject *Sender, TCustomWinSocket *Socket)
{
		tab = ClientSocket1->Socket->ReceiveText();
		//ShowMessage(tab);
		info.EnregistreDonnee("0B6",AnsiString(tab).c_str());
		info.AfficheDonnees("0B6");
	if(mp==1)     // mp (pour differencier du "0B6" et "128")
		{
		ShowMessage(info.ChaineHexaVersInt(info.donneeMoteur+23,2)*2.55);
		ShowMessage(info.ChaineHexaVersInt(info.donneeMoteur+19,2)*100/3.1);
		com.ChargerImage(Image9);
		com.DefinirCentre(Image9->Width/2,Image9->Height/2);
		com.Tracer(Image9->Height/4,100*M_PI/180,0xff,5);
		}
	if(mp==2)
	  {
	   //	RichEdit1->Clear();
		char Feux= info.ChaineHexaVersInt(info.donneeMoteur+27,2);
		if((Feux & 0x80)==0)
		{                                                //Line = cree une ligne
			Image3->Visible=0;      					//Add = saut de ligne
		}
		else
		{
			Image3->Visible=1;
		}
		if((Feux & 0x40)==0)
		{
			Image2->Visible=0;
		}
		else
		{
			Image2->Visible=1;
		}
		if((Feux & 0x20)==0)
		{
			Image4->Visible=0;
		}
		else
		{
			Image4->Visible=1;
		}
		if((Feux & 0x10)==0)
		{
			Image5->Visible=0;
		}
		else
		{
			Image5->Visible=1;
		}
		if((Feux & 0x08)==0)
		{
			Image6->Visible=0;
		}
		else
		{
			Image6->Visible=1;
		}
		if((Feux & 0x04)==0)
		{
			Image8->Visible=0;
		}
		else
		{
			Image8->Visible=1;
		}
		if((Feux & 0x02)==0)
		{
			Image7->Visible=0;
		}
		else
		{
			Image7->Visible=1;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
		//Button1->Caption = "Déconnexion";
		ClientSocket1->Socket->SendText("128");
		mp=2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	//ShowMessage("Connexion");
	Button1->Caption = "Déconnexion";
	ClientSocket1->Socket->SendText("0B6");
	mp=1;
}
//---------------------------------------------------------------------------
