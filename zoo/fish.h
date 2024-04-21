#pragma once
#include "animal.h"
class fish :
    public animal
{
public:
    fish(std::string name);
    void sound() override;
    void swim();
};

