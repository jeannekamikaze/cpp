#pragma once

#ifdef NDEBUG
#define DEBUG(x)
#define DCHECK(expr)
#else  // Debug
#define DEBUG(x) x
#define DCHECK(expr)          \
  {                           \
    if (!(expr)) {            \
      throw EXCEPTION(#expr); \
    }                         \
  }
#endif
#define DCHECK_EQ(a, b) DCHECK((a) == (b))
#define DCHECK_GE(a, b) DCHECK((a) >= (b))
#define DCHECK_LT(a, b) DCHECK((a) < (b))

/// A type that cannot be copied.
struct no_copy {
  no_copy() = default;
  virtual ~no_copy() = default;

  no_copy(const no_copy&) = delete;
  no_copy& operator=(const no_copy&) = delete;
};

using NonCopyable = no_copy;  // For cases where Pascal case is preferred.

/// A type that cannot be moved.
struct no_move {
  no_move() = default;
  virtual ~no_move() = default;

  no_move(no_move&&) = delete;
  no_move& operator=(no_move&&) = delete;
};

using NonMovable = no_move;  // For cases where Pascal case is preferred.

/// A type that can neither be copied nor moved.
struct unique : no_copy, no_move {
  unique() = default;
  virtual ~unique() = default;
};

// Types

#if defined(__GNUC__) || defined(__GNUG__)  // Compiling with GNU C/C++ compiler
typedef __INT8_TYPE__ I8;
typedef __INT16_TYPE__ I16;
typedef __INT32_TYPE__ I32;
typedef __INT64_TYPE__ I64;
typedef __UINT8_TYPE__ U8;
typedef __UINT16_TYPE__ U16;
typedef __UINT32_TYPE__ U32;
typedef __UINT64_TYPE__ U64;
#else  // Visual Studio
typedef __int8 I8;
typedef __int16 I16;
typedef __int32 I32;
typedef __int64 I64;
typedef unsigned __int8 U8;
typedef unsigned __int16 U16;
typedef unsigned __int32 U32;
typedef unsigned __int64 U64;
#endif

typedef unsigned uint;
