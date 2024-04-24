#include "SymbolTable.h"
#include <iostream>
#include <cassert>
using namespace std;

MyType::MyType(): type(INT){}
MyType::MyType(int t, int dim_size): type(ARRAY), dim_size(dim_size){}
MyType::MyType(vector<int>dim): type(ARRAY), dim_size(dim.size()), dim(dim){}
MyType::MyType(int t){
    switch (t)
    {
    case 0:
        type = VOID;
        break;
    case 1:
        type = INT;
        break;
    case 2:
        type = ARRAY;
        break;
    case 3:
        type = EMPTY;
        break;
    default:
        assert(0);
    }
}

Symbol::Symbol(){}
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
    return Symbol();
}

void FuncTable::insertFUNC(const string& ident,int t){
    MyType t1=MyType(t);
    Symbol s=Symbol(t1,ident);
    table.insert({ident,s});
}

void FuncTable::insertFUNC_Param(const string& ident, int t , vector<MyType> params){
    MyType t1=MyType(t);
    Symbol s=Symbol(t1,ident,params);
    table.insert({ident,s});
}


Symbol FuncTable::lookup(const string&ident){
    if(table.find(ident)!=table.end()){
        return table.find(ident)->second;
    }
    return Symbol();
}

void VariableStack::BeginScope(){
    v_stack.emplace_back(new VariableTable());
}

void VariableStack::EndScope(){
    v_stack.pop_back();
}

void VariableStack::insertINT(const string& ident){
    v_stack.back()->insertINT(ident);
}

void VariableStack::insertARRAY(const string& ident,vector<int>dim){
    v_stack.back()->insertARRAY(ident,dim);
}

MyType VariableStack::getType(const string& ident){
    int i=(int)v_stack.size()-1;
    for(; i>=0; i-=1){
        if(v_stack[i]->table.find(ident)!=v_stack[i]->table.end())break;
    }
    assert(i >= 0);
    Symbol s=v_stack[i]->lookup(ident);
    return s.type;
}

vector<int> VariableStack::getDim(const string& ident){
    int i=(int)v_stack.size()-1;
    for(;i>=0;i-=1){
        if(v_stack[i]->table.find(ident)!=v_stack[i]->table.end())break;
    }
    assert(i >= 0);
    Symbol s=v_stack[i]->lookup(ident);
    return s.type.dim;

}

size_t VariableStack::getDimSize(const string& ident){
    int i=(int)v_stack.size()-1;
    for(;i>=0;i-=1){
        if(v_stack[i]->table.find(ident)!=v_stack[i]->table.end())break;
    }
    assert(i >= 0);
    Symbol s=v_stack[i]->lookup(ident);
    return s.type.dim_size;
}

bool VariableStack::isInStack(const string& ident){
    int i=(int)v_stack.size()-1;
    for(; i>=0; i-=1){
        if(v_stack[i]->table.find(ident)!=v_stack[i]->table.end())break;
    }
    return (i >= 0);     
}

bool VariableStack::isInCurrentTable(const string&ident){
    return(v_stack.back()->table.find(ident)!=v_stack.back()->table.end());
}

void FuncStack::BeginScope(){
    f_stack.emplace_back(new FuncTable());
}

void FuncStack::EndScope(){
    f_stack.pop_back();
}

void FuncStack::insertFUNC(const string& ident,int t){
    f_stack.back()->insertFUNC(ident,t);
}

void FuncStack::insertFUNC_param(const string& ident,int type,vector<MyType>params){
    f_stack.back()->insertFUNC_Param(ident,type,params);
}

MyType FuncStack::getType(const string& ident){
    int i=(int)f_stack.size()-1;
    for(; i>=0; i-=1){
        if(f_stack[i]->table.find(ident)!=f_stack[i]->table.end())break;
    }
    assert(i >= 0);
    Symbol s=f_stack[i]->lookup(ident);
    return s.type;
}

vector<MyType> FuncStack::getParamsType(const string& ident){
    int i=(int)f_stack.size()-1;
    for(; i>=0; i-=1){
        if(f_stack[i]->table.find(ident)!=f_stack[i]->table.end())break;
    }
    assert(i >= 0);
    Symbol s=f_stack[i]->lookup(ident);
    if(s.params.size() != 0) return s.params;
    else return vector<MyType>();
}

bool FuncStack::isInStack(const string& ident){
    int i=(int)f_stack.size()-1;
    for(; i>=0; i-=1){
        if(f_stack[i]->table.find(ident)!=f_stack[i]->table.end())break;
    }
    return (i >= 0);  
}

bool FuncStack::isInCurrentTable(const string&ident){
    return(f_stack.back()->table.find(ident)!=f_stack.back()->table.end());
}

MyType::~MyType() {
}
Symbol::~Symbol() {
}
VariableTable::~VariableTable() {
}


