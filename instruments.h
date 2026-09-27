#ifndef INSTRUMENTS_H
#define INSTRUMENTS_H

#include <ostream>
#include <string>
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
        double sluchajnoe(double min, double max) const;

        Range diap;
        int tochn;
        std::string name;
    };

    class Voltmetr : public Instrument {
    public:
        using Instrument::Instrument;
        
        Dimension<Volt> measure_voltage() const;
    };

}

#endif 