#include "Menu.h"


Menu::Menu(int status_type, RenderWindow & window,std::string window_title,Font & font)
:Status(status_type,window,window_title,font)
{

}


void Menu::init()
{

	pnt_window->setMouseCursorVisible(true);
	header.setString(title);
	header.setFont(*pnt_font);
	header.setCharacterSize(86);
	header.setColor(Color(243,245,248,255));
	header.setStyle(Text::Bold);
 
	header.setPosition(Game::SCRN_WIDTH/2-header.getGlobalBounds().width/2,40);
 
	const int ile = 2;
 
    menuOptions[ile];
    string str[ile];

    if(title == "Game over")
    	str[0] = "Play again";
    else
    	str[0] = "Play";

	 str[1] = "Exit";

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
			menuOptions[i].setColor(Color(255,138,0,255));
			
		else menuOptions[i].setColor(Color::White);
	}
}


void Menu::render()
{
	pnt_window->clear(Color(178,30,0,255));

	pnt_window->draw(header);

	for(int i=0;i<2;i++)
		pnt_window->draw(menuOptions[i]);

	pnt_window->display();
}
