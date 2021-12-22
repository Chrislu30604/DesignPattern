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
#include <cstring>
#include <mutex>

class SingletonCat {
public:
    SingletonCat(const SingletonCat &rhs) = delete;             // no cloneable
    SingletonCat operator=(const SingletonCat &rhs) = delete;   // no assignable

    static SingletonCat *GetInstance();

private:
    SingletonCat()  = default;
    ~SingletonCat() = default;
    static SingletonCat  *instance;
    static std::once_flag once_flag;
};
