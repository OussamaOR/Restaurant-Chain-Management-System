
#include "../Header Files/readfiles.h"
// function to parse the date
Date parseDate(const std::string &dateString)
{
    int day, month, year;
    sscanf(dateString.c_str(), "%d-%d-%d", &day, &month, &year);
    return Date(day, month, year);
}

// Function to parse SalesVec from a string
SalesVec parseSalesVec(const std::string &salesVecString)
{
    SalesVec salesVec;
    std::regex pattern("\\((\\d{2}-\\d{2}-\\d{4}) (\\d+)\\)");
    auto salesBegin = std::sregex_iterator(salesVecString.begin(), salesVecString.end(), pattern);
    auto salesEnd = std::sregex_iterator();

    for (auto it = salesBegin; it != salesEnd; ++it)
    {
        std::smatch match = *it;
        Date date = parseDate(match[1]);
        double amount = std::stod(match[2]);
        DailySale dailySale(date, amount);
        salesVec.insert_dailysale(dailySale);
    }

    return salesVec;
}

// function to read data from costs.csv file
void readCSVAndInsertIntoCostsVec(const std::string &filename, CostsVec &costsVec,int restaurantIndex)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    
    for (int i = 0; i < restaurantIndex * 29; ++i)
    {
      
        std::string line;
        std::getline(file, line);
    }
    

    for (int i = 0; i < 29; ++i)
    {
    
        std::string line;
        std::getline(file, line);
        if(i == 0) continue;
        std::istringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;

        while (getline(ss, token, ','))
        {
            tokens.push_back(token);
        }

        if (tokens.size() == 11 )
        { // Expecting 11 values in each line
            // Parse date values
            int day = std::stoi(tokens[0]);
            int month = std::stoi(tokens[1]);
            int year = std::stoi(tokens[2]);

            // Create a Date object
            Date date(day, month, year);

            // Parse cost values
            float costs[8];
            for (int i = 0; i < 8; ++i)
            {
                costs[i] = std::stof(tokens[i + 3]); // Skip the first 3 values (day, month, year)
            }

            // Create a dailyCost object
            dailyCost dailyCostNode(date, costs);

            // Insert into CostsVec
            costsVec.insert_dailycost(dailyCostNode);
        }
        else
        {
            std::cerr
                << "Invalid number of values in line: " << line << std::endl;
        }
    }

    file.close();
}

// function to read sata from cuisine.csv file
Cuisine readCuisineFromCSV(const std::string &filePath, int cuisineIndex)
{

    std::ifstream inputFile(filePath);
    if (!inputFile.is_open())
    {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return Cuisine(); // Returning an empty Cuisine object indicating failure
    }
    for (int i = 0; i < cuisineIndex; ++i)
    {
        std::string line;
        std::getline(inputFile, line);
    }

    std::string first_line;
    std::getline(inputFile, first_line);
    std::istringstream first_line_stream(first_line);
    std::string cuisineTypeStr, dailySalesStr, monthlyRatingStr;

    // Reading CuisineType
    if (!std::getline(first_line_stream, cuisineTypeStr, ','))
    {
        std::cerr << "Error reading CuisineType" << std::endl;
        return Cuisine(); // Returning an empty Cuisine object indicating failure
    }

    // Reading DailySales
    if (!std::getline(first_line_stream, dailySalesStr, ','))
    {
        std::cerr << "Error reading DailySales" << std::endl;
        return Cuisine(); // Returning an empty Cuisine object indicating failure
    }

    // Reading MonthlyRating
    if (!std::getline(first_line_stream, monthlyRatingStr))
    {
        std::cerr << "Error reading MonthlyRating" << std::endl;
        return Cuisine(); // Returning an empty Cuisine object indicating failure
    }

    // Converting CuisineType string to enum
    CuisineType cuisineType;
    if (cuisineTypeStr == "ALGERIAN")
    {
        cuisineType = ALGERIAN;
    }
    else if (cuisineTypeStr == "SYRIAN")
    {
        cuisineType = SYRIAN;
    }
    else if (cuisineTypeStr == "CHINESE")
    {
        cuisineType = CHINESE;
    }
    else if (cuisineTypeStr == "INDIAN")
    {
        cuisineType = INDIAN;
    }
    else if (cuisineTypeStr == "EUROPEAN")
    {
        cuisineType = EUROPEAN;
    }
    else
    {
        std::cerr << "Unknown CuisineType: " << cuisineTypeStr << std::endl;
        return Cuisine(); // Return an empty Cuisine object indicating failure
    }

    // Parsing the RatingsBST
    std::vector<std::pair<std::pair<int, int>, std::vector<int>>> ratingsData;
    std::smatch match;
    std::regex pattern("\\((\\d{2}-\\d{4}): \\[([\\d ]+)\\]\\)");
    while (std::regex_search(monthlyRatingStr, match, pattern))
    {
        int month = std::stoi(match[1]);
        std::vector<int> ratings;
        std::istringstream ratingsStream(match[2]);
        int rating;
        while (ratingsStream >> rating)
        {
            ratings.push_back(rating);
        }
        ratingsData.push_back({{month, 2023}, ratings});
        monthlyRatingStr = match.suffix();
    }
    ratingsBST ratingsBST;
    for (const auto &data : ratingsData)
    {
        MonthlyRating monthlyRating(data.first.first, data.first.second, data.second);
        ratingsBST.insertRating(monthlyRating);
    }

    return Cuisine(cuisineType, parseSalesVec(dailySalesStr), ratingsBST);
}

