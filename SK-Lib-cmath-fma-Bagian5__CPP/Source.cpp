#pragma warning(disable:4996)
#pragma fenv_access(on)

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cfenv>
#include <conio.h>

/*
    Source by CPPReference
    Modified For Learn by RK
    I.D.E : VS2019
*/

int main() {
    // demo perbedaan antara fma() dan operator bawaan
    double in = 0.1;
    std::cout << "0.1 double is " << std::setprecision(23) << in
        << " (" << std::hexfloat << in << std::defaultfloat << ")\n"
        << "0.1*10 is 1.0000000000000000555112 (0x8.0000000000002p-3), "
        << "or 1.0 if rounded to double\n";
    double expr_result = 0.1 * 10 - 1;
    double fma_result = fma(0.1, 10, -1);
    std::cout << "0.1 * 10 - 1 = " << expr_result
        << " : 1 subtracted after intermediate rounding\n"
        << "fma(0.1, 10, -1) = " << std::setprecision(6) << fma_result << " ("
        << std::hexfloat << fma_result << std::defaultfloat << ")\n\n";

    // fma digunakan dalam aritmatika double-double
    double high = 0.1 * 10;
    double low = fma(0.1, 10, -high);
    std::cout << "in double-double arithmetic, 0.1 * 10 is representable as " << high << " + " << low << "\n\n";

    // penanganan error / error handling
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "fma(+Inf, 10, -Inf) = " << std::fma(INFINITY, 10, -INFINITY) << '\n';

    if (std::fetestexcept(FE_INVALID)) {
        std::cout << "    FE_INVALID raised\n";
    }
        
    _getch();
    return 0;
}