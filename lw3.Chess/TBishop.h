#pragma once
#include "tfigure.h"
class TBishop :
	public TFigure
{
public:
	TBishop(void);
	virtual int mapStep(int **Flags);
	virtual ~TBishop(void);
};