#pragma once
#include <string>
#include "TStack.h"
using namespace std;

class TCalculator 
{
private:
	string infix;
	string postfix;
	TStack<char> stc;

public:

	TCalculator();
	~TCalculator();
	string	GetInfix();
	void	SetInfix(const string st);
	string	GetPostfix();
	friend int Size(const string st);
     int Priority(int i);
	 bool ChecBrackets();
	 void ToPostfix();
	friend int ChekSymbols(char ch);
/*
void ToPostfix();

double Solution();
double StringToDouble(char ch);


*/



};


