#include "ifb-win32.hpp"

#pragma once

/**********************************************************************************/
/* FORWARD DECLARATIONS                                                           */
/**********************************************************************************/

namespace ifb_win32 {
    
    //validation
    const ifb::b8 file_ro_validate_request(const IFBFileRequestReadOnly* file_ro_request);
    const ifb::b8 file_ro_validate_context(const IFBFileContext*         file_ro_context);

    //memory
    IFBFileContext* file_ro_request_load_context     (const IFBFileRequestReadOnly* file_ro_request);
    IFBFileBuffer*  file_ro_request_load_buffer      (const IFBFileRequestReadOnly* file_ro_request);
    ifb::utf8*        file_ro_request_load_file_path   (const IFBFileRequestReadOnly* file_ro_request);
    IFBHNDFile*     file_ro_request_load_file_handle (const IFBFileRequestReadOnly* file_ro_request);

    //completion routines
    void file_ro_async_callback_read  (DWORD error_code, DWORD bytes_transfered, LPOVERLAPPED overlapped_ptr);
    void file_rw_async_callback_read  (DWORD error_code, DWORD bytes_transfered, LPOVERLAPPED overlapped_ptr);
    void file_rw_async_callback_write (DWORD error_code, DWORD bytes_transfered, LPOVERLAPPED overlapped_ptr);
};

/**********************************************************************************/
/* READ ONLY                                                                      */
/**********************************************************************************/

ifb_internal const ifb::u32
ifb_win32::file_ro_context_size(
    void) {

    const ifb::u32 context_size = ifb_macro_align_size_struct(IFBWin32FileReadOnly);
    return(context_size);
}

ifb_internal const ifb::b8
ifb_win32::file_ro_open(
    IFBFileRequestReadOnly* file_ro_request) {

    //validate the request
    ifb::b8 result = ifb_win32::file_ro_validate_request(file_ro_request);
    if (!result) return(false);

    //get the file path information
    const ifb::u32    file_count       = file_ro_request->file_count;
    const ifb::u32    file_path_stride = file_ro_request->file_path_stride;
    const ifb::utf8*  file_path_buffer = ifb_win32::file_ro_request_load_file_path (file_ro_request);
    IFBFileContext* file_context     = ifb_win32::file_ro_request_load_context   (file_ro_request);

    //loop through the contexts and open the handles
    for (
        ifb::u32 file_index = 0;
               file_index < file_count;
             ++file_index) {

        //get the file path
        const ifb::u32   win32_file_path_offset = file_index * file_path_stride;
        const ifb::utf8* win32_file_path_buffer = &file_path_buffer[win32_file_path_offset];
        
        //get the context
        IFBFileContext& current_context_ref = file_context[file_index];

        //validate the context
        result &= ifb_win32::file_ro_validate_context(&current_context_ref);

        //open the file handle
        const HANDLE win32_file_handle = CreateFile(
            win32_file_path_buffer,
            win32_file_access,
            win32_file_share_mode,
            win32_file_security_attributes,
            win32_file_creation,
            win32_file_flags,
            win32_file_template);

        //make sure the handle is valid
        result &= (win32_file_handle != INVALID_HANDLE_VALUE); 
    
        //update the file
        win32_file->win32_file_handle = win32_file_handle;
        win32_file->win32_overlapped  = {0};
    }

    //we're done
    return(result);
}

ifb_internal const ifb::b8
ifb_win32::file_ro_read_async(
    IFBFileRequestReadOnly* file_ro_request) {

    //validate the request
    ifb::b8 result = ifb_win32::file_ro_validate_request(file_ro_request);
    if (!result) return(false);

    const ifb::u32            file_count         = file_ro_request->file_count;
    IFBFileReadOnlyContext* file_array_context = file_ro_request->pointers.context;
    IFBFileBuffer*          file_array_buffer  = file_ro_request->pointers.buffer;

    LPOVERLAPPED_COMPLETION_ROUTINE win32_file_completion_routine = ifb_win32::file_ro_async_callback_read; 

    for (
        ifb::u32 file_index = 0;
               file_index < file_count;
             ++file_index) {

        //get the current context and buffer
        IFBFileReadOnlyContext& ref_file_context = file_array_context [file_index];
        IFBFileBuffer&          ref_file_buffer  = file_array_buffer  [file_index];

        //get the win32 file
        IFBWin32FileReadOnly* win32_file = ifb_win32::file_ro_validate_context(file_context_ref);
    
        //file read info
        const HANDLE win32_file_handle           = win32_file->win32_file_handle;
        LPVOID       win32_file_read_buffer      = ref_file_buffer.start;
        const DWORD  win32_file_read_buffer_size = ref_file_buffer.size;
        LPOVERLAPPED win32_file_overlapped       = &win32_file->win32_overlapped;

        //update the offset
        win32_file_overlapped->Offset = ref_file_buffer.file_offset;

        //read the file
        result &= ReadFileEx(
            win32_file_handle,
            win32_file_read_buffer,
            win32_file_read_buffer_size,
            win32_file_overlapped,
            win32_file_completion_routine);
    }

    //we're done
    return(result);   
}

