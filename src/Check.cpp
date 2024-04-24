#include "SymbolTable.h"
#include "AST.h"
VariableStack vs;
FuncStack fs;
void CompUnit::Check(){
    // 定义新的作用域
    vs.BeginScope();
    fs.BeginScope();
    // 检查全局变量
    for(auto &d : decls){
        d->Check();
    }

    // 加入函数
    vector<MyType> param_type;
    param_type.emplace_back(MyType(MyType::INT));
    fs.insertFUNC_param("putint", 0, param_type);
    fs.insertFUNC("getint", 1);

    // 检查函数
    for(auto &f : funcdefs)
        f->Check();

    fs.EndScope();
    vs.EndScope();
}

void Decl::Check(){
    if(vardecl != nullptr)
        vardecl->Check();
}

void VarDecl::Check(){
    for(auto &var_def : vardefs)
        var_def->Check();
}

/* Vardef检查内容:
1. 同一个作用域内重复定义变量(对VARIABLE/ARRAY类型)
2. 变量定义中左右表达式类型不匹配(对VARIABLE类型)
3. 数组维度不是正数(对ARRAY类型)
*/
void VarDef::Check(){
try{
    //ERROR 同一个作用域内重复定义变量
    if(vs.isInCurrentTable(ident))
        throw "Variable is defined repeatedly within the same scope.";
    if(tag == VARIABLE){
        if(initval == nullptr){
            //添加变量到符号表
            vs.insertINT(ident);                
        }
        else{
            MyType rtype = initval->Check();
            //ERROR 变量定义中左右表达式类型不匹配
            if(rtype.type != MyType::INT)
                throw "The left and right expression types in the variable definition do not match.";
            //添加变量到符号表
            vs.insertINT(ident);                  
        }
    }
    else if(tag == ARRAY){
        for(size_t i = 0; i < int_consts->list.size(); ++i){
            //ERROR 数组维度不是正数
            if(int_consts->list[i] <= 0)
                throw "The array dimension cannot be defined as a non-positive number.";
        }
        vs.insertARRAY(ident, int_consts->list);
    }
    else
        assert(0);
}

catch(const char* e){
    std::cout << "[Error]: " << e << std::endl;
    exit(1);
}
}

MyType InitVal::Check(){
    if(exp != nullptr) return exp->Check(false);
    else return MyType(3);
}

MyType Exp::Check(bool is_func_r_param){
    if(lorexp != nullptr) return lorexp->Check(is_func_r_param);
    else return MyType(3);
}

/* LOrExp检查内容:
1. 操作数类型不匹配或操作数类型与操作符不匹配(对LOR_LAND_EXP类型)
*/
MyType LOrExp::Check(bool is_func_r_param){
try{
    if(tag == LANDEXP){
        if(landexp != nullptr) return landexp->Check(is_func_r_param);
        else return MyType(3);
    }
    else if(tag == LOR_LAND_EXP){
        MyType ltype = (lorexp == nullptr) ? MyType(3) : lorexp->Check(is_func_r_param);
        MyType rtype = (landexp == nullptr) ? MyType(3) : landexp->Check(is_func_r_param);
        //ERROR 操作数类型不匹配或操作数类型与操作符不匹配(两个操作数必须都是INT类型)
        if(ltype.type != MyType::INT || rtype.type != MyType::INT)
            throw "The operand type does not match the operator.";
        return MyType(MyType::INT);
    }
    else
        assert(0);
}

catch(const char* e){
    std::cout << "[Error]: " << e << std::endl;
    exit(1);
}
}

/* LAndExp检查内容:
1. 操作数类型不匹配或操作数类型与操作符不匹配(对LAND_EQ_EXP类型)
*/
MyType LAndExp::Check(bool is_func_r_param){
try{
    if(tag == EQEXP){
        if(eqexp != nullptr) return eqexp->Check(is_func_r_param);
        else return MyType(3);
    }
    else if(tag == LAND_EQ_EXP){
        MyType ltype = (landexp == nullptr) ? MyType(3) : landexp->Check(is_func_r_param);
        MyType rtype = (eqexp == nullptr) ? MyType(3) : eqexp->Check(is_func_r_param);
        //ERROR 操作数类型不匹配或操作数类型与操作符不匹配(两个操作数必须都是INT类型)
        if(ltype.type != MyType::INT || rtype.type != MyType::INT)
            throw "The operand type does not match the operator.";
        return MyType(MyType::INT);
    }
    else
        assert(0);
}

catch(const char* e){
    std::cout << "[Error]: " << e << std::endl;
    exit(1);
}    
}

