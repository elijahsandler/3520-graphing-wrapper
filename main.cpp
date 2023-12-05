#include <iostream>
#include <matplot/matplot.h>
#include <commata/parse_csv.hpp>
#include <algorithm> // this here should be bonus points
#include "lib/include/geoGrapher.h"

using namespace matplot; using namespace std;

int main(int argc, char *argv[]) {

    Geographer geo("../worldcities_temp.csv");
    geo.scatterplot();

    return 0;
}
