# libkcrt

libkcrt provides an easy way to use C Run-time Library from Windows Kernel 
exported from ntdll.dll in your user-mode applications.

I suggest you use VC-LTL for non-special cases, not the libkcrt.

** Under Construction **

## Todo list

- Add SEH Support for the x86 target.
- Add GS Support.
- Add RTC Support.
- Add C++ EH Support.
- Add SDL Support.
- Add basic memory allocation support for C and C++.
- Without defining the entry point manually.

## Available CRT Functions

| Column 1   | Column 2    | Column 3 | Column 4  | Column 5 | Column 6 |
|------------|-------------|----------|-----------|----------|----------|
| __isascii  | _strnicmp   | atan     | iswdigit  | strchr   | vsprintf |
| __iscsym   | _strupr     | atoi     | iswlower  | strcmp   | wcscat   |
| __iscsymf  | _swprintf   | atol     | iswspace  | strcpy   | wcschr   |
| __toascii  | _ui64toa    | bsearch  | iswxdigit | strcspn  | wcscmp   |
| _atoi64    | _ui64tow    | ceil     | isxdigit  | strlen   | wcscpy   |
| _i64toa    | _ultoa      | cos      | labs      | strncat  | wcscspn  |
| _i64tow    | _ultow      | fabs     | log       | strncmp  | wcslen   |
| _itoa      | _vscwprintf | floor    | mbstowcs  | strncpy  | wcsncat  |
| _itow      | _vsnprintf  | isalnum  | memchr    | strpbrk  | wcsncmp  |
| _lfind     | _vsnwprintf | isalpha  | memcmp    | strrchr  | wcsncpy  |
| _ltoa      | _vswprintf  | iscntrl  | memcpy    | strspn   | wcspbrk  |
| _ltow      | _wcsicmp    | isdigit  | memmove   | strstr   | wcsrchr  |
| _memccpy   | _wcslwr     | isgraph  | memset    | strtol   | wcsspn   |
| _memicmp   | _wcsnicmp   | islower  | pow       | strtoul  | wcsstr   |
| _snprintf  | _wcstoui64  | isprint  | qsort     | swprintf | wcstol   |
| _snwprintf | _wcsupr     | ispunct  | sin       | tan      | wcstombs |
| _splitpath | _wtoi       | isspace  | sprintf   | tolower  | wcstoul  |
| _strcmpi   | _wtoi64     | isupper  | sqrt      | toupper  |          |
| _stricmp   | _wtol       | iswalpha | sscanf    | towlower |          |
| _strlwr    | abs         | iswctype | strcat    | towupper |          |

## License

libkcrt is distributed under the [MIT License](LICENSE).

## Chuyu Team
