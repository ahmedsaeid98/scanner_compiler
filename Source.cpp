#include <iostream>
#include <string>
#include <vector>
using namespace std;


class token
{
public:
	string tokenType;
	string tokenValue;


	token(string value, string type)
	{
		this->tokenType = type;
		this->tokenValue = value;
	}
};

bool isIdentifer(string symbol,string &type);
bool isReservedWord(string symbol,string& type);
bool isSpecialSymbol(string symbol, string& type);

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
			cout << "is special symbol with value : "<<type << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}

}

bool isSpecialSymbol(string symbol,string &type)
{
	//this is all special symbol at tiny
	//vector<string> tinySymbol{  "+"  ,  "-"  ,  "*"  ,  "/"  ,  "="  ,  "<" ,  ":="  ,  "("  ,  ")"  ,  ";"  };

	vector<token> tinySymbol{
		token("+","PLUS"),
		token("-","MINUS"),
		token("*","MULTIPLUE"),
		token("/","DIVIDE"),
		token("=","COMPARE"),
		token("<","LESS THAN"),
		token(":=","ASSIGN"),
		token("(","LEFT CURLY BRACKET"),
		token(")","RIGHT CURLY BRACKET"),
		token(";","SEMI"),
	};

	for (int i = 0; i < tinySymbol.size(); i++)
	{
		if (tinySymbol[i].tokenValue == symbol)
		{
			type = tinySymbol[i].tokenType;
			return true;
		}
	}
	type = "";
	return false;
}

bool isReservedWord(string symbol,string &type)
{
	//this is all reserved word at tiny
	//vector<string> tinyReservedWord{  "if"  ,  "then"  ,  "else"  ,  "end"  ,  "repeat"  ,  "until"  ,  "read"  ,  "write"  };

	vector<token> tinyReservedWord{
		token("if","IF"),
		token("then","THEN"),
		token("else","ELSE"),
		token("end","END"),
		token("repeat","REPEAT"),
		token("until","UNTIL"),
		token("read","READ"),
		token("write","WRITE")
	};

	for (int i = 0; i < tinyReservedWord.size(); i++)
	{
		if (symbol == tinyReservedWord[i].tokenValue)
		{
			type = tinyReservedWord[i].tokenType;
			return true;
		}
	}
	type = "";								//kda ya3ne el type be null
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
		if ((symbol[i] >='A' && symbol[i] <= 'Z')|| (symbol[i] >= 'a' && symbol[i] <= 'z'))				//||(symbol[i] == '_')
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
				//typ = 'd';
				typ = 'x';
				break;
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

