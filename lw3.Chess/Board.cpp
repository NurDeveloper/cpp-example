#include "Board.h"


Board::Board(void)
{
	Flags = new int *[SIZE];
	for (int i=0; i<SIZE; i++)
		Flags[i] = new int [SIZE];

	Storage = new TFigure *[SIZE];
	for (int i=0; i<SIZE; i++)
		Storage[i] = new TFigure [SIZE];
}


Board::~Board(void)
{
	delete [] Storage;
	delete [] Flags;
}
