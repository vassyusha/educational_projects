#pragma once
#include "animal.h"
class mammal :
    public animal
{
public:
    mammal(std::string name);
    void play(const mammal& fr);

    ~mammal() {}

};

class cat :
    public mammal 
{
public:
    cat(std::string name);
    void sound() override;
    void scratch(std::string stuff = "something");

    ~cat() {}
};

class dog :
    public mammal
{
public:
    dog(std::string name);
    void sound() override;
    void guard(std::string thing = "somebody");
};

class fox :
    public mammal
{
public:
    fox(std::string name);
    void sound() override;
    void plot();
};