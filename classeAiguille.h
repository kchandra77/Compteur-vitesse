//---------------------------------------------------------------------------

#ifndef classeAiguilleH
#define classeAiguilleH
#include <vcl.h>
//---------------------------------------------------------------------------
class CompteurAiguille
{
private:
int CentreX;
int CentreY;
TImage* ImagedeFond;
public:
CompteurAiguille();
void ChargerImage(TImage*);
void DefinirCentre(int x,int y);
void Tracer(int longueur, float alpha, int couleur, int largeur);
};
#endif
