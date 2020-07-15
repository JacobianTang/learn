# -*- coding: utf-8 -*-
def cal_function_value(x):
    y=np.log(1+np.exp(x/2))
    return y

import matplotlib.pyplot as plt  #导入matplotlib库
import numpy as np  #导入numpy库
import mpl_toolkits.axisartist as axisartist

#创建画布
fig = plt.figure()
#使用axisartist.Subplot方法创建一个绘图区对象ax
ax = axisartist.Subplot(fig, 111)
#将绘图区对象添加到画布中
fig.add_axes(ax)
#通过set_axisline_style方法设置绘图区的底部及左侧坐标轴样式
#"-|>"代表实心箭头："->"代表空心箭头
ax.axis["bottom"].set_axisline_style("-|>", size = 1.5)
ax.axis["left"].set_axisline_style("-|>", size = 1.5)
#通过set_visible方法设置绘图区的顶部及右侧坐标轴隐藏
ax.axis["top"].set_visible(False)
ax.axis["right"].set_visible(False)

#生成x步长为0.1的列表数据
x = np.arange(-15,15,0.1)
#生成sigmiod形式的y数据
#y=1/(1+np.exp(-x))
#y=np.exp(x)
y=np.log(1+np.exp(x/2))
#设置x、y坐标轴的范围
plt.xlim(-12,12)
plt.ylim(-0.2, 1)
#绘制图形
plt.plot(x,y, c='k')

####画一条x=-5 和 x=0的虚线
N=int(np.ceil(float(1-(-0.2))/0.1))

plt.plot([-5]*N,np.arange(-0.2,1,0.1),c='k',linestyle='--')
plt.plot([0]*N,np.arange(-0.2,1,0.1),c='k',linestyle='--')

plt.plot([-5.0,0.0], [cal_function_value(-5.0),cal_function_value(0.0)], c='r',linestyle='--')

plt.xlabel('x')
plt.ylabel('y')


plt.text(-5,cal_function_value(-5) , r'$\left(x,f(x)\right)$', fontsize=10)
plt.text(0, cal_function_value(0), r'$\left(z,f(z)\right)$',fontsize=10)
plt.text(-10,cal_function_value(-10) + cal_function_value(-10), r'$y=f(x)$', fontsize=10)

plt.xticks([])
plt.yticks([])

# ax.spines['top'].set_visible(False)
# ax.spines['right'].set_visible(False)

# ax.axis["x"] = ax.new_floating_axis(0,0)
# ax.axis["x"].set_axisline_style("->", size = 1.0)
# 添加y坐标轴，且加上箭头
# ax.axis["y"] = ax.new_floating_axis(1,0)
# ax.axis["y"].set_axisline_style("-|>", size = 1.0)

plt.show()