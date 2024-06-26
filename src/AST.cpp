#include "AST.h"
// #include "Symbol.h"

// #include "utils.h"
using namespace std;

void printIndent(int level)
{
    cout << string(level * 2, ' '); // 每层缩进两个空格
}

void CompUnit::MyPrint(int indent) const
{
    cout << "CompUnit {\n";
    for (const auto &decl : decls)
    {
        decl->MyPrint(1); // 增加缩进
    }
    for (const auto &func : funcdefs)
    {
        func->MyPrint(1); // 增加缩进
    }
    cout << "}\n";
}
void IntConstList::MyPrint(int indent) const
{
    if (list.empty())
    {
        cout << "[]\n"; // 输出占位符
    }
    else
    {
        // 遍历并为每个维度打印[]
        for (size_t i = 0; i < list.size(); ++i)
        {
            cout << "[" << list[i] << "]";
        }
        cout << "\n";
    }
}
void Decl::MyPrint(int indent) const
{
    vardecl->MyPrint(indent);
}

// // BType的打印方法
// void BType::MyPrint(int indent) const{
//     printIndent(indent); // 假设BType总是从CompUnit开始的第一层
//     cout << "BType: " << (tag == INT ? "int" : "unknown") <<"  ";
// }

// 变量定义
void VarDecl::MyPrint(int indent) const
{
    printIndent(indent);
    cout << "VarDecl:\n";
    for (const auto &varDef : vardefs)
    {
        varDef->MyPrint(indent + 1); // 增加缩进
    }
}

// VarDef的打印方法
void VarDef::MyPrint(int indent) const
{
    printIndent(indent); // 假设VarDef是VarDecl下一层

    if (tag == VARIABLE)
    {
        cout << "VARIABLE " << ident << "\n";
        if (initval)
            initval->MyPrint(indent + 1); // 若有初始化值，则进一步增加缩进
    }
    else
    {
        cout << "ARRAY " << ident;
        if (int_consts)
            int_consts->MyPrint(indent);
    }
}

void InitVal::MyPrint(int indent) const
{
    if (exp)
        exp->MyPrint(indent);
}

// 其他类的MyPrint方法以类似方式实现
// 以下是部分示例实现

void FuncDef::MyPrint(int indent) const
{
    printIndent(indent);
    cout << "FuncDef: " << ident << "{\n";
    printIndent(indent + 1);
    cout << "FuncType: " << functype << "\n";
    // 假设FuncType总是从FuncDef开始的第一层
    // TODO
    // functype->MyPrint(indent+1);

    if (funcfparams)
    {
        funcfparams->MyPrint(indent + 1);
    }
    if (block)
        block->MyPrint(indent + 1);
    printIndent(indent);
    cout << "}\n";
}

// void FuncType::MyPrint(int indent) const{
//     printIndent(indent);
//     cout << "FuncType: " << (tag == VOID ? "void" : "int") << "\n";
// }

void FuncFParams::MyPrint(int indent) const
{
    printIndent(indent);
    cout << "FuncFParams:"
         << "\n";
    for (const auto &param : funcfparams)
    {

        param->MyPrint(indent + 1); // 增加缩进
    }
}

void FuncFParam::MyPrint(int indent) const
{
    printIndent(indent);
    if (tag == VARIABLE)
    {
        cout << "VARIABLE " << ident << "\n";
    }
    else
    {
        cout << "ARRAY " << ident;
        int_consts->MyPrint(indent);
    }
}

void Block::MyPrint(int indent) const
{
    printIndent(indent);
    cout << "Block:{\n";
    for (const auto &item : blockitems)
    {
        item->MyPrint(indent + 1); // 增加缩进
    }
    printIndent(indent);
    cout << "}\n";
}

void BlockItem::MyPrint(int indent) const
{
    if (tag == DECL)
    {
        decl->MyPrint(indent);
    }
    else
    {
        stmt->MyPrint(indent);
    }
}

void Stmt::MyPrint(int indent) const
{
    if (tag == ASSIGN)
    {
        printIndent(indent);
        cout << "ASSIGN:{\n";
        lval->MyPrint(indent + 1);
        exp->MyPrint(indent + 1);
        printIndent(indent);
        cout << "}\n";
    }
    else if (tag == EXP)
    {
        exp->MyPrint(indent);
    }
    else if (tag == BLOCK)
    {
        if (block)
            block->MyPrint(indent);
    }
    else if (tag == IF)
    {
        printIndent(indent);
        cout << "IF_Stmt:{\n";

        printIndent(indent + 1);
        cout << "IF:{\n";
        exp->MyPrint(indent + 2);
        printIndent(indent + 1);
        cout << "}\n";
        if_stmt->MyPrint(indent + 1);
        if (else_stmt != nullptr)
        {
            printIndent(indent + 1);
            cout << "ELSE:\n";
            else_stmt->MyPrint(indent + 2);
        }

        printIndent(indent);
        cout << "}\n";
    }
    else if (tag == WHILE)
    {
        printIndent(indent);
        cout << "WHILE:\n";
        exp->MyPrint(indent + 1);
        while_stmt->MyPrint(indent + 1);
    }
    else if (tag == BREAK)
    {
        printIndent(indent);
        cout << "BREAK\n";
    }
    else if (tag == CONTINUE)
    {
        printIndent(indent);
        cout << "CONTINUE\n";
    }
    else
    {
        printIndent(indent);
        cout << "RETURN:\n";
        if (exp)
            exp->MyPrint(indent + 1);
    }
}
void Exp::MyPrint(int indent) const
{
    lorexp->MyPrint(indent);
}

