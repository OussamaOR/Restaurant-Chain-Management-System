

#include "curve drawer.h"
using namespace std;
// the origin of the plan is (WINDOW_WIDTH * 0.125, WINDOW_HEIGHT * 0.8)
// end of y-axis is (WINDOW_WIDTH * 0.125 , WINDOW_HEIGHT * 0.2)
// end of x-axis is (WINDOW_WIDTH * 0.75 , WINDOW_HEIGHT * 0.8)
// 


int getRestaurantIndex(const std::string& restaurantId, const std::string& csvFilePath) {
    std::ifstream file(csvFilePath);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << csvFilePath << std::endl;
        return -1; // return -1 to indicate an error
    }
    std::string first_line;
    std::getline(file, first_line);
    std::string line;
    int index = 0;

    while (std::getline(file, line)) {

        std::istringstream iss(line);
        std::string currentId;
        std::getline(iss, currentId, ',');
        if (currentId == restaurantId) {
            file.close();
            return index;
        }
        ++index;
    }

    file.close();
    return -1; // return -1 if the restaurant ID is not found
}

// function to calculate total costs for a given restaurant index
std::vector<int> calculateTotalCosts(int restaurantIndex, const std::string& csvFilePath) {
    std::ifstream file(csvFilePath);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << csvFilePath << std::endl;
        return {}; // return an empty vector to indicate an error
    }

    std::vector<int> totalCosts(28, 0);

    for (int i = 0; i < restaurantIndex * 29; ++i) {
        std::string line;
        std::getline(file, line);
    }
    std::string first_line;
    std::getline(file, first_line);
    for (int i = 0; i < 28; ++i) {
        std::string line;
        std::getline(file, line);

        std::istringstream iss(line);
        std::string token;
        int categoryIndex = 0;

        // skip the first 3 values (day, month, year)
        while (std::getline(iss, token, ',')) {
            if (categoryIndex >= 3) {
                totalCosts[i] += std::stoi(token);
            }
            ++categoryIndex;
        }
    }

    file.close();
    return totalCosts;
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
    int maximum = values[0];

    for (auto num : values) {
        if (maximum < num) maximum = num;           // getting the max
    }

     int x_values = 0;
    int step = std::max(1, static_cast<int>(std::floor(values.size() / 30.0)));         // calculating the step such that there is 30 points to draw

    for (int i = 0; i < values.size(); i += step) {
        int sum = 0;
        int numElements = std::min(step, static_cast<int>(values.size()) - i);

        for (int j = i; j < i + numElements; j++) {
            sum += values[j];                                       // summing elements in each step
        }

        int y = -static_cast<double>(sum/numElements) / maximum * 0.6 * W_HEIGHT + W_HEIGHT * 0.8;
        int x = i * 0.625 * W_WIDTH / values.size() + W_WIDTH * 0.125;

        curve.append(sf::Vertex(sf::Vector2f(x, y)));
        x_values += numElements;

        std::cout << "x : " << x << "  y : " << y << std::endl;
    }
   
}


void draw_curve2(std::vector<int>& values, sf::VertexArray& curve) {                  // plotting the real graph 
    int maximum = values[0];

    for (auto num : values) {
        if (maximum < num) maximum = num;
    }
     int x_values = 0;
    for (auto num : values) {
        std::cout << num << std::endl;
        int x = x_values * 0.625 * W_WIDTH / values.size() + W_WIDTH * 0.125;
        int y = (-static_cast<double>(num) / maximum * 0.6 * W_HEIGHT) + W_HEIGHT * 0.8;
        std::cout << "x : " << x << "  y : " << y << std::endl;
        curve.append(sf::Vertex(sf::Vector2f(x, y)));
        x_values++;
    }                                                                                      

}

std::pair<std::string,std::string> get_dailycosts_dates(std::string filepath, int restaurantIndex) {
    ifstream input(filepath);
    std::string first_line;
    std::getline(input, first_line);
    std::string line;
    // got to loop x times such that x is related to restaurant index, we read lines until we find an empty line
    // empty line -> new restaurant
    int resto_counts = 0;
    if(restaurantIndex)              // if index == 0 we dont have to read lines
    {
        while (std::getline(input, line)) {
            {
                if (line == "") resto_counts++;
                if (resto_counts == restaurantIndex) break;
            }

        }
    }
    std::getline(input, line);
    // we need to parse date by reading 3 commas
    int commas = 0;
    std::string start_date;
    for (int i = 0;i < line.length();i++) {
        if (line[i] == ',') commas++;
        
        
        if (commas == 3) {
            start_date = line.substr(0, i);
            break;
        }
        
    }
    for (int i = 0;i < start_date.length();i++) {
        if (start_date[i] == ',') start_date[i] = '/';
    }

    // we need to get number of days of that month to know when to stop reading , from utilities.h


    commas = 0;
    for (int i = 1;i <= daysInMonth(extractMonthYear(start_date).first, extractMonthYear(start_date).second)-1;i++) {
        std::getline(input, line);
    }
    std::string end_date;
    for (int i = 0;i < line.length();i++) {
        if (line[i] == ',') commas++;
        
        if (commas == 3) {
            end_date = line.substr(0, i);
            break;
        }
        
    }
    for (int i = 0;i < end_date.length();i++) {
        if (end_date[i] == ',') end_date[i] = '/';
    }
    return std::make_pair(start_date, end_date);
}

