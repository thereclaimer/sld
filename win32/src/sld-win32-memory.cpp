#pragma once

#include "ifb-win32.hpp"

ifb_internal const ptr 
win32::memory_reserve(
    const u64 reservation_size) {

    const ptr reservation_start = VirtualAlloc(
            NULL,
            reservation_size,
            MEM_RESERVE,
            PAGE_NOACCESS);

    return(reservation_start);
}

ifb_internal const b8 
win32::memory_release(
    const ptr reservation_start, 
    const u64 reservation_size) {

    const b8 result = VirtualFree(
        reservation_start,
        reservation_size,
        MEM_RELEASE);

    return(result);
}

ifb_internal const ptr 
win32::memory_commit(
    const ptr commit_start,
    const u64 commit_size) {

    //do the commit
    const ptr commit_result = VirtualAlloc(
        commit_start,
        commit_size,
        MEM_COMMIT,
        PAGE_READWRITE);

    //we're done
    return(commit_result);
}

ifb_internal const b8 
win32::memory_decommit(
    const ptr commit_start,
    const u64 commit_size) {

    //do the commit
    const b8 decommit_result = VirtualFree(
        commit_start,
        commit_size,
        MEM_DECOMMIT);

    //we're done
    return(decommit_result);
}