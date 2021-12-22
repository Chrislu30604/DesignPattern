#include "singleton_test.hpp"
#include "singleton/singleton.hpp"

bool SingletonTestSuite::TestSingletonCat() {
    SingletonCat *cat1 = SingletonCat::GetInstance();
    SingletonCat *cat2 = SingletonCat::GetInstance();
    return cat1 == cat2;
}
