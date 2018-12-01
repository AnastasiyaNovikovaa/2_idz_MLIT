#include "pch.h"
#include <string>
#include <iostream>

using namespace std;
void main() 
{
	string way;
	cout << "Enter your WAY:" << endl;
	cin >> way;//вводим наш путь
	cout << "Result:" << endl;
	cout << WAY(way);//вызываем функцию проверки алгоритма
	system("pause");
}


string HelpStroka(string oldstroka)//перезабиваем исходную строку в новую
{
	string newstroka;
	int i = 1;
	while (i < oldstroka.length() - 1)
	{
		newstroka += oldstroka[i];
		i++;
	}
	return newstroka;
}

string WAY(string &stroka)//проверка верности введенной строки,работает по принципу реккурсии
{
	if ( (stroka[0] == 'L') || (stroka[0] == 'R') || (stroka[0] == 'F') || (stroka[0] == 'T'))//проверка первого символа на принадлежность алфавиту
	{
		
		if (stroka[0] == 'L')//если i-ый символ L
		{
			if (stroka[0] != 'L')
			{
				stroka = "ERROR";
			}
			else
			{
				string s_n = HelpStroka(stroka);
				if (WAY(s_n) == "ERROR")
					stroka = "ERROR";
				if (stroka[stroka.length() - 1] != 'R')// проверка на то,чтобы симметричный символ был R
					stroka = "ERROR";
			}
		}

		else
			if (stroka[0] == 'R')//если i-ый символ R
			{
				if (stroka[0] != 'R')
				{
					stroka = "ERROR";
				}
				else
				{
					string s_n = HelpStroka(stroka);
					if (WAY(s_n) == "ERROR")
						stroka = "ERROR";
					if (stroka[stroka.length() - 1] != 'L')// проверка на то,чтобы симметричный символ был L
						stroka = "ERROR";
				}
			}
			else
				if (stroka[0] == 'F')//если i-ый символ F
				{
					if (stroka[0] != 'F')
					{
						stroka = "ERROR";
					}
					else
					{
						string newstroka = HelpStroka(stroka);
						if (WAY(newstroka) == "ERROR")
							stroka = "ERROR";
						if (stroka[stroka.length() - 1] != 'F')// проверка на то,чтобы симметричный символ был F
							stroka = "ERROR";
					}
				}
				else
					if (stroka[0] == 'T')//если i-ый символ T
					{
						if (stroka[0] != 'T')
						{
							stroka = "ERROR";
						}
					}
		else stroka = "ERROR";
	}
	else
		stroka = "ERROR";
	return stroka;
}

