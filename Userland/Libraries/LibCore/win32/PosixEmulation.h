/*
 * Copyright (c) 2022, Diego Iastrubni
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <dirent.h>
#include <winerror.h>
#include <sys/stat.h>
#include <time.h>

typedef int uid_t;
typedef int gid_t;

// Windows does not have the following types, emulate them
// and all APIs using them will be void.
#define O_CLOEXEC 0

// Problem: MinGW `stat()` has no concept of links.
// Maybe we should use another function instead?
#define	S_ISLNK(m) (false)

#define NAME_MAX PATH_MAX

#ifdef MINGW_SDK_INIT
// WHAT? signal handler functions in mingw are borked!
#define sighandler_t __p_sig_fn_t
#endif

typedef void (*sig_t) (int);

#define suseconds_t long

#ifndef _POSIX_THREAD_SAFE_FUNCTIONS
// I have no idea this this guard is not enabled on my build
__forceinline struct tm *__CRTDECL localtime_r(const time_t *_Time, struct tm *_Tm) {
  return localtime_s(_Tm, _Time) ? NULL : _Tm;
}
__forceinline struct tm *__CRTDECL gmtime_r(const time_t *_Time, struct tm *_Tm) {
  return gmtime_s(_Tm, _Time) ? NULL : _Tm;
}
__forceinline char *__CRTDECL ctime_r(const time_t *_Time, char *_Str) {
  return ctime_s(_Str, 0x7fffffff, _Time) ? NULL : _Str;
}
__forceinline char *__CRTDECL asctime_r(const struct tm *_Tm, char * _Str) {
  return asctime_s(_Str, 0x7fffffff, _Tm) ? NULL : _Str;
}
#endif

// unimplemented
int chown(const char *path, uid_t owner, gid_t group);

// unimplemented
int dirfd(DIR *dirp);

// unimplemented
int fchmod(int fildes, mode_t mode);

// unimplemented
int fchown(int fd, uid_t owner, gid_t group);

// unimplemented
int link(const char *path1, const char *path2);

// Emulate lstat, as we don't really have symbolink links on Windows
int lstat(const char *pathname, struct stat *statbuf);

// Emulate Posix, by doign a trampoline function.
// as win32's version has no mode.
int mkdir(const char *dirname, int);

char *realpath(const char *path, char *resolved_path);

// unimplemented
int symlink(const char *path1, const char *path2);
