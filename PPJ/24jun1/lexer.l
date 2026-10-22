%option noyywrap
%{
#include <iostream>
#include <cstdlib>

using namespace std;

#include "graf.hpp"
#include "parser.tab.hpp"
%}

%%

"begin"							{return BEGIN_T;}
"end"							{return END_T;}
"graph"							{return GRAF_T;}
"print_matrix_d"				{return PRINT_D;}
"print_matrix_u"				{return PRINT_U;}
"delete"						{return DEL_T;}
[a-zA-Z_][a-zA-Z_0-9]*			{
									yylval.ime = new string(yytext);
									return ID;
								}
[0-9]+							{
									yylval.br = atoi(yytext);
									return BROJ;
								}
[(){}:;,=+*~\[\]]				{return *yytext;}
[ \t\n]							{}
.								{
									cerr << "Leksicka greska: " << yytext << endl;
									exit(EXIT_FAILURE);
								}

%%
