from sympy.plotting import *
from sympy import plot_implicit,Eq,And,Or
from sympy import symbols
from sympy import diff
from sympy.functions import sin,exp,sqrt
import math as mt

x=symbols("x")
xx=[-2,-1,0,1,2]
yy=[0.25,0.50,1,2,4]

xx1=[1,1.4,1.8,2.0]
yy1=[-2.0,-0.8,0.40,1.2]


def getLarangleSymbol(xx,yy):
    x=symbols("x")
    l_x = 0
    print(len(xx))
    for i in range(len(xx)):
        factor=1
        li_x = 1
        for j in range(len(xx)):
            if j!=i:
                li_x *=(x-xx[j])
                factor*=(xx[i]-xx[j])
        li_x /=factor
        l_x += yy[i]*li_x
    return l_x


    
x_y = getLarangleSymbol(yy1,xx1)
print(x_y.evalf(subs={"x":0}))

L1_x = getLarangleSymbol(xx[2:4:1],yy[2:4:1])
f=getLarangleSymbol(xx[1:4:1],yy[1:4:1])
f1=getLarangleSymbol(xx,yy)
print(L1_x.evalf(subs={"x":0.3}),f.evalf(subs={"x":0.3}),f1.evalf(subs={"x":0.3}))

p1=plot(L1_x,(x,-2,2),show=False)
p2=plot(f,(x,-2,2),show=False)
p3=plot(f1,(x,-2,2),show=False)
p1.append(p3[0])
p1.append(p2[0])
p1.show()


