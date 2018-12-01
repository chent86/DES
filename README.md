# DES的c++实现
---
**quick start**
```
make
bin/main
```


## 模块介绍

|文件名|功能|
|---|---|
|fill.cpp|对原始明文进行字节填充|
|IP.cpp|初始置换IP以及逆置换IP-1|
|T-iteration.cpp|进行16轮迭代T(包括加密和解密过程)|
|Feistel.cpp|Feistel轮函数功能|
|E-expand.cpp|进行E扩展|
|key.cpp|根据64位秘钥生成子秘钥|
|S-box.cpp|使用S盒子进行二进制的6-4置换|
|P-displace.cpp|进行P置换|
|main.cpp|主函数，调用各个模块|

**具体函数介绍请参考各个头文件，具体实现过程请看注释**