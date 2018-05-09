# SantiagoHenao_Taller5
Taller sobre ecuaciones diferenciales

Todos los puntos pueden correrse ejecutando `$ make` dentro de la carpeta.

## Punto 2: Ecuación de onda

`$ make` correrá una simulación en tiempo real de la cuerda con las condiciones iniciales dadas. El código de la simulación en tiempo real con SFML está en `cuerda.cpp`

`sh pyanimate.py` correrá la simulación en C++, guardará los datos, y utilizará matplotlib para animar. En este proceso se demora BASTANTE más animando. En archivo resultante es `cuerda.mp4`.

Nota: `$ make clean` limpia los resultados de ambos métodos de animación, pero no borra los ejecutables de SFML.
