%option noyywrap
%{
#include <iostream>

using namespace std;

#include "parser.tab.hpp"
%}

%%

"sifra"						{return SIFRA_T;}
"stampaj"					{return PRINT_T;}
"fst"						{return FST_T;}
"snd"						{return SND_T;}
"sum"						{return SUM_T;}
"lista_sifri"				{return LIST_T;}
"=="						{return EQ;}
"!="						{return NEQ;}
">="						{return GEQ;}
"<="						{return LEQ;}
[a-zA-Z][a-zA-Z0-9]*		{return ID;}
(-)?[0-9]+(\.[0-9]+)?		{return BROJ;}
[+*,;=()/?\[\]\.-]			{return *yytext;}
[ \t\n]						{}
.							{
								cerr << "Leksicka greska: " << yytext << endl;
								exit(EXIT_FAILURE);
							}

%%
