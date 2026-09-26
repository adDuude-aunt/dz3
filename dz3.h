#ifndef quantities_H
#define quantities_H

namespace quantities{
    class Amper {
    private:
        double value;
    public:
        Amper(double value);
        constexpr double getvalue() const;
    };

    class Volt {
    private:
        double value;
    public:
        Volt(double value);
        constexpr double getvalue() const;
    };

    class Om {
    private:
        double value;
    public:
        Om(double value);
        constexpr double getvalue() const;
    };

    class Joule {   
    private:
        double value;
    public:
        Joule(double value);
        constexpr double getvalue() const;
    };

    class Watt {
    private:
        double value;
    public:
        Watt(double value);
        constexpr double getvalue() const;
    };

    class Sec {
    private:
        double value;
    public:
        Sec(double value);
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

}


#endif