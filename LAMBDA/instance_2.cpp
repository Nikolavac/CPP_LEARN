//返回值为int ,参数为一个int类型的参数
//递归
function<int(int)>fib = [&fib](int n){return n<= 2?1:fib(n-1) + fib(n-2);};
fib(5);