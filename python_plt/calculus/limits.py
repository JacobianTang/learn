# -*- coding: utf-8 -*-
def cal_function_value(x):
    y=np.log(1+np.exp(x/2))
    return y

import matplotlib.pyplot as plt  #导入matplotlib库
import numpy as np  #导入numpy库
import mpl_toolkits.axisartist as axisartist
from sympy.plotting import *
from sympy import plot_implicit,Eq,And,Or
from sympy import symbols
from sympy import diff
from sympy.functions import log,sin,exp,sqrt,ln
import math as mt

x1=symbols("x1")
f=log(1+ exp(x1/2))
dif_x1 = diff(f,x1).evalf(subs={"x1":-5.0})
line_kx = dif_x1*(x1 -(-5.0) ) + cal_function_value(-5.0)
print(dif_x1)

#创建画布
fig = plt.figure()
#使用axisartist.Subplot方法创建一个绘图区对象ax
ax = axisartist.Subplot(fig, 111)
# #将绘图区对象添加到画布中
fig.add_axes(ax)
ax.axis[:].set_visible(False)

ax.axis["x"] = ax.new_floating_axis(0,0)
ax.axis["x"].set_axisline_style("-|>", size = 1.0)
###添加y坐标轴，且加上箭头
ax.axis["y"] = ax.new_floating_axis(1,0)
ax.axis["y"].set_axisline_style("-|>", size = 1.0)


#生成x步长为0.1的列表数据
x = np.arange(-10,10,0.1)
#生成sigmiod形式的y数据
#y=1/(1+np.exp(-x))
#y=np.exp(x)
# y=np.log(1+np.exp(x/2))
y=x-1
#设置x、y坐标轴的范围
plt.xlim(-6, 6)
plt.ylim(-6, 6)
#绘制图形
x_left=np.arange(-10,2,0.1)
x_right=np.arange(2,10,0.1)
# plt.plot(x_left,x_left-1, c='k')
# plt.plot(x_right,x_right-1, c='k')

plt.plot(x_left,[f.evalf(subs={"x1":x}) for x in x_left], c='k')
plt.plot(x_right,[3 + f.evalf(subs={"x1":x}) for x in x_right], c='k')

# circ1 = plt.Circle((1.95,1.95-1.0),0.08,color='k',alpha=0.3)
# ax.add_patch(circ1)

# plt.xlabel('x')
# plt.ylabel('y')

plt.text(5,5, r'$y=f(x)$', fontsize=10)

# plt.xticks([])
# plt.yticks([])

plt.show()