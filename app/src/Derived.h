#pragma once

#include "Base.h"

/**
 * @brief The Derived class inhirits from Base and implements foo().
 */
class Derived: public Base
{
public:
    Derived();
    // Base interface
public:
    void foo();
};
