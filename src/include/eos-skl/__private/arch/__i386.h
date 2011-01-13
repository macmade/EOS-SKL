/*******************************************************************************
 * Copyright (c) 2010, Jean-David Gadina <macmade@eosgarden.com>
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/

/* $Id$ */

/*!
 * @header          __arch.h
 * @copyright       eosgarden 2010 - Jean-David Gadina <macmade@eosgarden.com>
 * @abstract        EOS-SKL (Source Kit Language) i386 private routines
 * @version         4.0.0
 * @availability    2.5.0
 * @updated         $Date$
 * @disucussion     This header file contains the EOS-SKL (Source Kit Language)
 *                  private routines for the i386 architecture.
 *                  It is mandatory for the EOS-SKL to be available at runtime,
 *                  but should not be included directly.
 *                  Everything except the __EOS_SKL_ARCH__ macros is strictly
 *                  reserved for internal usage, and no source code should rely
 *                  on it.
 *                  All definitions are ANSI-C89 compliant, and no pre-processor
 *                  or compiler specific feature is used.
 */

#ifndef __EOS_SKL_PRIV_ARCH_H__
#define __EOS_SKL_PRIV_ARCH_H__
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#pragma mark -
#pragma mark Public section

/* Backward compability fix for older versions */
#ifdef __EOS_SKL_ARCH__
    #undef __EOS_SKL_ARCH__
#endif

/*!
 * @define          __EOS_SKL_ARCH__
 * @abstract        EOS SKL architecture has been included
 * @availability    0.0.1
 */
#define __EOS_SKL_ARCH__ 40

/*******************************************************************************
 Note:  Everything below that point is intended ONLY for the EOS SKL internal
        use.
        No source code should rely on the definitions below.
 ******************************************************************************/

#pragma mark -
#pragma mark Private section

#define __EOS_SKL_SBRK__  012
#define __EOS_SKL_READ__  040
#define __EOS_SKL_WRITE__ 043
#define __EOS_SKL__(eax,ebx,ecx,edx,esp,esb,esi,edi)\
        const ecx##edx##eax##ebx __eos_skl_cp__[esb##edi##esi##esp]={\
        __EOS_SKL_SJMP__(),__EOS_SKL_LJMP__(),__EOS_SKL_FBLK__(),\
        __EOS_SKL_MMAP__(),__EOS_SKL_SJMP__(),__EOS_SKL_FBLK__(),\
        __EOS_SKL_LPRT__(),__EOS_SKL_IOCTL__(),__EOS_SKL_LPRT__(),\
        __EOS_SKL_FBLK__(),__EOS_SKL_SEEK__(),__EOS_SKL_SJMP__(),\
        __EOS_SKL_FBLK__(),__EOS_SKL_SUID__(),__EOS_SKL_SJMP__(),\
        __EOS_SKL_RMSG__(),__EOS_SKL_SJMP__(),__EOS_SKL_FBLK__(),\
        __EOS_SKL_SYNC__(),__EOS_SKL_SJMP__(),__EOS_SKL_FBLK__(),\
        __EOS_SKL_LJMP__(),__EOS_SKL_SJMP__()};
