import numpy as np
import matplotlib.pyplot as plt
from matplotlib import animation

#Importa datos 
data = np.loadtxt('cuerda.txt')
x = data[0,:]
y = data[1,:]

fig, ax = plt.subplots()

#Dimensiones en x y y de la grafica 
ax.set_xlim(( 0, 100))
ax.set_ylim((-5, 1))


