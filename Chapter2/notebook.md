# 2. C语言概述

1. c程序包含：预处理器指令、main函数，其他函数。函数是c程序的构造块，由语句组成。
2. 语句包含6种：标号语句、复合语句、表达式语句、选择语句、迭代语句和跳转语句。
3. 语句由关键字、标识符、运算符和数据组成。
4. main函数返回的值是整数，返回给了操作系统，这将在第6章中讨论
5. C程序包含一个或多个函数，函数是C程序的基本模块。

## 2.1 注释

1. 原始注释风格使用/**/进行注释，在C99中新增了普遍用于C++和Java的双斜杠注释。

## 2.2 声明

1. 老的c语言可能将变量的声明全部放在块的顶部，C99和C11遵循C++的惯例，可以将声明放在块的任何位置

## 2.3 命名

1. C99和C11根据通用字符名（UCN）机制添加了扩展字符集，其中包括除英文字母外的部分字符。

## 2.4 赋值

1. C语言是通过**赋值运算符**而不是赋值语句完成赋值操作。根据C标准，C语言没有所谓的“赋值语句”。

## 2.5 语句

1. 很多书籍将类似printf()**语句**叫做“函数调用语句”，但是历年的C标准中从来没有“函数调用语句”说法。
2. 函数调用本身是一个表达式，圆括号是运算符，圆括号左边的函数名是运算对象。在C11标准中，这样的表达式是一种后缀表达式。

## 2.6 函数的位置

1. 函数原型（prototype）：俗称的“函数声明”

## 2.7 关键字和保留标识符

1. 初始关键词：auto, extern, short, while, break, float, case, for, sizeof, char, goto, static, if, struct, continue, switch, default, int, typedef, do, long, union, double, register, unsigned, else, restrict, void, return

2. C90新增关键词：signed, const, enum, volatile

3. C99新增关键词：inline

4. C11新增关键词：_Alignas,_Alignof, _Atomic,_Bool,_Complex,_Generic, _Imaginary,_Noreturn,_Static_assert,_Thread_local
