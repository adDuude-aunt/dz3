#ifndef quantities_H
#define quantities_H

namespace quantities{
    class Amper {
    private:
        double value;
    public:
        constexpr double getvalue() const;
    };

    class Volt {
    private:
        double value;
    public:
        constexpr double getvalue() const;
    };

    class Om {
    private:
        double value;
    public:
        constexpr double getvalue() const;
    };

    class Joule {   
    private:
        double value;
    public:
        constexpr double getvalue() const;
    };

    class Watt {
    private:
        double value;
    public:
        constexpr double getvalue() const;
    };

    class Sec {
    private:
        double value;
    public:
        constexpr double getvalue() const;
    };

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


}


#endif