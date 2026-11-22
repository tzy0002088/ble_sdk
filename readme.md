## ble stack 项目结构设计

### 背景
对于 ble 应用来说，芯片厂不希望 ble stack 固件（linklayer 与 host）暴漏太多信息，因此需要有一种机制，能够让用户在得不到静态库的情况下，依然能够使用 ble stack 去构建自己的 ble 应用程序。芯片原厂同时有自己的需求，需要将 ble stack 固化到 rom 中（仅固化 linklayer）, 这种情况下，必须提供一种机制能够让上层软件能够调用 rom 中的 linklayer 程序。

### 介绍
    当前项目是为了探索一种方式，能够让 ble stack 与 app 程序分离开。
    `cmake .. -DCMAKE_TOOLCHAIN_FILE=../cmake/arm-none-eabi-toolchain.cmake` 可以直接编译链接。

