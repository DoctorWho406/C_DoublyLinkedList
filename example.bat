@echo off

set BAT_BASE_PATH=%~p0

IF EXIST "%BAT_BASE_PATH%examples\bin" (
    RD /S /Q "%BAT_BASE_PATH%examples\bin"
)

MD "%BAT_BASE_PATH%examples\bin"

clang -o "%BAT_BASE_PATH%examples/bin/Example.exe" -I "%BAT_BASE_PATH%include" -I "%BAT_BASE_PATH%examples/include" "%BAT_BASE_PATH%src/DoublyLinkedList.c" "%BAT_BASE_PATH%examples/src/IntItem.c" "%BAT_BASE_PATH%examples/src/main.c"

IF EXIST "%BAT_BASE_PATH%examples\bin\Example.exp" (
    DEL /Q "%BAT_BASE_PATH%examples\bin\Example.exp"
)

IF EXIST "%BAT_BASE_PATH%examples\bin\Example.lib" (
    DEL /Q "%BAT_BASE_PATH%examples\bin\Example.lib"
)