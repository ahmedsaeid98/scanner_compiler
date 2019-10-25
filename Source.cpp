#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isIdentifer(string symbol,string &type);
bool isReservedWord(string symbol);
bool isSpecialSymbol(string symbol);

void main()
{
	while (1)
	{
		string x;
		string type;
		cin >> x;
		if (isIdentifer(x,type))
		{
			cout << "yes" << endl;
			cout << type << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}

}

bool isSpecialSymbol(string symbol)
{
	//this is all special symbol at tiny
	vector<string> tinySymbol{  "+"  ,  "-"  ,  "*"  ,  "/"  ,  "%"  ,  "="  ,  "<"  ,  ">"  ,  "<="  ,  ">="  ,  ":="  ,  "("  ,  ")"  ,  ";"  };
	
	for (int i = 0; i < tinySymbol.size(); i++)
	{
		if (tinySymbol[i] == symbol)
		{
			return true;
		}
	}
	return false;
}

bool isReservedWord(string symbol)
{
	//this is all reserved word at tiny
	vector<string> tinyReservedWord{  "if"  ,  "then"  ,  "else"  ,  "end"  ,  "repeat"  ,  "until"  ,  "read"  ,  "write"  };

	for (int i = 0; i < tinyReservedWord.size(); i++)
	{
		if (symbol == tinyReservedWord[i])
		{
			return true;
		}
	}
	return false;
}

bool isIdentifer(string symbol,string &type)
{
	//typ : it is used to define the type of identifer
	//typ has only 3 value
	//x -> not identfier
	//n -> number
	//d -> identifier
	char typ=NULL;
	for (int i = 0; i < symbol.length() ; i++)
	{
		if ((symbol[i] >='A' && symbol[i] <= 'Z')|| (symbol[i] >= 'a' && symbol[i] <= 'z')||(symbol[i] == '_'))
		{
			if (typ == NULL || typ == 'd')
			{
				typ = 'd';
			}
			else if(typ == 'n')
			{
				typ = 'x';
				break;
			}
		}
		else if (symbol[i]>='0' && symbol[i]<='9')
		{
			if (typ == NULL || typ == 'n')
			{
				typ = 'n';
			}
			else if (typ == 'd')
			{
				typ = 'd';
			}
		}
		else
		{
			typ = 'x';
			break;
		}
	}

	if (typ == 'x')
	{
		type = "not identifier";
		return false;
	}
	else if(typ == 'n')
	{
		type = "number";
		return true;
	}
	else if (typ == 'd')
	{
		type = "identifier";
		return true;
	}
}

/*
*********************************************************************************************
bool isSpecialSymbol(string symbol);
input:part of string to be checked if it is special symbol or no.
output:true if it is special symbol , false if it isn't special symbol.
update:if you want to updata this function , add symbol at vactor tinySymbol. 
*********************************************************************************************
bool isReservedWord(string symbol);
input:part of string to be checked if it is Reserved word or no.
output:true if it is special symbol , false if it isn't Reserved word.
update:if you want to updata this function , add symbol at vactor tinyReservedWord.
*********************************************************************************************
bool isIdentifer(string symbol,string &type);
input:part of string to be checked if it is identifer and the type of identifier
output:true if it is special symbol , false if it isn't Reserved word.
		and the type of identifer (number,identifier) 
update:if you want to updata this function , you can module if condition at this function
*********************************************************************************************
*/

/*
test case ,i am not sure for that
1-else if	=>reserved
2-underscore in identifer
*/
