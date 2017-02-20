#pragma once

/// A class that cannot be moved.
struct NonMovable
{
    NonMovable () {}

    virtual ~NonMovable () {}

    NonMovable (NonMovable&&) = delete;
    NonMovable& operator= (NonMovable&&) = delete;
};
