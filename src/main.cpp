#include <iostream>

#include "builder/builder.hpp"
#include "prototype/prototype.hpp"
#include "singleton/singleton.hpp"

int main(int, char **) {
    SingletonCat *cat1 = SingletonCat::GetInstance();
    SingletonCat *cat2 = SingletonCat::GetInstance();

    std::cout << "Two instance is the same ? " << (cat1 == cat2) << std::endl;

    RobotFactory   *robot_factory = new RobotFactory();
    RobotPrototype *robot         = robot_factory->GetNewRobot("Gundam");
    robot->Print();
}
