递归算法:
int gcd(int a,int b)
{
	if(b==0)
        	return a;
	else
		return gcd(b,a%b);
}

优化
int gcd(int a,int b)
{
    return b ? gcd(b,a%b) : a;
}

迭代
 1 int Gcd(int a, int b)
 2 {
 3     while(b != 0)
 4     {
 5     　　int r = b;
 6     　　b = a % b;
 7     　　a = r;
 8     }
 9     return a;
10 }