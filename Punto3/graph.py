import numpy as np
import matplotlib.pyplot as plt

# importar daots
data=np.genfromtxt("result.dat")
# tamaño de puntos global
s_global=0.1
# incializar subplots
fig, ax = plt.subplots(4,sharex="all",figsize=(20,10))

# scatter
ax[0].scatter(data[:,0],data[:,1],s=s_global,c='k')
ax[1].scatter(data[:,0],data[:,2],s=s_global,c='k')
ax[2].scatter(data[:,0],data[:,3],s=s_global,c='k')
ax[3].scatter(data[:,0],data[:,4],s=s_global,c='k')

# definir límites
ax[0].set_ylim([data[:,1].min(),data[:,1].max()])
ax[1].set_ylim([data[:,2].min(),data[:,2].max()])
ax[2].set_ylim([data[:,3].min(),data[:,3].max()])
ax[3].set_ylim([data[:,4].min(),data[:,4].max()])

ax[0].set_xlim([data[:,0].min(),data[:,0].max()])
ax[1].set_xlim([data[:,0].min(),data[:,0].max()])
ax[2].set_xlim([data[:,0].min(),data[:,0].max()])
ax[3].set_xlim([data[:,0].min(),data[:,0].max()])

# Labels
ax[0].set_ylabel("q1",fontsize=20)
ax[1].set_ylabel("q2",fontsize=20)
ax[2].set_ylabel("p1",fontsize=20)
ax[3].set_ylabel("p2",fontsize=20)
ax[3].set_xlabel("t",fontsize=25)

# Guardar
plt.savefig("result.png",bbox_inches='tight')

# Limiar la figura
plt.clf()
# Fondo negro
plt.rcParams['axes.facecolor'] = 'black'


# Preparar para gráfica q1 contra q2
space=data[:,0][:-13000]

# Función de color tipo hue
scaled_space = (space - space.min()) / (space.ptp())
colors = plt.cm.hsv(scaled_space)

# Scatter con color
plt.scatter(data[:,1][:-13000],data[:,2][:-13000],c=colors,s=s_global)
plt.xlabel("q1",fontsize=25)
plt.ylabel("q2",fontsize=25)
# Guardar
plt.savefig("result2.png",bbox_inches='tight')
