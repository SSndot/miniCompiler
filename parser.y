%code requires {
    #include <memory>
    #include <string>
    #include "AST.h"
}

%{

#include <iostream>
#include <memory>
#include <string>
#include "AST.h"

int yylex();
void yyerror(std::unique_ptr<AST> &ast, const char* s);

using namespace std;

%}

%parse-param {std::unique_ptr<AST>& ast}

%union {
    int int_val;
    std::string* str_val;
    AST* ast_val;
}

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%token INT VOID RETURN LESS_EQ GREAT_EQ EQUAL NOT_EQUAL AND OR IF WHILE BREAK CONTINUE
%token <str_val> IDENT
%token <int_val> INT_CONST
%type <ast_val> CompUnit GlobalDef Decl VarDecl VarDefList VarDef IntConstList InitVal FuncDef FuncFParams FuncFParamList FuncFParam Block BlockItemList BlockItem Stmt Exp LVal ExpList PrimaryExp Number UnaryExp UnaryOp FuncRParams ExpIter MulExp AddExp RelExp EqExp LAndExp LOrExp
%%

CompUnit : GlobalDef {
    auto comp_unit = unique_ptr<CompUnit>((CompUnit*) $1);
    ast = move(comp_unit);
};

GlobalDef : GlobalDef Decl {
    auto comp_unit = new CompUnit();
    auto comp_units_it = unique_ptr<CompUnit>((CompUnit*) $1);
    for(auto &it : comp_units_it->decls){
        comp_unit->decls.emplace_back(it.release());
    }
    for(auto &it : comp_units_it->funcdefs){
        comp_unit->funcdefs.emplace_back(it.release());
    }
    comp_unit->decls.emplace_back((Decl*) $2);
    $$ = comp_unit;
} | GlobalDef FuncDef {
    auto comp_unit = new CompUnit();
    auto comp_units_it = unique_ptr<CompUnit>((CompUnit*) $1);
    for(auto &it : comp_units_it->decls){
        comp_unit->decls.emplace_back(it.release());
    }
    for(auto &it : comp_units_it->funcdefs){
        comp_unit->funcdefs.emplace_back(it.release());
    }
    comp_unit->funcdefs.emplace_back((FuncDef*) $2);
    $$ = comp_unit;
} | Decl {
    auto comp_unit = new CompUnit();
    comp_unit->decls.emplace_back((Decl*) $1);
    $$ = comp_unit;
} | FuncDef {
    auto comp_unit = new CompUnit();
    comp_unit->funcdefs.emplace_back((FuncDef*) $1);
    $$ = comp_unit;
};

/* BType : INT {
    auto btype = new BType();
    btype->tag = BType::INT;
    $$ = btype;    
}; */

Decl : VarDecl {
    auto decl = new Decl();
    decl->vardecl = unique_ptr<VarDecl>((VarDecl*) $1);
    $$ = decl;
};

VarDecl : INT VarDef VarDefList ';' {
    auto var_decl = new VarDecl(); 
    auto var_def_list = unique_ptr<VarDecl>((VarDecl*) $3);
    var_decl->btype = (string)"int"; 
    var_decl->vardefs.emplace_back((VarDef*) $2);
    for(auto &it : var_def_list->vardefs){
        var_decl->vardefs.emplace_back(it.release());
    }
    $$ = var_decl;
};

VarDefList : ',' VarDef VarDefList {
    auto var_def_list = new VarDecl();
    auto var_def_list_it = unique_ptr<VarDecl>((VarDecl*) $3);
    var_def_list->vardefs.emplace_back((VarDef*) $2);
    for(auto &it : var_def_list_it->vardefs){
        var_def_list->vardefs.emplace_back(it.release());
    }
    $$ = var_def_list;
} | %empty {
    auto var_def_list = new VarDecl();
    $$ = var_def_list;
};

