

#include <cmath>
#include <ctime>
#include "bar charts drawer.h"
#include "constants.h";

unsigned generate_random_interv(unsigned x, unsigned y) {        // including both
	if (x > y) std::swap(x, y);
	return (rand() % (y - x + 1)) + x;
}
void fill_vector(std::vector<unsigned>& vec, unsigned low , unsigned high) {
	for (int i = 0;i < vec.size();i++) {
		vec[i] = generate_random_interv(low, high);
	}
}

static void initialize_plan(sf::VertexArray& plan) {
	plan.append(sf::Vertex(sf::Vector2f(W_WIDTH * 0.125, W_HEIGHT * 0.8)));
	plan.append(sf::Vertex(sf::Vector2f(W_WIDTH * 0.125, W_HEIGHT * 0.15)));      // y-axis

	plan.append(sf::Vertex(sf::Vector2f(W_WIDTH * 0.125, W_HEIGHT * 0.8)));
	plan.append(sf::Vertex(sf::Vector2f(W_WIDTH * 0.75, W_HEIGHT * 0.8)));       // x-axis

	plan.append(sf::Vertex(sf::Vector2f(W_WIDTH * 0.125, W_HEIGHT * 0.15)));
	plan.append(sf::Vertex(sf::Vector2f(W_WIDTH * 0.125 + ARROW_PLAN_DIMENSIONS, W_HEIGHT * 0.15 + ARROW_PLAN_DIMENSIONS)));   //y-axis first part arrow

	plan.append(sf::Vertex(sf::Vector2f(W_WIDTH * 0.125, W_HEIGHT * 0.15)));
	plan.append(sf::Vertex(sf::Vector2f(W_WIDTH * 0.125 - ARROW_PLAN_DIMENSIONS, W_HEIGHT * 0.15 + ARROW_PLAN_DIMENSIONS)));          //y-axis second part arrow

	plan.append(sf::Vertex(sf::Vector2f(W_WIDTH * 0.75, W_HEIGHT * 0.8)));
	plan.append(sf::Vertex(sf::Vector2f(W_WIDTH * 0.75 - ARROW_PLAN_DIMENSIONS, W_HEIGHT * 0.8 - ARROW_PLAN_DIMENSIONS)));        //x-axis first part

	plan.append(sf::Vertex(sf::Vector2f(W_WIDTH * 0.75, W_HEIGHT * 0.8)));
	plan.append(sf::Vertex(sf::Vector2f(W_WIDTH * 0.75 - ARROW_PLAN_DIMENSIONS, W_HEIGHT * 0.8 + ARROW_PLAN_DIMENSIONS)));          // x-axis second part

}
unsigned map_x(unsigned x,unsigned size) {
	return x * 0.625 * W_WIDTH / size + W_WIDTH * 0.125 + 10;
}
unsigned map_y(unsigned y, unsigned maximum) {
	return  ( - static_cast<double>(y) / maximum * 0.6 * W_HEIGHT) + W_HEIGHT * 0.8 ;
}
std::vector<sf::RectangleShape> draw_bar_charts(std::vector <unsigned>& input) {
	
	std::vector<sf::RectangleShape> bars(input.size());

	
	// first we determine the width of each bar                  size / 2 * x-axis length which is ( 0.75 - 0.125 ) * W_WIDTH - some value to stay safe
	unsigned width = (0.625 * W_WIDTH - 20) / 2 / input.size();
	
	unsigned maximum = *std::max_element(input.begin(), input.end());
	for (int i = 0;i < bars.size();i++) {
		bars[i].setSize(sf::Vector2f(width, map_y(input[i], maximum))); // we need to map the second value 
		std::cout << map_y(input[i], maximum) << std::endl;
		bars[i].setOrigin(bars[i].getGlobalBounds().getPosition().x, bars[i].getGlobalBounds().getPosition().y + bars[i].getGlobalBounds().height);     // now the origin is the left bottom corner of the bar
		bars[i].setPosition(map_x(i,static_cast<unsigned>(bars.size())), W_HEIGHT * 0.8);
		
//		std::cout << "x : " << map_x(i,static_cast<unsigned>(bars.size())) << "  y : " << map_y(input[i], maximum) << std::endl;
	}

	return bars;


}

std::vector<sf::Text> setup_values(std::vector<unsigned>& input,sf::Font& font) {
	std::vector<sf::Text> labels(input.size());
	unsigned maximum = *std::max_element(input.begin(), input.end());
	for (int i = 0;i < input.size();i++) {
		labels[i].setFont(font);
		labels[i].setCharacterSize(10);
		labels[i].setString(std::to_string(input[i]));
		labels[i].setOrigin(labels[i].getGlobalBounds().getPosition().x+labels[i].getGlobalBounds().width,labels[i].getGlobalBounds().getPosition().y);
		labels[i].setPosition(W_WIDTH * 0.125 - 20,map_y(input[i],maximum));
		std::cout << "y : " << map_y(input[i], maximum) << std::endl;
	}
	return labels;
}


std::vector<unsigned> values2(10);
void program_run2() {
	srand(time(0));
	sf::Font font;
	if (!font.loadFromFile("./Roboto-Medium.ttf")) {
		std::cout << "couldnt load font !! " << std::endl;
	}
	sf::RenderWindow window(sf::VideoMode(W_WIDTH, W_HEIGHT), "bar charts plotting program");
	sf::VertexArray plan(sf::Lines);
	initialize_plan(plan);
	fill_vector(values2, 1000, 20000);
	std::vector<sf::RectangleShape> bars = draw_bar_charts(values2);
	std::vector<sf::Text> labels = setup_values(values2, font);
	sf::Event ev;
	while (window.isOpen()) {
		while (window.pollEvent(ev)) {
			if (ev.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear();

		window.draw(plan);
		for (int i = 0;i < values2.size();i++) {
			window.draw(bars[i]);
			window.draw(labels[i]);
		}
		
		window.display();

	}
}
