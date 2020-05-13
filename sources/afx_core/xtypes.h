/*
    Core library of AForgeX

    Copyright (C) 2020, cvsandbox
    http://www.cvsandbox.com/contacts.html

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/

#pragma once
#ifndef AFX_XTYPES_H
#define AFX_XTYPES_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "xerrors.h"

#ifdef __cplusplus
extern "C" {
#endif

// Handy macro to bypass MSVC level 4 warning regarding unreferenced parameter
#define XUNREFERENCED_PARAMETER(param) (void)param;
    
// Min/Max macros. NOTE: never use with increments and anything else changing value
#define XMIN(a, b) (((a)<(b))?(a):(b))
#define XMAX(a, b) (((a)>(b))?(a):(b))
// Macro to make sure a value is in certain range
#define XINRANGE(a, min, max) (((a)<(max))?(((a)>(min))?(a):(min)):(max))

// Macro to get array's size in bytes
#define XARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

// ===== Define common memory management functions =====

// Allocate memory block of required size - malloc() replacement
void* XMAlloc( size_t size );
// Allocate memory block of required size and zero initialize it - calloc() replacement
void* XCAlloc( size_t count, size_t size );
// Free specified block - free() replacement
void XFree( void** memblock );

// ===== Definition of ARGB color type =====
typedef union
{
    uint32_t argb;
    struct
    {
        uint8_t b;
        uint8_t g;
        uint8_t r;
        uint8_t a;
    }
    components;
}
xargb;

#ifdef __cplusplus
}
#endif

#endif // AFX_XTYPES_H
