/*
 * Copyright (c) 2021, Peter Elliott <pelliott@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibCore/Directory.h>
#include <LibCore/LockFile.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/file.h>
#include <unistd.h>

#include <windows.h>
//#include <winnt.h>

#define LK_LEN      ULONG_MAX

namespace Core {

LockFile::LockFile(char const* filename, Type type)
    : m_filename(filename)
{
    if (Core::Directory::create(LexicalPath(m_filename).parent(), Core::Directory::CreateDirectories::Yes).is_error())
        return;

    m_fd = open(filename, O_RDONLY | O_CREAT | O_CLOEXEC, 0666);
    if (m_fd == -1) {
        m_errno = errno;
        return;
    }

#if !defined(AK_OS_WINDOWS)
    if (flock(m_fd, LOCK_NB | ((type == Type::Exclusive) ? LOCK_EX : LOCK_SH)) == -1) {
        m_errno = errno;
        close(m_fd);
        m_fd = -1;
    }
#else
    HANDLE fh = (HANDLE) _get_osfhandle (m_fd);
    OVERLAPPED o;
    LockFileEx(fh, 0, 0, LK_LEN, LK_LEN, &o);
#endif
}

LockFile::~LockFile()
{
    release();
}

bool LockFile::is_held() const
{
    return m_fd != -1;
}

void LockFile::release()
{
    if (m_fd == -1)
        return;

    unlink(m_filename);
#if !defined(AK_OS_WINDOWS)
    flock(m_fd, LOCK_NB | LOCK_UN);
#else
    HANDLE fh = (HANDLE) _get_osfhandle (m_fd);
    OVERLAPPED o;
    UnlockFileEx(fh, 0, LK_LEN, LK_LEN, &o);
#endif

    close(m_fd);

    m_fd = -1;
}

}
