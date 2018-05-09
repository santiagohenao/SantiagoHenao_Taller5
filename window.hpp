sf::CircleShape dots[n];

for(int i=0;i<n;i++)
{
    dots[i]=sf::CircleShape(1);
    dots[i].setPosition(i*dx*10,(-u[i]*150)+150);
}


sf::RenderWindow window(sf::VideoMode(1000, 300), "Wave Equation Solution");

while (window.isOpen())
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    window.setFramerateLimit(60);
    window.clear();

    // zona de actualización


        // Cálculos

    for(int j=0;j<10;j++)
    {
        for(int i=1;i<n-1;i++)
        {
            u[i]=-up[i]+2*(1-alpha)*u[i]+alpha*(u[i+1]+u[i-1]);
            u[0]=0;
        }
        for(int i=0;i<n;i++)
        {
            up[i]=u[i];
        }
    }

        // Actualizar posiciones

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
