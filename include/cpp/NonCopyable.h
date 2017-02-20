#pragma once

/// A class that cannot be copied.
struct NonCopyable
{
    NonCopyable () {}

    virtual ~NonCopyable () {}

    NonCopyable (const NonCopyable&) = delete;
    NonCopyable& operator= (const NonCopyable&) = delete;
};
