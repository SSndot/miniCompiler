#include "SymbolTable.h"
#include <iostream>
using namespace std;

MyType::MyType():type(INT){}
MyType::MyType(vector<int>dim):type(ARRAY),dim(dim){}
MyType::MyType(int t){
    if(t==0){
        type=FUNC_VOID;
    }
    else{
        type=FUNC_INT;
    }
}

Symbol::Symbol(MyType type, string ident):type(type),ident(ident){}
Symbol::Symbol(MyType type, string ident,vector<MyType>params):type(type),ident(ident),params(params){}

void VariableTable::insertINT(const string &ident){
    MyType t=MyType();
    Symbol s=Symbol(t,ident);
    table.insert({ident,s});
}

void VariableTable::insertARRAY(const string &ident, vector<int>a){
    MyType t=MyType(a);
    Symbol s=Symbol(t,ident);
    table.insert({ident,s});
}

Symbol VariableTable::lookup(const string &ident){
    if(table.find(ident)!=table.end()){
        return table.find(ident)->second;
    }
}

void FuncTable::insertFUNC(const string& ident,int t){
    MyType t1=MyType(t);
    Symbol s=Symbol(t1,ident);
    table.insert({ident,s});
}

void FuncTable::insertFUNC_Param(const string& ident,int t , vector<MyType> params){
    MyType t1=MyType(t);
    Symbol s=Symbol(t1,ident,params);
    table.insert({ident,s});
}

Symbol FuncTable::lookup(const string&ident){
    if(table.find(ident)!=table.end()){
        return table.find(ident)->second;
    }
}

void VariableStack::BeginScope(){
    v_stack.emplace_back(new VariableTable());
}

void VariableStack::EndScope(){
    v_stack.pop_back();
}

void  VariableStack::insertINT(const string& ident){
    v_stack.back()->insertINT(ident);
}

void VariableStack::insertARRAY(const string& ident,vector<int>dim){
    v_stack.back()->insertARRAY(ident,dim);
}

MyType VariableStack::getType(const string& ident){
    int i=(int)v_stack.size()-1;
    for(;i>=0;i=i-1){
        if(v_stack[i]->table.find(ident)!=v_stack[i]->table.end())break;
    }
    Symbol s=v_stack[i]->lookup(ident);
    return s.type;
}

vector<int> VariableStack::getDim(const string& ident){
    int i=(int)v_stack.size()-1;
    for(;i>=0;i=i-1){
        if(v_stack[i]->table.find(ident)!=v_stack[i]->table.end())break;
    }
    Symbol s=v_stack[i]->lookup(ident);
    return s.type.dim;

}



void FuncStack::BeginScope(){
    f_stack.emplace_back(new FuncTable());
}

void FuncStack::EndScope(){
    f_stack.pop_back();
}

void  FuncStack::insertFUNC(const string& ident,int t){
    f_stack.back()->insertFUNC(ident,t);
}

void FuncStack::insertFUNC_param(const string& ident,int type,vector<MyType>params){
    f_stack.back()->insertFUNC_Param(ident,type,params);
}

MyType FuncStack::getType(const string& ident){
    int i=(int)f_stack.size()-1;
    for(;i>=0;i=i-1){
        if(f_stack[i]->table.find(ident)!=f_stack[i]->table.end())break;
    }
    Symbol s=f_stack[i]->lookup(ident);
    return s.type;
}

vector<MyType> FuncStack::getParamsType(const string& ident){
    int i=(int)f_stack.size()-1;
    for(;i>=0;i=i-1){
        if(f_stack[i]->table.find(ident)!=f_stack[i]->table.end())break;
    }
    Symbol s=f_stack[i]->lookup(ident);
    return s.params;
    
}

MyType::~MyType() {
}
Symbol::~Symbol() {
}
VariableTable::~VariableTable() {
}


