#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
class RobotPrototype {
public:
    RobotPrototype(string product_name, string material,
                   string gender, string color)
        : product_name(product_name), material(material),
          gender(gender), color(color) {}
    virtual RobotPrototype *Clone() const = 0;   // * need to implement !
    virtual ~RobotPrototype(){};

    void         SetProductName(string product_name) { this->product_name = product_name; }
    void         SetMaterial(string material) { this->material = material; }
    void         SetGender(string gender) { this->gender = gender; }
    void         SetColor(string color) { this->color = color; }
    virtual void Print() = 0;

    friend ostream &operator<<(ostream &os, const RobotPrototype &robot);

private:
    string product_name;
    string material;
    string gender;
    string color;
};

class MetalRobot : public RobotPrototype {
public:
    MetalRobot(string product_name, string material,
               string gender, string color, int lifetime)
        : RobotPrototype(product_name, material, gender, color),
          lifetime(lifetime) {}

    ~MetalRobot() override {}
    RobotPrototype *Clone() const override {
        return new MetalRobot(*this);
    }

    void Print() override {
        cout << *this << "lifetime: " << this->lifetime << endl;
    }

private:
    int lifetime;
};

class WoodRobot : public RobotPrototype {
public:
    WoodRobot(string product_name, string material, string gender,
              string color, string wood_type)
        : RobotPrototype(product_name, material, gender, color),
          wood_type(wood_type) {}

    ~WoodRobot() override {}
    RobotPrototype *Clone() const override {
        return new WoodRobot(*this);
    }

    void Print() override {
        cout << *this << "wood_type " << this->wood_type << endl;
    }

private:
    string wood_type;
};

class RobotFactory {
public:
    RobotFactory() {
        robot_map["Gundam"]    = new MetalRobot("Gundam", "iron", "male", "white", 5);
        robot_map["Pinocchio"] = new WoodRobot("Pinocchio", "wood", "male", "brown", "fir");
    }

    ~RobotFactory() {
        delete robot_map["Gundam"];
        delete robot_map["Pinocchio"];
    }

    RobotPrototype *GetNewRobot(string name) {
        return robot_map[name]->Clone();
    }

private:
    unordered_map<string, RobotPrototype *> robot_map;
};

ostream &operator<<(ostream &os, const RobotPrototype &robot) {
    return os << "product_name: " << robot.product_name << endl
              << "material: " << robot.material << endl
              << "gender: " << robot.gender << endl
              << "color: " << robot.color << endl;
}