VarDef : IDENT '=' InitVal {
    auto var_def = new VarDef();
    var_def->tag = VarDef::VARIABLE;
    var_def->ident = *unique_ptr<string>($1);
    var_def->initval = unique_ptr<InitVal>((InitVal*) $3);
    $$ = var_def;
} | IDENT {
    auto var_def = new VarDef();
    var_def->tag = VarDef::VARIABLE;
    var_def->ident = *unique_ptr<string>($1);
    $$ = var_def;
} | IDENT '[' INT_CONST ']' IntConstList {
    auto var_def = new VarDef();
    auto temp_list = new IntConstList();
    auto int_const_list = unique_ptr<IntConstList>((IntConstList*) $5);
    temp_list->list.emplace_back((int) $3);
    for(int i = 0; i < int_const_list->list.size(); ++i){
        temp_list->list.emplace_back(int_const_list->list[i]);
    }
    var_def->tag = VarDef::ARRAY;
    var_def->ident = *unique_ptr<string>($1);
    var_def->int_consts = unique_ptr<IntConstList>((IntConstList*) temp_list);
    $$ = var_def;
}; 

// {'[' INT_CONST ']'}
IntConstList : '[' INT_CONST ']' IntConstList {
    auto int_const_list = new IntConstList();
    auto int_const_list_it = unique_ptr<IntConstList>((IntConstList*) $4);
    int_const_list->list.emplace_back((int) $2);
    for(int i = 0; i < int_const_list_it->list.size(); ++i){
        int_const_list->list.emplace_back(int_const_list_it->list[i]);
    }
    $$ = int_const_list;
} | %empty {
    auto int_const_list = new IntConstList();
    $$ = int_const_list;
};

InitVal : Exp {
    auto init_val = new InitVal();
    init_val->exp = unique_ptr<Exp>((Exp*) $1);
    $$ = init_val;
};

FuncDef : INT IDENT '(' ')' Block {
    auto func_def = new FuncDef();
    func_def->functype = (string)"int";
    func_def->ident = *unique_ptr<string>($2);
    func_def->block = unique_ptr<Block>((Block*) $5);
    $$ = func_def;
} | VOID IDENT '(' ')' Block {
    auto func_def = new FuncDef();
    func_def->functype = (string)"void";
    func_def->ident = *unique_ptr<string>($2);
    func_def->block = unique_ptr<Block>((Block*) $5);
    $$ = func_def;
} | INT IDENT '(' FuncFParams ')' Block {
    auto func_def = new FuncDef();
    func_def->functype = (string)"int";
    func_def->ident = *unique_ptr<string>($2);
    func_def->funcfparams = unique_ptr<FuncFParams>((FuncFParams*) $4);
    func_def->block = unique_ptr<Block>((Block*) $6);
    $$ = func_def;
} | VOID IDENT '(' FuncFParams ')' Block {
    auto func_def = new FuncDef();
    func_def->functype = (string)"void";
    func_def->ident = *unique_ptr<string>($2);
    func_def->funcfparams = unique_ptr<FuncFParams>((FuncFParams*) $4);
    func_def->block = unique_ptr<Block>((Block*) $6);
    $$ = func_def;
};

/* FuncType : VOID {
    auto func_type = new FuncType();
    func_type->tag = FuncType::VOID;
    $$ = func_type;
} | INT {
    auto func_type = new FuncType();
    func_type->tag = FuncType::INT;
    $$ = func_type;    
}; */

FuncFParams : FuncFParam FuncFParamList {
    auto func_f_params = new FuncFParams();
    auto func_f_param_list = unique_ptr<FuncFParams>((FuncFParams*) $2);
    func_f_params->funcfparams.emplace_back((FuncFParam*) $1);
    for(auto &it : func_f_param_list->funcfparams){
        func_f_params->funcfparams.emplace_back(it.release());
    }
    $$ = func_f_params;
};

FuncFParamList : ',' FuncFParam FuncFParamList {
    auto func_f_param_list = new FuncFParams();
    auto func_f_param_list_it = unique_ptr<FuncFParams>((FuncFParams*) $3);
    func_f_param_list->funcfparams.emplace_back((FuncFParam*) $2);
    for(auto &it : func_f_param_list_it->funcfparams){
        func_f_param_list->funcfparams.emplace_back(it.release());
    }
    $$ = func_f_param_list;
} | %empty {
    auto func_f_param_list = new FuncFParams();
    $$ = func_f_param_list;
};