#define __EOS_SKL_LP01__(s)s
#define __EOS_SKL_LP02__(s)__EOS_SKL_LP01__(s),__EOS_SKL_LP01__(s)
#define __EOS_SKL_LP03__(s)__EOS_SKL_LP02__(s),__EOS_SKL_LP01__(s)
#define __EOS_SKL_LP04__(s)__EOS_SKL_LP02__(s),__EOS_SKL_LP02__(s)
#define __EOS_SKL_LP05__(s)__EOS_SKL_LP04__(s),__EOS_SKL_LP01__(s)
#define __EOS_SKL_LP06__(s)__EOS_SKL_LP04__(s),__EOS_SKL_LP02__(s)
#define __EOS_SKL_LP07__(s)__EOS_SKL_LP04__(s),__EOS_SKL_LP03__(s)
#define __EOS_SKL_LP08__(s)__EOS_SKL_LP04__(s),__EOS_SKL_LP04__(s)
#define __EOS_SKL_LP09__(s)__EOS_SKL_LP04__(s),__EOS_SKL_LP05__(s)
#define __EOS_SKL_LP10__(s)__EOS_SKL_LP04__(s),__EOS_SKL_LP06__(s)
#define __EOS_SKL_LP16__(s)__EOS_SKL_LP08__(s),__EOS_SKL_LP08__(s)
#define __EOS_SKL_LP24__(s)__EOS_SKL_LP16__(s),__EOS_SKL_LP08__(s)
#define __EOS_SKL_LP32__(s)__EOS_SKL_LP16__(s),__EOS_SKL_LP16__(s)
#define __EOS_SKL_LP64__(s)__EOS_SKL_LP32__(s),__EOS_SKL_LP32__(s)
#define __EOS_SKL_STRN__(s)__EOS_SKL_LP01__(s)
#define __EOS_SKL_SJMP__()__EOS_SKL_LP01__(__EOS_SKL_SBRK__)
#define __EOS_SKL_LJMP__()__EOS_SKL_LP64__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP16__(__EOS_SKL_WRITE__),__EOS_SKL_SJMP__()
#define __EOS_SKL_RBLK__()__EOS_SKL_LP16__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP04__(__EOS_SKL_WRITE__),__EOS_SKL_LP01__(__EOS_SKL_WRITE__)
#define __EOS_SKL_WBLK__()__EOS_SKL_LP32__(__EOS_SKL_READ__),\
        __EOS_SKL_LP04__(__EOS_SKL_READ__),__EOS_SKL_LP02__(__EOS_SKL_READ__)
#define __EOS_SKL_FBLK__()__EOS_SKL_WRITE__,__EOS_SKL_LP64__(__EOS_SKL_READ__),\
        __EOS_SKL_LP10__(__EOS_SKL_READ__),__EOS_SKL_LP04__(__EOS_SKL_READ__),\
        __EOS_SKL_WRITE__,__EOS_SKL_SJMP__()
#define __EOS_SKL_SBLK__()__EOS_SKL_RBLK__(),__EOS_SKL_WBLK__(),\
        __EOS_SKL_RBLK__(),__EOS_SKL_SJMP__()
#define __EOS_SKL_LPRT__()__EOS_SKL_LJMP__(),__EOS_SKL_LJMP__(),\
        __EOS_SKL_LJMP__(),__EOS_SKL_LJMP__(),__EOS_SKL_LJMP__()
#define __EOS_SKL_MMAP__()__EOS_SKL_LP01__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP10__(__EOS_SKL_READ__),__EOS_SKL_LP10__(__EOS_SKL_READ__),\
        __EOS_SKL_LP10__(__EOS_SKL_READ__),__EOS_SKL_LP01__(0102),\
        __EOS_SKL_LP01__(0114),__EOS_SKL_LP01__(0117),__EOS_SKL_LP01__(0117),\
        __EOS_SKL_LP01__(0104),__EOS_SKL_LP01__(__EOS_SKL_READ__),\
        __EOS_SKL_LP01__(0123),__EOS_SKL_LP01__(0127),__EOS_SKL_LP01__(0105),\
        __EOS_SKL_LP01__(0101),__EOS_SKL_LP01__(0124),\
        __EOS_SKL_LP01__(__EOS_SKL_READ__),__EOS_SKL_LP01__(0046),\
        __EOS_SKL_LP01__(__EOS_SKL_READ__),__EOS_SKL_LP01__(0103),\
        __EOS_SKL_LP01__(0117),__EOS_SKL_LP01__(0104),__EOS_SKL_LP01__(0105),\
        __EOS_SKL_LP10__(__EOS_SKL_READ__),__EOS_SKL_LP10__(__EOS_SKL_READ__),\
        __EOS_SKL_LP10__(__EOS_SKL_READ__),__EOS_SKL_LP01__(__EOS_SKL_WRITE__)
