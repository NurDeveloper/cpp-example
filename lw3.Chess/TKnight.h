#pragma once
#include "tfigure.h"
class TKnight :
	public TFigure
{
public:
	TKnight(void);
	virtual int mapStep();
	virtual ~TKnight(void);
};

