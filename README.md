# ft_printf - Custom printf Function Implementation

## Overview
**ft_printf** is one of the 42Tokyo projects that involves creating your own version of the C standard library function `printf`. This project strengthens system programming skills through variable arguments, format specifier parsing, and output processing. 

This implementation is primarily based on the behavior of glibc (GNU C Library) used in Ubuntu and Debian systems. As a result, there may be behavioral differences compared to other C library implementations such as Darwin libc (used in macOS) or musl libc (used in Alpine Linux).

---

## Project Objectives
1. **Learning to handle variable arguments**:
   - Using `stdarg.h` for processing variable arguments.
2. **Parsing and processing format specifiers**:
   - Implementing processing for strings, integers, hexadecimal numbers, and other data types.
3. **Improving low-level programming skills**:
   - Controlling output formats and manipulating strings.
4. **C language error handling and optimization**:
   - Practicing memory management and performance optimization.

---

## Feature List
- **Supported format specifiers**:
  - `%c`: Character.
  - `%s`: String.
  - `%p`: Pointer address.
  - `%d` and `%i`: Decimal integers.
  - `%u`: Unsigned decimal integer.
  - `%x` and `%X`: Hexadecimal integers (lowercase and uppercase).
  - `%%`: Percent character.
- **Flag support**:
  - Width specification, precision specification, left-align, and zero-padding.
- **Error handling**:
  - Handling invalid format strings.

---

## Implementation Requirements
1. **Library restrictions**:
   - Standard C library functions cannot be used (with some exceptions).
2. **Error handling**:
   - Handling argument errors and memory errors.
3. **Code standard compliance**:
   - Must comply with the 42 norm standards.

---

## Usage
### Requirements
- Linux or macOS.
- `make` command and `gcc` compiler installed.

### Compilation
```
make
```
### Example Usage
```
#include "ft_printf.h"

int main()
{
    ft_printf("String: %s\n", "Hello, World!");
    ft_printf("Integer: %d\n", 42);
    ft_printf("Hexadecimal: %x\n", 255);
    return 0;
}
```

---

## Learning Points
- **Parsing and processing format specifiers**:
  Complex string parsing and dynamic output processing.
- **Using variable arguments**:
  Flexible argument management and versatile function design.
- **Low-level string manipulation**:
  Understanding efficient string and numerical manipulation algorithms.
- **Enhancing error handling**:
  Handling invalid inputs and edge cases.

---

## References
- [42Tokyo Official Page](https://42tokyo.jp/)
- [Linux man pages - printf(3)](https://man7.org/linux/man-pages/man3/printf.3.html)

---

## License
This project is part of the 42Tokyo curriculum and is intended for educational purposes. Redistribution or commercial use may be restricted.

