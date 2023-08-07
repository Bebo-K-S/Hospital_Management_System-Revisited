#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "admin.h"

using namespace std;
using namespace sf;

inline void runLoginScreen(int* scene, Admin *admin)
{
    RenderWindow window(VideoMode(1600, 900), "Login Screen");
    window.setVerticalSyncEnabled(true);

    Font font;
    if (!font.loadFromFile("Assets/Font/Noto_Serif_Khitan_Small_Script/NotoSerifKhitanSmallScript-Regular.ttf"))
    {
        cout << "Error loading font" << endl;
        *scene = -1;
        return;
    }

    Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("Assets/Backgrounds/HBM-Login_Page.jpg"))
    {
        cout << "Error loading background image\n";
            *scene = -1;
            return;
    }

    sf::Color transparentColor(255, 255, 255, 0);

    RectangleShape background(Vector2f(1600, 900));
    background.setTexture(&backgroundTexture);
    background.setPosition(Vector2f(0, 0));

    RectangleShape usernameBox(Vector2f(470, 64));
    usernameBox.setPosition(945, 422);
    usernameBox.setFillColor(transparentColor);
    usernameBox.setOutlineThickness(0);

    RectangleShape passwordBox(Vector2f(470, 64));
    passwordBox.setPosition(945, 515);
    passwordBox.setFillColor(transparentColor);
    passwordBox.setOutlineThickness(0);

    Text loginText("Login", font, 60);
    loginText.setPosition(1105, 668);

    Text usernameInputText("", font, 35);
    usernameInputText.setPosition(970, 435);
    usernameInputText.setFillColor(Color(0x14, 0x6C, 0x94)); // Set the text color to black

    Text passwordInputText("", font, 35);
    passwordInputText.setPosition(970, 535);
    passwordInputText.setFillColor(Color(0x14, 0x6C, 0x94)); // Set the text color to black

    string usernameInput = "";
    string passwordInput = "";

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                *scene = -1;
                window.close();
            }

            if (event.type == Event::TextEntered)
            {
                if (event.text.unicode == 8) // Check for the backspace character explicitly
                {
                    if (usernameInput.size() > 0 && usernameBox.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
                    {
                        usernameInput.erase(usernameInput.end() - 1); // Remove the last character from the input string
                        usernameInputText.setString(usernameInput); // Update the input text object with the new input string
                    }

                    if (passwordInput.size() > 0 && passwordBox.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
                    {
                        passwordInput.erase(passwordInput.end() - 1); // Remove the last character from the input string
                        passwordInputText.setString(string(passwordInput.size(), '*')); // Update the input text object with a string of asterisks
                    }
                }
                else if (event.text.unicode >= 32 && event.text.unicode < 127) // Check for printable ASCII characters
                {
                    if (usernameBox.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
                    {
                        usernameInput += static_cast<char>(event.text.unicode);
                        usernameInputText.setString(usernameInput); // Update the input text object with the new input string
                    }

                    if (passwordBox.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
                    {
                        passwordInput += static_cast<char>(event.text.unicode);
                        passwordInputText.setString(string(passwordInput.size(), '*')); // Update the input text object with a string of asterisks
                    }
                }
            }

            if (event.type == Event::KeyPressed || event.type == Event::MouseButtonPressed)
            {
                if (event.key.code == Keyboard::Return || loginText.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
                {
                    if (usernameInput == "ADMIN" && passwordInput == "123") // 5218550
                    {
                        cout << "Login successful" << endl;
                        *scene = -1; // Admin's Page
                        return;
                    }
                    else if (admin->findDoctorName(usernameInput) && admin->findDoctorID(passwordInput))
                    {
                        cout << "Doctor login recognized\n";
                        *scene = -1; // Doctor Page
                        return;
                    }
                    else if (admin->findNurseName(usernameInput) && admin->findNurseID(passwordInput))
                    {
                        cout << "Nurse login recognized\n";
                        *scene = -1;
                        return;
                    }
                    else if (admin->findReceptionistName(usernameInput) && admin->findReceptionistID(passwordInput))
                    {
                        cout << "Receptionist login recognized\n";
                        *scene = -1;
                        return;
                    }
                    else
                    {
                        cout << "Incorrect username or password" << endl;
                    }
                }
            }
        }

        loginText.setFillColor(Color(0xF6, 0xF1, 0xF1));
        if (loginText.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
        {
            loginText.setFillColor(Color(0xAF, 0xD3, 0xE2));
        }

        window.clear(Color::White);
        window.draw(background);
        window.draw(usernameBox);
        window.draw(passwordBox);

        window.draw(usernameInputText);
        window.draw(passwordInputText);

        window.draw(loginText);
        window.display();
    }
}