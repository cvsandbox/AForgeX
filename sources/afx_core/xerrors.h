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
#ifndef AFX_XERRORS_H
#define AFX_XERRORS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef int32_t XErrorCode;

// ===== Standard error codes =====
static const XErrorCode SuccessCode                         = 0;
static const XErrorCode ErrorFailed                         = 1;  // General failure code
static const XErrorCode ErrorNullParameter                  = 2;  // Failed because of some parameters are null pointers
static const XErrorCode ErrorOutOfMemory                    = 3;  // Out of memory failure
static const XErrorCode ErrorTooSmallBuffer                 = 4;  // Amount of provided memory is not enough (given buffer is too small)
static const XErrorCode ErrorArgumentOutOfRange             = 5;  // One of the specified parameters is out of range
static const XErrorCode ErrorInvalidArgument                = 6;  // One of the specified paramters is not valid
static const XErrorCode ErrorNotImplemented                 = 7;  // The invoked API is not implemented

// ===== Error codes related to image processing functions =====
static const XErrorCode ErrorUnsupportedPixelFormat         = 11001;
static const XErrorCode ErrorImageParametersMismatch        = 11002;
static const XErrorCode ErrorImageIsTooSmall                = 11003;
static const XErrorCode ErrorImageIsTooBig                  = 11004;
static const XErrorCode ErrorInvalidImageSize               = 11005;
static const XErrorCode ErrorImagePaletteIsMissing          = 11006;

// ===== Error codes related to image encoding/decoding =====
static const XErrorCode ErrorUnknownImageFileFormat         = 12001;
static const XErrorCode ErrorFailedImageDecoding            = 12002;
static const XErrorCode ErrorFailedImageEncoding            = 12003;

#ifdef __cplusplus
}
#endif

#endif // AFX_XERRORS_H
