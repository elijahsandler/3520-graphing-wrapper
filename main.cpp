#include <cmath>
#include <matplot/matplot.h>
#include <iostream>
using namespace matplot; using namespace std;

int main() {

    std::vector<double> x = linspace(0, 2 * pi);
    std::vector<double> y = transform(x, [](auto x) { return sin(x); });


    cout << "about to plot" << endl;
    plot(x, y, "-");
    cout << "plot called" << endl;

    show();
    return 0;
}