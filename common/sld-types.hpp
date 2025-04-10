#ifndef SLD_TYPES_HPP
#define SLD_TYPES_HPP

#include "sld-primitives.hpp"

using namespace sld;

/**********************************************************************************/
/* FORWARD DECLARATIONS                                                           */
/**********************************************************************************/

namespace sld {

    struct memory_t;
    struct iterator_t;

    ptr iterate(iterator_t* i);
};

/**********************************************************************************/
/* DEFINITIONS                                                                    */
/**********************************************************************************/

namespace sld {

    struct memory_t {
        addr start;
        u64  size;
    };

    struct iterator_t {
        addr start;
        u64  count;
        u32  index;
        u32  stride;
    };
};

static inline ptr
sld::iterate(iterator_t* iter) {

    const u32  offset  = iter->stride * iter->index;
    const addr address = iter->start  + offset;

    if (iter->index < iter->count) {

        ptr result = (ptr)address;
        ++iter->index;

        return(result);
    }
    return(NULL);
}

#endif //SLD_TYPES_HPP
