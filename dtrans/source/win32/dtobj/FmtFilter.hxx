/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */

#ifndef INCLUDED_DTRANS_SOURCE_WIN32_DTOBJ_FMTFILTER_HXX
#define INCLUDED_DTRANS_SOURCE_WIN32_DTOBJ_FMTFILTER_HXX

#include <sal/types.h>

#include <com/sun/star/uno/Sequence.hxx>

#if defined _MSC_VER
#pragma warning(push,1)
#endif
#if !defined WIN32_LEAN_AND_MEAN
# define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#include <objidl.h>
#if defined _MSC_VER
#pragma warning(pop)
#endif

/*------------------------------------------------------------------------
    input:
    aMetaFilePict - a sequence of bytes containing a METAFILEPICT struct
------------------------------------------------------------------------*/
css::uno::Sequence< sal_Int8 > WinMFPictToOOMFPict( css::uno::Sequence< sal_Int8 >& aMetaFilePict );
css::uno::Sequence< sal_Int8 > WinENHMFPictToOOMFPict( HENHMETAFILE hEnhMetaFile );

/*------------------------------------------------------------------------
    input:
    aByteStream - a sequence of bytes containing a openoffice metafile
                  picture with a leading METAFILEHEADER
------------------------------------------------------------------------*/
HMETAFILEPICT OOMFPictToWinMFPict( css::uno::Sequence< sal_Int8 > const & aOOMetaFilePict );
HENHMETAFILE  OOMFPictToWinENHMFPict( css::uno::Sequence< sal_Int8 > const & aOOMetaFilePict );

/*------------------------------------------------------------------------
    input:
    aWinDIB - sequence of bytes containing a windows device independent
              bitmap
------------------------------------------------------------------------*/
css::uno::Sequence< sal_Int8 > WinDIBToOOBMP( const css::uno::Sequence< sal_Int8 >& aWinDIB );

/*------------------------------------------------------------------------
    input:
    aWinDIB - sequence of bytes containing a windows bitmap handle
------------------------------------------------------------------------*/
css::uno::Sequence< sal_Int8 > WinBITMAPToOOBMP( HBITMAP );

/*------------------------------------------------------------------------
    input:
    aOOBmp - sequence of bytes containing a openoffice bitmap
    May contain CF_DIBV5 or CF_DIB, but removing the BITMAPFILEHEADER
    is always the same size
------------------------------------------------------------------------*/
css::uno::Sequence< sal_Int8 > OOBmpToWinDIB( css::uno::Sequence< sal_Int8 >& aOOBmp );

/*------------------------------------------------------------------------
    input:
    aTextHtml - a sequence of text/html which will be converted to the
    HTML Format; the HTML Format has header before the real html data
    the Format is described in the MSDN Library under HTML Clipboard
    Format
------------------------------------------------------------------------*/
css::uno::Sequence< sal_Int8 > TextHtmlToHTMLFormat( css::uno::Sequence< sal_Int8 > const & aTextHtml );

/**
    Return a FileList in which Windows Shell Links (lnk) are resolved.
    If for what ever reason a resolution is not possible leave the
    original lnk file.
*/
css::uno::Sequence< sal_Int8 > CF_HDROPToFileList(HGLOBAL hGlobal);

#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
