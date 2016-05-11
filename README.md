# FindFilesWithinFolder

提供一段 C/C++ 代码示例，用于自动获取指定文件夹下的所有文件列表（包括子目录中的文件）。
可以在 Windows 和 Linux 下运行。

代码文件可以在 GitHub 中下载：

  - [yhlleo/FindFilesWithinFolder: Find and generate a file list of the folder.](https://github.com/yhlleo/FindFilesWithinFolder), or a featured fork
  - [district10/FindFilesWithinFolder: Find and generate a file list of the folder.](https://github.com/district10/FindFilesWithinFolder)

在查找文件时，对于子文件夹里的文件采用递归的方式获取。Windows 版本的利用递归实现，Linux 版本利用的是队列。

## 编译

```
# cd source dir
mkdir build && cd build
cmake ..
make
```

## 效果

```
➜  build git:(master) ✗ ./FindFilesWithinFolder CMakeFiles
CMakeFiles/CMakeDirectoryInformation.cmake
CMakeFiles/Makefile2
CMakeFiles/progress.marks
CMakeFiles/TargetDirectories.txt
CMakeFiles/Makefile.cmake
CMakeFiles/cmake.check_cache
CMakeFiles/CMakeOutput.log
CMakeFiles/3.0.2/CMakeDetermineCompilerABI_CXX.bin
CMakeFiles/3.0.2/CMakeCCompiler.cmake
CMakeFiles/3.0.2/CMakeDetermineCompilerABI_C.bin
CMakeFiles/3.0.2/CMakeSystem.cmake
CMakeFiles/3.0.2/CMakeCXXCompiler.cmake
CMakeFiles/FindFilesWithinFolder.dir/link.txt
CMakeFiles/FindFilesWithinFolder.dir/main.cpp.o
CMakeFiles/FindFilesWithinFolder.dir/CXX.includecache
CMakeFiles/FindFilesWithinFolder.dir/cmake_clean.cmake
CMakeFiles/FindFilesWithinFolder.dir/DependInfo.cmake
CMakeFiles/FindFilesWithinFolder.dir/FindFiles.cpp.o
CMakeFiles/FindFilesWithinFolder.dir/depend.make
CMakeFiles/FindFilesWithinFolder.dir/depend.internal
CMakeFiles/FindFilesWithinFolder.dir/progress.make
CMakeFiles/FindFilesWithinFolder.dir/build.make
CMakeFiles/FindFilesWithinFolder.dir/flags.make
CMakeFiles/3.0.2/CompilerIdC/a.out
CMakeFiles/3.0.2/CompilerIdC/CMakeCCompilerId.c
CMakeFiles/3.0.2/CompilerIdCXX/CMakeCXXCompilerId.cpp
CMakeFiles/3.0.2/CompilerIdCXX/a.out
```

## References

- [yhlleo/FindFilesWithinFolder: Find and generate a file list of the folder.](https://github.com/yhlleo/FindFilesWithinFolder)
- [How can I get the list of files in a directory using C or C++? - Stack Overflow](http://stackoverflow.com/questions/612097/how-can-i-get-the-list-of-files-in-a-directory-using-c-or-c)

## Koans

Several days ago, I wrote a function to grab all descendent folders of a dir,
it's pretty much the same:

```
QStringList CuteWatchDog::grabAllDescendents( const QString &root )
{
    QStringList dirEntries;
    QDir dir( root );
    QQueue<QDir> queue;
    queue.enqueue( dir );
    while( !queue.isEmpty() ) {
        QDir d = queue.dequeue();
        dirEntries << d.absolutePath();
        foreach( const QFileInfo &info, d.entryInfoList( QDir::Dirs | QDir::NoDotAndDotDot ) ) {
             QDir subdir( info.absoluteFilePath() );
             queue.enqueue( subdir );
         }
    }
    return dirEntries;
}
```

checkout the source: <https://github.com/district10/CuteWatchDog/commit/c496e03bfaebea37d9b16a99df9ac15922a91676#diff-34ab4d129103a08bf0033d323034e0c9R78>