FuncFParam : INT IDENT {
    auto func_f_param = new FuncFParam();
    func_f_param->tag = FuncFParam::VARIABLE;
    func_f_param->btype = (string)"int";
    func_f_param->ident = *unique_ptr<string>($2);
    $$ = func_f_param;
} | INT IDENT '[' ']' IntConstList {
    auto func_f_param = new FuncFParam();
    func_f_param->tag = FuncFParam::ARRAY;
    func_f_param->btype = (string)"int";
    func_f_param->ident = *unique_ptr<string>($2);
    func_f_param->int_consts = unique_ptr<IntConstList>((IntConstList*) $5);
    $$ = func_f_param;    
};

Block : '{' BlockItemList '}' {
    auto block = new Block();
    auto block_item_list = unique_ptr<Block>((Block*) $2);
    for(auto &it : block_item_list->blockitems){
        block->blockitems.emplace_back(it.release());
    }    
    $$ = block;
};

BlockItemList : BlockItem BlockItemList {
    auto block_item_list = new Block();
    auto block_item_list_it = unique_ptr<Block>((Block*) $2);
    block_item_list->blockitems.emplace_back((BlockItem*) $1);
    for(auto &it : block_item_list_it->blockitems){
        block_item_list->blockitems.emplace_back(it.release());
    }
    $$ = block_item_list;
} | %empty {
    auto block_item_list = new Block();
    $$ = block_item_list;
};

BlockItem : Decl {
    auto block_item = new BlockItem();
    block_item->tag = BlockItem::DECL;
    block_item->decl = unique_ptr<Decl>((Decl*) $1);
    $$ = block_item; 
} | Stmt {
    auto block_item = new BlockItem();
    block_item->tag = BlockItem::STMT;
    block_item->stmt = unique_ptr<Stmt>((Stmt*) $1);
    $$ = block_item; 
};

Stmt : LVal '=' Exp ';'{
    auto stmt = new Stmt();
    stmt->tag = Stmt::ASSIGN;
    stmt->lval = unique_ptr<LVal>((LVal*) $1);
    stmt->exp = unique_ptr<Exp>((Exp*) $3);
    $$ = stmt;
} | Exp ';' {
    auto stmt = new Stmt();
    stmt->tag = Stmt::EXP;
    stmt->exp = unique_ptr<Exp>((Exp*) $1);
    $$ = stmt;
} | Block {
    auto stmt = new Stmt();
    stmt->tag = Stmt::BLOCK;
    stmt->block = unique_ptr<Block>((Block*) $1);
    $$ = stmt;
} | IF '(' Exp ')' Stmt %prec LOWER_THAN_ELSE {
    auto stmt = new Stmt();
    stmt->tag = Stmt::IF;
    stmt->exp = unique_ptr<Exp>((Exp*) $3);
    stmt->if_stmt = unique_ptr<Stmt>((Stmt*) $5);
    $$ = stmt;
} | IF '(' Exp ')' Stmt ELSE Stmt {
    auto stmt = new Stmt();
    stmt->tag = Stmt::IF;
    stmt->exp = unique_ptr<Exp>((Exp*) $3);
    stmt->if_stmt = unique_ptr<Stmt>((Stmt*) $5);
    stmt->else_stmt = unique_ptr<Stmt>((Stmt*) $7);    
    $$ = stmt;    
} | WHILE '(' Exp ')' Stmt {
    auto stmt = new Stmt();
    stmt->tag = Stmt::WHILE;
    stmt->exp = unique_ptr<Exp>((Exp*) $3);
    stmt->while_stmt = unique_ptr<Stmt>((Stmt*) $5);
    $$ = stmt;
} | BREAK ';' {
    auto stmt = new Stmt();
    stmt->tag = Stmt::BREAK;
    $$ = stmt;
} | CONTINUE ';' {
    auto stmt = new Stmt();
    stmt->tag = Stmt::CONTINUE;
    $$ = stmt;
} | RETURN ';' {
    auto stmt = new Stmt();
    stmt->tag = Stmt::RETURN;
    $$ = stmt;
} | RETURN Exp ';' {
    auto stmt = new Stmt();
    stmt->tag = Stmt::RETURN;
    stmt->exp = unique_ptr<Exp>((Exp*) $2);
    $$ = stmt;
};

