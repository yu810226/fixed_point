#include <iostream>

#include <sg14/fixed_point>

using sg14::fixed_point;
using sg14::make_fixed;
using sg14::make_ufixed;
using sg14::_impl::identical;


int main (void) {
    make_ufixed<4, 4> value_one{15.9375};
    make_ufixed<5, 4> value_two{15.9375};
    make_ufixed<45, 4> value_three{15.9375};
    make_ufixed<45, 19> value_four{15.9375};
    
    //Will fail on compiling
    //make_ufixed<46, 19> value_five{15.9375};
    
    //std::cout << value << std::endl; 

    //if(identical(make_fixed<7, 0>(15)/make_fixed<7, 0>(2), fixed_point<int, -7>(7.5f)))
    //    std::cout << "true" << std::endl ;
    
    //Will fail on compiling
    //make_fixed<45, 32> value{1677721534.996093750};
    
    //error: template argument for template type parameter must be a type
    //auto pi = fixed_point<45, -32>{1677721534.996093750};

    //auto pi = fixed_point<uint16_t, -14>{3.141};
    //if (pi > 3.1 && pi < 3.2) 
    //    std::cout << "true" << std::endl;

    return 0;
}
