//---------------------------------------------------------------------------

#pragma hdrstop

#include "classeAiguille.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
CompteurAiguille::CompteurAiguille()
{
}

void CompteurAiguille::DefinirCentre(int x,int y)
{
CentreX=x;
CentreY=y;
}

void CompteurAiguille::Tracer(int longueur, float alpha, int couleur,int largeur){
ImagedeFond->Picture->LoadFromFile("compteur.bmp");
ImagedeFond->Canvas->Pen->Color=couleur;
ImagedeFond->Canvas->Pen->Width=largeur;
ImagedeFond->Canvas->MoveTo(CentreX,CentreY);
float X1=CentreX+longueur*-cos(alpha);
float Y1=CentreY-longueur*sin(alpha);
ImagedeFond->Canvas->LineTo(X1,Y1);
}


void CompteurAiguille::ChargerImage(TImage * im){
	 ImagedeFond=im;

}


