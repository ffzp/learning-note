# 台大机器人学第二章
## 2.1 Fixed angles--由angles推算R
$${}_B^A\!R_{xyz}(γ，β，α)={}\!R_z(α){}\!R_y(β){}\!R_x(γ)
=\left[
\begin{matrix}
cαcβ & cαsβsγ-sαcγ & cαsβcγ+sαsγ\\
sαcβ & sαsβsγ+cαcγ & sαsβcγ-cαsγ\\
-sβ & cβsγ & cβcγ
\end{matrix}
\right]$$
"以operator来想，对某一个向量，以同一个坐标为基准，进行转动或移动的操作“

<mark>转动的顺序不能更换，先后顺序会导致末端位姿不同<mark>
$${}_B^A\!R_{xyz}(γ，β，α)=\left[
\begin{matrix}
cαcβ & cαsβsγ-sαcγ & cαsβcγ+sαsγ\\
sαcβ & sαsβsγ+cαcγ & sαsβcγ-cαsγ\\
-sβ & cβsγ & cβcγ
\end{matrix}
\right]
=
\left[
\begin{matrix}
r11 & r12 & r13\\
r21 & r22 & r23\\
r31 & r32 & r33
\end{matrix}
\right]$$
- 结论：

if β≠90°

β=Atan2(-r31,$\sqrt{(r11)^2+(r21)^2}$)

α=Atan2(r21/cβ,r11/cβ)

γ=Atan2(r32/cβ,r33/cβ)

if β=90°,则α=0°，γ=Atan2(r12，r22)

if β=-90°,则α=0°，γ=-Atan2(r12，r22)

<mark>Atan2:matlab中的函数<mark>
- 则对于任意旋转矩阵，可以解出其方位角
## 2.2 Euler angles
${}_B^A\!R_{z'y'x'}$(α,β,γ)=${}\!R_z'$(α)${}\!R_y'$(β)${}\!R_x'$(γ)
- 将先转的放在前面：对某一个向量，从最后一个frame逐渐转动或移动来回到第一个frame，即
${}^A\!p$=${}_B^A\!R$ ${}^B\!p$=$R_1$ $R_2$ $R_3$ ${}^B\!p$
- 可以和fixed angle得到一样的R，末端姿态相同
- 由R推算angles：
![M81_B5R6T`B_II2_CAE33_9.png](https://s2.loli.net/2022/03/26/VpYigHn7r92c1oy.png)

- 小结：12种euler angles和12种fixed angles
- 存在duality-共12种对principal axes连三次转动的拆解方式
## 2.3 刚体状态的表达
如何将移动和转动整合在一起描述？
$$\left[
\begin{matrix}
 & {}_B^A\!R &  & {}^A\!R_{B org}\\
0& 0 &0 & 1
\end{matrix}
\right]={}_B^A\!T$$
描述其正确性：
- 仅有移动和仅有转动之情况下均成立
- 移动和转动复合
![F4_A9HOL`NRK5Z_P2_KQ4YE.png](https://s2.loli.net/2022/03/26/nDOm8vWHcUuM5VI.png)

也可以对向量进行移动和转动
![WCD75AXOTDD_PS_R0_@_8H3.png](https://s2.loli.net/2022/03/26/7hKIzuScxUJXCY8.png)

想法：由于运动是相对的，当operator时对向量(或点)进行移动或转动的操作，也可以想象成是对frame进行反向的移动或转动的操作

Homogeneous transformation matrix的三种用法：
- 描述一个frame相对于另一个frame的x空间状态
- 将point由某一个frame的表达换到另一个frame来表达
- 将point在同一个frame中进行移动和转动
## 2.4 Trans matrix
- 连续运算：
$${}^A\!p ={}_B^A\!T {}^B\!p={}_B^A\!T ({}_C^B\!T {}^C\!p)={}_B^A\!T {}_C^B\!T {}^C\!p$$
- 连续运算法则：
![GJA1OK`W47VMZ_B1JUQAF_R.png](https://s2.loli.net/2022/03/26/DpW6aBJnm7CNOGu.png)
