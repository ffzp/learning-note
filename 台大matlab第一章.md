# 台大matlab第一章---matlab的基本语法
## 变量
1、具有特殊意义的变量：
- ans（上一句运算的结果）
- i，j（complex number）
- inf（无穷）
- eps（浮点相对精度）
- nan（非数字）

==对于这类变量，不适合声明为变量名==

2、变量名：
- 变量名不能以数字开头
- 变量名对大小写敏感
- 变量名不应覆盖函数名，matlab变量调用优先级高于函数

3、变量类型：
- MATLAB中的变量类型有: logical、char、numeric、cell、struct以及由它们组成的数组或矩阵.

![](https://img-blog.csdnimg.cn/20191112184307618.png)
4、数字变量的显示格式：
- 使用format<显示格式>来体现各种显示格式以提高精度或实现各种数据表示方法。
short：显示小数点后4位
long：显示小数点后15位
hex：16进制格式
## 基本操作窗口
- command window
   ==实用操作==：（clc：清除终端输出、clear：清除当前工作区所有变量、help：检索词条）
- workspace
- command history
- currentfolder
## 基本运算
1、常见运算符：+、-、*、/、^
2、一些数学表达式求值：
```matlab
cos(sqrt((1+2+3+4)^3/5))
sin(sqrt(pi))+log(tan(1))
exp(sin(10))
```
## 矩阵运算
1、创建矩阵：
- row vector：a=[1 2 3 4]      column vector: b=[1、2、3、4];
==分号作为矩阵的换行符==
- 使用冒号符创建向量：
==j:i:k=[j , j+i , j+2i , …… j+m*i]==
- 特殊矩阵的调用：
eye（n):nxn单位矩阵
zeros（n1，n2）：n1xn2全零矩阵
ones（n1，n2） ：n1xn2全1矩阵