/* EqExp检查内容:
1. 操作数类型不匹配或操作数类型与操作符不匹配(对EQ_REL_EXP类型)
*/
MyType EqExp::Check(bool is_func_r_param){
try{
    if(tag == RELEXP){
        if(relexp != nullptr) return relexp->Check(is_func_r_param);
        else return MyType(3);
    }      
    else if(tag == EQ_REL_EXP){
        MyType ltype = (eqexp == nullptr) ? MyType(3) : eqexp->Check(is_func_r_param);
        MyType rtype = (relexp == nullptr) ? MyType(3) : relexp->Check(is_func_r_param);
        //ERROR 操作数类型不匹配或操作数类型与操作符不匹配(两个操作数必须都是INT类型)
        if(ltype.type != MyType::INT || rtype.type != MyType::INT)
            throw "The operand type does not match the operator.";
        return MyType(MyType::INT);
    }
    else
        assert(0);
}

catch(const char* e){
    std::cout << "[Error]: " << e << std::endl;
    exit(1);
}    
}

/* RelExp检查内容:
1. 操作数类型不匹配或操作数类型与操作符不匹配(对REL_ADD_EXP类型)
*/
MyType RelExp::Check(bool is_func_r_param){
try{
    if(tag == ADDEXP){
        if(addexp != nullptr) return addexp->Check(is_func_r_param);
        else return MyType(MyType::EMPTY);
    }
    else if(tag == REL_ADD_EXP){
        MyType ltype = (relexp == nullptr) ? MyType(MyType::EMPTY) : relexp->Check(is_func_r_param);
        MyType rtype = (addexp == nullptr) ? MyType(MyType::EMPTY) : addexp->Check(is_func_r_param);
        //ERROR 操作数类型不匹配或操作数类型与操作符不匹配(两个操作数必须都是INT类型)
        if(ltype.type != MyType::INT || rtype.type != MyType::INT)
            throw "The operand type does not match the operator.";
        return MyType(MyType::INT);
    }
    else
        assert(0);
}

catch(const char* e){
    std::cout << "[Error]: " << e << std::endl;
    exit(1);
}    
}

/* AddExp检查内容:
1. 操作数类型不匹配或操作数类型与操作符不匹配(对ADD_MUL_EXP类型)
*/
MyType AddExp::Check(bool is_func_r_param){
try{
    if(tag == MULEXP){
        if(mulexp != nullptr) return mulexp->Check(is_func_r_param);
        else return MyType(MyType::EMPTY);
    }
    else if(tag == ADD_MUL_EXP){
        MyType ltype = (addexp == nullptr) ? MyType(MyType::EMPTY) : addexp->Check(is_func_r_param);
        MyType rtype = (mulexp == nullptr) ? MyType(MyType::EMPTY) : mulexp->Check(is_func_r_param);
        //ERROR 操作数类型不匹配或操作数类型与操作符不匹配(两个操作数必须都是INT类型)
        if(ltype.type != MyType::INT || rtype.type != MyType::INT)
            throw "The operand type does not match the operator.";
        return MyType(MyType::INT);
    }
    else
        assert(0);
}

catch(const char* e){
    std::cout << "[Error]: " << e << std::endl;
    exit(1);
}    
}

/* MulExp检查内容:
1. 操作数类型不匹配或操作数类型与操作符不匹配(对MUL_UNARY_EXP类型)
*/
MyType MulExp::Check(bool is_func_r_param){
try{
    if(tag == UNARY_EXP){
        if(unaryexp != nullptr) return unaryexp->Check(is_func_r_param);
        else return MyType(MyType::EMPTY);
    }
    else if(tag == MUL_UNARY_EXP){
        MyType ltype = (mulexp == nullptr) ? MyType(MyType::EMPTY) : mulexp->Check(is_func_r_param);
        MyType rtype = (unaryexp == nullptr) ? MyType(MyType::EMPTY) : unaryexp->Check(is_func_r_param);
        //ERROR 操作数类型不匹配或操作数类型与操作符不匹配(两个操作数必须都是INT类型)
        if(ltype.type != MyType::INT || rtype.type != MyType::INT)
            throw "The operand type does not match the operator.";
        return MyType(MyType::INT);
    }
    else
        assert(0);
}

catch(const char* e){
    std::cout << "[Error]: " << e << std::endl;
    exit(1);
}    
}

