//
// Created by elija on 12/4/2023.
//
#include <string>
#include <commata/parse_csv.hpp>
#include <commata/stored_table.hpp>
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
    vector<string> getColumn(stored_table table, const vector<string>& header,
                             const string& colName, int max = 100);
    vector<string> getHeader(const stored_table& table);
    string requestFeature(string reasonForFeature);
    bool testColumn(string col);
    int requestNumber();

public:
    explicit Geographer(const char * csv_path); // constructor
    void scatterplot();
    void histogram();
    void geobubble();
    void printHeader(bool error = false);

};

#endif //INC_3520_NN_PROJECT_GEOGRAPHER_H
