# 浙江大学2024编译原理实验

## 项目结构
```
.
├── include
│   └── AST.h
├── src
│   ├── AST.cpp
│   ├── main.cpp
│   ├── parser.y
│   └── lexer.l
├── tests
│   └── ...
├── CMakeLists.txt
└── README.md
```

## 项目依赖
- C 和 C++编译器
- CMake
- Flex
- Bison
  
## 项目构建

第一次构建项目时，需要执行以下命令：
```bash
mkdir build && cd build && cmake .. && make
```

执行测试时，在tests目录下执行以下命令：
```bash
Python3 test.py ../build/compiler lab<lab_num>
```

//TODO : 优化测试脚本,整合到CMakeLists.txt中

## lab1：词法分析 & 语法分析

### 词法分析
根据简化的SysY语法，完成了词法分析器的设计，能够识别出以下几种类型的单词：
- 关键字：int、void、if、else、while、for、break、continue、return
- 运算符：+、-、*、/、%、<、<=、>、>=、==、!=、=、;、,、(、)、[、]、{、}、 && 、||、!、.、\\、'、"
- 标识符：以字母开头，由字母、数字、下划线组成
- 常数：整数
- 注释：//单行注释、/*多行注释*/
- 错误：非法字符

### 语法分析
//TODO
根据简化的SysY语法，完成了语法分析器的设计，能够识别出以下几种类型的语法结构：
- 基本类型：int、void
- 基本类型声明：int a;
- 数组类型声明：int a[10];
- 函数声明：int main() {}
- 语句块：{}
- 语句：if、while、for、break、continue、return
- 表达式：+、-、*、/、%、<、<=、>、>=、==、!=、=、&&、||、!、.、\\、'、"
- 错误：语法错误
- 注释：//单行注释、/*多行注释*/
- 优先级：括号

## lab2：语义分析

//TODO

## lab3：中间代码生成

//TODO