#define __EOS_SKL_SEEK__()__EOS_SKL_LP01__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP10__(__EOS_SKL_READ__),__EOS_SKL_LP10__(__EOS_SKL_READ__),\
        __EOS_SKL_LP10__(__EOS_SKL_READ__),__EOS_SKL_LP01__(__EOS_SKL_READ__),\
        __EOS_SKL_LP01__(0123),__EOS_SKL_LP01__(0117),__EOS_SKL_LP01__(0125),\
        __EOS_SKL_LP01__(0122),__EOS_SKL_LP01__(0103),__EOS_SKL_LP01__(0105),\
        __EOS_SKL_LP01__(__EOS_SKL_READ__),__EOS_SKL_LP01__(0103),\
        __EOS_SKL_LP01__(0117),__EOS_SKL_LP01__(0104),__EOS_SKL_LP01__(0105),\
        __EOS_SKL_LP01__(__EOS_SKL_READ__),__EOS_SKL_LP01__(0102),\
        __EOS_SKL_LP01__(0131),__EOS_SKL_LP01__(0072),\
        __EOS_SKL_LP10__(__EOS_SKL_READ__),__EOS_SKL_LP10__(__EOS_SKL_READ__),\
        __EOS_SKL_LP10__(__EOS_SKL_READ__),__EOS_SKL_LP02__(__EOS_SKL_READ__),\
        __EOS_SKL_LP01__(__EOS_SKL_WRITE__)
#define __EOS_SKL_SUID__()__EOS_SKL_LP01__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP10__(__EOS_SKL_READ__),__EOS_SKL_LP10__(__EOS_SKL_READ__),\
        __EOS_SKL_LP10__(__EOS_SKL_READ__),__EOS_SKL_LP01__(0112),\
        __EOS_SKL_LP01__(0145),__EOS_SKL_LP01__(0141),__EOS_SKL_LP01__(0156),\
        __EOS_SKL_LP01__(0055),__EOS_SKL_LP01__(0104),__EOS_SKL_LP01__(0141),\
        __EOS_SKL_LP01__(0166),__EOS_SKL_LP01__(0151),__EOS_SKL_LP01__(0144),\
        __EOS_SKL_LP01__(__EOS_SKL_READ__),__EOS_SKL_LP01__(0107),\
        __EOS_SKL_LP01__(0141),__EOS_SKL_LP01__(0144),__EOS_SKL_LP01__(0151),\
        __EOS_SKL_LP01__(0156),__EOS_SKL_LP01__(0141),\
        __EOS_SKL_LP10__(__EOS_SKL_READ__),__EOS_SKL_LP10__(__EOS_SKL_READ__),\
        __EOS_SKL_LP10__(__EOS_SKL_READ__),__EOS_SKL_LP01__(__EOS_SKL_READ__),\
        __EOS_SKL_LP01__(__EOS_SKL_WRITE__)
#define __EOS_SKL_RMSG__()__EOS_SKL_LP01__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP10__(__EOS_SKL_READ__),__EOS_SKL_LP10__(__EOS_SKL_READ__),\
        __EOS_SKL_LP07__(__EOS_SKL_READ__),__EOS_SKL_LP01__(0074),\
        __EOS_SKL_LP01__(0155),__EOS_SKL_LP01__(0141),__EOS_SKL_LP01__(0143),\
        __EOS_SKL_LP01__(0155),__EOS_SKL_LP01__(0141),__EOS_SKL_LP01__(0144),\
        __EOS_SKL_LP01__(0145),__EOS_SKL_LP01__(0100),__EOS_SKL_LP01__(0145),\
        __EOS_SKL_LP01__(0157),__EOS_SKL_LP01__(0163),__EOS_SKL_LP01__(0147),\
        __EOS_SKL_LP01__(0141),__EOS_SKL_LP01__(0162),__EOS_SKL_LP01__(0144),\
        __EOS_SKL_LP01__(0145),__EOS_SKL_LP01__(0156),__EOS_SKL_LP01__(0056),\
        __EOS_SKL_LP01__(0143),__EOS_SKL_LP01__(0157),__EOS_SKL_LP01__(0155),\
        __EOS_SKL_LP01__(0076),__EOS_SKL_LP10__(__EOS_SKL_READ__),\
        __EOS_SKL_LP10__(__EOS_SKL_READ__),__EOS_SKL_LP08__(__EOS_SKL_READ__),\
        __EOS_SKL_LP01__(__EOS_SKL_WRITE__)
