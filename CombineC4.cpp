//---------------------------------------------------------------------------

#pragma hdrstop
#include <vcl.h>
#include "CombineC4.h"
#include <string.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
CombineC4::CombineC4()
{
	strcpy(idFeux,"128");
	strcpy(idMoteur,"0B6");
}
void CombineC4::EnregistreDonnee(char id [4],char donnee [16])
{
	if(!strcmp(id,"128"))
	{
	strcpy(donneeFeux,donnee);
	}
	else strcpy(donneeMoteur,donnee);
}
void CombineC4::AfficheDonnees(char id[4])
  {
	if(!strcmp(id,"128"))
		 ShowMessage(donneeFeux);
	else ShowMessage(donneeMoteur);
}
int CombineC4::ChaineHexaVersInt(char ChaineHexa [9], int NbCar)
{
	int nb=0;
	char c;
	for(int j=0 ; j<NbCar ; j++)
	{
		c=ChaineHexa[j];
		if(c>='0'&&c<='9')
		{
			nb+=((c-'0')<<(4*(NbCar-j-1)));
		}
		else
		{
			nb+=((c-'A'+10)<<(4*(NbCar-j-1)));
		}

	}
	return nb;
}

