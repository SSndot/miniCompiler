#include "AST.h"
#include "Symbol.h"
#include <memory>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include "utils.h"
using namespace std;

void printIndent(int level) {
    cout << string(level * 2, '     '); // 每层缩进两个空格
}

void CompUnit::MyPrint(int indent) const {
    cout << "CompUnit {\n";
    for (const auto& decl : Decls) {
        decl->MyPrint(1); // 增加缩进
    }
    for (const auto& func : funcdefs) {
        func->MyPrint(1); // 增加缩进
    }
    cout<<"}\n";
}

void Decl::MyPrint(int indent) const{
    vardecl->MyPrint(indent);
}
// BType的打印方法
void BType::MyPrint(int indent) const {
    printIndent(indent); // 假设BType总是从CompUnit开始的第一层
    cout << "BType: " << (tag == INT ? "int" : "unknown") <<"  ";
}

// 变量定义
void VarDecl::MyPrint(int indent) const {
    printIndent(indent);
    cout << "VarDecl:\n";
   
    for (const auto& varDef : vardefs) {
        varDef->MyPrint(indent+1); // 增加缩进
    }
}

// VarDef的打印方法
void VarDef::MyPrint(int indent) const {
    printIndent(indent); // 假设VarDef是VarDecl下一层
 
    if(tag==VARIABLE){
        cout<<"VARIABLE "<<ident<<"\n";
        initval->MyPrint(indent+1); // 若有初始化值，则进一步增加缩进
    }
    else{
        cout<<"ARRAY "<<ident;
        for (size_t i = 0; i < int_consts.size(); ++i) {
            cout << "[" <<int_consts[i]<<"]";
        }
        cout<<"\n";
    }
}

void InitVal::MyPrint(int indent)const{
    if(exp)exp->MyPrint(indent);
}

// 其他类的MyPrint方法以类似方式实现
// 以下是部分示例实现

void FuncDef::MyPrint(int indent) const {
    printIndent(indent);
    cout << "FuncDef: {" << ident << "\n";
    // 假设FuncType总是从FuncDef开始的第一层
    functype->MyPrint(indent+1);
    printIndent(indent+1);
    cout<<ident<<"\n";
    if (funcfparams) {
        funcfparams->MyPrint(indent+1);
    }
    block->MyPrint(indent+1);
    printIndent(indent);
    cout<<"}\n";
}

void FuncType::MyPrint(int indent) const {
    printIndent(indent);
    cout << "FuncType: " << (tag == VOID ? "void" : "int") << "\n";
}

void FuncFParams::MyPrint(int indent) const {
    printIndent(indent);
    cout<<"FuncFParams:"<<"\n";
    for (const auto& param : funcfparams) {
        param->MyPrint(indent+1); // 增加缩进
    }
}

void FuncFParam::MyPrint(int indent) const {
    printIndent(indent);
    if(tag==VARIABLE){
        cout<<"VARIABLE "<<ident<<"\n";
    }
    else{
        cout<<"ARRAY "<<ident;
        if (int_consts.empty()) {
                cout << "[]\n"; // 输出占位符
        } else {
            // 遍历并为每个维度打印[]
            for (size_t i = 0; i < int_consts.size(); ++i) {
                cout << "[" << int_consts[i] << "]";
            }
            cout<<"\n";
        }
    }
 
}

void Block::MyPrint(int indent)const{
    printIndent(indent);
    cout<<"Block:{\n";
    for (const auto& item : blockitems) {
        item->MyPrint(indent+1); // 增加缩进
    }
    printIndent(indent);
    cout<<"}\n";
}

void BlockItem::MyPrint(int indent)const{
    if(tag==DECL){
        decl->MyPrint(indent);
    }
    else{
        stmt->MyPrint(indent);
    }
}

