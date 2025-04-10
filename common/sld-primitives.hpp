#ifndef SLD_PRIMITIVES_HPP
#define SLD_PRIMITIVES_HPP

#include <cstdint>

#define NULL 0

namespace sld {

    //signed integers
    typedef int8_t   s8;
    typedef int16_t  s16;
    typedef int32_t  s32;
    typedef int64_t  s64;

    //unsigned integer 
    typedef uint8_t  u8;
    typedef uint16_t u16;
    typedef uint32_t u32;
    typedef uint64_t u64;

    //floats
    typedef float    f32;
    typedef double   f64;

    //booleans
    typedef int8_t   b8;
    typedef int16_t  b16;
    typedef int32_t  b32;
    typedef int64_t  b64;

    //chars
    typedef char     c8;
    typedef wchar_t  c16;

    //memory
    typedef void*    ptr;
    typedef intptr_t addr;
    typedef int8_t   byte;
};


#endif //SLD_PRIMITIVES_HPP
