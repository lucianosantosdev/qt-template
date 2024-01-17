#pragma once

class Derived;

/**
 * @brief The Foo class uses Derived.
 */
class Foo
{
public:
    Foo(Derived& derived);

private:

    Derived& m_derived; ///< Reference to Derived.
};
