#include <iostream>
#include <matplot/matplot.h>
#include <commata/parse_csv.hpp>
#include <commata/stored_table.hpp>

using commata::make_stored_table_builder;
using commata::parse_csv;
using commata::stored_table;

using namespace matplot; using namespace std;

int main(int argc, char *argv[]) {

    // create an empty table
    stored_table world_cities;

    // load csv
    parse_csv(std::ifstream("../worldcities.csv"), make_stored_table_builder(world_cities));

    world_cities.content();

    vector<double> lat {};
    vector<double> lon {};
    vector<double> pop {};
    vector<double> capital {};


//    auto log_tsunami_height =
//            transform(tsunami_height, [](double x) { return log(x + 2); });
//
//    geobubble(tsunami_lat, tsunami_lon, log_tsunami_height);
//
//    show();
    return 0;
}