int parseDailySalesData(std::string token) {   // (01-02-2023 2300)
    istringstream iss(token);
   
    char openpare, closedpare;
    string date,valuee;
    iss >> openpare >> date >> valuee >> closedpare;
    return stoi(valuee);
}



void draw_DailyCosts(std::string restaurantId) {
    std::string restaurantName = getRestauName(restaurantId, "../Restaurant Chain Management System/Database/restaurant.csv");
    int restaurantIndex = getRestaurantIndex(restaurantId, "../Restaurant Chain Management System/Database/restaurant.csv");
    if (restaurantIndex) {
        std::cout << "Restaurant Not Found";
        return;
    }
    std::pair<std::string, std::string> dates = get_dailycosts_dates("../Restaurant Chain Management System/Database/dailycosts.csv", restaurantIndex);

    std::vector<int> totalCosts = calculateTotalCosts(restaurantIndex, "../Restaurant Chain Management System/Database/dailycosts.csv");
    sf::Font font;
    font.loadFromFile("Roboto-Medium.ttf");
    // function to determine the start date from the csv file
    sf::Text start_date(dates.first, font, 15);
    start_date.setPosition(sf::Vector2f(W_WIDTH * 0.125, W_HEIGHT * 0.8));
    start_date.setFillColor(sf::Color::Black);

    sf::Text start_date_label("Start Date", font, 15);
    start_date_label.setPosition(sf::Vector2f(W_WIDTH * 0.125, W_HEIGHT * 0.8 + 20));
    start_date_label.setFillColor(sf::Color::Black);

    sf::Text end_date(dates.second, font, 15);
    end_date.setPosition(sf::Vector2f(W_WIDTH * 0.75, W_HEIGHT * 0.8));
    end_date.setFillColor(sf::Color::Black);

    sf::Text end_date_label("End Date", font, 15);
    end_date_label.setPosition(sf::Vector2f(W_WIDTH * 0.75, W_HEIGHT * 0.8 + 20));
    end_date_label.setFillColor(sf::Color::Black);

    sf::Text yaxis_label("Daily Cost (DA)", font, 15);
    yaxis_label.setPosition(sf::Vector2f(W_WIDTH * 0.125 - 45, W_HEIGHT * 0.15 - 30));
    yaxis_label.setFillColor(sf::Color::Black);


    sf::RenderWindow window(sf::VideoMode(W_WIDTH, W_HEIGHT), "Plotting Program");
    sf::VertexArray plan(sf::Lines);
    initialize_plan(plan);



    sf::VertexArray curve(sf::LinesStrip);
    draw_curve(totalCosts, curve);

    unsigned minimum = *std::min_element(totalCosts.begin(), totalCosts.end());
    unsigned maximum = *std::max_element(totalCosts.begin(), totalCosts.end());
    sf::Text min_value(std::to_string(minimum), font, 15);
    min_value.setOrigin(min_value.getGlobalBounds().getPosition().x + min_value.getGlobalBounds().width, min_value.getGlobalBounds().getPosition().y);
    min_value.setPosition(sf::Vector2f(W_WIDTH * 0.125 - 15, -static_cast<double>(minimum) / maximum * 0.6 * W_HEIGHT + W_HEIGHT * 0.8 - 8));
    min_value.setFillColor(sf::Color::Black);
    plan.append(sf::Vertex(sf::Vector2f(W_WIDTH * 0.125, -static_cast<double>(minimum) / maximum * 0.6 * W_HEIGHT + W_HEIGHT * 0.8)));
    plan.append(sf::Vertex(sf::Vector2f(W_WIDTH * 0.125 - 10, -static_cast<double>(minimum) / maximum * 0.6 * W_HEIGHT + W_HEIGHT * 0.8)));


    sf::Text max_value(std::to_string(*std::max_element(totalCosts.begin(), totalCosts.end())), font, 15);
    max_value.setFillColor(sf::Color::Black);
    max_value.setOrigin(max_value.getGlobalBounds().getPosition().x + max_value.getGlobalBounds().width, max_value.getGlobalBounds().getPosition().y);
    max_value.setPosition(sf::Vector2f(W_WIDTH * 0.125 - 15, W_HEIGHT * 0.2 - 8));

    for (int i = 0; i < curve.getVertexCount(); ++i) {
        curve[i].color = sf::Color::Blue;
    }

    for (int i = 0; i < plan.getVertexCount(); ++i) {
        plan[i].color = sf::Color::Black;
    }
    sf::Text restoID("Restaurant ID : " + restaurantId, font, 12);
    restoID.setFillColor(sf::Color::Black);
    restoID.setPosition(60, 540);

    sf::Text restoName("Restaurant Name : " + restaurantName, font, 12);
    restoName.setFillColor(sf::Color::Black);
    restoName.setPosition(60, 560);

    sf::Text curveTitle("Daily Costs of " + restaurantName + " From " + dates.first + " To " + dates.second, font, 24);
    curveTitle.setFillColor(sf::Color::Black);
    curveTitle.setPosition(68, 10);

    sf::Event event;
    while (window.isOpen()) {

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);



        window.draw(plan);
        window.draw(curve);
        window.draw(start_date);
        window.draw(start_date_label);
        window.draw(end_date);
        window.draw(end_date_label);
        window.draw(yaxis_label);
        window.draw(max_value);
        window.draw(min_value);
        window.draw(restoID);
        window.draw(restoName);
        window.draw(curveTitle);
        window.display();
    }






}
void program_run(std::string restaurantId, CurveType curveType) {
    if (curveType == DailyCosts) {
        draw_DailyCosts(restaurantId);
    }
}





