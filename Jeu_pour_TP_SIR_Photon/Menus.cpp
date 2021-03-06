#include "Menus.h"

Menus::Menus()
{
}


Menus::~Menus()
{
}

void Menus::display(sf::RenderWindow & renderWindow)
{
	sf::Sprite sprite(fond);

	renderWindow.clear();

	renderWindow.draw(sprite);
	
	for (auto const &textes : listeTexte) {
		renderWindow.draw(*textes);
	}
	

	renderWindow.display();
}

Menus::Action Menus::handleClick(sf::RenderWindow & renderWindow, int xMouse, int yMouse)
{
	for (auto const& it : listeBoutton) {
		sf::Rect<int> menuItemRect = (*it).rect;

		int gauche = menuItemRect.left;
		int droite = menuItemRect.left + menuItemRect.width;
		int haut = menuItemRect.top;
		int bas = menuItemRect.height + menuItemRect.top;
		
		if (bas > yMouse && haut < yMouse && droite > xMouse && gauche < xMouse)
		{
			return (*it).action;
		}
	}
	return Vide;
}

void Menus::Advance()
{
}

void Menus::UpdateScore(Action answer)
{
}

