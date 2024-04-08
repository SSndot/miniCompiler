#include <cassert>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <cstring>
// #include "AST.h"
#include "AST.cpp"
using namespace std;
extern FILE *yyin;
extern int yyparse(unique_ptr<AST> &ast);

int main(int argc, const char *argv[])
{
    
    assert(argc == 2);
    auto input = argv[1];
    // auto output = argv[3];

    yyin = fopen(input, "r");
    assert(yyin);
    unique_ptr<AST> base_ast;
    unique_ptr<CompUnit> ast;
    // ast.reset((CompUnit *)base_ast.release());
    auto ret = yyparse(base_ast);
    assert(!ret);
    ast.reset((CompUnit *)base_ast.release());
    ast->MyPrint(0);
    std::cout << "End!" << std::endl;
    return 0;
}
