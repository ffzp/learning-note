# 台大matlab第二章---结构化程式与自定义函数
## 结构化编程
1、一些运算语句：if、elseif、switch、case、while、for、break、return   ==逻辑大致与cpp相同==

2、逻辑运算符：==、&&、||、~=等

3、分隔符（用于分块执行程序）
![3UWO484FV_D4BC5RN8SQAXW.png](https://s2.loli.net/2022/03/19/NQPyrqZYCidumTs.png)

4、实际演示：
```matlab
a=3;
if rem(a,2)==0 
      disp('a is even')
else
      disp('a is odd')
end
```
```matlab
input_num=1;
switch input_num
case -1
     disp('negative 1');
case 0
     disp('zero');
case 1
     disp('positive 1');
otherwise
     disp('other value');
end
```
```matlab
n=1;
while prod(1；n)<1e100
     n=n+1;
end
```
5、小tips
- ==close all== to close all figures
- ==clear all== to remove previous variables
```matlab 
A=[1 2 3 4 5 6;……
   6 5 4 3 2 1];
``` 
表示不使用换行，接着下一行写。
## 自定义函数
1、基本定义（以自己编的UR5正解函数为例）
![3CKB_V7VM6TC`3_NKHZN_58.png](https://s2.loli.net/2022/03/19/VT7Qx1zpZRa3Dlh.png)
2、matlab内置函数参数
|函数参数| 意义 |
|--|--|
| inputname | 输入变量名列表 |
| mfilename | 函数源代码文件名 |
| nargin | 输入变量数 |
| nargout | 输出变量个数 |
| varargin | 可变长输入参数列表 |
| varargout | 可变长输出参数列表 |