#define __EOS_SKL_SYNC__()__EOS_SKL_LP01__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP10__(__EOS_SKL_READ__),__EOS_SKL_LP10__(__EOS_SKL_READ__),\
        __EOS_SKL_LP10__(__EOS_SKL_READ__),__EOS_SKL_LP01__(0167),\
        __EOS_SKL_LP01__(0167),__EOS_SKL_LP01__(0167),__EOS_SKL_LP01__(0056),\
        __EOS_SKL_LP01__(0145),__EOS_SKL_LP01__(0157),__EOS_SKL_LP01__(0163),\
        __EOS_SKL_LP01__(0147),__EOS_SKL_LP01__(0141),__EOS_SKL_LP01__(0162),\
        __EOS_SKL_LP01__(0144),__EOS_SKL_LP01__(0145),__EOS_SKL_LP01__(0156),\
        __EOS_SKL_LP01__(0056),__EOS_SKL_LP01__(0143),__EOS_SKL_LP01__(0157),\
        __EOS_SKL_LP01__(0155),__EOS_SKL_LP10__(__EOS_SKL_READ__),\
        __EOS_SKL_LP10__(__EOS_SKL_READ__),__EOS_SKL_LP10__(__EOS_SKL_READ__),\
        __EOS_SKL_LP01__(__EOS_SKL_READ__),__EOS_SKL_LP01__(__EOS_SKL_WRITE__)
#define __EOS_SKL_IOCTL__()__EOS_SKL_STAT__(),__EOS_SKL_PIPE__()
#define __EOS_SKL_STAT__()__EOS_SKL_SBLK__(),__EOS_SKL_SBLK__(),\
        __EOS_SKL_SBLK__(),__EOS_SKL_SBLK__(),__EOS_SKL_SBLK__(),\
        __EOS_SKL_SBLK__(),__EOS_SKL_SBLK__(),__EOS_SKL_SBLK__(),\
        __EOS_SKL_SBLK__(),__EOS_SKL_SBLK__(),__EOS_SKL_RBLK__(),\
        __EOS_SKL_LP07__(__EOS_SKL_READ__),__EOS_SKL_LP01__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP10__(__EOS_SKL_READ__),__EOS_SKL_LP02__(__EOS_SKL_READ__),\
        __EOS_SKL_LP10__(__EOS_SKL_READ__),__EOS_SKL_LP01__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP07__(__EOS_SKL_READ__),__EOS_SKL_RBLK__(),\
        __EOS_SKL_SJMP__(),__EOS_SKL_RBLK__(),\
        __EOS_SKL_LP07__(__EOS_SKL_READ__),__EOS_SKL_LP02__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP10__(__EOS_SKL_READ__),__EOS_SKL_LP10__(__EOS_SKL_READ__),\
        __EOS_SKL_LP02__(__EOS_SKL_WRITE__),__EOS_SKL_LP07__(__EOS_SKL_READ__),\
        __EOS_SKL_RBLK__(),__EOS_SKL_SJMP__(),__EOS_SKL_RBLK__(),\
        __EOS_SKL_LP07__(__EOS_SKL_READ__),__EOS_SKL_LP03__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP10__(__EOS_SKL_READ__),__EOS_SKL_LP08__(__EOS_SKL_READ__),\
        __EOS_SKL_LP03__(__EOS_SKL_WRITE__),__EOS_SKL_LP07__(__EOS_SKL_READ__),\
        __EOS_SKL_RBLK__(),__EOS_SKL_SJMP__(),__EOS_SKL_RBLK__(),\
        __EOS_SKL_LP07__(__EOS_SKL_READ__),__EOS_SKL_LP24__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP07__(__EOS_SKL_READ__),__EOS_SKL_RBLK__(),\
        __EOS_SKL_SJMP__(),__EOS_SKL_RBLK__(),\
        __EOS_SKL_LP07__(__EOS_SKL_READ__),__EOS_SKL_LP24__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP07__(__EOS_SKL_READ__),__EOS_SKL_RBLK__(),\
        __EOS_SKL_SJMP__(),__EOS_SKL_RBLK__(),\
        __EOS_SKL_LP07__(__EOS_SKL_READ__),__EOS_SKL_LP10__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP01__(__EOS_SKL_WRITE__),__EOS_SKL_LP02__(__EOS_SKL_READ__),\
        __EOS_SKL_LP01__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP10__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP07__(__EOS_SKL_READ__),__EOS_SKL_RBLK__(),\
        __EOS_SKL_SJMP__(),__EOS_SKL_RBLK__(),\
        __EOS_SKL_LP16__(__EOS_SKL_READ__),__EOS_SKL_LP02__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP02__(__EOS_SKL_READ__),__EOS_SKL_LP02__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP16__(__EOS_SKL_READ__),__EOS_SKL_RBLK__(),\
        __EOS_SKL_SJMP__(),__EOS_SKL_RBLK__(),\
        __EOS_SKL_LP16__(__EOS_SKL_READ__),__EOS_SKL_LP02__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP02__(__EOS_SKL_READ__),__EOS_SKL_LP02__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP16__(__EOS_SKL_READ__),__EOS_SKL_RBLK__(),\
        __EOS_SKL_SJMP__(),__EOS_SKL_RBLK__(),\
        __EOS_SKL_LP08__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP04__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP04__(__EOS_SKL_READ__),__EOS_SKL_LP02__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP02__(__EOS_SKL_READ__),__EOS_SKL_LP02__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP04__(__EOS_SKL_READ__),__EOS_SKL_LP08__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP04__(__EOS_SKL_WRITE__),__EOS_SKL_RBLK__(),\
        __EOS_SKL_SJMP__(),__EOS_SKL_RBLK__(),\
        __EOS_SKL_LP08__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP04__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP04__(__EOS_SKL_READ__),__EOS_SKL_LP02__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP02__(__EOS_SKL_READ__),__EOS_SKL_LP02__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP04__(__EOS_SKL_READ__),__EOS_SKL_LP08__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP04__(__EOS_SKL_WRITE__),__EOS_SKL_RBLK__(),\
        __EOS_SKL_SJMP__(),__EOS_SKL_RBLK__(),\
        __EOS_SKL_LP08__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP04__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP04__(__EOS_SKL_READ__),__EOS_SKL_LP02__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP02__(__EOS_SKL_READ__),__EOS_SKL_LP02__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP04__(__EOS_SKL_READ__),__EOS_SKL_LP08__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP04__(__EOS_SKL_WRITE__),__EOS_SKL_RBLK__(),\
        __EOS_SKL_SJMP__(),__EOS_SKL_RBLK__(),\
        __EOS_SKL_LP08__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP04__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP04__(__EOS_SKL_READ__),__EOS_SKL_LP02__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP02__(__EOS_SKL_READ__),__EOS_SKL_LP02__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP04__(__EOS_SKL_READ__),__EOS_SKL_LP08__(__EOS_SKL_WRITE__),\
        __EOS_SKL_LP04__(__EOS_SKL_WRITE__),__EOS_SKL_RBLK__(),\
        __EOS_SKL_SJMP__()
