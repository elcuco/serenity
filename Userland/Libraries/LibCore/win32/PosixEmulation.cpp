/*
 * Copyright (c) 2022, Diego Iastrubni
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibCore/win32/PosixEmulation.h>
#include <cstring>
#include <limits.h>
#include <sys/stat.h>

// unimplemented
int chown(const char *path, uid_t owner, gid_t group)
{
    (void)(path);
    (void)(owner);
    (void)(group);
    return ERROR_API_UNAVAILABLE;
}

int dirfd(DIR *dirp)
{
    // TODO I think there is a way to get the real FD here
    (void)(dirp);
    return ERROR_API_UNAVAILABLE;
}

int fchmod(int fildes, mode_t mode)
{
    (void)(fildes);
    (void)(mode);
    return ERROR_API_UNAVAILABLE;
}

int fchown(int fd, uid_t owner, gid_t group)
{
    (void)(fd);
    (void)(owner);
    (void)(group);
    return ERROR_API_UNAVAILABLE;
}

int link(const char *path1, const char *path2)
{
    (void)(path1);
    (void)(path2);
    return ERROR_API_UNAVAILABLE;
}

int lstat(const char *pathname, struct stat *statbuf)
{
    // TODO: port to GetFileAttributesEx
    // https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getfileattributesexa?redirectedfrom=MSDN
    return stat(pathname, statbuf);
}

int mkdir(const char *dirname, int)
{
    // TODO: port to CreateDirectory and use the mode argument
    // https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createdirectorya?redirectedfrom=MSDN
    return mkdir(dirname);
}

char *realpath(const char *path, char *resolved_path)
{
    if (!resolved_path) {
        resolved_path = strdup(path);
    } else {
        strncpy(resolved_path, path, PATH_MAX);
    }
    return resolved_path;
}

int symlink(const char *path1, const char *path2)
{
    // TODO use CreateSymbolicLynk
    // https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-createsymboliclinka
    (void)(path1);
    (void)(path2);
    return ERROR_API_UNAVAILABLE;
}



