#ifndef IFB_WIN32_HPP
#define IFB_WIN32_HPP

#include <Windows.h>
#include <ifb.hpp>
#include <ifb-engine.hpp>

using namespace ifb;

namespace ifb {

/**********************************************************************************/
/* REGISTRY                                                                       */
/**********************************************************************************/

struct win32_reg_key_u32_t {
    HKEY key;
    u32  value;
};

namespace win32 {

    //read only
    const b8 registry_key_open_read_only_classes_root   (const LPCSTR key_path, HKEY& key_ref);
    const b8 registry_key_open_read_only_current_user   (const LPCSTR key_path, HKEY& key_ref);
    const b8 registry_key_open_read_only_local_machine  (const LPCSTR key_path, HKEY& key_ref);
    const b8 registry_key_open_read_only_users          (const LPCSTR key_path, HKEY& key_ref);
    const b8 registry_key_open_read_only_current_config (const LPCSTR key_path, HKEY& key_ref);

    //close
    const b8 registry_key_close(const HKEY key);

    //values
    const b8 registry_key_read_value_u32           (const HKEY key, const LPCSTR value_name, u32& value_ref);
    const b8 registry_key_read_value_cpu_speed_mhz (win32_reg_key_u32_t& key_u32);
};

#define IFB_WIN32_SYSTEM_REGKEY_PROCESSOR_0     R"(HARDWARE\DESCRIPTION\System\CentralProcessor\0)" 
#define IFB_WIN32_SYSTEM_REGKEY_PROCESSOR_0_MHZ "~MHz"

#define ifb_win32_macro_registry_key_cpu_0(key_ref)                         ifb::win32::registry_key_open_read_only_local_machine(IFB_WIN32_SYSTEM_REGKEY_PROCESSOR_0, key_ref)
#define ifb_win32_macro_registry_key_cpu_0_value_u32_mhz(key,value_u32_ref) ifb::win32::registry_key_read_value_u32(key,IFB_WIN32_SYSTEM_REGKEY_PROCESSOR_0_MHZ,value_u32_ref)

/**********************************************************************************/
/* SYSTEM                                                                         */
/**********************************************************************************/

namespace win32 {

    const b8   system_get_info_cpu    (platform_system_info_cpu_t*    cpu_info);
    const b8   system_get_info_memory (platform_system_info_memory_t* memory_info);
    const u64  system_time_ms         (void);
          void system_sleep           (const u32   ms);
          void system_debug_print     (const utf8* debug_string);
};

/**********************************************************************************/
/* MEMORY                                                                         */
/**********************************************************************************/

namespace win32 {

    const ptr memory_reserve  (const u64 reservation_size);
    const b8  memory_release  (const ptr reservation_start, const u64 reservation_size);
    const ptr memory_commit   (const ptr commit_start,      const u64 commit_size);
    const b8  memory_decommit (const ptr commit_start,      const u64 commit_size);
};

/**********************************************************************************/
/* WINDOW                                                                         */
/**********************************************************************************/

struct win32_window_t : platform_window_t {
    struct {
        struct {
            HWND window;
            HDC  device;
        } handles;
        struct {
            WPARAM w;
            LPARAM l;
        } message_params;
    } win32;
};
 
namespace win32 {

    const u32 window_size           (void);
    const b8  window_create         (win32_window_t* window);
    const b8  window_destroy        (win32_window_t* window);
    const b8  window_process_events (win32_window_t* window);
    const b8  window_swap_buffers   (win32_window_t* window);
    const b8  window_show           (win32_window_t* window);
};

/**********************************************************************************/
/* MONITOR                                                                        */
/**********************************************************************************/

namespace win32 {

    const u32 monitor_count (void);
    
    const b8
    monitor_info(
        const u32                 monitor_count,
              platform_monitor_t* monitor_array);

    BOOL CALLBACK monitor_enum_callback_count (HMONITOR handle,HDC device_context, LPRECT rect_ptr, LPARAM data_ptr);
    BOOL CALLBACK monitor_enum_callback_info  (HMONITOR handle,HDC device_context, LPRECT rect_ptr, LPARAM data_ptr);
};

/**********************************************************************************/
/* FILES                                                                          */
/**********************************************************************************/

struct win32_file_readonly {
    HANDLE     win32_file_handle;
    OVERLAPPED win32_overlapped;
};

struct win32_file_readwrite {
    HANDLE     win32_file_handle;
    OVERLAPPED win32_overlapped;
};

namespace win32 {

    //read only
    const u32 file_ro_context_size     (void);
    const b8  file_ro_open             (platform_file_request_t* file_ro_request);
    const b8  file_ro_read_async       (platform_file_request_t* file_ro_request);
    const u32 file_ro_read_immediate   (platform_file_request_t* file_ro_request);
    const b8  file_ro_close            (platform_file_request_t* file_ro_request);
    
    //read write
    const u32 file_rw_context_size     (void);
    const b8  file_rw_open             (platform_file_request_t* file_rw_request);
    const u32 file_rw_read_immediate   (platform_file_request_t* file_rw_request);
    const b8  file_rw_read_async       (platform_file_request_t* file_rw_request);
    const u32 file_rw_write_immediate  (platform_file_request_t* file_rw_request);
    const b8  file_rw_write_async      (platform_file_request_t* file_rw_request);
    const b8  file_rw_close            (platform_file_request_t* file_rw_request);
};

/**********************************************************************************/
/* USER INPUT                                                                     */
/**********************************************************************************/

namespace win32 {

    const key_code_t user_input_keycode(const u32 win32_keycode); 

}; //namespace win32
}; //namespace ifb

#endif //IFB_WIN32_HPP