rm -f Result.dat
g++ cuerda_datos.cpp -o datos
./datos
python3 animate.py
rm datos
