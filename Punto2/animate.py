from time import time
import os
import numpy as np
import matplotlib.pyplot as plt

from matplotlib import animation, rc
rc('animation', html='html5')
import matplotlib.animation as animation
FFwriter = animation.FFMpegWriter()
Writer = animation.writers['ffmpeg']
writer = Writer(fps=15, metadata=dict(artist='Me'), bitrate=1800)


data=np.genfromtxt("Result.dat")    # Lee los datos
n=len(data[0,:])    # Lee la dimensión
space=range(n)      # Crea unidades arbitrarias para el scatter plot

fig, ax = plt.subplots()    # Inicializa la figura
x=space    # inizializa el primer frame con la primera serie de datos
y=data[0,:]
sc = ax.scatter(x,y,s=10,c='k')  # Inicializa el sactter propiamente dicho
plt.ylim([-1,1])  # Cuida los márgenes

def animate(i): # Por cada frame avanzará una fila en los datos
    x=space
    y=data[i,:]
    sc.set_offsets(np.c_[x,y])


sim = animation.FuncAnimation(fig, animate, frames=len(data[:,0]), interval=20, repeat=True) # Anima todos los frames, a intervalos de 50 ms
sim.save('cuerda.mp4', writer=writer) # guarda la animación
