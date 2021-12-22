// Copyright 2021 chrislu
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#include <iostream>
#include <string>
#include <unordered_map>

class CatPrototype {
public:
    CatPrototype(){};
    CatPrototype(std::string _feed, std::string _colorhex)
        : feed(_feed), colorhex(_colorhex) {}

    void SayMeow() {
        std::cout << "[" << this->name << "]: meow" << std::endl;
    }
    void SetName(std::string _name) {
        this->name = _name;
    }
    void SetFeed(std::string _feed) {
        this->feed = _feed;
    }
    void SetColor(std::string _colorhex) {
        this->colorhex = _colorhex;
    }

    virtual ~CatPrototype(){};
    virtual CatPrototype *Clone() const = 0;

private:
    std::string name;
    std::string feed;
    std::string colorhex;
};

class BlackCat : public CatPrototype {
public:
    BlackCat(std::string _feed, std::string _colorhex)
        : CatPrototype(_feed, _colorhex) {}

    ~BlackCat() override {}

    CatPrototype *Clone() const override {
        return new BlackCat(*this);
    }
};

class SiameseCat : public CatPrototype {
public:
    SiameseCat(std::string _feed, std::string _colorhex)
        : CatPrototype(_feed, _colorhex) {}

    ~SiameseCat() override {}

    CatPrototype *Clone() const override {
        return new SiameseCat(*this);
    }
};

class SnowshoeCat : public CatPrototype {
public:
    SnowshoeCat(std::string _feed, std::string _colorhex)
        : CatPrototype(_feed, _colorhex) {}

    ~SnowshoeCat() override {}

    CatPrototype *Clone() const override {
        return new SnowshoeCat(*this);
    }
};

class CatHouse {
public:
    CatHouse() {
        cat_map["blackcat"]    = new BlackCat("xisha", "black");
        cat_map["siamesecat"]  = new SiameseCat("farmina", "orange");
        cat_map["snowshoecat"] = new SnowshoeCat("nourish", "white");
    }

    ~CatHouse() {
        delete cat_map["blackcat"];
        delete cat_map["siamesecat"];
        delete cat_map["snowshoecat"];
    }

    CatPrototype *GetNewCat(std::string name) {
        return cat_map[name]->Clone();
    }

private:
    std::unordered_map<std::string, CatPrototype *> cat_map;
};
