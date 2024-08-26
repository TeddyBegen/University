# -*- coding: utf-8 -*-
"""
Created on Mon Apr 24 14:14:32 2023

@author: tedlj
"""
import numpy as np
import scipy.integrate as integ
import matplotlib.pyplot as plt


def func1():
    def trapets(fun,a,b,N):
        h = (b-a)/N
        x = np.linspace(a,b,N+1)
        y = fun(x)
        return h*(np.sum(y[1:-1]) + 0.5 * (y[0] + y[-1]))
    
    f = lambda x:np.log(1 + np.sin(x)) * np.cos(x)
    print("N = 10 ger:")
    print(trapets(f, 0, np.pi/2, 10))
    
    print("N = 100 ger:")
    print(trapets(f, 0, np.pi/2, 100))
    
    print("N = 1000 ger:")
    print(trapets(f, 0, np.pi/2, 1000))
    
    
    
    print("exakta värdet är:")
    print(2 * np.log(2) - 1)

def func2(): 
    I, tol = integ.quad(lambda x: np.exp(-x) * np.cos(x), 0, np.inf)
    print("I: ")
    print(I)
    print("tol:")
    print(tol)
    return

def func3a():
    t = np.linspace(0,4*np.pi,100)
    x = 5*t - 5 * np.sin(t)
    y = 5 - 5 * np.cos(t)
    plt.plot(x,y)
    plt.title("McDonalds")
    plt.xlabel("x")
    plt.ylabel("y")
    plt.grid()
    
def func3b():

    L, tol = integ.quad(lambda x:np.sqrt((5 - 5 * np.cos(x))**2 + (5 * np.sin(x))**2), 0, 4*np.pi)
    print("L: ")
    print(L)
    print("tol:")
    print(tol)
    
def func4b():
    L, tol = integ.quad(lambda x:np.sqrt(1 + (0.2 * x)**2),-5, 5)
    print("L: ")
    print(L)
    print("tol: ")
    print(tol)
    
func4b()

    
    
    


    
    
        