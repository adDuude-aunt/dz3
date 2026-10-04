#ifndef INSTRUMENTS_H
#define INSTRUMENTS_H

#include <ostream>
#include <string>
#include <random>
#include <cmath>    
#include <stdexcept>
#include "quantities.h"


namespace Instruments {
    using namespace quantities;


    class Range {
    private:
        double r_min;
        double r_max;
    public:
        Range(double min, double max) : r_min(min), r_max(max) {
            if (min > max)
                throw std::invalid_argument("min can`t be bigger than max");
        }
        double getMin() const {return r_min;}
        double getMax() const {return r_max;}
};



    template <typename T>
    class Dimension {
    public:
        Sec time;
        T value;
        double rate;
        Dimension(const Sec& t, const T& v, double r) : time(t), value(v), rate(r) {
            if (r < 0) throw std::invalid_argument("Rate can`t be negative");
        }
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
        double v = rand(diap.getMin, diap.getMax);
        double d = (std::fabs(diap.min) + std::fabs(diap.max)) * tochn / 200.0;
        double t = rand(0.0, 10.0);
        return Dimension<T>(Sec(t), T(v), d);
    }
}

#endif 