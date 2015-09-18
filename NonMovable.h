#pragma once

/// A class that cannot be moved.
class NonMovable
{
protected:

    NonMovable () {}

    virtual ~NonMovable () {}

private:

#if __cplusplus > 199711L
    NonMovable (NonMovable&&) = delete;
    NonMovable& operator= (NonMovable&&) = delete;
#endif
};
