#include <iostream>
#include <matplot/matplot.h>
#include <commata/parse_csv.hpp>
#include <algorithm> // this here should be bonus points
#include "lib/include/geoGrapher.h"
#include <cstdlib>

using namespace matplot; using namespace std;

void ui(Geographer geo) {
    string input;
    string prompt = "Enter 'scatter', 'geobubble', 'histogram' to create plot. "
                    "\nEnter 'done' to exit. \n"
                    "Enter 'update' to run get_weather.py, but do so sparingly.\n";

    do {
        cout << prompt;
        cin >> input;
        cout << endl;

        if(input == "scatter") {geo.scatterplot();}
        else if(input == "geobubble") {geo.geobubble();}
        else if(input == "histogram") {geo.histogram();}
        else if(input == "update") {system("python ..\\get_weather.py");}
        else if(input != "done") {cout << "Invalid input." << endl;}

    } while(input != "done");
    cout << "Thank you.";
}

int main(int argc, char *argv[]) {

    Geographer geo("../worldcities_temp.csv");
    ui(geo);

    return 0;
}