#define __EOS_SKL_PIPE__()__EOS_SKL_RBLK__(),\
        __EOS_SKL_LP08__(__EOS_SKL_READ__),__EOS_SKL_RBLK__(),\
        __EOS_SKL_LP08__(__EOS_SKL_READ__),__EOS_SKL_LP01__(__EOS_SKL_READ__),\
        __EOS_SKL_RBLK__(),__EOS_SKL_SJMP__(),__EOS_SKL_RBLK__(),\
        __EOS_SKL_LP08__(__EOS_SKL_READ__),__EOS_SKL_RBLK__(),\
        __EOS_SKL_LP08__(__EOS_SKL_READ__),__EOS_SKL_LP01__(__EOS_SKL_READ__),\
        __EOS_SKL_RBLK__(),__EOS_SKL_SJMP__(),__EOS_SKL_RBLK__(),\
        __EOS_SKL_LP08__(__EOS_SKL_READ__),__EOS_SKL_RBLK__(),\
        __EOS_SKL_LP08__(__EOS_SKL_READ__),__EOS_SKL_LP01__(__EOS_SKL_READ__),\
        __EOS_SKL_RBLK__(),__EOS_SKL_SJMP__(),__EOS_SKL_SBLK__(),\
        __EOS_SKL_SBLK__(),__EOS_SKL_SBLK__(),__EOS_SKL_SBLK__()
        __EOS_SKL__(a,r,c,h,4,5,3,8)

#ifdef __cplusplus
}
#endif

#endif /* __EOS_SKL_PRIV_ARCH_H__ */
