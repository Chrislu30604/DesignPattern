#include <iostream>

#include "builder/builder.hpp"
#include "prototype/prototype.hpp"
#include "singleton/singleton.hpp"

int main(int, char **) {
    SingletonCat *cat1 = SingletonCat::GetInstance();
    SingletonCat *cat2 = SingletonCat::GetInstance();

    std::cout << "Two instance is the same ? " << (cat1 == cat2) << std::endl;

    CatHouse     *cat_house   = new CatHouse();
    CatPrototype *blackcat    = cat_house->GetNewCat("blackcat");
    CatPrototype *siamesecat  = cat_house->GetNewCat("siamesecat");
    CatPrototype *snowshoecat = cat_house->GetNewCat("snowshoecat");

    Toy toyz = Toy::New()
                   .SetProductName("Toyz")
                   .SetColorHex("#41E194")
                   .SetMaterial("metal")
                   .SetAppearance("Round & Fat");
    std::cout << toyz << endl;
}
