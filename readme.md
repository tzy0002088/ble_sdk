## ble stack 项目结构设计

### 背景
对于 ble 应用来说，芯片厂不希望 ble stack 固件（linklayer 与 host）暴露太多信息，因此需要有一种机制，能够让用户在得不到静态库的情况下，依然能够使用 ble stack 去构建自己的 ble 应用程序。芯片原厂同时有自己的需求，需要将 ble stack 固化到 rom 中（仅固化 linklayer）, 这种情况下，必须提供一种机制能够让上层软件能够调用 rom 中的 linklayer 程序。

### 信息暴露的边界
该机制保护的是**源代码与实现细节**，而**符号名与布局是公开的**：

- 不暴露：stack 的源码、算法与内部实现——用户只拿到 fw 的二进制产物；
- 公开的：stack 镜像的**全局符号表**（符号名 + 绝对地址）。部分链接 `ld -r -R fw.elf` 会把 fw 的整个全局符号表以 ABS 符号的形式拷入 libfw.o——包括未被任何代码引用的符号（如 `ll_em_pool`），因此 app 可以 extern 并直呼栈内任意全局符号。

这是机制的必然代价：app 必须在链接期知道目标的绝对地址才能调用，符号名随符号表一起流动，无法只给地址不给名字。若想进一步收敛暴露面，把不希望公开的符号在栈侧声明为 `static` 即可——局部符号不进 fw.elf 的全局符号表，也就不会流出。

### 介绍
    当前项目是为了探索一种方式，能够让 ble stack 与 app 程序分离开。
    `cmake .. -DCMAKE_TOOLCHAIN_FILE=../cmake/arm-none-eabi-toolchain.cmake` 可以直接编译链接。

