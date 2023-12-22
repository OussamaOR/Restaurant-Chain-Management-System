
#include <algorithm>
#include <cmath>
#include <ctime>
#include "curve drawer.h"
#include "constants.h"
#include <fstream>
#include <vector>
#include "../Restaurant Chain Management System/Part A/Header Files/readfiles.h"
#include "../Restaurant Chain Management System/Database/dailycosts.csv"
#include "../Restaurant Chain Management System//Part A/Header Files/RestaurantHashTable.h"
// the origin of the plan is (WINDOW_WIDTH * 0.125, WINDOW_HEIGHT * 0.8)
// end of y-axis is (WINDOW_WIDTH * 0.125 , WINDOW_HEIGHT * 0.2)
// end of x-axis is (WINDOW_WIDTH * 0.75 , WINDOW_HEIGHT * 0.8)
// 

unsigned generate_random_interv(unsigned x, unsigned y) {        // including both
	if (x > y) std::swap(x, y);
	return (rand() % (y - x + 1)) + x;
}
void fill_vector(std::vector<unsigned>& vec, unsigned low , unsigned high) {
	for (int i = 0;i < vec.size();i++) {
		vec[i] = generate_random_interv(low, high);
	}
}
std::vector<int> get_dailycosts_values(std::vector<dailyCost> costs) {
    std::vector<int> dailycosts;
    for (int i = 0;i < costs.size();i++) {
        dailycosts[i] = costs[i].getTotal();
    }
    return dailycosts;
}
std::vector<int> get_dailycosts(int restaurant_id,RestaurantHashTable& restaurants) {
    Restaurant restaurant;
    restaurants.search(restaurant_id, restaurant);
    return get_dailycosts_values(restaurant.getDailyCosts().getDailyCosts());
}
void initialize_plan(sf::VertexArray& plan) {
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

    plan.append(sf::Vertex(sf::Vector2f(W_WIDTH * 0.125, W_HEIGHT * 0.2)));
    plan.append(sf::Vertex(sf::Vector2f(W_WIDTH * 0.125 - 10, W_HEIGHT * 0.2)));          // max value label
}

void draw_curve(std::vector<int>& values, sf::VertexArray& curve) {     // noise reduction version
    unsigned maximum = values[0];

    for (auto num : values) {
        if (maximum < num) maximum = num;
    }

    unsigned int x_values = 0;
    int step = std::max(1, static_cast<int>(std::floor(values.size() / 30.0)));

    for (int i = 0; i < values.size(); i += step) {
        int sum = 0;
        int numElements = std::min(step, static_cast<int>(values.size()) - i);

        for (int j = i; j < i + numElements; j++) {
            sum += values[j];
        }

        int y = -static_cast<double>(sum/numElements) / maximum * 0.6 * W_HEIGHT + W_HEIGHT * 0.8;
        int x = i * 0.625 * W_WIDTH / values.size() + W_WIDTH * 0.125;

        curve.append(sf::Vertex(sf::Vector2f(x, y)));
        x_values += numElements;

        std::cout << "x : " << x << "  y : " << y << std::endl;
    }
}


void draw_curve2(std::vector<int>& values, sf::VertexArray& curve) {                  // plotting the real graph 
    unsigned maximum = values[0];

    for (auto num : values) {
        if (maximum < num) maximum = num;
    }
    unsigned int x_values = 0;
    for (auto num : values) {
        std::cout << num << std::endl;
        int x = x_values * 0.625 * W_WIDTH / values.size() + W_WIDTH * 0.125;
        int y = (-static_cast<double>(num) / maximum * 0.6 * W_HEIGHT) + W_HEIGHT * 0.8;
        std::cout << "x : " << x << "  y : " << y << std::endl;
        curve.append(sf::Vertex(sf::Vector2f(x, y)));
        x_values++;
    }                                                                                      

}



void program_run() {
    RestaurantHashTable restaurants;
    readRestaurantCSV("../Restaurant Chain Management System/Database/restaurant.csv");
    std::vector<unsigned> values(30) = get_dailycosts(310610000, restaurants);


    sf::Font font;
    font.loadFromFile("Roboto-Medium.ttf");
    sf::Text start_date("2023/01/01", font, 15);
    start_date.setPosition(sf::Vector2f(W_WIDTH * 0.125, W_HEIGHT * 0.8));

    sf::Text start_date_label("Start Date", font, 15);
    start_date_label.setPosition(sf::Vector2f(W_WIDTH * 0.125, W_HEIGHT * 0.8 + 20));

    sf::Text end_date("2023/12/30", font, 15);
    end_date.setPosition(sf::Vector2f(W_WIDTH * 0.75, W_HEIGHT * 0.8));

    sf::Text end_date_label("End Date", font, 15);
    end_date_label.setPosition(sf::Vector2f(W_WIDTH * 0.75, W_HEIGHT * 0.8 + 20));

    sf::Text yaxis_label("Daily Cost (DA)", font, 15);
    yaxis_label.setPosition(sf::Vector2f(W_WIDTH * 0.125 - 45, W_HEIGHT * 0.15 - 30));



    sf::RenderWindow window(sf::VideoMode(W_WIDTH, W_HEIGHT), "Plotting Program");
    sf::VertexArray plan(sf::Lines);
    initialize_plan(plan);

   

    sf::VertexArray curve(sf::LinesStrip);
    draw_curve(values, curve);

    unsigned minimum = *std::min_element(values.begin(), values.end());
    unsigned maximum = *std::max_element(values.begin(), values.end());
    sf::Text min_value(std::to_string(minimum), font, 15);
    min_value.setOrigin(min_value.getGlobalBounds().getPosition().x + min_value.getGlobalBounds().width, min_value.getGlobalBounds().getPosition().y);
    min_value.setPosition(sf::Vector2f(W_WIDTH * 0.125 - 15, -static_cast<double>(minimum) / maximum * 0.6 * W_HEIGHT + W_HEIGHT * 0.8 - 8));

    plan.append(sf::Vertex(sf::Vector2f(W_WIDTH * 0.125, -static_cast<double>(minimum) / maximum * 0.6 * W_HEIGHT + W_HEIGHT * 0.8)));
    plan.append(sf::Vertex(sf::Vector2f(W_WIDTH * 0.125 - 10, -static_cast<double>(minimum) / maximum * 0.6 * W_HEIGHT + W_HEIGHT * 0.8)));


    sf::Text max_value(std::to_string(*std::max_element(values.begin(), values.end())), font, 15);
    max_value.setOrigin(max_value.getGlobalBounds().getPosition().x + max_value.getGlobalBounds().width, max_value.getGlobalBounds().getPosition().y);
    max_value.setPosition(sf::Vector2f(W_WIDTH * 0.125 - 15, W_HEIGHT * 0.2 - 8));

    sf::Event event;
    while (window.isOpen()) {
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();



        window.draw(plan);
        window.draw(curve);
        window.draw(start_date);
        window.draw(start_date_label);
        window.draw(end_date);
        window.draw(end_date_label);
        window.draw(yaxis_label);
        window.draw(max_value);
        window.draw(min_value);
        window.display();
    }




}


