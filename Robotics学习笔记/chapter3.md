# 机器人学第三章
## 3.1 顺向运动学
运动学：讨论运动状态本身，未连结到产生运动的力
- 位置、速度、加速度、和时间之间的关系

动力学：讨论力/力矩如何产生运动
- Newton's law
- work & energy
- impuse & momentum

机械手臂
- 多个杆件相串联，具有复杂的几何外形
- 杆件间可相对移动或转动，由制动器驱动来达成

对应关系
- 需求：手臂末端点状态（位置、速度……）
- 达成方式：驱动各制动器
$$ {}^W\!P =f(theta1,theta2,theta3……,thetan)$$
## 3.2 手臂的几何描述
joint
- 每个revolute或prismatic的joint具有1DOF
- 每个joint对某特定axis进行rotation或translation

link
- 连接joints的杆件，为刚体
- 编号方式：link0（地杆）、link1、link2

对空间中2个任意方向的axes，两axes之间具有一线段和此2个axes都互相垂直

但如果要多杆串联，则另需要两个参数d、theta，来描述相邻线段a_i和a_{i-1}间的相对几何关系
![XG72B8__81E6Y9R0MIBKXY1.png](https://s2.loli.net/2022/03/26/9FaJev8iPGdKTcO.png)
## 3-3 DH描述法
在杆件上建立frames
- $z_i$：转动或移动axis的方向
- $x_i$：沿着$a_i$方向（if $a_i$ !=0)；和$z_i$、$z_{i+1}$两者垂直（if $a_i$=0)
- $y_i$：与$x_i$和$z_i$两者垂直，依据右手定则

DH表示法（Denavit-Hartenberg）
- $α_{i-1}$：以$x_{i-1}$方向看，$z_{i-1}$和$z_i$间的夹角
- $a_{i-1}$：沿着$x_{i-1}$方向看，$z_{i-1}$和$z_i$间的距离
- $theta_i$：以$z_i$方向看，$x_{i-1}$和$x_i$间的夹角
- $d_i$：沿着$z_i$方向，$x_{i-1}$和$x_i$间的距离

Link transformation
![@_1G_LAF`_FS_0R_O~2JR54.png](https://s2.loli.net/2022/03/26/GDqZRLzIbUWi4XO.png)

thus
$$ {}_{i}^{i-1}\!T=
\left[
\begin{matrix}
cθ_i&-sθ_i&0&a_{i-1}\\
sθ_i cα_{i-1}&cθ_i cα_{i-1}&-sα_{i-1}&-sα_{i-1}d_i\\
sθ_i sα_{i-1}&cθ_i sα_{i-1}&cα_{i-1}&cα_{i-1}d_i\\
0&0&0&1
\end{matrix}
\right]
$$
link trans example:(RPR、RRR、PRRR manipulator)
![CLX_LG2C_ZA_UXBD7P_A__D.png](https://s2.loli.net/2022/03/26/Tt8UVDZCRpN2bLg.png)

## 3.4 Actuator joint and cartesian spaces:
- 正运动学（forward kinematics）

由关节角推出位姿
- 逆运动学（inverse kinematics）

由末端位姿推出关节角（一般有多组解）

example：PUMA-560
![_`WKI`E3KUTI803JJ@N_COC.png](https://s2.loli.net/2022/03/26/fnl1Pba2sLOyMZI.png)

- DH参数：
![J`2O_ARS9KND`_0_TPEI2HT.png](https://s2.loli.net/2022/03/26/98GFQzxydt2obcS.png)
