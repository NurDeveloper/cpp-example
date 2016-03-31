#pragma once
#include "tfigure.h"
class TRook :
	public TFigure
{
public:
	TRook(void);
	virtual int mapStep();
	virtual ~TRook(void);
};

