#pragma once

#include "NonCopyable.h"
#include "NonMovable.h"

/// A class that can neither be copied nor moved.
class unique : NonCopyable, NonMovable
{
protected:

    unique () {}

    virtual ~unique () {}
};
