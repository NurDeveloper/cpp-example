#pragma once
#include "tfigure.h"
class TQueen :
	public TFigure
{
public:
	TQueen(void);
	virtual int mapStep();
	virtual ~TQueen(void);
};

