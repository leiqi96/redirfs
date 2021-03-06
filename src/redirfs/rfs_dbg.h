/*
 * RedirFS: Redirecting File System
 *
 * Copyright 2017 Slava Imameev
 * All rights reserved.
 *
 * This file is part of RedirFS.
 *
 * RedirFS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * RedirFS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with RedirFS. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _RFS_DBG_H
#define _RFS_DBG_H

#include <asm-generic/bug.h>
#include <linux/printk.h>

#ifdef RFS_RBG_PREEMPTIBLE
    #define rfs_preemptible() preemptible()
    #define rfs_in_softirq() in_softirq()
#else
    #define rfs_preemptible() true
    #define rfs_in_softirq() false
#endif

#ifdef RFS_DBG
    #define DBG_BUG_ON(cond) BUG_ON(cond)
    #define rfs_pr_debug(fmt, ...) \
	    printk(KERN_INFO "redirfs: %s:%d:%s:" pr_fmt(fmt) , __FILE__, __LINE__, __PRETTY_FUNCTION__, ##__VA_ARGS__)
#else
    #define DBG_BUG_ON(cond) do {} while(0)
    #define rfs_pr_debug(fmt, ...) \
        no_printk(KERN_INFO "redirfs: %s:%d:%s:" pr_fmt(fmt) , __FILE__, __LINE__, __PRETTY_FUNCTION__, ##__VA_ARGS__)
#endif

#endif //_RFS_DBG_H
