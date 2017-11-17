#include "TCalculator.h"
#include <string>
using namespace std;

TCalculator:: TCalculator()
{

}

TCalculator:: ~TCalculator()
{
	
}

string TCalculator:: GetInfix()
{

	return infix;
}

string TCalculator:: GetPostfix()
{
	return postfix;
}

int  Size(const string st)
{
	int flag = 0;

	while (st[flag] != '\0')
	{
		flag++;
	}

	return flag;

}

void TCalculator:: SetInfix(const string st)
{
	infix=st;
}


int TCalculator:: Priority(int i)
{
	int flag = -1;

	if ((infix[i] == '(' )||(infix[i] == ')'))
	{
		flag = 0;
	}

	if ((infix[i] == '+') ||(infix[i] == '-'))
	{
		flag = 1;
	}

	if ((infix[i] == '*') || (infix[i] == '/'))
	{
		flag = 2;
	}

	if (infix[i] == '^')
	{
		flag = 3;
	}

	if (flag == -1)
	{
		throw 0;
	}
	else
	{
		return flag;
	}

}



bool TCalculator:: ChecBrackets()
{
	stc.Clr();

	for (int i = 0; i < Size(infix); i++)
	{
			if (infix[i] == '(')
			{
				stc.Push(infix[i]);
			}
			else
			{
				if (infix[i] == ')')
				{
					stc.Pop();
				}
			}
		}

	

	if (stc.IsEmpty())
		return true;
	else
		throw 0;

}

int ChekSymbols(char ch)
{
	if (((ch >= '0') && (ch <= '9'))|| (ch == '.'))
	{
		return -1;
	}

	if ((ch == '(') || (ch == ')'))
	{
		return 0;
	}

	if ((ch == '+') || (ch == '-'))
	{
		return 1;
	}

	if ((ch == '*') || (ch == '/'))
	{
		return 2;
	}

	if (ch == '^')
	{
		return 3;
	}

	return -2;

	

}

/*
double TCalculator::StringToDouble(char ch)
{
	switch (ch)
	{
	    case'0':
			return 0;
		case'1':
			return 1;
		case'2':
			return 2;
		case'3':
			return 3;
		case'4':
			return 4;
		case'5':
			return 5;
		case'6':
			return 6;
		case'7':
			return 7;
		case'8':
			return 8;
		case'9':
			return 9;
	}
}
*/

void TCalculator:: ToPostfix()
{
	TCalculator tc;

	stc.Clr();
	tc.SetInfix('(' + infix + ')');

	tc.ChecBrackets();

	for (int i = 0; i < Size(tc.GetInfix()); i++)
	{
		
		switch(ChekSymbols(tc.GetInfix()[i]))
			{

			case -2:

				break;

			case -1:

				postfix += tc.GetInfix()[i];

				if ( ChekSymbols(tc.GetInfix()[i+1]) != -1)
				{
					postfix += ' ';
				}

				break;

			case 0:

				if (tc.GetInfix()[i] == '(')
				{
					stc.Push(tc.GetInfix()[i]);
				}
				else
				{
					while (stc.Top() != '(')
					{
						postfix += stc.Pop();
						postfix += ' ';
					}
					stc.Pop();
				}

				break;

			default:

				while (Priority(stc.Top()) >= Priority(temp[i]))
				{
					postfix += stc.Pop;
					postfix += ' ';
				}

				stc.Push(temp[i]);
				break;

			}





	}
}
/*
double TCalculator::Solution()
{
	string startpostfix;
	string endpostfix;
	int i = 0;

	for (int i = 0; i < postfix.size(); i++)
	{

		if ( Priority(postfix[i] == -1) || Priority(postfix[i] == -2))
		{
		}
		else
		{
			string bst;
			string ast;
			double a;
			double b;
			double c;
			int flag = i-2;
			int flagpoint = 0;

			

				while (Priority(postfix[flag]) != -2) //заполняем второе число в строку
				{
					bst += postfix[flag];
					flag--;
				}
				flag--;

				for (char tempch, int k = 0; k < bst.size() / 2; k++)// переворачиваем строку
				{
					tempch = bst[k];
					bst[k] = bst[bst.size() - k];
					bst[bst.size() - k] = tempch;
				}

				for (int k = 0; k < bst.size(); k++)//преобразуем в double и узнаем кол-во знаков после точки
				{
					switch (bst[k])
					{
					case'1':
						b += 1 ^ (bst.size() - k);
						break;
					case'2':
						b += 2 ^ (bst.size() - k);
						break;
					case'3':
						b += 3 ^ (bst.size() - k);
						break;
					case'4':
						b += 4 ^ (bst.size() - k);
						break;
					case'5':
						b += 5 ^ (bst.size() - k);
						break;
					case'6':
						b += 6 ^ (bst.size() - k);
						break;
					case'7':
						b += 7 ^ (bst.size() - k);
						break;
					case'8':
						b += 8 ^ (bst.size() - k);
						break;
					case'9':
						b += 9 ^ (bst.size() - k);
						break;
					case'.':
						flagpoint = bst.size();
						break;
					}
				}

				if (flagpoint != 0)                         //если чилсло не целое, то преобразуем число в нужное нам
				{
					flagpoint = bst.size() - flagpoint;
					b *= 10 ^ (-flagpoint);
				}


				flagpoint = 0;
				while (Priority(postfix[flag]) != -2) //заполняем первое число в строку
				{
					ast += postfix[flag];
					flag--;
				}

				for (char tempch, int k = 0; k < ast.size() / 2; k++)// переворачиваем строку
				{
					tempch = ast[k];
					ast[k] = ast[ast.size() - k];
					ast[ast.size() - k] = tempch;
				}

				for (int k = 0; k < ast.size(); k++)//преобразуем в double и узнаем кол-во знаков после точки
				{
					switch (ast[k])
					{
					case'1':
						a += 1 ^ (ast.size() - k);
						break;
					case'2':
						a += 2 ^ (ast.size() - k);
						break;
					case'3':
						a += 3 ^ (ast.size() - k);
						break;
					case'4':
						a += 4 ^ (ast.size() - k);
						break;
					case'5':
						a += 5 ^ (ast.size() - k);
						break;
					case'6':
						a += 6 ^ (ast.size() - k);
						break;
					case'7':
						a += 7 ^ (ast.size() - k);
						break;
					case'8':
						a += 8 ^ (ast.size() - k);
						break;
					case'9':
						a += 9 ^ (ast.size() - k);
						break;
					case'.':
						flagpoint = ast.size();
						break;
					}
				}

				if (flagpoint != 0)                         //если чилсло не целое, то преобразуем число в нужное нам
				{
					flagpoint = ast.size() - flagpoint;
					a *= 10 ^ (-flagpoint);
				}

				switch (postfix[i])
				{
				case'+':
					c = a + b;
					break;
				case'-':
					c = a - b;
					break;
				case'*':
					c = a * b;
					break;
				case'/':
					c = a / b;
					break;
				case'^':
					c = 1;
					
					for (int k = 0;k < b;k++)
					{
						c *= a;
					}
					break;
				}

		}


	}


	return 0;

}
*/