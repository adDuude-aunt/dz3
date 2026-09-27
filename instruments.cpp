#include "instruments.h"
#include <random>

using namespace quantities;
using namespace Instruments;

Instrument::Instrument(Range range, int accuracy, std::string id) : diap(range),tochn(accuracy),name(id),gen(std::random_device{}())  {}

double Instrument::rand(double min, double max) const {
    std::uniform_real_distribution<double> dist(min, max);
    return dist(gen);
}

Dimension<Amper> Ampermetr::measure_amper() const {
    return measure<Amper>();
}

Dimension<Volt> Voltmetr::measure_voltage() const {
    return measure<Volt>();
}

Dimension<Amper> Multimetr::measure_amper() const {
    return measure<Amper>();
}

Dimension<Volt> Multimetr::measure_voltage() const {
    return measure<Volt>();
}

Dimension<Om> Multimetr::measure_om() const {
    return measure<Om>();
}