// function to read data from the restaurant csv file
void readRestaurantCSV(const std::string &filename, RestaurantHashTable &restaurantTable)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    std::string line;
    std::string first_line;
    std::getline(file, first_line);
    int cuisineIndex = 1;
    int restaurantIndex = 0;
    while (std::getline(file, line))
    {
        try
        {

            std::istringstream iss(line);
            std::string token;
            std::vector<std::string> tokens;

            while (std::getline(iss, token, ','))
            {
                tokens.push_back(token);
            }

            if (tokens.size() == 7)
            {
                int restaurantId = std::stoi(tokens[0]);
                std::string restaurantName = tokens[1];
                int numOfEmployees = std::stoi(tokens[2]);
                RestaurantType restaurantType;
                if (tokens[3] == "OWNED")
                {
                    restaurantType = OWNED;
                }
                else if (tokens[3] == "FRANCHISED")
                {
                    restaurantType = FRANCHISED;
                }
                else
                {
                    throw std::invalid_argument("Invalid restaurant type");
                }

                std::string district = tokens[5];
                std::string wilaya = tokens[4];
                std::string country = tokens[6];

                CostsVec costsvec;
                readCSVAndInsertIntoCostsVec("../../Database/dailycosts.csv", costsvec,restaurantIndex);

                Cuisine cuisine1 = readCuisineFromCSV("../../Database/cuisine.csv", cuisineIndex++);
                Cuisine cuisine2 = readCuisineFromCSV("../../Database/cuisine.csv", cuisineIndex++);
                Cuisine cuisine3 = readCuisineFromCSV("../../Database/cuisine.csv", cuisineIndex++);
                Cuisine cuisine4 = readCuisineFromCSV("../../Database/cuisine.csv", cuisineIndex++);
                Cuisine cuisine5 = readCuisineFromCSV("../../Database/cuisine.csv", cuisineIndex++);
                Restaurant restaurant(restaurantId, numOfEmployees, restaurantType, restaurantName,
                                      district, wilaya, country, costsvec,cuisine1,cuisine2,cuisine3,cuisine4,cuisine5);

                restaurantTable.insert(restaurant);
                ++restaurantIndex;
            }
            else
            {
                throw std::invalid_argument("Invalid number of columns in CSV");
            }
        }
        catch (const std::exception &e)
        {

            std::cerr << "Error while processing a line: " << e.what() << std::endl;
        }
    }

    file.close();
}