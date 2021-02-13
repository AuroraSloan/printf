# printf
This is a library that contains a recreation of the printf funciton in C. It also contains all functions from the libft project.

This printf function ```ft_printf()``` handles the conversion ```cspdiuxX``` and the flags ```-0 +```. Precision and width are also handled with the ```.``` flag as well as the wildcard ```*``` implementation.

The only allowed external functions were malloc, free, write, va_start, va_arg, va_copy, and va_end.

### Conversions
|Specifier|Description|
|---------|-----------|
|%c       |           |
|%s       |           |
|%p       |           |
|%d %i    |           |
|%u       |           |
|%x       |           |
|%X       |           |

### flags
|flag     |Description|
|---------|-----------|
|'-'      |Output will be left-aligned instead of right.|
|'+'      |puts a '-' or '+' in front of a signed integer output.|
|' '      |Puts a space in front of a positive signed integer output.|
|'0'      |puts '0' padding instead of ' ' padding.|
|'.'      |Indicates presicion.|
|'*'      |           |

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