Exp : LOrExp {
    auto exp = new Exp();
    exp->lorexp = unique_ptr<LOrExp>((LOrExp*) $1);
    $$ = exp;
};

LVal : IDENT {
    auto lval = new LVal();
    lval->tag = LVal::VARIABLE;
    lval->ident = *unique_ptr<string>($1);
    $$ = lval;
} | IDENT '[' Exp ']' ExpList {
    auto lval = new LVal();
    auto exp_list = unique_ptr<LVal>((LVal*) $5);
    lval->tag = LVal::VARIABLE;
    lval->ident = *unique_ptr<string>($1);
    lval->exps.emplace_back((Exp*) $3);
    for(auto &it : exp_list->exps){
        lval->exps.emplace_back(it.release());
    }
    $$ = lval;    
};

// {'[' Exp ']'}
ExpList : '[' Exp ']' ExpList {
    auto exp_list = new LVal();
    auto exp_list_it = unique_ptr<LVal>((LVal*) $4);
    exp_list->exps.emplace_back((Exp*) $2);
    for(auto &it: exp_list_it->exps){
        exp_list->exps.emplace_back(it.release());
    }
    $$ = exp_list;
} | %empty {
    auto exp_list = new LVal();
    $$ = exp_list;
};

PrimaryExp : '(' Exp ')'{
    auto primary_exp = new PrimaryExp();
    primary_exp->tag = PrimaryExp::EXP;
    primary_exp->exp = unique_ptr<Exp>((Exp*) $2);
    $$ = primary_exp;
} | LVal {
    auto primary_exp = new PrimaryExp();
    primary_exp->tag = PrimaryExp::LVAL;
    primary_exp->lval = unique_ptr<LVal>((LVal*) $1);
    $$ = primary_exp;
} | Number {
    auto primary_exp = new PrimaryExp();
    primary_exp->tag = PrimaryExp::NUMBER;
    primary_exp->number = unique_ptr<Number>((Number*) $1);
    $$ = primary_exp;
};

Number : INT_CONST {
    auto number = new Number();
    number->num = (int) $1;
    $$ = number;
};

UnaryExp : PrimaryExp {
    auto unary_exp = new UnaryExp();
    unary_exp->tag = UnaryExp::PRIMARY_EXP;
    unary_exp->primaryexp = unique_ptr<PrimaryExp>((PrimaryExp*) $1);
    $$ = unary_exp;
} | IDENT '(' ')' {
    auto unary_exp = new UnaryExp();
    unary_exp->tag = UnaryExp::FUNC;
    unary_exp->ident = *unique_ptr<string>($1);
    $$ = unary_exp;
} | IDENT '(' FuncRParams ')' {
    auto unary_exp = new UnaryExp();
    unary_exp->tag = UnaryExp::FUNC;
    unary_exp->ident = *unique_ptr<string>($1);
    unary_exp->funcrparams = unique_ptr<FuncRParams>((FuncRParams*) $3);
    $$ = unary_exp;
} | UnaryOp UnaryExp {
    auto unary_exp = new UnaryExp();
    unary_exp->tag = UnaryExp::OP_EXP;
    unary_exp->unaryop = unique_ptr<UnaryOp>((UnaryOp*) $1);
    unary_exp->unaryexp = unique_ptr<UnaryExp>((UnaryExp*) $2);
    $$ = unary_exp;
};

UnaryOp : '+' {
    auto unary_op = new UnaryOp();
    unary_op->unaryop = '+';
    $$ = unary_op;
} | '-' {
    auto unary_op = new UnaryOp();
    unary_op->unaryop = '-';
    $$ = unary_op;
} | '!' {
    auto unary_op = new UnaryOp();
    unary_op->unaryop = '!';
    $$ = unary_op;
};

