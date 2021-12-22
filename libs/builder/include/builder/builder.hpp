#include <iostream>
#include <ostream>
#include <string>
#include <utility>

using namespace std;

class ToyBuilder;

class Toy {
public:
    friend ostream   &operator<<(ostream &os, const Toy &toyz);
    static ToyBuilder New();

private:
    Toy() = default;
    friend class ToyBuilder;
    string product_name;   // * required
    string color_hex;      // * required
    string material;       // * required
    string appearance;     // * option
};

// * Abstract Builder
class ToyBuilderAbstract {
public:
    ToyBuilderAbstract(){};
    virtual ~ToyBuilderAbstract(){};
    virtual ToyBuilderAbstract &SetProductName(string product_name) = 0;
    virtual ToyBuilderAbstract &SetColorHex(string coclor_hex)      = 0;
    virtual ToyBuilderAbstract &SetMaterial(string material)        = 0;
    virtual ToyBuilderAbstract &SetAppearance(string appearance)    = 0;
};

// * Concrete Builder
class ToyBuilder : public ToyBuilderAbstract {
public:
    ToyBuilder()  = default;
    ~ToyBuilder() = default;

    ToyBuilder &SetProductName(string product_name) override {
        this->toyz.product_name = product_name;
        return *this;
    }
    ToyBuilder &SetColorHex(string color_hex) override {
        this->toyz.color_hex = color_hex;
        return *this;
    }
    ToyBuilder &SetMaterial(string material) override {
        this->toyz.material = material;
        return *this;
    }
    ToyBuilder &SetAppearance(string appearance) override {
        this->toyz.appearance = appearance;
        return *this;
    }

    // user-defined conversion
    operator Toy &&() noexcept {
        return move(toyz);
    }

private:
    Toy toyz;
};