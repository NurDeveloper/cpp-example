#pragma once
#include "TFigure.h"
#define SIZE 6

class Board
{
	int **Flags;
	TFigure **Storage;
public:
	Board(void);
	int AddFigure(const TFigure& F);
	~Board(void);
};

