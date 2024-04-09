#pragma once
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class AST;
class CompUnit; // 编译单元
class BType;    // 基本类型
class Decl;     // 声明
class VarDecl;  // 变量声明
class VarDef;   // 变量定义
class InitVal;  // 变量初值

class FuncDef;     // 函数定义
class FuncType;    // 函数类型
class FuncFParams; // 函数形参
class FuncFParam;  // 函数形参

class Block;       // 语句块
class BlockItem;   // 语句块项
class Stmt;        // 语句
class Exp;         // 表达式
class LVal;        // 左值表达式
class PrimaryExp;  // 基本表达式
class Number;      // 数值
class UnaryExp;    // 一元表达式
class UnaryOp;     // 单目运算符
class FuncRParams; // 函数实参表

class MulExp;  // 乘除模表达式
class AddExp;  // 加减表达式
class RelExp;  // 关系表达式
class EqExp;   // 相等性表达式
class LOrExp;  // 逻辑或表达式
class LAndExp; // 逻辑与表达式

class IntConstList;

class AST
{
public:
    virtual ~AST() = default;
    // virtual void MyPrint(int indent = 0);
};

// 数组
class IntConstList : public AST
{
public:
    vector<int> list;
    void MyPrint(int indent) const;
};

// 编译单元
class CompUnit : public AST
{
public:
    vector<unique_ptr<Decl>> decls;
    vector<unique_ptr<FuncDef>> funcdefs;
    void MyPrint(int indent) const;
};

// //基本类型  只有int
// class BType:public AST{
// public:
//     enum TAG {INT};
//     TAG tag;
//     void MyPrint(int indent) const;
// };

// 声明
class Decl : public AST
{
public:
    unique_ptr<VarDecl> vardecl;
    void MyPrint(int indent) const;
};

class VarDecl : public AST
{
public:
    vector<unique_ptr<VarDef>> vardefs;
    string btype;
    void MyPrint(int indent) const;
};

// 变量定义
class VarDef : public AST
{
public:
    enum TAG
    {
        VARIABLE,
        ARRAY
    };
    TAG tag;
    string ident;
    unique_ptr<InitVal> initval; // 若为空说明没有初始值
    unique_ptr<IntConstList> int_consts;
    void MyPrint(int indent) const;
};

// 变量初值
class InitVal : public AST
{
public:
    unique_ptr<Exp> exp;
    void MyPrint(int indent) const;
};

// 函数定义
class FuncDef : public AST
{
public:
    string functype;
    string ident;
    unique_ptr<FuncFParams> funcfparams;
    unique_ptr<Block> block;
    void MyPrint(int indent) const;
};

// //函数类型
// class FuncType:public AST{
// public:
//     enum TAG{VOID,INT};
//     TAG tag;
//     void MyPrint(int indent) const;
// };

// 函数形参
class FuncFParams : public AST
{
public:
    vector<unique_ptr<FuncFParam>> funcfparams;
    void MyPrint(int indent) const;
};

class FuncFParam : public AST
{
public:
    enum TAG
    {
        VARIABLE,
        ARRAY
    };
    TAG tag;
    string btype;
    string ident;
    unique_ptr<IntConstList> int_consts;

    void MyPrint(int indent) const;
};

// 函数体
class Block : public AST
{
public:
    vector<unique_ptr<BlockItem>> blockitems;
    void MyPrint(int indent) const;
};

// 语句块项
class BlockItem : public AST
{
public:
    enum TAG
    {
        DECL,
        STMT
    };
    TAG tag;
    unique_ptr<Decl> decl;
    unique_ptr<Stmt> stmt;
    void MyPrint(int indent) const;
};

// 语句
class Stmt : public AST
{
public:
    enum TAG
    {
        ASSIGN,
        EXP,
        BLOCK,
        IF,
        WHILE,
        BREAK,
        CONTINUE,
        RETURN
    };
    TAG tag;
    unique_ptr<LVal> lval;
    unique_ptr<Exp> exp;
    unique_ptr<Block> block;
    unique_ptr<Stmt> if_stmt;
    unique_ptr<Stmt> else_stmt;
    unique_ptr<Stmt> while_stmt;
    void MyPrint(int indent) const;
};

// 表达式
class Exp : public AST
{
public:
    unique_ptr<LOrExp> lorexp;
    void MyPrint(int indent) const;
};

class LVal : public AST
{
public:
    enum TAG
    {
        VARIABLE,
        ARRAY
    };
    TAG tag;
    string ident;
    vector<unique_ptr<Exp>> exps;
    void MyPrint(int indent) const;
};

// 基本表达式
class PrimaryExp : public AST
{
public:
    enum TAG
    {
        EXP,
        LVAL,
        NUMBER
    };
    TAG tag;
    unique_ptr<Exp> exp;
    unique_ptr<LVal> lval;
    unique_ptr<Number> number;
    void MyPrint(int indent) const;
};
class Number : public AST
{
public:
    int num;
    void MyPrint(int indent) const;
};

// 一元表达式
class UnaryExp : public AST
{
public:
    enum TAG
    {
        PRIMARY_EXP,
        FUNC,
        OP_EXP
    };
    TAG tag;
    unique_ptr<PrimaryExp> primaryexp;
    string ident;
    unique_ptr<FuncRParams> funcrparams;
    unique_ptr<UnaryOp> unaryop;
    unique_ptr<UnaryExp> unaryexp;
    void MyPrint(int indent) const;
};

class UnaryOp : public AST
{
public:
    char unaryop;
    void MyPrint(int indent) const;
};

// 函数实参表
class FuncRParams : public AST
{
public:
    vector<unique_ptr<Exp>> exps;
    void MyPrint(int indent) const;
};

class MulExp : public AST
{
public:
    enum TAG
    {
        UNARY_EXP,
        MUL_UNARY_EXP
    };
    TAG tag;
    unique_ptr<UnaryExp> unaryexp;
    unique_ptr<MulExp> mulexp;
    char op;
    void MyPrint(int indent) const;
};

// 加减表达式
class AddExp : public AST
{
public:
    enum TAG
    {
        MULEXP,
        ADD_MUL_EXP
    };
    TAG tag;
    unique_ptr<MulExp> mulexp;
    unique_ptr<AddExp> addexp;
    char op;
    void MyPrint(int indent) const;
};
// 关系表达式
class RelExp : public AST
{
public:
    enum TAG
    {
        ADDEXP,
        REL_ADD_EXP,
        IDENT
    };
    TAG tag;
    unique_ptr<AddExp> addexp;
    unique_ptr<RelExp> relexp;
    char op[2];
    void MyPrint(int indent) const;
};

// 相等性表达式
class EqExp : public AST
{
public:
    enum TAG
    {
        RELEXP,
        EQ_REL_EXP,
        IDENT
    };
    TAG tag;
    unique_ptr<RelExp> relexp;
    unique_ptr<EqExp> eqexp;
    char op[2];
    void MyPrint(int indent) const;
};

class LAndExp : public AST
{
public:
    enum TAG
    {
        EQEXP,
        LAND_EQ_EXP,
        IDENT
    };
    TAG tag;
    unique_ptr<EqExp> eqexp;
    unique_ptr<LAndExp> landexp;
    void MyPrint(int indent) const;
};

// 逻辑或表达式
class LOrExp : public AST
{
public:
    enum TAG
    {
        LANDEXP,
        LOR_LAND_EXP,
        IDENT
    };
    TAG tag;
    unique_ptr<LAndExp> landexp;
    unique_ptr<LOrExp> lorexp;
    void MyPrint(int indent) const;
};
