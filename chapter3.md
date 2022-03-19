# 台大matlab第三章---变量与档案存取
## 数据类型
1、数值类型:double、single、int、uint等
```matlab
n = 3;
class(n)	% 得到 double

n = int8(3);
class(n)	% 得到 int8
```
2、Character（char）
```matlab
s1 = 'h';
uint16(s1)	% 得到 104
```
- 字符串形式
```matlab
str1 = 'hello';
str2 = 'world';

str3 = [str1 str2];
size(str3)		% 得到 [1 10]

str4 = [str1; str2];
size(str4)		% 得到 [2 5]
```
3、structure（类似于cpp中的类）
![](https://img-blog.csdnimg.cn/20191114143804469.png)
```matlab
student.name = 'John Doe';
student.id = 'jdo2@sfu.ca';
student.number = 301073268;
student.grade = [100, 75, 73; ...
                 95, 91, 85.5; ...
                 100, 98, 72];
student

```
- 扩充或缩减结构体列表：
![](https://img-blog.csdnimg.cn/20191114143906392.png)
```matlab
student(2).name = 'Ann Lane';
student(2).id = 'aln4@sfu.ca';
student(2).number = 301078853;
student(2).grade = [95 100 90; 95 82 97; 100 85 100];
student

student(1) = []		% 删除student列表第一项

```
- 结构体的常用函数（struct、isstruct、structfun等）
