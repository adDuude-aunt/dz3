#ifndef quantities_H
#define quantities_H

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

    Amper::Amper(double value)
    {
        this->value = value;
    }

    Volt::Volt(double value)
    {
        this->value = value;
    }

    Om::Om(double value)
    {
        this->value = value;
    }

    Joule::Joule(double value)
    {
        this->value = value;
    }

    Watt::Watt(double value)
    {
        this->value = value;
    }

    Sec::Sec(double value)
    {
        this->value = value;
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

    constexpr Volt operator""_V(unsigned long long x) 
    { return {static_cast<double>(x)}; }

    constexpr Om operator""_Ohm(unsigned long long x) 
    { return {static_cast<double>(x)}; }

    constexpr Joule operator""_J(unsigned long long x) 
    { return {static_cast<double>(x)}; }

    constexpr Watt operator""_W(unsigned long long x) 
    { return {static_cast<double>(x)}; }

    constexpr Sec operator""_s(unsigned long long x) 
    { return {static_cast<double>(x)}; }

}


#endif