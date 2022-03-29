# 机器人学第一章
## 1.1移动与转动
1、移动：以向量$\vec p$来描述{B}的原点相对于{A}的状态
- world frame A+p=body frame B
- vector $\vec p$:
$$
\vec p=\left[
\begin{matrix}
px\\
py\\
pz
\end{matrix}
\right] \tag{1}
$$
- 向量用于表示空间关系的两个方式：a position in space or a vector

2、转动：描述{B}相对于{A}的姿态--Rotation Matrix
$$
{}_B^A\!R=\left[
\begin{matrix}
{}^A\!X_B & {}^A\!Y_B & {}^A\!Z_B
\end{matrix}
\right] \tag{2}
$$
${}^A\!X_B$ 等分别表示为xb、yb、zb轴的vector

利用方向余弦，有：
$$
{}_B^A\!R=\left[
\begin{matrix}
{}\!X_B*{}\!X_A & {}\!Y_B*{}\!X_A & {}\!Z_B*{}\!X_A\\
{}\!X_B*{}\!Y_A & {}\!Y_B*{}\!Y_A & {}\!Z_B*{}\!Y_A\\
{}\!X_B*{}\!Z_A & {}\!Y_B*{}\!Z_A & {}\!Z_B*{}\!Z_A
\end{matrix}
\right] \tag{3}
$$
## 2.2 旋转矩阵Rotation matrix
- 性质：描述坐标的姿态
$$   
{}_B^A\!R={}_A^B\!R^T
\tag{4}
$$
$$
{}_B^A\!R^T {}_B^A\!R=I_3
\tag{5}
$$
- 用于坐标的转换
$$   
{}^A\!P={}_B^A\!R {}^B\!P
\tag{6}
$$
- 描述物体的运动状态
$$   
{}\!R_{{}\!Z_A}(θ)=\left[
\begin{matrix}
cosθ & -sinθ & 0\\
sinθ & cosθ & 0\\
0 & 0 & 1
\end{matrix}
\right]\tag{7}
$$
${}\!R_{{}\!X_A}(θ)和{}\!R_{{}\!Y_A}(θ)$ 同理可得：
$$   
{}\!R_{{}\!X_A}(θ)=\left[
\begin{matrix}
1 & 0 & 0\\
0 & cosθ & -sinθ\\
0 & sinθ & cosθ
\end{matrix}
\right]\tag{8}
$$
$$   
{}\!R_{{}\!Y_A}(θ)=\left[
\begin{matrix}
cosθ & 0 & sinθ\\
0 & 1 & 0\\
-sinθ & 0 & cosθ
\end{matrix}
\right]\tag{9}
$$