ifb_internal const ifb::b8
ifb_win32::file_ro_read_immediate(
          IFBFileReadOnly* file_read_only,
    const ifb::u32           read_buffer_size,
          ifb::byte*         read_buffer_ptr,
    const ifb::u32           file_offset) {

    //sanity check
    ifb::b8 result = true;
    result &= (file_read_only   != NULL);
    result &= (read_buffer_size != 0);
    result &= (read_buffer_ptr  != NULL);
    result &= (file_offset      <  file_read_only->size);
    result &= (!file_read_only->platform_lock);
    if (!result) return(false);

    //get the file info
    IFBWin32FileInfoReadOnly* ptr_file_info = ifb_win32::file_read_only_get_win32_info(file_read_only);
    ifb_macro_assert(ptr_file_info);

    //do the read
    result &= ReadFile(
        ptr_file_info->win32_file_handle,  // file handle
        (LPVOID)read_buffer_ptr,           // read buffer pointer
        read_buffer_size,                  // read buffer size
        &file_read_only->bytes_read,       // bytes actually read
        &ptr_file_info->win32_overlapped); // win32 overlapped

    //make sure the bytes read is the bytes requested
    result &= (file_read_only->bytes_read == read_buffer_size);

    //we're done
    return(result);
}

ifb_internal const ifb::b8
ifb_win32::file_ro_close(
    IFBFileReadOnly* file_read_only) {

    ifb::b8 result = true;

    //sanity check
    ifb_macro_assert(file_read_only);

    //get the file info
    IFBWin32FileInfoReadOnly* ptr_file_info = ifb_win32::file_read_only_get_win32_info(file_read_only);
    ifb_macro_assert(ptr_file_info);

    //tell win32 to close the file
    result &= CloseHandle(ptr_file_info->win32_file_handle);
    if (!result) return(false);

    //clear the stack
    result &= ifb_stack::reset(file_read_only->platform_context_stack);

    //we're done
    return(result);
}

/**********************************************************************************/
/* COMPLETION ROUTINES                                                            */
/**********************************************************************************/

ifb_internal void
ifb_win32::file_async_completion_routine_ro_read(
    DWORD        error_code,
    DWORD        bytes_transfered,
    LPOVERLAPPED overlapped_ptr) {

    //get the file pointer
    IFBFileReadOnly* ptr_file = ifb_win32::file_read_only_from_overlapped(overlapped_ptr);
    ifb_macro_assert(ptr_file);

    //make sure there was an operation in progress
    ifb_macro_assert(ptr_file->platform_lock);

    //update the file
    ptr_file->platform_lock = false;
    ptr_file->bytes_read    = bytes_transfered; 
}

ifb_internal void
ifb_win32::file_async_completion_routine_rw_read(
    DWORD        error_code,
    DWORD        bytes_transfered,
    LPOVERLAPPED overlapped_ptr) {

    //get the file pointer
    IFBFileReadOnly* ptr_file = ifb_win32::file_read_only_from_overlapped(overlapped_ptr);
    ifb_macro_assert(ptr_file);

    //make sure there was an operation in progress
    ifb_macro_assert(ptr_file->platform_lock);

    //update the file
    ptr_file->platform_lock = false;
    ptr_file->bytes_read    = bytes_transfered; 
}

ifb_internal void
ifb_win32::file_async_completion_routine_rw_write(
    DWORD        error_code,
    DWORD        bytes_transfered,
    LPOVERLAPPED overlapped_ptr) {

    //get the file pointer
    IFBFileReadOnly* ptr_file = ifb_win32::file_read_only_from_overlapped(overlapped_ptr);
    ifb_macro_assert(ptr_file);

    //make sure there was an operation in progress
    ifb_macro_assert(ptr_file->platform_lock);

    //update the file
    ptr_file->platform_lock = false;
    ptr_file->bytes_read    = bytes_transfered; 
}

/**********************************************************************************/
/* INTERNAL                                                                        */
/**********************************************************************************/

inline const ifb::b8
ifb_win32::file_ro_validate_request(
    const IFBFileRequestReadOnly* file_ro_request) {
    
    if (!file_ro_request) return(false);

    ifb::b8 is_valid = true;
    is_valid &= (file_ro_request->pointers.platform_context != NULL);
    is_valid &= (file_ro_request->pointers.file_table_index != NULL);
    is_valid &= (file_ro_request->file_count != 0);
    return(is_valid);
}

inline IFBFileContext*
ifb_win32::file_ro_request_load_context(
    const IFBFileRequestReadOnly* file_ro_request) {

    const ifb::u32  offset      = file_ro_request->handles.context.offset;
    const ifb::addr start       = file_ro_request->memory_start;
    const ifb::addr result_addr = start + offset;

    IFBFileContext* result_ptr = (IFBFileContext*)result_addr;
    return(result_ptr);
}

inline IFBFileBuffer*
ifb_win32::file_ro_request_load_buffer(
    const IFBFileRequestReadOnly* file_ro_request) {

    const ifb::u32  offset      = file_ro_request->handles.buffer.offset;
    const ifb::addr start       = file_ro_request->memory_start;
    const ifb::addr result_addr = start + offset;

    IFBFileBuffer* result_ptr = (IFBFileBuffer*)result_addr;
    return(result_ptr);
}

inline ifb::utf8*
ifb_win32::file_ro_request_load_file_path(
    const IFBFileRequestReadOnly* file_ro_request) {

    const ifb::u32  offset      = file_ro_request->handles.file_path.offset;
    const ifb::addr start       = file_ro_request->memory_start;
    const ifb::addr result_addr = start + offset;

    ifb::utf8* result_ptr = (ifb::utf8*)result_addr;
    return(result_ptr);
}

inline IFBHNDFile*
ifb_win32::file_ro_request_load_file_handle(
    const IFBFileRequestReadOnly* file_ro_request) {

    const ifb::u32  offset      = file_ro_request->handles.file_handle.offset;
    const ifb::addr start       = file_ro_request->memory_start;
    const ifb::addr result_addr = start + offset;

    IFBHNDFile* result_ptr = (IFBHNDFile*)result_addr;
    return(result_ptr);
}

