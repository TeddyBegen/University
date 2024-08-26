# -*- coding: utf-8 -*-
"""
Created on Mon May 15 12:51:26 2023

@author: tedlj
"""

import matplotlib.pyplot as plt
import numpy as np
import scipy.integrate as integ


def func1b():
    f = lambda t,v: 9.82 - (40/100)*v**2

    sol = integ.solve_ivp(f, [0,5], [20], t_eval = np.linspace(0,5,100))

    fig, ax = plt.subplots()
    ax.plot(sol.t, sol.y[0])

    ax.set_xlabel('x', fontsize = 14)
    ax.set_ylabel('y', fontsize = 14)
    ax.tick_params(labelsize = 14)
    print(sol.t[-1])
    


def func2b():
    f = lambda t,y: [y[1], -0.3*y[1] - np.sin(y[0])]
    
    sol = integ.solve_ivp(f, [0,30], [1,0], t_eval=np.linspace(0,30,100))
    
    fig, ax = plt.subplots()
    ax.plot(sol.t, sol.y[0])

    ax.set_xlabel('x', fontsize = 14)
    ax.set_ylabel('y', fontsize = 14)
    ax.tick_params(labelsize = 14)
   
    
    
def func3b():
    w = 1.01

    f = lambda t,y: [y[1], -y[0] + np.cos(w*t)]
    
    sol = integ.solve_ivp(f, [0,100], [0,0], t_eval=np.linspace(0,100,1000))
    
    fig, ax = plt.subplots()
    ax.plot(sol.t, sol.y[1])

    ax.set_xlabel('x', fontsize = 14)
    ax.set_ylabel('y', fontsize = 14)
    ax.set_title('w = 0.1')

    ax.tick_params(labelsize = 14)

func3b()
    
    


