#ifndef QUANTITIES_H
#define QUANTITIES_H



#include <stdexcept>


namespace quantities{
    class Amper {
    private:
        double value;
    public:
        constexpr Amper(double value);
        constexpr double getvalue() const;
    };

    class Volt {
    private:
        double value;
    public:
        constexpr Volt(double value);
        constexpr double getvalue() const;
    };

    class Om {
    private:
        double value;
    public:
        constexpr Om(double value);
        constexpr double getvalue() const;
    };

    class Joule {   
    private:
        double value;
    public:
        constexpr Joule(double value);
        constexpr double getvalue() const;
    };

    class Watt {
    private:
        double value;
    public:
        constexpr Watt(double value);
        constexpr double getvalue() const;
    };

    class Sec {
    private:
        double value;
    public:
        constexpr Sec(double value);
        constexpr double getvalue() const;
    };

    constexpr Amper::Amper(double value) : value(value) {}

    constexpr Volt::Volt(double value)   : value(value) {}

    constexpr Om::Om(double value)       : value(value) {
        if (value < 0) throw std::invalid_argument("Om can`t be negative");
    }

    constexpr Joule::Joule(double value) : value(value) {
        if (value < 0) throw std::invalid_argument("Joule can`t be negative");
    }

    constexpr Watt::Watt(double value)   : value(value) {
        if (value < 0) throw std::invalid_argument("Watt can`t be negative");
    }

    constexpr Sec::Sec(double value)     : value(value) {
        if (value < 0) throw std::invalid_argument("Sec can`t be negative");
    }







    constexpr double Amper::getvalue() const {
     return this->value; 
    }
    constexpr double Volt::getvalue() const {
        return this->value;
    }
    constexpr double Om::getvalue() const {
        return this->value; 
    }
    constexpr double Joule::getvalue() const {
        return this->value; 
    }
    constexpr double Watt::getvalue() const {
       return this->value; 
    }
    constexpr double Sec::getvalue() const {
        return this->value; 
    }



    constexpr Amper operator""_mA(unsigned long long x) 
    { return {static_cast<double>(x)}; }
    constexpr Amper operator""_mA(long double x) {
    return {static_cast<double>(x)}; }

    constexpr Volt operator""_V(unsigned long long x) 
    { return {static_cast<double>(x)}; }
    constexpr Volt operator""_V(long double x) {
    return {static_cast<double>(x)}; }

    constexpr Om operator""_Ohm(unsigned long long x) 
    { return {static_cast<double>(x)}; }
    constexpr Om operator""_Ohm(long double x) {
    return {static_cast<double>(x)}; }

    constexpr Joule operator""_J(unsigned long long x) 
    { return {static_cast<double>(x)}; }
    constexpr Joule operator""_J(long double x) {
    return {static_cast<double>(x)}; }

    constexpr Watt operator""_W(unsigned long long x) 
    { return {static_cast<double>(x)}; }
    constexpr Watt operator""_W(long double x) {
    return {static_cast<double>(x)}; }

    constexpr Sec operator""_s(unsigned long long x) 
    { return {static_cast<double>(x)}; }
    constexpr Sec operator""_s(long double x) {
    return {static_cast<double>(x)}; }



// закон ома U=R*I
    constexpr Om operator/(const Volt& u, const Amper& i) {
    return Om(u.getvalue() / i.getvalue());
    }

    constexpr Volt operator*(const Amper& i, const Om& r) {
    return Volt(i.getvalue() * r.getvalue());
    }
    constexpr Volt operator*(const Om& r, const Amper& i) {
       return Volt(r.getvalue() * i.getvalue());
    }


// E=P*t

    constexpr Joule operator*(const Watt& p, const Sec& t) {
    return Joule(p.getvalue() * t.getvalue());
    }
    constexpr Joule operator*(const Sec& t, const Watt& p) {
        return Joule(t.getvalue() * p.getvalue());
    }

    constexpr Sec operator/(const Joule& e, const Watt& p) {
    return Sec(e.getvalue() / p.getvalue());
    }

    constexpr Watt operator/(const Joule& e, const Sec& t) {
    return Watt(e.getvalue() / t.getvalue());
    }


// P=U*I

    constexpr Watt operator*(const Volt& u, const Amper& i) {
    return Watt(u.getvalue() * i.getvalue());
    }
    constexpr Watt operator*(const Amper& i, const Volt& u) {
        return Watt(i.getvalue() * u.getvalue());
    }

    constexpr Amper operator/(const Watt& p, const Volt& u) {
    return Amper(p.getvalue() / u.getvalue());
    }

    constexpr Volt operator/(const Watt& p, const Amper& i) {
    return Volt(p.getvalue() / i.getvalue());
    }





}


#endif