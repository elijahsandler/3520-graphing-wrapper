#include <iostream>
#include <matplot/matplot.h>
using namespace matplot;

int main(int argc, char *argv[]) {

    std::vector<double> lon = iota(-170, 10, 170);
    std::vector<double> lat =
            transform(lon, [](double x) { return 50. * cosd(3 * x); });
    std::vector<double> A = transform(
            lon, [](double lon) { return (101. + 100 * (sind(2 * lon))) / 7; });
    std::vector<double> C =
            transform(lon, [](double lon) { return cosd(4 * lon); });

    geoscatter(lat, lon, A, C)
            ->marker_style(line_spec::marker_style::upward_pointing_triangle);

    show();
    return 0;

    return 0;
}
