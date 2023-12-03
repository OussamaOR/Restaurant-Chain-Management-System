#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>



void initialize_plan(sf::VertexArray&);

 std::vector<sf::RectangleShape> draw_bar_charts(std::vector<unsigned>& );
void program_run2();
unsigned map_x(unsigned ,unsigned);
unsigned map_y(unsigned , unsigned );
