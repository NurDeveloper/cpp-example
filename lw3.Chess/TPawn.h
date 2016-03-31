#pragma once
#include "tfigure.h"
class TPawn :
	public TFigure
{
public:
	TPawn(void);
	virtual int mapStep();
	virtual ~TPawn(void);
};

