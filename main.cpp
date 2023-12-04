#include <cmath>
#include <matplot/matplot.h>
#include <iostream>
#include <cstdlib>
using namespace matplot; using namespace std;

int main() {
    const char* runPyCmd = "python ../frugally-deep/keras_export/convert_model.py regression_nn.keras fdeep_model.json";
    int result = system(runPyCmd);

    return result;
}

#include <iostream>
#include <fstream>
#include <commata/parse_csv.hpp>
#include <commata/stored_table.hpp>

//using commata::make_stored_table_builder;
//using commata::parse_csv;
//using commata::stored_table;
//using namespace std;
//
//int main() {
//
//    stored_table colorTable;
//
//    parse_csv(ifstream("../color_srgb.csv"), make_stored_table_builder(colorTable));
//
//    cout << colorTable.size()-1 << " colors loaded" << endl;
//
//
//
//    return 0;
//}