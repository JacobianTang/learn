from sympy.plotting import *
from sympy import plot_implicit,Eq,And,Or
from sympy import symbols
from sympy import diff
from sympy.functions import sin,exp,sqrt
import math as mt

x=symbols("x")
f=1/(1 + x**2)

xx=[]
yy=[]


def getLarangleSymbol(xx,yy):
    x=symbols("x")
    l_x = 0.0
    print(len(xx))
    for i in range(len(xx)):
        factor = 1.0
        li_x = 1.0
        for j in range(len(xx)):
            if j!=i:
                li_x *=(x-xx[j])
                factor*=(xx[i]-xx[j])
        li_x /=factor
        l_x += yy[i]*li_x
    return l_x

N = 10
for i in range(N+1):
    cur_x =  -5.0 + 10.0*i/N
    cur_y =f.evalf(subs={"x":cur_x})
    xx.append(cur_x)
    yy.append(cur_y)
    print(cur_x,cur_y)
y_x = getLarangleSymbol(xx,yy)
p2=plot(y_x,(x,-5,5),show=False)
p1=plot(f,(x,-5,5),show=False)

#print(x_y.evalf(subs={"x":0}))
#
#L1_x = getLarangleSymbol(xx[2:4:1],yy[2:4:1])
#f=getLarangleSymbol(xx[1:4:1],yy[1:4:1])
#f1=getLarangleSymbol(xx,yy)
#print(L1_x.evalf(subs={"x":0.3}),f.evalf(subs={"x":0.3}),f1.evalf(subs={"x":0.3}))
#
#p2=plot(f,(x,-2,2),show=False)
#p3=plot(f1,(x,-2,2),show=False)
#p1.append(p3[0])
p1.append(p2[0])
p1.show()


