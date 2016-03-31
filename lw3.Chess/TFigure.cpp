#include "TFigure.h"


TFigure::TFigure(TColor cl, char A, int O)
{
	Color=cl;
	if ((A>='a') && (A<='h')) Abscissa=A;
	else exit(1);

	if ((O>=1) && (A<=8)) Ordinate=O;
	else exit(1);
}

TFigure::~TFigure(void)
{
}
