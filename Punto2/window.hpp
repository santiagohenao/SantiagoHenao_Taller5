
// lista de círculos para animar
sf::CircleShape dots[n];

// Inicialización
for(int i=0;i<n;i++)
{
    dots[i]=sf::CircleShape(1.3);
    dots[i].setPosition(i*dx*10,(-u[i]*150)+150);
}

// Ventana de animación
sf::RenderWindow window(sf::VideoMode(1000, 300), "Wave Equation Solution");

while (window.isOpen()) // Ciclo de manejo de eventos y animación en tiempo real
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }

    window.setFramerateLimit(60);
    window.clear();

    // zona de actualización


        // Cálculos

    for(int j=0;j<60;j++)
    {
        // Machaca las condiciones iniciales
        u[0]=0;u[n-1]=0;
        up[0]=0;up[n-1]=0;
        uf[0]=0;uf[n-1]=0;


        for(int i=1;i<n-1;i++)
        {
            // Solución de la ecuación difernecial
            uf[i]=-up[i]+2*(1-alpha)*u[i]+alpha*(u[i+1]+u[i-1]);
        }

        // Actualiza los datos
        for(int i=0;i<n;i++)
        {
            up[i]=u[i];
        }
        for(int i=0;i<n;i++)
        {
            u[i]=uf[i];
        }
    }

        // Actualizar posiciones en la animación

    for(int i=0;i<n;i++)
    {
        dots[i].setPosition(i*dx*10,(-u[i]*150)+150);
    }


    // zona de dibujo

    for(int i=0;i<n;i++)
    {
        window.draw(dots[i]);
    }

    window.display();




}