void LVal::MyPrint(int indent) const
{
    printIndent(indent); // 假设已经有了这个辅助函数
    cout << "Ident: " << ident << "\n";
    if (tag == ARRAY)
    {

        if (!exps.empty())
        {
            for (const auto &exp : exps)
            {
                printIndent(indent + 1);
                cout << "[\n";
                exp->MyPrint(indent + 1); // 假设Exp也实现了MyPrint方法，不增加额外缩进
                printIndent(indent + 1);
                cout << "]\n";
            }
        }
    }
}

void PrimaryExp::MyPrint(int indent) const
{
    if (tag == EXP)
    {
        exp->MyPrint(indent);
    }
    else if (tag == LVAL)
    {
        lval->MyPrint(indent);
    }
    else
    {
        number->MyPrint(indent);
    }
}

void Number::MyPrint(int indent) const
{
    printIndent(indent);
    cout << "INT_CONST " << num << "\n";
}

void UnaryExp::MyPrint(int indent) const
{
    if (tag == PRIMARY_EXP)
    {
        primaryexp->MyPrint(indent);
    }
    else if (tag == FUNC)
    {
        printIndent(indent);
        cout << "CALL " << ident << ":\n";
        if (funcrparams)
            funcrparams->MyPrint(indent + 1);
    }
    else
    {
        unaryop->MyPrint(indent);
        unaryexp->MyPrint(indent);
    }
}

void UnaryOp::MyPrint(int indent) const
{
    printIndent(indent);
    cout << "UNARY_OP: " << unaryop << "\n";
}

void FuncRParams::MyPrint(int indent) const
{
    printIndent(indent);
    cout << "FUNR_PARAMS: \n";
    for (const auto &exp : exps)
    {
        exp->MyPrint(indent + 1);
    }
}

void MulExp::MyPrint(int indent) const
{
    if (tag == UNARY_EXP)
    {
        unaryexp->MyPrint(indent);
    }
    else
    {
        printIndent(indent);
        if (op != '\0')
            cout << "BINARY_OP: " << op << "\n";
        if (mulexp)
            mulexp->MyPrint(indent + 1);
        if (unaryexp)
            unaryexp->MyPrint(indent + 1);
    }
}

void AddExp::MyPrint(int indent) const
{
    if (tag == MULEXP)
    {
        mulexp->MyPrint(indent);
    }
    else
    {
        printIndent(indent);
        if (op != '\0')
            cout << "BINARY_OP: " << op << "\n";
        if (addexp)
            addexp->MyPrint(indent + 1);
        if (mulexp)
            mulexp->MyPrint(indent + 1);
    }
}

void RelExp::MyPrint(int indent) const
{
    if (tag == ADDEXP)
    {
        addexp->MyPrint(indent);
    }
    else
    {
        printIndent(indent);
        if (op[0] != '\0')
            cout << "REL_OP: " << string(op, 2) << "\n";
        if (relexp)
            relexp->MyPrint(indent + 1);
        if (addexp)
            addexp->MyPrint(indent + 1);
    }
}

void EqExp::MyPrint(int indent) const
{
    if (tag == RELEXP)
    {
        relexp->MyPrint(indent);
    }
    else
    {
        printIndent(indent);
        if (op[0] != '\0')
            cout << "EQ_OP: " << string(op, 2) << "\n";
        if (eqexp)
            eqexp->MyPrint(indent + 1);
        if (relexp)
            relexp->MyPrint(indent + 1);
    }
}

void LAndExp::MyPrint(int indent) const
{
    if (tag == EQEXP)
    {
        eqexp->MyPrint(indent);
    }
    else
    {
        printIndent(indent);
        cout << "LAND_OP: &&\n";
        if (landexp)
            landexp->MyPrint(indent + 1);
        if (eqexp)
            eqexp->MyPrint(indent + 1);
    }
}

void LOrExp::MyPrint(int indent) const
{
    if (tag == LANDEXP)
    {
        landexp->MyPrint(indent);
    }
    else
    {
        printIndent(indent);
        cout << "LAND_OP: &&\n";
        if (landexp)
            landexp->MyPrint(indent + 1);
        if (lorexp)
            lorexp->MyPrint(indent + 1);
    }
}