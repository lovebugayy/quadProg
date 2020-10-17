源码地址：https://github.com/liuq/QuadProgpp.git
在源码的基础上做了以下改正：
添加了初始化函数：
Array.h文件下：
Vector(const std::vector<T>& a,const unsigned int n);
Matrix(std::vector<std::vector<T>>& a, const unsigned int n, const unsigned int m);
修改了代码的错误：
QuadProg.cpp文件下：
202行：  A[i] =(-(static_cast<int> (i)) - 1); 原来是：A[i]=-i-1;
修改原因：i是unsigned int，加了符号之后仍然是unsigned int。
