#pragma once

#include "ifb-win32-api-memory.cpp"
#include "ifb-win32-api-system.cpp"
#include "ifb-win32-api-monitor.cpp"
#include "ifb-win32-api-window.cpp"
#include "ifb-win32-api-user-input.cpp"
#include "ifb-win32-api-registry.cpp"
// #include "ifb-win32-file.cpp"

namespace ifb::win32 {

    ifb_global platform_api_t _platform_api = {

        //----------------------------------------
        // system
        {
            ifb::win32::system_get_info_cpu,     // IFBPlatformSystemGetInfoCPU
            ifb::win32::system_get_info_memory,  // IFBPlatformSystemGetInfoMemory
            ifb::win32::system_time_ms,          // IFBPlatformSystemTimeMS
            ifb::win32::system_sleep,            // IFBPlatformSystemSleep
            ifb::win32::system_debug_print       // IFBPlatformSystemDebugPrint
        },
        //----------------------------------------
        // memory
        {
            ifb::win32::memory_reserve,          // IFBPlatformMemoryReserve
            ifb::win32::memory_release,          // IFBPlatformMemoryRelease
            ifb::win32::memory_commit,           // IFBPlatformMemoryCommit
            ifb::win32::memory_decommit          // IFBPlatformMemoryDecommit
        },
        //----------------------------------------
        // threads
        {
            NULL,                               // IFBPlatformThreadSize
            NULL,                               // IFBPlatformThreadCreate
            NULL,                               // IFBPlatformThreadDestroy
            NULL,                               // IFBPlatformThreadAssignCores
            NULL,                               // IFBPlatformThreadWake
            NULL                                // IFBPlatformThreadSleep
        },
        //----------------------------------------
        // window
        {
            (platform_api_window_size_f)           ifb::win32::window_size,
            (platform_api_window_create_f)         ifb::win32::window_create,
            (platform_api_window_destroy_f)        ifb::win32::window_destroy,
            (platform_api_window_process_events_f) ifb::win32::window_process_events,
            (platform_api_window_swap_buffers_f)   ifb::win32::window_swap_buffers,
            (platform_api_window_show_f)           ifb::win32::window_show
        },
        //----------------------------------------
        // monitor
        {
            ifb::win32::monitor_count,           // IFBPlatformMonitorCount
            ifb::win32::monitor_info             // IFBPlatformMonitorInfo
        }
    };

    inline platform_api_t* platform_api(void) { return(&_platform_api); }
};
