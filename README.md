# libkcrt

libkcrt provides an easy way to use C Run-time Library from Windows Kernel 
exported from ntdll.dll in your user-mode applications.

** Under Construction **

## Available CRT Functions

| __isascii  | _strnicmp   | atan     | iswdigit  | strchr   | vsprintf |
|------------|-------------|----------|-----------|----------|----------|
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
