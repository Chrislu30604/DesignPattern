#include "builder/builder.hpp"

#include <ostream>

using namespace std;

ToyBuilder Toy::New() {
    return ToyBuilder();
}

ostream &operator<<(ostream &os, const Toy &toyz) {
    return os << "Let's propose a new toy proposal: " << endl
              << "name:                " << toyz.product_name << endl
              << "color:               " << toyz.color_hex << endl
              << "material:            " << toyz.material << endl
              << "appearance (Option): " << toyz.appearance << endl;
}
