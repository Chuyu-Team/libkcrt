@echo off

mkdir build\x86
LIB /NOLOGO /DEF:source\ntdll-crt-common.def /MACHINE:X86 /OUT:build\x86\ntdll-crt-common.lib
LIB /NOLOGO /DEF:source\x86\ntdll-crt-specific.def /MACHINE:X86 /OUT:build\x86\ntdll-crt-specific.lib
LIB /NOLOGO /MACHINE:X86 /OUT:build\x86\libkcrt.lib build\x86\ntdll-crt-common.lib build\x86\ntdll-crt-specific.lib source\x86\*.obj
del build\x86\ntdll-crt-common.*
del build\x86\ntdll-crt-specific.*

mkdir build\x64
LIB /NOLOGO /DEF:source\ntdll-crt-common.def /MACHINE:X64 /OUT:build\x64\ntdll-crt-common.lib
LIB /NOLOGO /DEF:source\x64\ntdll-crt-specific.def /MACHINE:X64 /OUT:build\x64\ntdll-crt-specific.lib
LIB /NOLOGO /MACHINE:X64 /OUT:build\x64\libkcrt.lib build\x64\ntdll-crt-common.lib build\x64\ntdll-crt-specific.lib source\x64\*.obj
del build\x64\ntdll-crt-common.*
del build\x64\ntdll-crt-specific.*

mkdir build\arm
LIB /NOLOGO /DEF:source\ntdll-crt-common.def /MACHINE:ARM /OUT:build\arm\ntdll-crt-common.lib
LIB /NOLOGO /DEF:source\arm\ntdll-crt-specific.def /MACHINE:ARM /OUT:build\arm\ntdll-crt-specific.lib
LIB /NOLOGO /MACHINE:ARM /OUT:build\arm\libkcrt.lib build\arm\ntdll-crt-common.lib build\arm\ntdll-crt-specific.lib source\arm\*.obj
del build\arm\ntdll-crt-common.*
del build\arm\ntdll-crt-specific.*

mkdir build\arm64
LIB /NOLOGO /DEF:source\ntdll-crt-common.def /MACHINE:ARM64 /OUT:build\arm64\ntdll-crt-common.lib
LIB /NOLOGO /DEF:source\arm64\ntdll-crt-specific.def /MACHINE:ARM64 /OUT:build\arm64\ntdll-crt-specific.lib
LIB /NOLOGO /MACHINE:ARM64 /OUT:build\arm64\libkcrt.lib build\arm64\ntdll-crt-common.lib build\arm64\ntdll-crt-specific.lib source\arm64\*.obj
del build\arm64\ntdll-crt-common.*
del build\arm64\ntdll-crt-specific.*

copy source\libkcrt.gitignore build\.gitignore
copy source\libkcrt.props build\libkcrt.props

echo on