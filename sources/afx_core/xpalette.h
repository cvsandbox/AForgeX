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
#ifndef AFX_XPALETTE_H
#define AFX_XPALETTE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "xtypes.h"

// ===== Color palette structure =====
typedef struct _xpalette
{
    int32_t  colorsCount;
    xargb*   values;
}
xpalette;

// Allocates palette of the specified size
// Note: the *pPalette must bet either NULL or a valid previously allocated palette (if so it will be re-used if its size matches)
AFX_PUBLIC XErrorCode XPalleteAllocate( int32_t colorsCount, xpalette** pPalette );
// Frees the specified palette
AFX_PUBLIC void XPaletteFree( xpalette** pPalette );
// Copy palette's colors
AFX_PUBLIC XErrorCode XPalleteCopy( const xpalette* src, xpalette* dst );
// Copy palette's colors. If destination palette is not allocated or does not match, then it will be (re)allocated.
AFX_PUBLIC XErrorCode XPalleteClone( const xpalette* src, xpalette** dst );

#ifdef __cplusplus
}
#endif

#endif // AFX_XPALETTE_H
