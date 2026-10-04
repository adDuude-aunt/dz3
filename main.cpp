#include <iostream>
#include "quantities.h"
#include "instruments.h"

using namespace quantities;
using namespace Instruments;

void test_literals() {
    auto v = 220_V;
    auto i = 15_mA;
    auto r = 135_Ohm;
    auto t = 5_s;
    std::cout << v.getvalue() << " V\n";
    std::cout << i.getvalue() << " A\n";
    std::cout << r.getvalue() << " Ohm\n";
    std::cout << t.getvalue() << " s\n";

    std::cout << "\n";
}

void test_laws() {
    auto u = 220_V;
    auto i = 2_mA;
    Om r = u / i;
    std::cout << "R = U/I = " << r.getvalue() << " Ohm\n";

    Watt p = u * i;
    std::cout << "P = U*I = " << p.getvalue() << " W\n";

    auto t = 10_s;
    Joule e = p * t;
    std::cout << "E = P*t = " << e.getvalue() << " J\n";


    std::cout << "\n";
}

void test_instruments() {
    Range Vr(0.0, 250.0);
    Voltmetr Vm(Vr, 1, "VM.1212");
    auto mv = Vm.measure_voltage();
    std::cout << "Voltmetr: " << mv.value.getvalue() << "\n" << "V, rate=" << mv.rate << "\n" << "time=" << mv.time.getvalue() << " s";
    std::cout << "\n";

    Range Ar(0.0, 10.0);
    Ampermetr Am(Ar, 2, "AM-1");
    auto ma = Am.measure_amper();
    std::cout << "Ampermetr: " << ma.value.getvalue() << "\n" << "A, rate=" << ma.rate << "\n";
    std::cout << "\n";

    Range Mr(0.0, 1000.0);
    Multimetr Mm(Mr, 1, "MM-1");
    auto mo = Mm.measure_om();
    std::cout << "Multimetr: " << mo.value.getvalue() << "\n" << "Ohm, rate=" << mo.rate << "\n";
    std::cout << "\n";
}

void test_invariants() {

    try { 
        Range bad(10.0, 2.0); 
    } 
    catch (const std::invalid_argument& e) {
        std::cout << "Range: " << e.what() << "\n";
    }

    try { 
        Om bad(-1.0);
    } 
    catch (const std::invalid_argument& e) {
        std::cout << "Om: " << e.what() << "\n";
    }

    try {
        Sec bad(-1.0);
    } 
    catch (const std::invalid_argument& e) {
        std::cout << "Sec: " << e.what() << "\n";
    }

    try {
        Range good(0, 10);
        Instrument bad(good, -3, "bad");
    } 
    catch (const std::invalid_argument& e) {
        std::cout << "Instrument: " << e.what() << "\n";
    }

    std::cout << "\n";
}

int main() {
    test_literals();
    std::cout << "\n---------------------------------\n";
    test_laws();
    std::cout << "\n---------------------------------\n";
    test_instruments();
    std::cout << "\n---------------------------------\n";
    test_invariants();
    std::cout << "\n---------------------------------\n";
    return 0;
}