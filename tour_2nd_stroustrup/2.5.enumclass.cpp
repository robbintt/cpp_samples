
#include <iostream>

using namespace std;

//enum class Color { red, blue, green };
//enum class Traffic_light { green, yellow, red };

int main() {

    enum class Color { red, blue, green };
    enum class Traffic_light { green, yellow, red };

    //Color col = Color::red;
    //Traffic_light light = Traffic_light::red;

    // does not work... wtf
    //Color x = Color{5};
    Color x = Color::red;

    Color y { Color::red };

    // allowed as of c++17
    Color z{2};

    // doesn't work, as expected
    //Color aa = 2;
};
