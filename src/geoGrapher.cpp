//
// Created by elija on 12/4/2023.
//
#include <iostream>
#include <matplot/matplot.h>
#include <commata/parse_csv.hpp>
#include <commata/stored_table.hpp>
#include <algorithm> // this here should be bonus points
#include "../include/geoGrapher.h"

using commata::make_stored_table_builder;
using commata::parse_csv;
using commata::stored_table;

using namespace matplot; using namespace std;

Geographer::Geographer(const char* csv_path) {
    // load csv
    parse_csv(std::ifstream(csv_path),
              make_stored_table_builder(table));

    header = getHeader(table);
}

vector<string> Geographer::getHeader(const stored_table& table) {
    std::vector<string> header;
    for(auto cell : table.content()[0]) {
        header.emplace_back(static_cast<string>(cell));
    }
    return header;
}

vector<string> Geographer::getColumn(stored_table table, const vector<string>& header,
                         const string& colName, const int max) {
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

void Geographer::printHeader(bool error) {
    cout << "Column names: ";
    if(error) {
        for(auto cell : getHeader(table)) {
            cerr << cell << ", ";
        }
        cout << endl;
    } else {
        for(auto cell : getHeader(table)) {
            cout << cell << ", ";
        }
        cout << endl;
    }



}

string Geographer::requestFeature(string reasonForFeature) {
    bool validCol = false;
    string feat;
    do {
        printHeader(false);
        cout << "Select a column " << reasonForFeature << " -  ";
        cin >> feat; cout << endl;
        validCol = testColumn(feat);
    } while(!validCol);

    return feat;
}

int Geographer::requestNumber() {
    bool validInt = false;
    int num;

    do {
        cout << "Enter how many cities you'd like to graph -  ";
        if (cin >> num) {
            // Input is an integer
            validInt = true;
        } else {
            // this block was chatgpt
            // Input is not an integer
            cin.clear(); // Clear error flag
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid integer.\n";
        }
    } while (!validInt);

    return num;
}

bool Geographer::testColumn(string col) {
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

    vector<double> featVec = convertToDoubles(getColumn(table, header, feat, max));
    hist(featVec);
    title(feat + " distribution for" + (string) reinterpret_cast<const char *>(max) + "most populated cities");
    xlabel(feat);
    ylabel("count");

    show();
}



