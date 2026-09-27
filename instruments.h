#ifndef INSTRUMENTS_H
#define INSTRUMENTS_H

#include <ostream>
#include <string>
#include <random>
#include "quantities.h"


namespace Instruments {
    using namespace quantities;


    struct Range {
        double min;
        double max;
    };
    template <typename T>
    class Dimension {
    public:
        Sec time;
        T value;
        double rate;
        Dimension(const Sec& t, const T& v, double r) : time(t), value(v), rate(r) {}
    };

    class Instrument {
    public:
        Instrument(Range range, int accuracy, std::string id);
        template <typename T>
        Dimension<T> measure() const;
    protected:
        double rand(double min, double max) const;

        Range diap;
        int tochn;
        std::string name;
        mutable std::mt19937 gen;
    };

    class Voltmetr : public Instrument {
    public:
        using Instrument::Instrument;
        
        Dimension<Volt> measure_voltage() const;
    };


    class Ampermetr : public Instrument {
    public:
        using Instrument::Instrument;
        
        Dimension<Amper> measure_amper() const;
    };

    class Multimetr : public Instrument {
    public:
        using Instrument::Instrument;
        
        Dimension<Amper> measure_amper() const;
        Dimension<Volt> measure_voltage() const;
        Dimension<Om> measure_om() const;
    };


    template <typename T>
    Dimension<T> Instrument::measure() const {
        double v = rand(diap.min, diap.max);
        double d = (std::fabs(diap.min) + std::fabs(diap.max)) * tochn / 200.0;
        double t = rand(0.0, 10.0);
        return Dimension<T>(Sec(t), T(v), d);
    }
}

#endif 