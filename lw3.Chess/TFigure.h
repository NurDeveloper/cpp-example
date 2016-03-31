#pragma once

typedef enum TColor {white, black};

class TFigure
{
	TColor Color;
	char Abscissa;
	int Ordinate;
public:
	TFigure(TColor cl, char A, int O);
	virtual int mapStep(int **Flags)=0;
	virtual ~TFigure(void);
};