FuncRParams : Exp ExpIter{
    auto func_r_params = new FuncRParams();
    auto exp_iter = unique_ptr<FuncRParams>((FuncRParams*) $2);
    func_r_params->exps.emplace_back((Exp*) $1);
    for(auto &it : exp_iter->exps){
        func_r_params->exps.emplace_back(it.release());
    }
    $$ = func_r_params;
};

// { ',' Exp }
ExpIter : ',' Exp ExpIter{
    auto exp_iter = new FuncRParams();
    auto exp_iter_it = unique_ptr<FuncRParams>((FuncRParams*) $3);
    exp_iter->exps.emplace_back((Exp*) $2);
    for(auto &it : exp_iter_it->exps){
        exp_iter->exps.emplace_back(it.release());
    }
    $$ = exp_iter;
} | %empty {
    auto exp_iter = new FuncRParams();
    $$ = exp_iter;
};

MulExp : UnaryExp {
    auto mul_exp = new MulExp();
    mul_exp->tag = MulExp::UNARY_EXP;
    mul_exp->unaryexp = unique_ptr<UnaryExp>((UnaryExp*) $1);
    $$ = mul_exp;
} | MulExp '*' UnaryExp {
    auto mul_exp = new MulExp();
    mul_exp->tag = MulExp::MUL_UNARY_EXP;
    mul_exp->unaryexp = unique_ptr<UnaryExp>((UnaryExp*) $3);
    mul_exp->mulexp = unique_ptr<MulExp>((MulExp*) $1);
    mul_exp->op = '*';
    $$ = mul_exp;
} | MulExp '/' UnaryExp {
    auto mul_exp = new MulExp();
    mul_exp->tag = MulExp::MUL_UNARY_EXP;
    mul_exp->unaryexp = unique_ptr<UnaryExp>((UnaryExp*) $3);
    mul_exp->mulexp = unique_ptr<MulExp>((MulExp*) $1);
    mul_exp->op = '/';
    $$ = mul_exp;
} | MulExp '%' UnaryExp {
    auto mul_exp = new MulExp();
    mul_exp->tag = MulExp::MUL_UNARY_EXP;
    mul_exp->unaryexp = unique_ptr<UnaryExp>((UnaryExp*) $3);
    mul_exp->mulexp = unique_ptr<MulExp>((MulExp*) $1);
    mul_exp->op = '%';
    $$ = mul_exp;
};

AddExp : MulExp {
    auto add_exp = new AddExp();
    add_exp->tag = AddExp::MULEXP;
    add_exp->mulexp = unique_ptr<MulExp>((MulExp*) $1);
    $$ = add_exp;
} | AddExp '+' MulExp {
    auto add_exp = new AddExp();
    add_exp->tag = AddExp::ADD_MUL_EXP;
    add_exp->mulexp = unique_ptr<MulExp>((MulExp*) $3);
    add_exp->addexp = unique_ptr<AddExp>((AddExp*) $1);
    add_exp->op = '+';
    $$ = add_exp;
} | AddExp '-' MulExp {
    auto add_exp = new AddExp();
    add_exp->tag = AddExp::ADD_MUL_EXP;
    add_exp->mulexp = unique_ptr<MulExp>((MulExp*) $3);
    add_exp->addexp = unique_ptr<AddExp>((AddExp*) $1);
    add_exp->op = '-';
    $$ = add_exp;
};

