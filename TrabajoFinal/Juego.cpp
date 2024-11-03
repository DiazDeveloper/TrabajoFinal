#include "Juego.h"

Juego::Juego(int width, int height)
{
	background = new Background();  
	player = new Player(10, 150);  
	escopeta = new Shotgun(0, 0); 
	Random r;

	for (int i = 0; i < 9; i++)
	{
		int direccion = r.Next(1, 4); 
		int PosicionX = r.Next(0, width - 102);  
		int PosicionY = r.Next(0, height - 102); 
		enemigos.push_back(new Enemy(PosicionX, PosicionY, direccion));     
	}
}

void Juego::mostrarMenu(Graphics^ canvas)  
{
	menu = new MenuInicio(); 
	menu->mostrar(canvas);
}

void Juego::mostrar(Graphics^ canvas)
{
	
	background->mostrar(canvas);
	player->mostrar(canvas); 

	for (int i = 0; i < enemigos.size(); i++)
	{
		enemigos[i]->mostrar(canvas); 
	}
}

void Juego::mover(Graphics^ canvas)
{
	for (int i = 0; i < enemigos.size(); i++) 
	{
		enemigos[i]->mover(canvas);  
	}
}

void Juego::moverTeclas(Graphics^ canvas, Movimiento movimiento)
{
	player->MoverTeclar(canvas, movimiento);   

}

void Juego::mostrarShotgun(Graphics^ canvas)
{
	escopeta->setX(player->getX());    
	escopeta->setY(player->getY()+ 55);  
	escopeta->setVisible(true);
	escopeta->mostrar(canvas); 
}

Shotgun* Juego::getEscopeta()
{
	return escopeta; 
}
