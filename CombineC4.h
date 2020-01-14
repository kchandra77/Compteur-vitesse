//---------------------------------------------------------------------------

#ifndef CombineC4H

#define CombineC4H
//---------------------------------------------------------------------------
class CombineC4 {
private :
	char idFeux [4];
	char idMoteur [4];
	char donneeFeux [50];
	int regime ;
	int vitesse ;
	bool clignoD ;
	bool clignoG ;
	bool brouillard ;
	bool route ;
	bool croisement ;

public :
	CombineC4();
	int ChaineHexaVersInt(char ChaineHexa [9], int NbCar);
	void EnregistreDonnee(char id [4],char donnee [16]);
	CalculeRegime();
	char donneeMoteur [50];
	CalculeVItesse();
	ExtraitEtatFeux();
	int Vitesse();
	int Regime();
	bool ClignoD();
	bool ClignoG();
	bool Brouillard();
	bool Route();
	bool Croisement();
	void AfficheDonnees(char id[4]);
	};

#endif
