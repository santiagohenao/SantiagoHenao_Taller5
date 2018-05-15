from time import time
import os
import numpy as np
import matplotlib.pyplot as plt

from matplotlib import animation, rc
rc('animation', html='html5')
import matplotlib.animation as animation
FFwriter = animation.FFMpegWriter()
Writer = animation.writers['ffmpeg']
writer = Writer(fps=120, metadata=dict(artist='Me'), bitrate=1800)
plt.rcParams['axes.facecolor'] = 'black'

data=np.genfromtxt("result.dat")

q1=data[:,1][3000:-13000]
q2=data[:,2][3000:-13000]

space=data[:,0][:-13000]
scaled_space = (space - space.min()) / (space.ptp())
colors = plt.cm.hsv(scaled_space)

fig, ax = plt.subplots(figsize=(10,10))    # Inicializa la figura

x=q1[0]    # inizializa el primer frame con la primera serie de datos
y=q2[0]
plt.xlabel("q1",fontsize=25)
plt.ylabel("q2",fontsize=25)
plt.scatter(q1,q2,c=colors,s=0.1,alpha=0.2) # pone la gráfica de color de fondo

sc = ax.scatter(x,y,s=8,c='w')  # Inicializa el sactter propiamente dicho

plt.ylim([q2.min(),q2.max()])
plt.xlim([q1.min(),q1.max()])

start=time()
def animate(i): # Por cada frame avanzará una fila en los datos
    x=q1[4*i]
    y=q2[4*i]
    sc.set_offsets(np.c_[x,y])
    if(i%100==0):
        print(i,time()-start,sep="\t")


sim = animation.FuncAnimation(fig, animate, frames=3000, interval=500, repeat=True) # Anima todos los frames
sim.save('result.mp4', writer=writer) # guarda la animación
