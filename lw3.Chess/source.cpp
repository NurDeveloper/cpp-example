/* source.cpp
 ���������� ������ ������� �������� �� ������� ���� ����
 � �������.*/
#include <iostream>
#include <fstream>

using namespace std;

void main(){

	ifstream in("input.txt",ios::in|ios::_Nocreate);
	if (!in) exit(1);

	in.get();

	return;}