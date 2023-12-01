#include <cmath>
#include <matplot/matplot.h>
#include <iostream>
using namespace matplot; using namespace std;

int main() {

    std::vector<double> x = linspace(0, 2 * pi);
    std::vector<double> y = transform(x, [](auto x) { return sin(x); });

    cout << "about to plot" << endl;
    plot(x, y, "-o");
    cout << "plot called" << endl;
    hold(on);
    plot(x, transform(y, [](auto y) { return -y; }), "--xr");
    plot(x, transform(x, [](auto x) { return x / pi - 1.; }), "-:gs");
    plot({1.0, 0.7, 0.4, 0.0, -0.4, -0.7, -1}, "k");

    show();
    return 0;
}