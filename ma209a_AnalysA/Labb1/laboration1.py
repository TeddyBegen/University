# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

import matplotlib.pyplot as plt
import numpy as np
import scipy.optimize as opt
import scipy.integrate as itg



#uppgift 1

def func1a():
    x = 35*25
    print(x)

def func1b():
    x = np.sqrt(5) + 1/4
    print(x)
  
def func1c():
    x = np.exp(10)
    print(x)

def func1d():
    x = np.tan(np.pi/6)
    print(x)
    
#uppgift 2, A: 1.3533e+16 = 1.3533 * 10**16, B: 2.1191e-11 = 2.1191 * 10**-11


#uppgift 3

def func3():
    x = np.linspace(0,10)
    y1 = np.sin(x)
    y2 = np.sin(x)*np.cos(x)
    plt.plot(x,y1)
    plt.plot(x,y2)
    plt.xlabel("x")
    plt.ylabel("y")

#uppgift 4

def func4a():
    x = np.arange(10, 33, 2)
    print(x)
    
def func4b():
    x = np.arange(-2, -36, -3)
    print(x)
    
#uppgift 5

def func5():
    f = lambda x:1.2 * x + np.sqrt(x) - 2
    x = np.linspace(0,2)
    y = f(x)
    plt.plot(x,y)
    plt.grid()
    plt.xlabel("x")
    plt.ylabel("y")
    x0 = opt.fsolve(f, 0.9)
    print(x0)
    
#uppgift 6

def func6():
    f = lambda x:np.exp(-x) * np.sin(x)
    x = np.linspace(0,6)
    y = f(x)
    plt.plot(x,y)
    plt.grid()
    plt.xlabel("x")
    plt.ylabel("y")
    xmin = opt.minimize(f, 4)
    print(xmin.x)
    
#uppgift 7

def func7():
    f = lambda x: x**3 + 2*x**2 - x + 1
    i = itg.quad(f,0,5)
    print(i)
    

    

    
    
    
    
    
    
    