%option noyywrap
%option nounput
%option noinput

%{
    
#include <cstdlib>
#include <string>
#include <iostream>
#include "SysY.tab.hpp" // TODO: 由 bison 生成的头文件,按需要更改

using namespace std;
%}


Blank               [ \n\r\t]*
SingleLineComment   "\/\/".*
MultiLineComment    "\/\*"([^\*]|[\*]+[^\*\/])*[\*]+"\/"

Identifier          [a-zA-Z_][a-zA-Z0-9_]*

Decimal             [1-9][0-9]*
Octal               0[0-7]*
Hexadecimal         0[xX][0-9a-fA-F]+

Default             .|\n
%%

{Blank}             { /* ignore */ }
{SingleLineComment} { /* ignore */ }
{MultiLineComment}  { /* ignore */ }


"("         { return LPAREN; }
")"         { return RPAREN; }
"{"         { return LBRACE; }
"}"         { return RBRACE; }
"["         { return LBRACKET; }
"]"         { return RBRACKET; }

";"         { return SEMICOLON; }
","         { return COMMA; }
"\'"        { return SQUATE; }
"\""        { return DQUATE; }

"="         { return ASSIGN; }
"=="        { return EQUAL; }
"!="        { return NOT_EQUAL; }
"<"         { return LESS_THAN; }
"<="        { return LESS_EQUAL_THAN; }
">"         { return GREATER_THAN; }
">="        { return GREATER_EQUAL_THAN; }

"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return MUL; }
"/"         { return DIV; }
"%"         { return MOD; }

"&&"        { return AND; }
"||"        { return OR; }
"!"         { return NOT; }
"."         { return DOT; }
"\\\\"      { return BACKSLASH; }


"if"        { return IF; }
"else"      { return ELSE; }
"while"     { return WHILE; }
"for"       { return FOR; }
"return"    { return RETURN; }
"break"     { return BREAK; }
"continue"  { return CONTINUE; }

"int"       { return TyINT; }
"void"      { return TyVOID; }


{Identifier}    {  yylval.str_val = new string(yytext);          return IDENT; }
{Decimal}       {  yylval.int_val = strtol(yytext, nullptr, 0);  return INT_CONST; }
{Octal}         {  yylval.int_val = strtol(yytext, nullptr, 0);  return INT_CONST; }
{Hexadecimal}   {  yylval.int_val = strtol(yytext, nullptr, 0);  return INT_CONST; }

{Default}       {  return yytext[0];}
%%