/* UnaryExp检查内容:
1. 调用未定义的函数(对FUNC类型)
2. 函数调用时实参与形参的数目不匹配(对FUNC类型)
3. 函数调用时实参与形参的类型不匹配(对FUNC类型)
4. 函数调用时数组对应维数不匹配(对FUNC类型)
*/
MyType UnaryExp::Check(bool is_func_r_param){
try{
    if(tag == PRIMARY_EXP){
        if(primaryexp != nullptr) return primaryexp->Check(is_func_r_param);
        else return MyType(MyType::EMPTY);
    }
    else if(tag == FUNC){
        //ERROR 调用未定义的函数
        if(!fs.isInStack(ident))
            throw "Calling undefined functions.";
        vector<MyType> param_type = fs.getParamsType(ident);
        size_t f_size = (funcrparams == nullptr) ? 0 : funcrparams->exps.size();
        //ERROR 函数调用时实参与形参的数目不匹配
        if(param_type.size() != f_size)
            throw "The number of actual parameters involved in function calls does not match.";

        for(size_t i = 0; i < param_type.size(); ++i){
            MyType ty = funcrparams->exps[i]->Check(true);
            MyType ty_param = param_type[i];

            //ERROR 函数调用时实参与形参的类型不匹配
            if(ty.type != ty_param.type)
                throw "The type of actual parameters involved in function calls does not match.";
            
            //ERROR 函数调用时数组对应维数不匹配
            if(ty_param.type == MyType::ARRAY && ty_param.dim_size != ty.dim_size)
                throw "Array dimension mismatch during function call.";
        }

        return fs.getType(ident);
    }
    else if(tag == OP_EXP){
        if(unaryexp == nullptr) return MyType(MyType::EMPTY);
        //ERROR 操作数类型不匹配或操作数类型与操作符不匹配(右操作数必须是INT类型)
        if(unaryexp->Check(is_func_r_param).type != MyType::INT)
            throw "The operand type does not match the operator.";
        return MyType(MyType::INT);
    }
    else
        assert(0);
}

catch(const char* e){
    std::cout << "[Error]: " << e << std::endl;
    exit(1);
} 
}

MyType PrimaryExp::Check(bool is_func_r_param){
try{
    if(tag == EXP){
        if(exp != nullptr) return exp->Check(is_func_r_param);
        else return MyType(MyType::EMPTY);
    }
    else if(tag == LVAL){
        if(lval != nullptr) return lval->Check(is_func_r_param);
        else return MyType(MyType::EMPTY);
    }
    else if(tag == NUMBER)
        return MyType(MyType::INT);
    else
        assert(0);
}

catch(const char* e){
    std::cout << "[Error]: " << e << std::endl;
    exit(1);
} 
}

