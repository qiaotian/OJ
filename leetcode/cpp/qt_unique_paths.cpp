/**
* @Author: Tian Qiao <root>
* @Date:   2016-07-10T19:18:27+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   root
* @Last modified time: 2016-07-13T12:49:15+08:00
* @Inc: Bloomberg
*/



/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?

Above is a 3 x 7 grid. How many possible unique paths are there?
Note: m and n will be at most 100.
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(n == 1 || m == 1) return 1;
        return uniquePaths(m, n-1) + uniquePaths(m-1, n);
    }
};


// C(m+n, n) overflow
/*
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long numerator = 1, denominator = 1;
        for(int i = m; i <= m + n -2; i++) denominator *= i;
        for(int i = 1; i <= n-1; i++) numerator *= i;
        return denominator/numerator;
    }
};
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        double res = 1.0;
        for(int i = 1; i < n; i++)
            res *= (double)(m+i-1)/i;
        return round(res)
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        double res = 1.0;
        for(int i = 1; i < n; i++)
            res = res * (m+i-1)/i; // right
            //res *= (double)(m+i-1)/i; wrong
        return (int)res;
    }
};

/**
 * WARNING
 * 1. 当m+i-1和i都是整数时，其比值亦为整数，造成精度损失
 * 2. 强制类型转换的优先级高于四则运算，仅次于[]、取值、和负运算符‘-’
 * 3. return (int)res will give wrong answer if input is 10 and 10, where output is 48619 but expeected 48620
 * 4. a *= b*c 和 a = a*b*c的区别在于前者先计算b*c，而后者先计算a*b
 * /
