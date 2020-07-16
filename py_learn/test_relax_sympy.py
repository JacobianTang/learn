from sympy.plotting import *
from sympy import plot_implicit,Eq,And,Or
from sympy import symbols
from sympy import diff
from sympy.functions import log,sin,exp,sqrt,ln
import math as mt

x,lamda=symbols("x,lamda")
f=3*x**2 - exp(x)
phi_x=sqrt(exp(x)/3)
#phi_x=exp(x)/(3*x)
#lamda = 0.5 
#f=x**3+2*x**2+10*x-20
#phi_x=lamda*x/(1 + lamda) + 20/(x**2 + 2*x + 10)/(1+lamda)
diff_phi_x=diff(phi_x,x)
phi_x_lamda=x*(lamda)/(1+lamda) + (phi_x)/(1+lamda)
dif_phi_x_lamda =diff(phi_x_lamda,x)

#p4=plot3d(dif_phi_x_lamda,(x,1,2),(lamda,-0.5,2))
a=1
b=2
x0=a
pre_x0=0
p1=plot(f,(x,a,b),show=False)
p2=plot(phi_x,(x,a,b),show=False)
p3=plot(diff_phi_x,(x,a,b),show=False)
p1.append(p2[0])
p1.append(p3[0])
p1.show()

for i in range(100):
    cur_f= f.evalf(subs={"x":x0})
    cur_phi_x= phi_x.evalf(subs={"x":x0})
    cur_dif_x = diff_phi_x.evalf(subs={"x":x0})
    lamda_k = -cur_dif_x
    cur_dif_phi_x_lamda = dif_phi_x_lamda.evalf(subs={"x":x0,"lamda":lamda_k})
    print(cur_f,x0,cur_phi_x,cur_dif_x,cur_dif_phi_x_lamda)
    #x0=phi_x_lamda.evalf(subs={"x":x0,"lamda":lamda_k})
    x0=cur_phi_x
    if abs(pre_x0 - x0)<0.00001:
        break
    pre_x0=x0


