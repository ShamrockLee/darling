/*
 * Copyright (c) 2016 Apple Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */
#include <machine/cpu_capabilities.h>
#include <time.h>
#include "../../emulation/linux/base.h"
#include "../../emulation/linux/linux-syscalls/linux.h"

uint64_t
mach_boottime_usec(void)
{
	struct timespec ts;
	LINUX_SYSCALL(__NR_clock_gettime, CLOCK_MONOTONIC, &ts);
	return ((ts.tv_sec*1000*1000*1000)+ts.tv_nsec)/1000;
	/* We don't have this working, so make Linux syscall */
	/* return *(uint64_t*)_COMM_PAGE_BOOTTIME_USEC; */
}