RelExp : AddExp {
    auto rel_exp = new RelExp();
    rel_exp->tag = RelExp::ADDEXP;
    rel_exp->addexp = unique_ptr<AddExp>((AddExp*) $1);
    $$ = rel_exp;
} | RelExp '<' AddExp {
    auto rel_exp = new RelExp();
    rel_exp->tag = RelExp::REL_ADD_EXP;
    rel_exp->addexp = unique_ptr<AddExp>((AddExp*) $3);
    rel_exp->relexp = unique_ptr<RelExp>((RelExp*) $1);
    rel_exp->op[0] = '<';
    rel_exp->op[1] = 0;
    $$ = rel_exp;
} | RelExp '>' AddExp {
    auto rel_exp = new RelExp();
    rel_exp->tag = RelExp::REL_ADD_EXP;
    rel_exp->addexp = unique_ptr<AddExp>((AddExp*) $3);
    rel_exp->relexp = unique_ptr<RelExp>((RelExp*) $1);
    rel_exp->op[0] = '>';
    rel_exp->op[1] = 0;
    $$ = rel_exp;
} | RelExp LESS_EQ AddExp {
    auto rel_exp = new RelExp();
    rel_exp->tag = RelExp::REL_ADD_EXP;
    rel_exp->addexp = unique_ptr<AddExp>((AddExp*) $3);
    rel_exp->relexp = unique_ptr<RelExp>((RelExp*) $1);
    rel_exp->op[0] = '<';
    rel_exp->op[1] = '=';
    $$ = rel_exp;
} | RelExp GREAT_EQ AddExp {
    auto rel_exp = new RelExp();
    rel_exp->tag = RelExp::REL_ADD_EXP;
    rel_exp->addexp = unique_ptr<AddExp>((AddExp*) $3);
    rel_exp->relexp = unique_ptr<RelExp>((RelExp*) $1);
    rel_exp->op[0] = '>';
    rel_exp->op[1] = '=';
    $$ = rel_exp;
};

EqExp : RelExp {
    auto eq_exp = new EqExp();
    eq_exp->tag = EqExp::RELEXP;
    eq_exp->relexp = unique_ptr<RelExp>((RelExp*) $1);
    $$ = eq_exp;
} | EqExp EQUAL RelExp{
    auto eq_exp = new EqExp();
    eq_exp->tag = EqExp::EQ_REL_EXP;
    eq_exp->relexp = unique_ptr<RelExp>((RelExp*) $3);
    eq_exp->eqexp = unique_ptr<EqExp>((EqExp*) $1);
    eq_exp->op[0] = '=';
    eq_exp->op[1] = '=';
    $$ = eq_exp;
} | EqExp NOT_EQUAL RelExp{
    auto eq_exp = new EqExp();
    eq_exp->tag = EqExp::EQ_REL_EXP;
    eq_exp->relexp = unique_ptr<RelExp>((RelExp*) $3);
    eq_exp->eqexp = unique_ptr<EqExp>((EqExp*) $1);
    eq_exp->op[0] = '!';
    eq_exp->op[1] = '=';
    $$ = eq_exp;
};

LAndExp : EqExp {
    auto l_and_exp = new LAndExp();
    l_and_exp->tag = LAndExp::EQEXP;
    l_and_exp->eqexp = unique_ptr<EqExp>((EqExp*) $1);
    $$ = l_and_exp;
} | LAndExp AND EqExp {
    auto l_and_exp = new LAndExp();
    l_and_exp->tag = LAndExp::LAND_EQ_EXP;
    l_and_exp->eqexp = unique_ptr<EqExp>((EqExp*) $3);
    l_and_exp->landexp = unique_ptr<LAndExp>((LAndExp*) $1);
    $$ = l_and_exp;
};

LOrExp : LAndExp {
    auto l_or_exp = new LOrExp();
    l_or_exp->tag = LOrExp::LANDEXP;
    l_or_exp->landexp = unique_ptr<LAndExp>((LAndExp*) $1);
    $$ = l_or_exp;
} | LOrExp OR LAndExp {
    auto l_or_exp = new LOrExp();
    l_or_exp->tag = LOrExp::LOR_LAND_EXP;
    l_or_exp->landexp = unique_ptr<LAndExp>((LAndExp*) $3);
    l_or_exp->lorexp = unique_ptr<LOrExp>((LOrExp*) $1);
    $$ = l_or_exp;
};

%%

void yyerror(unique_ptr<AST> &ast, const char *s) {
    cerr << "error: " << s << endl;
}