/* LVal检查内容:
1. 使用未定义的变量(对VARIABLE/ARRAY类型)
2. 非法的数组访问操作
*/
MyType LVal::Check(bool is_func_r_param){
try{
    //ERROR 使用未定义的变量
    if(!vs.isInStack(ident))
        throw "Using undefined variables.";

    MyType ty = vs.getType(ident); //寻找变量维数

    if(tag == ARRAY){
        for(auto& exp : exps){
            //ERROR 非法的数组访问操作(使用非整型作为数组索引)
            if(exp->Check(is_func_r_param).type != MyType::INT)
                throw "Illegal array access operation.";
        }
    }

    //不属于函数实参(方括号个数必须和数组变量的维数相同)
    if(!is_func_r_param){
        //单变量类型匹配
        if(ty.type == MyType::INT && tag == VARIABLE)
            return MyType(MyType::INT);
        //ERROR 非法的数组访问操作(对非数组型变量使用数组访问操作符)
        else if(ty.type == MyType::INT && tag == ARRAY)
            throw "Illegal array access operation.";
        //ERROR 非法的数组访问操作(变量定义维数不等于使用维数)
        else if(ty.type == MyType::ARRAY && tag == VARIABLE)
            throw "Illegal array access operation.";
        else if(ty.type == MyType::ARRAY && tag == ARRAY){
            //变量使用维数等于定义维数，为INT
            if(exps.size() == vs.getDimSize(ident))
                return MyType(MyType::INT);
            //ERROR 非法的数组访问操作(变量定义维数不等于使用维数)
            else
                throw "Illegal array access operation.";
        }
        else
            assert(0);
    }
    //属于函数实参(数组的方括号个数可以不与维数相同)
    else{
        //单变量类型匹配
        if(ty.type == MyType::INT && tag == VARIABLE)
            return MyType(MyType::INT);
        //ERROR 非法的数组访问操作(对非数组型变量使用数组访问操作符)
        else if(ty.type == MyType::INT && tag == ARRAY)
            throw "Illegal array access operation.";
        //变量使用维数小于定义维数，为ARRAY
        else if(ty.type == MyType::ARRAY && tag == VARIABLE)
            return MyType(MyType::ARRAY, vs.getDimSize(ident));
        else if(ty.type == MyType::ARRAY && tag == ARRAY){
            //变量使用维数等于定义维数，为INT
            if(exps.size() == vs.getDimSize(ident))
                return MyType(MyType::INT);
            //变量使用维数小于定义维数，为ARRAY
            else if(exps.size() < vs.getDimSize(ident))
                return MyType(MyType::ARRAY, vs.getDimSize(ident) - exps.size());
            //ERROR 非法的数组访问操作(变量使用维数大于定义维数)
            else
                throw "Illegal array access operation.";
        }
        else
            assert(0);
    }
}

catch(const char* e){
    std::cout << "[Error]: " << e << std::endl;
    exit(1);
} 
}

/* FuncDef检查内容:
1. 重复定义函数
2. return 语句的返回类型与函数定义的返回类型不匹配
*/
MyType FuncDef::Check(){
try{
    vs.BeginScope();
    //ERROR 重复定义函数
    if(fs.isInStack(ident))
        throw "Repeatedly defining functions.";
    if(funcfparams == nullptr){
        if(functype == "void") fs.insertFUNC(ident, 0);
        else if(functype == "int") fs.insertFUNC(ident, 1);
    }
    else{
        if(funcfparams != nullptr) funcfparams->Check();
        //将FuncFParam数组转为MyType数组
        vector<MyType> params_type;
        for(auto& func_f_param : funcfparams->funcfparams){
            if(func_f_param->tag == FuncFParam::VARIABLE){
                MyType ty(MyType::INT);
                params_type.emplace_back(ty);
            }
            else if(func_f_param->tag == FuncFParam::ARRAY){
                vector<int> new_list;
                new_list.emplace_back(0);
                new_list.insert(new_list.end(), func_f_param->int_consts->list.begin(), func_f_param->int_consts->list.end());
                MyType ty(new_list);
                params_type.emplace_back(ty);
            }
        }
        if(functype == "void") fs.insertFUNC_param(ident, 0, params_type);
        else if(functype == "int") fs.insertFUNC_param(ident, 1, params_type);        
    }
    MyType res_ty = (block == nullptr) ? MyType(MyType::EMPTY): block->Check(true); 
    //ERROR return 语句的返回类型与函数定义的返回类型不匹配
    if((functype == "void" && (res_ty.type != MyType::VOID && res_ty.type != MyType::EMPTY)) || (functype == "int" && res_ty.type != MyType::INT))
        throw "The return type of the return statement does not match the return type defined by the func.";
    vs.EndScope();
    return res_ty;
}

catch(const char* e){
    std::cout << "[Error]: " << e << std::endl;
    exit(1);
} 
}

void FuncFParams::Check(){
    for(auto& func_f_param : funcfparams)
        func_f_param->Check();
}

