#include <iostream>
#include <matplot/matplot.h>
#include <commata/parse_csv.hpp>
#include <commata/stored_table.hpp>
#include <algorithm> // this here should be bonus points
#include "include/geoGrapher.h"

using commata::make_stored_table_builder;
using commata::parse_csv;
using commata::stored_table;

using namespace matplot; using namespace std;

vector<string> getHeader(const stored_table& table) {
    std::vector<string> header;
    for(auto cell : table.content()[0]) {
        header.emplace_back(static_cast<string>(cell));
    }
    return header;
}

vector<string> getColumn(stored_table table, const vector<string>& header,
                         const string& colName, const int max = 100) {
    vector<string> column;

    auto it = find(header.begin(), header.end(), colName);
    if (it != header.end()) {
        int idx = distance(header.begin(), it);


        for (size_t i = 1; i < table.size(); ++i) {  // start from 1 to skip header
            if(column.size() == max) {
                return column;
            }
            const string& cell = static_cast<string>(table[i][idx]);
            column.emplace_back(cell);
            }

    } else {
        throw runtime_error("Column '" + colName + "' not found.");
    }

    return column;
}

std::vector<double> convertToDoubles(const vector<string>& vec) {
    std::vector<double> doubleVec;

    for (const std::string& str : vec) {
        // error catching :)
        std::stringstream ss(str);
        double value;
        if (ss >> value) {
            doubleVec.push_back(value);
        } else {
            // Handle invalid strings or non-numeric values
            cerr << "Error: Unable to convert vector to doubles" << endl;
        }
    }

    return doubleVec;
}

int main(int argc, char *argv[]) {

    // create an empty table
    stored_table world_cities;

    // load csv
    parse_csv(std::ifstream("../worldcities_temp.csv"),
              make_stored_table_builder(world_cities));
    // each row is just a vector of stored values

    vector<string> latStr = getColumn(world_cities, getHeader(world_cities),
                                             "lat", 150);
    vector<string> lonStr = getColumn(world_cities, getHeader(world_cities),
                                      "lng", 150);
    vector<string> popStr = getColumn(world_cities, getHeader(world_cities),
                                      "population", 150);
    vector<string> tempStr = getColumn(world_cities, getHeader(world_cities),
                                      "temp", 150);




    vector<double> lat = convertToDoubles(latStr);
    vector<double> lon = convertToDoubles(lonStr);
    vector<double> pop = convertToDoubles(popStr);
    vector<double> temp = convertToDoubles(tempStr);
    auto log_pop =
            transform(pop, [](double x) { return (log(x)/10); });

    geobubble(lat, lon);
//    hist(temp);
//    geoscatter(lat, lon);
//    title("temperature distribution for 500 most populated cities");
//    xlabel("avg temperature");
//    ylabel("count");

    show();

//    Geographer geo("../worldcities_temp.csv");
//    geo.histogram();

    return 0;
}
