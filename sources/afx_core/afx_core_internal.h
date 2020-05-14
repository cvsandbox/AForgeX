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
#ifndef AFX_CORE_INTERNAL_H
#define AFX_CORE_INTERNAL_H

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

// ===== Define common memory management functions =====

// Allocate memory block of required size - malloc() replacement
void* XMAlloc( size_t size );
// Allocate memory block of required size and zero initialize it - calloc() replacement
void* XCAlloc( size_t count, size_t size );
// Free specified block - free() replacement
void XFree( void** memblock );


#ifdef __cplusplus
}
#endif

#endif // AFX_CORE_INTERNAL_H
