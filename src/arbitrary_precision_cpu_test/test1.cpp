#include <iostream>

#include <sg14/fixed_point>

using sg14::fixed_point;
using sg14::make_fixed;
using sg14::make_ufixed;
using sg14::_impl::identical;


int main (void) {
    make_ufixed<4, 4> value{15.9375};
    
    //error: no support for print out
    //std::cout << value << std::endl; 

    if(identical(make_fixed<7, 0>(15)/make_fixed<7, 0>(2), fixed_point<int, -7>(7.5f)))
        std::cout << "true" << std::endl ;
    
    auto pi = fixed_point<uint16_t, -14>{3.141};
    if (pi > 3.1 && pi < 3.2) 
        std::cout << "true" << std::endl;

    return 0;
}
