# -*- coding: utf-8 -*-
import matplotlib.pyplot as plt  #导入matplotlib库
import numpy as np  #导入numpy库
import mpl_toolkits.axisartist as axisartist
from sympy.plotting import *
from sympy import plot_implicit,Eq,And,Or
from sympy import symbols
from sympy import diff
from sympy.functions import log,sin,exp,sqrt,ln
import math as mt

#创建画布
fig = plt.figure()
#使用axisartist.Subplot方法创建一个绘图区对象ax
ax = axisartist.Subplot(fig, 111)
#将绘图区对象添加到画布中
fig.add_axes(ax)
#通过set_axisline_style方法设置绘图区的底部及左侧坐标轴样式
#"-|>"代表实心箭头："->"代表空心箭头

ax.axis["x"] = ax.new_floating_axis(0,0)
ax.axis["x"].set_axisline_style("-|>", size = 1.0)
#添加y坐标轴，且加上箭头
ax.axis["y"] = ax.new_floating_axis(1,0)
ax.axis["y"].set_axisline_style("-|>", size = 1.0)

#生成x步长为0.1的列表数据
x = np.arange(-10,10,0.1)
y=np.power(x,0.5)
#设置x、y坐标轴的范围
plt.xlim(-10,10)
# plt.ylim(-0.2, 1)
#绘制图形
plt.plot(x,y, c='k')

y1=np.power(x,1)
plt.plot(x,y1, c='k')
y2=np.power(x,2)
plt.plot(x,y2, c='k')

plt.text(8.0,np.power(8.0,0.5) , r'$y=x^{0.5}$',verticalalignment="baseline",horizontalalignment="right",fontsize=8)

plt.text(4.0, 4.0, r'$y=x$',fontsize=8)

plt.text(4.0,np.power(4.0,2), r'$y=x^2$', fontsize=8)

plt.title(r'$x^{\mu},\mu = 0.5 \quad 1 \quad 2 $', fontsize=20)

plt.show()