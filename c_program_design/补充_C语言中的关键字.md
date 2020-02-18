[TOC]

# C语言中的关键字(ANSI C 标准)

| 1 | 2 | 3 | 4 | 5 |
:---: | :---: | :---: | :---: | :---:
| auto | break | case | char | const
| continue | default | do | double | else
| enum | extern | float | for | goto
| if | inline | int | long | register
| restrict | return | short | signed | sizeof
| static | struct | switch | typedef | union
| unsigned | void | volatile | while | _bool
| _Complex | _Imaginary | > 

## auto 

- auto 在声明变量时使用，通常被省略。例如， auto int a = 1。

## extern

- extern 使用该关键字修饰的变量是==全局变量（也就是外部变量）==，而全局变量存储在静态存储区。
- 需要注意的是，该关键字修饰变量时，不会为变量分配存储空间。因此，通过该关键字使用全局变量时，需要确保对应的变量已经完成了初始化。

## inline

- 用来定义内联函数。例如，inline char * dbtest(int a) { ... }。
- inline 关键字必须与==函数体==放在一起才能使函数成为内联函数。
  - > 不应该将 inline 放在函数声明中。
- 内联函数本身不能是直接递归函数（自己直接调用自己）。
- 内联函数节省函数调用堆栈，但是会导致代码膨胀（实际上是编译器复制了代码）。 

- 内联函数的使用场景：
  - 函数体比较大的函数不宜作为内联函数。
  - 函数体内包含循环的函数也可以不作为内联函数（循环的执行代价往往高于函数调用）。
  - > 编译器会自动的取消不值得的内联。

## register

- register 用来告知编译器==尽量==把被修饰的变量存储在寄存器中，以便提高运行速度。
- 需要注意的是，被修饰的变量需要是寄存器能够接受的类型，即是一个单个的值，并且不能使用取址运算符访问该变量（该变量可能不存放在内存中，也就没有内存地址）。

## restrict

- C 99 标准引入的关键字。
- restrict 用来限定和约束指针：表明指针是访问一个数据对象的唯一且初始的方式。即所有修改该指针所指向内存中的内容的操作都必须通过该指针来修改，而不能通过其他途径（其他变量或指针）。
- 这样做可以帮助编译器更好的优化代码，生成的汇编代码效率更高。

## volatile

- volatile 表示每次访问该变量时，都直接存取原始的内存地址。
- 使用该关键字修饰的变量，可以避免因编译器优化（编译器一般倾向于使用寄存器缓存局部变量，从而提高运行速度）而导致的错误（例如多线程情况下的共享变量）。

## _Complex

- C 99 标准引入的关键字。
- _Complex 表示一种基本的数据类型 -- 复数。
- 支持三种复数类型
  - float _Complex a;
  - double _Complex b;
  - long double _Complex c。

## _Imaginary

(暂未找到，略)