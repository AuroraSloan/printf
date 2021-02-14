# printf
This is a library that contains a recreation of the printf funciton in C. It also contains all functions from the libft project.

This printf function ```ft_printf()``` handles the conversions ```cspdiuxX``` and the flags ```-0 +```. Field width and precision are also handled with the ```.``` flag as well as the wildcard ```*``` implementation.

The only allowed external functions were malloc, free, write, va_start, va_arg, va_copy, and va_end.

### Conversions
|Specifier  |Description|
|-----------|-----------|
|%c         |           |
|%s         |           |
|%p         |           |
|%d %i      |           |
|%u         |           |
|%x         |           |
|%X         |           |

### flags
|flag       |Description|
|-----------|-----------|
|Field width|A number or asterisk can be added before the conversion specifier letter in order to dictate the total width of the output. If width is longer than the output string, it will be blank padded unless specified otherwise with another flag.|
|'.'        |Indicates presicion. A number or asterisk can be added after a period to indicate|
|'-'        |Output will be left-aligned instead of right.|
|'+'        |puts a '-' or '+' in front of a signed integer output.|
|' '        |Puts a space in front of a positive signed integer output.|
|'0'        |puts '0' padding instead of ' ' padding.|
|'*'        |           |

### Installation
```bash
git clone https://github.com/AuroraSloan/printf.git
```

## Usage
```bash
make - compiles library libftprintf.a
make clean - removes all .o files
make fclean - removes all .o files and library
make re - removes all .o files and library before recompiling library
```
