#pragma once
#include "animal.h"
class bird :
    public animal
{
public:
    bird(std::string name);

    void sound() override;
};

class parrot :
    public bird 
{
public:
    parrot(std::string name);

    void parody();
};

