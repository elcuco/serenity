set(SOURCES
    FileSystemWindows.cpp
    TempFile.cpp
)

serenity_lib(LibFileSystem filesystem)
target_link_libraries(LibFileSystem PRIVATE LibCore)
