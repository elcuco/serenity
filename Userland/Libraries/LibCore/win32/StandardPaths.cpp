/*
 * Copyright (c) 2020, Andreas Kling <kling@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <AK/LexicalPath.h>
#include <AK/String.h>
#include <AK/StringBuilder.h>
#include <LibCore/StandardPaths.h>
#include <stdlib.h>
#include <unistd.h>

namespace Core {

// TODO: port all this to use SHGetSpecialFolderPathW
// https://learn.microsoft.com/en-us/windows/win32/api/shlobj_core/nf-shlobj_core-shgetspecialfolderpathw

String StandardPaths::home_directory()
{
    auto* path = getenv("USERPROFILE");
    VERIFY(path != nullptr);
    return LexicalPath::canonicalized_path(path);
}

String StandardPaths::desktop_directory()
{
    StringBuilder builder;
    builder.append(home_directory());
    builder.append("/Desktop"sv);
    return LexicalPath::canonicalized_path(builder.to_string());
}

String StandardPaths::downloads_directory()
{
    StringBuilder builder;
    builder.append(home_directory());
    builder.append("/Downloads"sv);
    return LexicalPath::canonicalized_path(builder.to_string());
}

String StandardPaths::config_directory()
{
    auto path = getenv("LOCALAPPDATA");
    VERIFY(path != nullptr);
    return LexicalPath::canonicalized_path(path);
}

String StandardPaths::tempfile_directory()
{
    auto* path = getenv("TEMP");
    VERIFY(path != nullptr);
    return LexicalPath::canonicalized_path(path);
}

}
