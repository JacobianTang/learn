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

ax.axis[:].set_visible(False)

ax.axis["x"] = ax.new_floating_axis(0,0)
ax.axis["x"].set_axisline_style("-|>", size = 1.0)
#添加y坐标轴，且加上箭头
ax.axis["y"] = ax.new_floating_axis(1,0)
ax.axis["y"].set_axisline_style("-|>", size = 1.0)

#生成x步长为0.1的列表数据
x = np.arange(-10,10,0.1)
#生成sigmiod形式的y数据
#y=1/(1+np.exp(-x))
#y=np.exp(x)
#y=np.log(1+np.exp(x/2))
y=np.sin(x)
#设置x、y坐标轴的范围
plt.xlim(-10,10)
# plt.ylim(-0.2, 1)
#绘制图形
plt.plot(x,y, c='r')

####画一条x=-5 和 x=0的虚线
N=int(np.ceil(float(1.5-(-1.5))/0.1))

plt.plot([-mt.pi/2]*N,np.arange(-1.5,1.5,0.1),c='k',linestyle='--')
plt.plot([mt.pi/2]*N,np.arange(-1.5,1.5,0.1),c='k',linestyle='--')

plt.text(-mt.pi/2, -1.0, r'$y=\frac{-\pi}{2}$',fontsize=10)
plt.text(mt.pi/2, 1.0, r'$y=\frac{\pi}{2}$',fontsize=10)
plt.show()