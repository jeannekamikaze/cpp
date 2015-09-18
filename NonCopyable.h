#pragma once

/// A class that cannot be copied.
class NonCopyable
{
protected:

    NonCopyable () {}

    virtual ~NonCopyable () {}

private:

    NonCopyable (const NonCopyable&) = delete;
    NonCopyable& operator= (const NonCopyable&) = delete;
};
