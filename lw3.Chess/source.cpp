/* source.cpp
 Реализация задачи анализа ситуации на игровом поле игры
 в шахматы.*/
#include <iostream>
#include <fstream>

using namespace std;

void main(){

	ifstream in("input.txt",ios::in|ios::_Nocreate);
	if (!in) exit(1);

	in.get();

	return;}