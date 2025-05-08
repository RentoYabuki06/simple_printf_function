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

### Mandatory Features
- **Supported format specifiers**:
  - `%c`: Character.
  - `%s`: String.
  - `%p`: Pointer address.
  - `%d` and `%i`: Decimal integers.
  - `%u`: Unsigned decimal integer.
  - `%x` and `%X`: Hexadecimal integers (lowercase and uppercase).
  - `%%`: Percent character.
- **Error handling**:
  - Handling invalid format strings.

### Bonus Features
- **Flag support**:
  - `-`: Left-align output within the field width.
  - `0`: Pad numbers with leading zeros (instead of spaces).
  - `.`: Precision specification for strings and numbers.
  - `#`: Alternative form (adds '0x'/'0X' for hex values).
  - `+`: Always show sign for numeric values.
  - ` `: (space) Insert space before positive number.
- **Width support**:
  - Specify minimum field width for outputs.
- **Precision support**:
  - For strings: Limits maximum character count.
  - For integers: Specifies minimum number of digits.

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
#### Standard Version
```
make
```

#### Bonus Version
```
make bonus
```

### Testing
#### Standard Version
```
make test
```

#### Bonus Version
```
make test_bonus
```

#### Both Versions
```
make test_all
```

### Example Usage
```c
#include "ft_printf.h"

int main()
{
    // Basic usage
    ft_printf("String: %s\n", "Hello, World!");
    ft_printf("Integer: %d\n", 42);
    ft_printf("Hexadecimal: %x\n", 255);
    
    // Bonus features
    ft_printf("Left-aligned: [%-10s]\n", "hello");
    ft_printf("Zero-padded: [%05d]\n", 42);
    ft_printf("With precision: [%.3s] [%.5d]\n", "hello", 42);
    ft_printf("With width and precision: [%8.3d]\n", 42);
    ft_printf("Hex with alternative form: [%#x]\n", 255);
    ft_printf("With sign: [%+d]\n", 42);
    ft_printf("With space: [% d]\n", 42);
    
    return 0;
}
```

---

## Bonus Features in Detail

### Flag Combinations
Flags can be combined to create complex formatting:

| Format Example | Description |
|----------------|-------------|
| `%5d` | Right-aligned integer with width 5 |
| `%-5d` | Left-aligned integer with width 5 |
| `%05d` | Zero-padded integer with width 5 |
| `%.3d` | Integer with precision 3 (minimum 3 digits) |
| `%8.3d` | Integer with width 8, precision 3 |
| `%-8.3d` | Left-aligned integer with width 8, precision 3 |
| `%+d` | Integer with explicit sign |
| `% d` | Integer with space before positive numbers |
| `%#x` | Hex with '0x' prefix (alternative form) |

### Character (`%c`) Formatting
- `%5c`: Character right-aligned in field width 5
- `%-5c`: Character left-aligned in field width 5

### String (`%s`) Formatting
- `%10s`: String right-aligned in field width 10
- `%-10s`: String left-aligned in field width 10
- `%.3s`: String truncated to 3 characters
- `%10.3s`: String truncated to 3 characters, right-aligned in field width 10

### Number (`%d`, `%i`, `%u`) Formatting
- `%5d`: Integer right-aligned in field width 5
- `%-5d`: Integer left-aligned in field width 5
- `%05d`: Integer zero-padded to field width 5
- `%.3d`: Integer with minimum 3 digits (zero-padded if needed)
- `%+d`: Integer with sign (+ for positive, - for negative)
- `% d`: Integer with space for positive, - for negative

### Hexadecimal (`%x`, `%X`) Formatting
- `%#x`: Lowercase hex with '0x' prefix
- `%#X`: Uppercase hex with '0X' prefix
- `%8x`: Hex right-aligned in field width 8
- `%08x`: Hex zero-padded to field width 8
- `%.5x`: Hex with minimum 5 digits
- `%#8.5x`: Hex with '0x' prefix, minimum 5 digits, right-aligned in field width 8

### Pointer (`%p`) Formatting
- `%p`: Pointer address shown as hexadecimal
- `%20p`: Pointer right-aligned in field width 20
- `%-20p`: Pointer left-aligned in field width 20

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
- **Flag and modifier combinations**:
  Managing priority and interaction between different formatting directives.

---

## References
- [42Tokyo Official Page](https://42tokyo.jp/)
- [Linux man pages - printf(3)](https://man7.org/linux/man-pages/man3/printf.3.html)

---

## License
This project is part of the 42Tokyo curriculum and is intended for educational purposes. Redistribution or commercial use may be restricted.