void Stmt::MyPrint(int indent)const{
    if(tag==ASSIGN){
        printIndent(indent);
        cout<<"ASSIGN:{\n";
        lval->MyPrint(indent+1);
        exp->MyPrint(indent+1);
        printIndent(indent);
        cout<<"}\n";
    }
    else if(tag==EXP){
        exp->MyPrint(indent);
    }
    else if(tag==BLOCK){
        block->MyPrint(indent);
    }
    else if(tag==IF){
        printIndent(indent);
        cout<<"IF_STMT:{\n";

        printIndent(indent+1);
        cout<<"IF:{\n";
        exp->MyPrint(indent+2);
        printIndent(indent+1);
        cout<<"}\n";
        if_stmt->MyPrint(indent+1);
        if(else_stmt!=nullptr){
            printIndent(indent+1);
            cout<<"ELSE:\n";
            else_stmt->MyPrint(indent+2);
        }

        printIndent(indent);
        cout<<"}\n";
    }
    else if(tag==WHILE){
        printIndent(indent);
        cout<<"WHILE:\n";
        exp->MyPrint(indent+1);
        while_stmt->MyPrint(indent+1);
    }
    else if (tag==BREAK){
        printIndent(indent);
        cout<<"BREAK\n";
    }
    else if(tag==CONTINUE){
        printIndent(indent);
        cout<<"CONTINUE\n";
    }
    else {
        printIndent(indent);
        cout<<"RETURN:\n";
        exp->MyPrint(indent+1);
    }
    
}
void Exp::MyPrint(int indent)const{
    lorexp->MyPrint(indent);
}

void LVal::MyPrint(int indent) const  {
    printIndent(indent); // 假设已经有了这个辅助函数
    cout << "LVal: " << ident<<"\n";
    if (tag == ARRAY) {
        for (const auto& exp : exps) {
            printIndent(indent+1); 
            cout << "[\n";
            exp->MyPrint(indent+1); // 假设Exp也实现了MyPrint方法，不增加额外缩进
            printIndent(indent+1); 
            cout << "]\n";
        }
    }
}

void PrimaryExp::MyPrint(int indent)const{
    if(tag==EXP){
        exp->MyPrint(indent);
    }
    else if (tag==LVAL){
        lval->MyPrint(indent);
    }
    else{
        number->MyPrint(indent);
    }
}

void Number::MyPrint(int indent)const{
    printIndent(indent);
    cout<<"INT_CONST "<<num<<"\n";
}

void UnaryExp::MyPrint(int indent)const{
    if(tag==PRIMARY_EXP){
        primaryexp->MyPrint(indent);
    }
    else if(tag==FUNC){
        printIndent(indent);
        cout<<"CALL "<<ident<<":\n";
        funcrparams->MyPrint(indent+1);
    }
    else {
        unaryop->MyPrint(indent);
        unaryexp->MyPrint(indent);
    }
}

void UnaryOp::MyPrint(int indent)const{
    printIndent(indent);
    cout<<"UNARY_OP: "<<unaryop<<"\n";
}

void FuncRParams::MyPrint(int indent)const{
    printIndent(indent);
    cout<<"FUNR_PARAMS: \n";
    for (const auto& exp : exps){
        exp->MyPrint(indent+1);
    }
}

void MulExp::MyPrint(int indent)const{
    if(tag==UNARY_EXP){
        unaryexp->MyPrint(indent);
    }
    else{
        printIndent(indent);
        cout<<"BINARY_OP: "<<op<<"\n";
        mulexp->MyPrint(indent+1);
        unaryexp->MyPrint(indent+1);
    }
}

void AddExp::MyPrint(int indent)const{
    if(tag==MULEXP){
        mulexp->MyPrint(indent);
    }
    else{
        printIndent(indent);
        cout<<"BINARY_OP: "<<op<<"\n";
        addexp->MyPrint(indent+1);
        mulexp->MyPrint(indent+1);
    }
}

void RelExp::MyPrint(int indent)const{
    if(tag==ADDEXP){
        addexp->MyPrint(indent);
    }
    else{
        printIndent(indent);
        cout<<"REL_OP: "<<string(op,2)<<"\n";
        relexp->MyPrint(indent+1);
        addexp->MyPrint(indent+1);
    }
}

void EqExp::MyPrint(int indent)const{
    if(tag==RELEXP){
        relexp->MyPrint(indent);
    }
    else{
        printIndent(indent);
        cout<<"EQ_OP: "<<string(op,2)<<"\n";
        eqexp->MyPrint(indent+1);
        relexp->MyPrint(indent+1);
    }
}

void LAndExp::MyPrint(int indent)const{
    if(tag==EQEXP){
        eqexp->MyPrint(int indent);
    }
    else{
        printIndent(indent);
        cout<<"LAND_OP: &&\n";
        landexp->MyPrint(indent+1);
        eqexp->MyPrint(indent+1);
    }
}

void LOrExp::MyPrint(int indent)const{
    if(tag==LANDEXP){
        landexp->MyPrint(int indent);
    }
    else{
        printIndent(indent);
        cout<<"LAND_OP: &&\n";
        landexp->MyPrint(indent+1);
        eqexp->MyPrint(indent+1);
    }
}