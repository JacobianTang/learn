from sympy.plotting import *
from sympy import plot_implicit,Eq,And,Or
from sympy import symbols
from sympy import diff
from sympy import *
from sympy.functions import  Abs,sin,exp,sqrt
import math as mt

x=symbols("x")
fx=(10-2-2)*x
f1=(x+4)/(x+1)
f2=(x+2)/(x+1)
result=reduce_inequalities([Abs(f1) < 1,Abs(f2)<1])
print(result)

