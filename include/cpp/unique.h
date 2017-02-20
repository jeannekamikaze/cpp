#pragma once

#include "NonCopyable.h"
#include "NonMovable.h"

/// A class that can neither be copied nor moved.
struct unique : NonCopyable, NonMovable
{
    unique () {}

    virtual ~unique () {}
};
