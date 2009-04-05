/*
 * File functions
 *
 * Copyright (c) 2006-2009, Joachim Metz <forensics@hoffmannbv.nl>,
 * Hoffmann Investigations. All rights reserved.
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#if !defined( _LIBBFIO_FILE_H )
#define _LIBBFIO_FILE_H

#include <common.h>
#include <narrow_string.h>
#include <types.h>
#include <wide_string.h>

#include <liberror.h>

#if defined( WINAPI ) && defined( USE_NATIVE_WINAPI_FUNCTIONS )
#include <winbase.h>
#endif

#include "libbfio_extern.h"
#include "libbfio_system_string.h"
#include "libbfio_types.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct libbfio_file_io_handle libbfio_file_io_handle_t;

struct libbfio_file_io_handle
{
	/* The name
	 */
	libbfio_system_character_t *name;

	/* The size of the name
	 */
	size_t name_size;

#if defined( WINAPI ) && defined( USE_NATIVE_WINAPI_FUNCTIONS )
	/* The file handle
	 */
	HANDLE file_handle;
#else
	/* The file descriptor
	 */
	int file_descriptor;
#endif

	/* The flags
	 */
	int flags;
};

LIBBFIO_EXTERN int libbfio_file_initialize(
                    libbfio_handle_t **handle,
                    liberror_error_t **error );

int libbfio_file_free_io_handle(
     intptr_t *io_handle,
     liberror_error_t **error );

LIBBFIO_EXTERN int libbfio_file_get_name_size(
                    libbfio_handle_t *handle,
                    size_t *name_size,
                    liberror_error_t **error );

LIBBFIO_EXTERN int libbfio_file_get_name(
                    libbfio_handle_t *handle,
                    char *name,
                    size_t name_size,
                    liberror_error_t **error );

LIBBFIO_EXTERN int libbfio_file_set_name(
                    libbfio_handle_t *handle,
                    const char *name,
                    size_t name_size,
                    liberror_error_t **error );

#if defined( HAVE_WIDE_CHARACTER_TYPE )
LIBBFIO_EXTERN int libbfio_file_get_name_size_wide(
                    libbfio_handle_t *handle,
                    size_t *name_size,
                    liberror_error_t **error );

LIBBFIO_EXTERN int libbfio_file_get_name_wide(
                    libbfio_handle_t *handle,
                    wchar_t *name,
                    size_t name_size,
                    liberror_error_t **error );

LIBBFIO_EXTERN int libbfio_file_set_name_wide(
                    libbfio_handle_t *handle,
                    const wchar_t *name,
                    size_t name_size,
                    liberror_error_t **error );
#endif

int libbfio_file_open(
     intptr_t *io_handle,
     int flags,
     liberror_error_t **error );

int libbfio_file_close(
     intptr_t *io_handle,
     liberror_error_t **error );

ssize_t libbfio_file_read(
         intptr_t *io_handle,
         uint8_t *buffer,
         size_t size,
         liberror_error_t **error );

ssize_t libbfio_file_write(
         intptr_t *io_handle,
         uint8_t *buffer,
         size_t size,
         liberror_error_t **error );

off64_t libbfio_file_seek_offset(
         intptr_t *io_handle,
         off64_t offset,
         int whence,
         liberror_error_t **error );

int libbfio_file_is_open(
     intptr_t *io_handle,
     liberror_error_t **error );

LIBBFIO_EXTERN int libbfio_file_exists(
                    const char *filename,
                    liberror_error_t **error );

#if defined( HAVE_WIDE_CHARACTER_TYPE )
LIBBFIO_EXTERN int libbfio_file_exists_wide(
                    const wchar_t *filename,
                    liberror_error_t **error );
#endif

#if defined( __cplusplus )
}
#endif

#endif

