#pragma once
#include "tfigure.h"
class TKing :
	public TFigure
{
public:
	TKing(void);
	virtual int mapStep();
	virtual ~TKing(void);
};

