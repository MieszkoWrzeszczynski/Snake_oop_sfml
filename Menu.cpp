#include "Menu.h"


Menu::Menu(int status_type, RenderWindow & window,Font & font):Status(status_type,window,font)
{

}


void Menu::init()
{
	title.setString("SNAKE");
	title.setFont(*pnt_font);
	title.setCharacterSize(86);
	title.setColor(Color::Cyan);
	title.setStyle(Text::Bold);
 
	title.setPosition(Game::SCRN_WIDTH/2-title.getGlobalBounds().width/2,20);
 
	const int ile = 2;
 
    menuOptions[ile];
 
	string str[] = {"Play","Exit"};

	for(int i=0;i<ile;i++)
	{
		menuOptions[i].setFont(*pnt_font);
		menuOptions[i].setCharacterSize(65);
 
		menuOptions[i].setString(str[i]);
		menuOptions[i].setPosition(Game::SCRN_WIDTH/2-menuOptions[i].getGlobalBounds().width/2,250+i*120);
	}

 
}


int Menu::getEvents(Event & event)
{
	
	Vector2f mousePosition = Vector2f((float)Mouse::getPosition(*pnt_window).x, (float)Mouse::getPosition(*pnt_window).y);

	while (pnt_window->pollEvent(event))
	{
		if (event.type == Event::Closed || (event.type == Event::MouseButtonReleased && menuOptions[1].getGlobalBounds().contains(mousePosition)))
			return Game::END;

		else if (event.type == Event::MouseButtonReleased && menuOptions[0].getGlobalBounds().contains(mousePosition))
			return Game::RUN;

		else if(event.key.code == Keyboard::Escape)
             return Game::END;
	}

	return type;
}



void Menu::update()
{
	Vector2f mousePosition = Vector2f((float)Mouse::getPosition(*pnt_window).x, (float)Mouse::getPosition(*pnt_window).y);

	for (int i = 0; i < 2; i++) 
	{
		if (menuOptions[i].getGlobalBounds().contains(mousePosition))
			menuOptions[i].setColor(Color::Cyan);
		else menuOptions[i].setColor(Color::White);
	}
}


void Menu::render()
{
	pnt_window->clear();

	pnt_window->draw(title);

	for(int i=0;i<2;i++)
	pnt_window->draw(menuOptions[i]);

	pnt_window->display();
}



