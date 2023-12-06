//
// Created by elija on 12/4/2023.
//
#include <iostream>
#include <matplot/matplot.h>
#include "commata/parse_csv.hpp"
#include "commata/stored_table.hpp"
#include <algorithm> // this here should be bonus points
#include "../include/geoGrapher.h"

using commata::make_stored_table_builder;
using commata::parse_csv;
using commata::stored_table;

namespace plt = matplot; using namespace std;

Geographer::Geographer(const char* csv_path) {
    // load csv
    parse_csv(std::ifstream(csv_path),
              make_stored_table_builder(table));

    header = getHeader(table);
}

vector<string> Geographer::getHeader(const stored_table& tab) {
    for(auto cell : tab.content()[0]) {
        header.emplace_back(static_cast<string>(cell));
    }
    return header;
}

vector<string> Geographer::getColumn(const string& colName, const int max) {
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
        cerr << "Column '" << colName << "' not found. Please choose a valid column:" << endl;
        this->printHeader();
    }

    return column;
}

std::vector<double> Geographer::convertToDoubles(const vector<string>& vec) {
    std::vector<double> doubleVec;

    for (const std::string& str : vec) {
        // error catching :)
        std::stringstream ss(str);
        double value;
        if (ss >> value) {
            doubleVec.push_back(value);
        } else {
            // Handle invalid strings or non-numeric values
            cerr << "Unable to convert column to doubles." << endl;
        }
    }

    return doubleVec;
}

vector<double> Geographer::scaleColumn(const vector<double> &vec) {

    auto minmax = minmax_element(vec.begin(), vec.end());
    double range = *minmax.second - *minmax.first;

    std::vector<double> scaledVector;

    for (const auto& value : vec) {
        double scaledValue = (value - *minmax.first) / (range * 10);
        scaledVector.push_back(scaledValue);
    }
    return scaledVector;
}

bool Geographer::requestBool(string message) {
    string input;

    cout << "Enter anything to " << message << ", or type 'no':" << endl;
    cin >> input;
    cout << input;

    return input != string("no");
}

void Geographer::printHeader() {
    cout << "Column names: ";

    for(auto cell : header) {
        cout << cell << ", ";
    }
    cout << endl;
}

string Geographer::requestFeature(const string& reasonForFeature) {
    bool validCol = false;
    string feat;
    do {
        printHeader();
        cout << "Select a column " << reasonForFeature << ": " << endl;
        cin >> feat;
        validCol = testColumn(feat);
    } while(!validCol);

    return feat;
}

int Geographer::requestNumber() {
    bool validInt = false;
    int num;

    do {
        cout << "Enter how many cities you'd like to graph: " << endl;
        if (cin >> num) {
            validInt = true;
        } else {
            // this block was chatgpt
            // Input is not an integer
            cin.clear(); // Clear error flag
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid integer." << endl;
        }
    } while (!validInt);

    return num;
}

bool Geographer::testColumn(const string& col) {
    auto it = find(header.begin(), header.end(), col);
    if (it != header.end()) {
        int idx = distance(header.begin(), it);

        string cell_string = string(table[1][idx]);

        std::stringstream ss(cell_string);
        double value;
        if (ss >> value) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}

void Geographer::histogram() {
    string feat = requestFeature("to be used as the feature");
    int max = requestNumber();

    vector<double> featVec = convertToDoubles(getColumn(feat, max));

    plt::hist(featVec);

    plt::title(feat + " distribution for " + to_string(max) + " most populated cities");
    plt::xlabel(feat);
    plt::ylabel("count");

    plt::show();
    getchar();
}

void Geographer::scatterplot() {
    string x_feat = requestFeature("to be graphed on the x axis");
    string y_feat = requestFeature("to be graphed on the y axis");

    int max = requestNumber();
    vector<double> x_featVec = convertToDoubles(getColumn(x_feat, max));
    vector<double> y_featVec = convertToDoubles(getColumn(y_feat, max));

    plt::scatter(x_featVec, y_featVec);
    plt::title(x_feat + " vs " + y_feat + " for " + to_string(max) + " most populated cities");
    plt::xlabel(x_feat);
    plt::ylabel(y_feat);

    plt::show();
    getchar();
}

void Geographer::geobubble() {
    int max = requestNumber();

    vector<double> lat = convertToDoubles(getColumn("lat", max));
    vector<double> lon = convertToDoubles(getColumn("lng", max));

    string size_feat = requestFeature("to be the size of the bubbles");
    vector<double> size_featVec = convertToDoubles(getColumn(size_feat, max));

    bool shouldScale = requestBool("scale " + size_feat);

    if (shouldScale) {
        vector<double> scale_featVec = scaleColumn(size_featVec);
        plt::geobubble(lat, lon, scale_featVec);
    } else {
        plt::geobubble(lat, lon, size_featVec);
    }

    plt::title("location and " + size_feat + " for " + to_string(max) + " most populated cities");

    plt::show();
    getchar();
}
