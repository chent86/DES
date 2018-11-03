# DES的c++实现
---
**quick start**
```
make
bin/main
```

##　模块介绍

1. fill.cpp
功能: 对原始明文进行字节填充

2. IP.cpp
功能: 初始置换IP以及逆置换IP-1

3. T-iteration.cpp
功能: 进行16轮迭代T(包括加密和解密过程)

4. Feistel.cpp
功能: Feistel轮函数功能

5. E-expand.cpp
功能: 进行E扩展

6. key.cpp
功能: 根据64位秘钥生成子秘钥

7. S-box.cpp
功能: 使用S盒子进行二进制的6-4置换

8. P-displace.cpp
功能: 进行P置换

9. main.cpp
功能: 主函数，调用各个模块

**具体函数介绍请参考各个头文件，具体实现过程请看注释**