#pragma once
#include <unordered_map>
#include <string>
#include <vector>
#include <queue>
#include <memory>
using namespace std;

//对外的接口是VariableStack类和FuncStack类

class MyType{
public:
    enum TYPE{
        INT,FUNC_VOID,FUNC_INT,ARRAY
    };
    TYPE type;//类型
    vector<int> dim;//数组每一维的维数
    MyType();//初始化INT类型
    MyType(vector<int>dim);//初始化ARRAY类型
    MyType(int type);//初始化函数（不含参数），TYPE==0表示VOID类型，TYPE==1表示INT类型
    ~MyType();
};

//符号表中的符号定义
class Symbol{
public:
    MyType type;
    string ident;//变量/函数名
    vector<MyType> params;//存储函数参数类型
    Symbol(MyType type, string ident);//构建变量或无参数的函数
    Symbol(MyType type, string ident,vector<MyType>params);//构建有参数的函数
    ~Symbol();

};

//存放变量的符号表
class VariableTable{
public:
    unordered_map<string,Symbol> table;//符号表
    VariableTable()=default;
    void insertINT(const string &ident);//插入一个INT类型的变量
    void insertARRAY(const string &ident, vector<int>a);//插入一个INT类型的数组,a记录了数组的各个维度
    Symbol lookup(const string &ident);//返回要查找的变量
    ~VariableTable();
};

//存放函数的符号表
class FuncTable{
public:
    unordered_map<string,Symbol> table;
    FuncTable()=default;
    void insertFUNC(const string& ident,int type );//无参数，ident表示函数名，type表示函数返回类型（0:VOID 1:INT）
    void insertFUNC_Param(const string& ident,int type , vector<MyType> params);//ident表示函数名，type表示函数返回类型（0:VOID 1:INT），params记录了各个参数的类型
    Symbol lookup(const string&ident);//返回要查找的函数
};

//存放变量的符号表的栈
class VariableStack{
private:
    deque<unique_ptr<VariableTable>> v_stack;
public:
    void BeginScope();//进入一个新的域
    void EndScope();//退出域
    void insertINT(const string& ident);//插入INT类型的变量
    void insertARRAY(const string& ident,vector<int>dim);//插入INT类型的数组，ident表示数组名，dim表示各个维度
    MyType getType(const string& ident);//查询变量的类型
    vector<int> getDim(const string& ident);//查询数组变量的维数
};

//存放函数符号表的栈
class FuncStack{
private:
    deque<unique_ptr<FuncTable>> f_stack;
public:
    void BeginScope();//进入一个新的域
    void EndScope();//退出域
    void insertFUNC(const string& ident,int type);//插入无参数的函数,type==0表示函数返回值VOID类型，type==1表示INT类型
    void insertFUNC_param(const string& ident,int type,vector<MyType>params);//插入有参数的函数
    MyType getType(const string& ident);//查询函数的返回类型
    vector<MyType> getParamsType(const string& ident);//查询参数的类型
};
