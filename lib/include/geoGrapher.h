//
// Created by elija on 12/4/2023.
//
#include <string>
#include "commata/parse_csv.hpp"
#include "commata/stored_table.hpp"
using namespace std;
using commata::make_stored_table_builder;
using commata::parse_csv;
using commata::stored_table;

#ifndef INC_3520_NN_PROJECT_GEOGRAPHER_H
#define INC_3520_NN_PROJECT_GEOGRAPHER_H

class Geographer {
private:
    stored_table table;
    vector<string> header;
    vector<double> convertToDoubles(const vector<string>& vec);
    vector<string> getColumn(const string& colName, int max = 100);
    vector<double> scaleColumn(const vector<double>& vec);
    bool requestBool(string message);
    vector<string> getHeader(const stored_table& table);
    string requestFeature(const string& reasonForFeature);
    bool testColumn(const string& col);
    int requestNumber();

public:
    explicit Geographer(const char * csv_path); // constructor
    void scatterplot();
    void histogram();
    void geobubble();
    void printHeader();

};

#endif //INC_3520_NN_PROJECT_GEOGRAPHER_H
