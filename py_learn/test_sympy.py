from sympy.plotting import *
from sympy import plot_implicit,Eq,And,Or
from sympy import symbols
from sympy import diff
from sympy.functions import sin,exp,sqrt
import math as mt

x,y=symbols("x,y")
x1,x2,x3=symbols("x1,x2,x3")
a=1
b=1
f=x1**4+2*x1**2*x2**2 +x2**4 
z0 = f.evalf(subs={"x1":a,"x2":b})
dif_x1 = diff(f,x1).evalf(subs={"x1":a,"x2":b})
dif_x2 = diff(f,x2).evalf(subs={"x1":a,"x2":b})
dif_x1x1 = diff(diff(f,x1),x1).evalf(subs={"x1":a,"x2":b})
dif_x1x2 = diff(diff(f,x1),x2).evalf(subs={"x1":a,"x2":b})
dif_x2x2 = diff(diff(f,x2),x2).evalf(subs={"x1":a,"x2":b})
print(dif_x1,dif_x2)
f1= z0+ dif_x1*(x1 - a) + dif_x2*(x2-b)
f2= 10 - (x1-a)**2-(x2-b)**2 - (x3-z0)**2 
f3= z0+ dif_x1*(x1 - a) + dif_x2*(x2-b)  + (x1-a)**2*dif_x1x1 + 2*dif_x1x2*(x1-a)*(x2-b) + dif_x2x2*(x2-b)**2
p2=plot3d((f,(x1,-5,5),(x2,-5,5)),(f1,(x1,1,-2),(x2,-1,1)),(f3,(x1,-3,3),(x2,-3,3)))


#p1=plot_implicit(Or(Eq(x**2-y**2,12),Eq(2*x*y,16)),(x,-10,10),(y,-10,10))
#p1=plot_implicit(Eq(x**2+y**2,2),(x,-10,10),(y,-10,10))

