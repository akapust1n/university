#include <Superfile.h>
#include <algorithm>
#include <cmath>

vector<double> Method::getXvalues()
{
    return x_values;
}

Method::Method(decltype(info2) info1)
{
    info2 = info1;
    double i = info2->start;
    for (; i <= info2->end; i += info2->step)
        x_values.push_back(i);
    y_values.resize(x_values.size());
}

vector<double> Pickar1::getValues()
{
    transform(x_values.begin(), x_values.end(), y_values.begin(),
        [](double x) -> double {
            double output = x * x * x / 3;
            return output;
        });

    return y_values;
}

vector<double> Pickar2::getValues()
{
    transform(x_values.begin(), x_values.end(), y_values.begin(),
        [](double x) -> double {
            double output = x * x * x / 3 * (1 + x * x * x * x / 21);
            return output;
        });

    return y_values;
}

vector<double> Pickar3::getValues()
{
    transform(x_values.begin(), x_values.end(), y_values.begin(),
        [](double x) -> double {
            double output = x * x * x / 3 * (1 + x * x * x * x / 21 + pow(x, 8) * 2 / 693 + pow(x, 12) / 19845);
            return output;
        });

    return y_values;
}

vector<double> Pickar4::getValues()
{
    transform(x_values.begin(), x_values.end(), y_values.begin(),
        [](double x) -> double {
            //   double output =  x * x * x / 3 * (1 + x * x * x *x / 21 + pow(x,8) * 2 / 693 + pow(x, 12) / 19845 );
            double output = pow(x, 3) / 3 + pow(x, 7) / 63 + pow(x, 11) / 594 + (47 * pow(x, 15)) / 498960 + (127 * pow(x, 19)) / 37328445 + (241 * pow(x, 23)) / 2982346290 + (4 * pow(x, 27)) / 3341878155 + pow(x, 31) / 109876902975;
            return output;
        });
    return y_values;
}

RungeKutt::RungeKutt(decltype(info2) info1, double _alpha)
    : Method(info1)
{
    alpha = _alpha;
}

vector<double> RungeKutt::getValues()
{
    double prevValue = 0;
    double step = x_values[1] - x_values[0];
    auto f = [](double u, double x) { return x * x + u * u; };
    y_values[0] = 0;

    for (int i = 1; i < x_values.size(); i++) {
        double x = x_values[i - 1];
        y_values[i] = prevValue + step * ((1 - alpha) * f(x, prevValue) + alpha * f(x + step / (2 * alpha), prevValue + step / (2 * alpha) * f(x, prevValue)));
        prevValue = y_values[i];
    };

    return y_values;
}

vector<double> ExplicitMethod::getValues()
{
    double prevValue = 0;
    double step = x_values[1] - x_values[0];
    auto f = [](double u, double x) { return x * x + u * u; };
    y_values[0] = 0;

    for (int i = 1; i < x_values.size(); i++) {
        double x = x_values[i - 1];
        y_values[i] = prevValue + f(x, prevValue) * step;
        prevValue = y_values[i];
    };

    return y_values;
}

vector<double> NotExplicitMethod::getValues()
{
    double prevValue = 0;
    double step = x_values[1] - x_values[0];
    //auto f = [](double u, double x){ return x*x + u*u;};
    auto sqrtD = [](double a,  double c) { return sqrt(1 - 4 * a * c); };

    y_values[0] = 0;

    for (int i = 1; i < x_values.size(); i++) {
        double b = y_values[i];
        double a = step;
        double c = y_values[i - 1] + step * x_values[i] * x_values[i];

        y_values[i] = (((+1 - sqrtD(a, c)) / (2*step)));
    };

    return y_values;
}
