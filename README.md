# SantiagoHenao_Taller5
Taller sobre ecuaciones diferenciales

Todos los puntos pueden correrse ejecutando `$ make` dentro de la carpeta.

## Punto 2: Ecuación de onda

`$ make` correrá una simulación en tiempo real de la cuerda con las condiciones iniciales dadas. El código de la simulación en tiempo real con SFML está en `cuerda.cpp`

`sh pyanimate.sh` correrá la simulación en C++, guardará los datos, y utilizará matplotlib para animar. En este proceso se demora BASTANTE más animando. En archivo resultante es `cuerda.mp4`.

Nota: `$ make clean` limpia los resultados de ambos métodos de animación, pero no borra los ejecutables de SFML.

## Punto 3: Simulación caótica

`$ make` correrá la simulación, volcará los resultados en result.dat, hará las gráficas correspondientes y compilará un archivo `.tex` con las gráficas.

`$ python3 animate.py` animará los resultados. Para generar 3000 frames a 120 fps demoró 36 minutos, así que mejor no compilarlo de nuevo. Se incluyen dos videos de muestra.

La gráfica de q1 contra q2 no está en todo los 3000 segundos de tiempo, el resto sí.

Todos los cálculos se hicieron con valores diferentes a los que mandaba la guía, en pos de ver mejor la simulación. Con los parámetros originales simplemente se quedaba estática y se perdía el movimiento periódico.