/* FuncFParam检查内容:
1. 同一个作用域内重复定义变量(对VARIABLE/ARRAY类型)
2. 数组维度是负数(对ARRAY类型)
*/
void FuncFParam::Check(){
try{
    //ERROR 同一个作用域内重复定义变量
    if(vs.isInCurrentTable(ident))
        throw "Variable is defined repeatedly within the same scope.";  
    if(tag == FuncFParam::VARIABLE)
        vs.insertINT(ident);
    else if(tag == FuncFParam::ARRAY){
       for(size_t i = 0; i < int_consts->list.size(); ++i){
            //ERROR 数组维度是负数
            if(int_consts->list[i] < 0)
                throw "The array dimension cannot be defined as a negative number.";
        }
        vs.insertARRAY(ident, int_consts->list);
    }
    else
        assert(0);
}

catch(const char* e){
    std::cout << "[Error]: " << e << std::endl;
    exit(1);
} 
}

/* Block检查内容:
1. return 语句的返回类型与函数定义的返回类型不匹配(两个return的返回类型不同)
*/
MyType Block::Check(bool if_func){
try{
    if(!if_func) vs.BeginScope();
    MyType res_ty(MyType::EMPTY); //没有return语句
    for(auto& block_item : blockitems){
        MyType ty = block_item->Check();
        //ERROR return 语句的返回类型与函数定义的返回类型不匹配(两个return的返回类型不同)
        if(res_ty.type != MyType::EMPTY && ty.type != MyType::EMPTY && res_ty.type != ty.type)
            throw "The return type of the return statement does not match the return type defined by the func.";
        else if(res_ty.type == MyType::EMPTY && res_ty.type != ty.type){
            res_ty = ty;
        }
    }
    if(!if_func) vs.EndScope();
    return res_ty;
}

catch(const char* e){
    std::cout << "[Error]: " << e << std::endl;
    exit(1);
} 
}

MyType BlockItem::Check(){
    if(tag == DECL){
        if(decl != nullptr) decl->Check();
        return MyType(MyType::EMPTY); //变量定义不涉及返回
    }
    else if(tag == STMT){
        if(stmt != nullptr) return stmt->Check(false);
        else return MyType(MyType::EMPTY);
    }
    else
        assert(0);
}


MyType Stmt::Check(bool is_if){
try{
    if(tag == ASSIGN){
        MyType ltype = (lval == nullptr) ? MyType(MyType::EMPTY) : lval->Check(false);
        MyType rtype = (exp == nullptr) ? MyType(MyType::EMPTY) : exp->Check(false);
        //ERROR 变量赋值中左右表达式类型不匹配
        if(ltype.type != rtype.type)
            throw "Mismatched left and right expression types in variable assignment.";
        else
            return MyType(MyType::EMPTY);
    }
    else if(tag == EXP){
        if(exp != nullptr) exp->Check(false);
        return MyType(MyType::EMPTY);
    }
    else if(tag == BLOCK){
        MyType block_ty = (block == nullptr) ? MyType(MyType::EMPTY) : block->Check(false);
        if(!is_if){
            //ERROR 语句的返回类型与函数定义的返回类型不匹配(没有对应的函数)
            if(block_ty.type != MyType::EMPTY)
                throw "The return type of the return statement does not match the return type defined by the func.";
            return MyType(MyType::EMPTY);
        }
        else
            return block_ty;
    }
    else if(tag == IF){
        if(exp != nullptr) exp->Check(false);
        if(if_stmt != nullptr){
            MyType if_ty = if_stmt->Check(true);
            if(else_stmt == nullptr)
                return if_ty;
            else{
                MyType else_ty = else_stmt->Check(true);
                //ERROR return 语句的返回类型与函数定义的返回类型不匹配(两个return的返回类型不同)
                if(if_ty.type != MyType::EMPTY && else_ty.type != MyType::EMPTY && if_ty.type != else_ty.type)
                    throw "The return type of the return statement does not match the return type defined by the func.";
                else if(if_ty.type == MyType::EMPTY)
                    return else_ty;
                else
                    return if_ty;
            }
        }
        else return MyType(MyType::EMPTY);
    }
    else if(tag == WHILE){
        if(exp != nullptr) exp->Check(false);
        if(while_stmt != nullptr) while_stmt->Check(false);
        return MyType(MyType::EMPTY);
    }
    else if(tag == BREAK || tag == CONTINUE)
        return MyType(MyType::EMPTY);
    else if(tag == RETURN){
        if(exp == nullptr) return MyType(MyType::VOID);
        else return exp->Check(false);
    }
    else
        assert(0);
}

catch(const char* e){
    std::cout << "[Error]: " << e << std::endl;
    exit(1);
} 
}