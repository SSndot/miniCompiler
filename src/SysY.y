%code requires {
  #include <memory>
  #include <string>
}

%{
#include <iostream>
#include <memory>
#include <string>
%}

/* Bison提供的数据类型，用于token值 */
%union {
  std::string *str_val;
  int int_val;
}

/* Token声明区块 */
%token LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET
%token SEMICOLON COMMA SQUATE DQUATE
%token ASSIGN EQUAL NOT_EQUAL LESS_THAN LESS_EQUAL_THAN GREATER_THAN GREATER_EQUAL_THAN
%token PLUS MINUS MUL DIV MOD
%token AND OR NOT
%token DOT BACKSLASH
%token IF ELSE WHILE FOR RETURN BREAK CONTINUE
%token TyINT TyVOID
%token <str_val> IDENT
%token <int_val> INT_CONST

%%
// TODO: add grammar rules here.
empty:
    /* empty */
    ;
%%

/* 辅助代码块 */
