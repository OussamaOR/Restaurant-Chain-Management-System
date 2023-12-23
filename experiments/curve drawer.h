#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include "constants.h"
#include "utilities.h"
#include <fstream>
#include <sstream>
#include <vector>
#include "../Restaurant Chain Management System/Part A/Header Files/readfiles.h"
#include "../Restaurant Chain Management System//Part A/Header Files/RestaurantHashTable.h"


enum CurveType {
	DailyCosts,
	DailySales,
	MonthlyRatings
};


void initialize_plan(sf::VertexArray&);
void draw_curve(std::vector<unsigned>&, sf::VertexArray&);
void draw_curve2(std::vector<unsigned>&, sf::VertexArray&);
void program_run(std::string,CurveType);
void program_run(std::string , CurveType , CuisineType);
int getRestaurantIndex(const std::string& restaurantId, const std::string& csvFilePath);
std::vector<int> calculateTotalCosts(int restaurantIndex, const std::string& csvFilePath);