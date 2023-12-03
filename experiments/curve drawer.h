#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

void initialize_plan(sf::VertexArray&);
void draw_curve(std::vector<unsigned>&, sf::VertexArray&);
void draw_curve2(std::vector<unsigned>&, sf::VertexArray&);
void program_run();