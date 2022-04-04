# 机器人学第七章：基于matlab机器人工具箱的机械臂运动学
## DH表示法在matlab中的实现
- $σ_j$ 表示关节类型，σ=0为转动副，σ=1为移动副。由于对于转动关节$\theta$是关节变量且d是常量，然而对于移动关节d是变量，$\theta$是常量，且$\alpha$=0.所以一般用$q_j$表示$\theta$和d，σ来表示转动或移动关节
- 示例代码：
```matlab
L=Link([0,0.1,0.2,pi/2,0])
L=
  theta=q,d=0.1,a=0.2,alpha=pi/2 (R,stdDH)
```
输入向量的元素顺序分别是$\theta_j$,$d_j$, $a_j$, $\alpha_j$第五个元素σ表示该关节是转动或移动。标签R表示其是转动关节，stdDH表示标准的D-H参数表达
## 正运动学
正运动学表示末端执行器的位姿是基于关节坐标的一个函数
### 两连杆机器人
```matlab
L(1)=Link([0 0 1 0]);
L(2)=Link([0 0 1 0]);
two_link=SerialLink(L,'name','two link');
```
![_5F___YGB5_NW__1@DO_C_B.png](https://s2.loli.net/2022/03/29/3gOfHrZRSWKMFtA.png)
输入指令：
```matlab
>>mdl_planar2
```
机器人工具箱会将该机器人定义在matlab的工作空间，并创建名为twolink的SerialLink对象
- 复制一个SerialLink对象，并命名为bob
```matlab
>>clone=SerialLink(two_link,'name','bob')
clone=
```
![_G2_M__EN_WNRH3_DNX_F38.png](https://s2.loli.net/2022/03/29/1TSaIdCXibKsrLB.png)
- 使用正运动学函数计算（fkine）
```matlab
>>twolink.fkine([0,0])
```
![FT__H4ER4F`67_VFRTDELT5.png](https://s2.loli.net/2022/03/29/haUQIsb42plDZfA.png)

该方法即返回代表机器人第二个连杆坐标系位姿的齐次变换矩阵T
- 用以下指令可以画出机器人的图形：
```
twolink.plot([0,0])
```
![1ZM_I_S_XQJ2DVX~SDZ_AAK.png](https://s2.loli.net/2022/03/29/ApM4UfRosw81XKC.png)
### 六轴机器人

以puma_560机械臂为例
```matlab
>>mdl_puma560
```
即创建一个名为p560的SerialLink对象：
- 指令mdl_puma560还在工作区中创建了大量关节坐标，代表了一些简单的机器人位型：

qz （0，0，0，0，0，0） 零角度

qr （0，pi/2，-pi/2，0，0，0） 就绪状态，机械臂伸直且垂直

qs （0，0，-pi/2，0，0，0） 伸展状态，机械臂伸直且水平

qn （0，pi/4，-pi，0，pi/4，0） 标准状态，机械臂处于一个灵巧工作姿态

- 通过plot方法绘制：
```
>>p560.plot(qz)
```
- 正向运动学计算如下：
```
>>p560.fkine(qz)
```
返回值是末端执行器位姿的齐次变换矩阵$T_6$
- 变换工具顶端的位姿
```
>>p_560.tool = transl(0,0,0.2)
```
- 变化机器人的原点
```
>>p_560.base = transl(0 ,0 , 30);
```
- 将机器人坐标系绕着x轴旋转：
```
p560.base = trotx(pi);
```
- 关节角按时间序列或按轨迹线的显示方式
```
>>q
```
## 逆运动学
知道一个物体的位姿，求解其关节坐标
- 六轴机器人有封闭解的必要条件：三个腕关节交于一个点
### 封闭形式解
- 使用逆解函数：
```matlab
mdl_puma560
T=p560.fkine(qn) %标准状态机器人末端姿态
qi=p560.ikine6s(T) %求解所需关节坐标
```
而qi与初始标准姿态并不一样，使用正解函数：
```
p560.fkine(qi)
```
得到结果和T一样,可以得出：<mark>逆解并不唯一

这两组解中，一组对应在机械臂腰部的左侧，一组对应在右侧，故被称为左、右运动学位型

可以人为指定获取右手位形解：
```
qi=p560.inine6s(T,'ru')
```
<mark>不仅是左右侧的解，还有解对应于肘关节在上或在下，以及手腕是否翻转。

有以下字符标志控制：

| 位置 | 符号 |
| -- | -- |
| 左手或右手 | 'l','r' |
| 肘部在上或在下 | 'u','d' |
| 手腕翻转或不翻转 | 'f','n' |

### 数值解
- 利用逆解函数ikine

缺点：并不能像解析法提供对手臂位形的明显控制，需要通过设置关节坐标初始值才能控制

优点：求解处于奇异位形以及非6关节形的机械臂

### 欠驱动机械臂
关节数小于6（如twolinks）
### 冗余机械臂
关节数多于6。由于关节限制和奇异位形的存在，六轴机器人不能实现空间中所有的位姿
```matlab
paltform=SerialLink([0 0 0 -pi/2 1; -pi/2 0 0 pi/2 1],...
                   'base','troty(pi/2),'name','platform');%创建平台对象
p8=platform*p560 %关联平台和puma_560
p8=SerialLink([paltform,p560]); %或者通过这种方式关联
p560.links(1).d=30*0.0254; %设置基座高度
p8=SerialLink([platform,p560],'name','p8'); %实现关联
```
- 可操控性：这个机器人有8个自由度，对于每一个笛卡尔自由度都有布置一个关节可以使之产生运动，也就是可操控性，程序如下：
```matlab
p560.maniplty(qn);
p8.maniplty([0 0 qn]);
```
## 轨迹
考虑机器人末端执行器平滑地从位姿A移动至位姿B，使用关节空间运动和笛卡尔空间运动
### 关节空间运动
```matlab
T1=transl(0.4,0.2,0)*trotx(pi);
T2=transl(0.4,-0.2,0)*trotx(pi/2); %初始和最终位姿
q1=p560.ikine6s(T1);
q2=p560.ikine6s(T2); %初始和最终关节向量
t=[0:0.05:2]';%在两个位形之间平滑插值
q=jtraj(q1,q2,t)；%得到关节空间轨迹
%对于SerialLink类，可以使用如下简便方法：
q=p560.jtraj(T1,T2,t);
p560.plot(q);%绘制动画进行观察
qplot(t,q);%所有随时间变化的关节角
```
![RRR_L2_P9_7_D__J696_R~H.png](https://s2.loli.net/2022/04/04/QFJd5kYPchH8vlu.png)
- 想要研究末端执行器的轨迹：
```
T=p560.fkine(q);
p=transl(T);
plot(p(:,1),p(:,2));
```
得到的轨迹并不是一条直线
### 笛卡尔运动
```
Ts=ctraj(T1,T2,length(t));
p=transl(Ts);
plot(p(:,1),p(:,2))
```
得到轨迹是一条直线
  
![0_RA0_B3FXLQX__9T87_LX5.png](https://s2.loli.net/2022/04/04/TY1OJjVHZgXfvGe.png)
  
win！
## 高级问题
