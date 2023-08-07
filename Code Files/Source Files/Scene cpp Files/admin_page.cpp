#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "admin.h"

using namespace std;
using namespace sf;

inline void runAdminPage(int* scene, Admin* admin, RenderWindow* window)
{
	/* Loading the Inika font and if failed to do so close the program */
	Font font;
	if (!font.loadFromFile("Assets/Font/Inika/Inika-Bold.ttf"))
	{
		cout << "Error loading font" << endl;
		*scene = -1;
		return;
	}


	/* Loading the background and if failed to do so close the program */
	Texture backgroundTexture;
	if (!backgroundTexture.loadFromFile("Assets/Backgrounds/HMS-Admin_Screen.jpg"))
	{
		cout << "Error loading background image\n";
		*scene = -1;
		return;
	}

	/* Beginning of declaring shapes and texts to use */

	RectangleShape background(Vector2f(1600, 900));
	background.setTexture(&backgroundTexture);
	background.setPosition(Vector2f(0, 0));

	Text addStaffText("Add Staff\n Member", font, 60),
		deleteStaffText("Delete Staff\n  Member", font, 60),
		updateStaffText("Update Staff\n   Member", font, 60);

	addStaffText.setPosition(Vector2f(136, 54));
	deleteStaffText.setPosition(Vector2f(652, 54));
	updateStaffText.setPosition(Vector2f(1164, 54));

	/* End of declaring */

	while (window->isOpen())
	{
		Event event;
		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				*scene = -1;
				window->close();
			}

			if (event.type == Event::MouseButtonPressed)
			{
				if (addStaffText.getGlobalBounds().contains(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y))
				{
					cout << "Add button pressed!\n";
				}
				if (deleteStaffText.getGlobalBounds().contains(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y))
				{
					cout << "Delete button pressed!\n";
				}
				if (updateStaffText.getGlobalBounds().contains(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y))
				{
					cout << "Update button pressed!\n";
				}
			}
		}


		/* Simulating a hover effect on the buttons in the scene */
		addStaffText.setFillColor(Color(0xF6, 0xF1, 0xF1));
		if (addStaffText.getGlobalBounds().contains(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y))
		{
			addStaffText.setFillColor(Color(0xAF, 0xD3, 0xE2));
		}

		deleteStaffText.setFillColor(Color(0xF6, 0xF1, 0xF1));
		if (deleteStaffText.getGlobalBounds().contains(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y))
		{
			deleteStaffText.setFillColor(Color(0xAF, 0xD3, 0xE2));
		}

		updateStaffText.setFillColor(Color(0xF6, 0xF1, 0xF1));
		if (updateStaffText.getGlobalBounds().contains(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y))
		{
			updateStaffText.setFillColor(Color(0xAF, 0xD3, 0xE2));
		}

		/* Clearing the window then drawing then displaying which is kept on repeat */
		window->clear(Color::White);

		window->draw(background);

		window->draw(addStaffText);
		window->draw(deleteStaffText);
		window->draw(updateStaffText);

		window->display();
	}
}