//
//  main.c
//  C语言经典算法
//
//  Created by 严锦龙 on 17/7/5.
//  Copyright © 2017年 moonbasa. All rights reserved.
//

#include <stdio.h>


typedef int Status;

//  (1)输出9*9乘法口诀
void Table99() {
    int i, j;
    
    for (i = 1; i < 10 ; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d*%d=%-2d    ", i, j, i * j);
        }
        
        printf("\n");
//        for (j = 1; j < 10; j++) {
//            if (j <= i) {
//                printf("%d*%d=%2d    ", i, j, i * j);
//                
//                if (j == i) {
//                    printf("\n");
//                }
//            }
//        }
    }
}
/*
 (2)古典问题：有一对兔子，从出生后第3个月起每个月都生一对兔子，小兔子长到第三个月后每个月又生一对兔子，假如兔子都不死，问每个月的兔子总数为多少？(兔子的规律为数列1,1,2,3,5,8,13,21....)这也是著名的斐波那契数列。
 */
void Fabocci() {
    int f1, f2;
    
    f1 = f2 = 1;
    
    for (int i = 1; i < 20; i++) {
        printf("%20d, %20d", f1, f2);
        
        // 控制每行输出4个数字
        if (i % 2 == 0) {
            printf("\n");
        }
        
        // 斐波那契数列的规律 后一个数等于前面两个数之和
        f1 = f1 + f2;
        f2 = f2 + f1;
    }
}

/*
 (3)1-100之间有多少个素数，并输出所有素数及素数的个数。
 */
void Prime() {
    int count = 2;
    printf("\n");
    int b = 2;
    printf("%5d", b);
    
    for (int i = 3; i <= 100; i++) {
        Status isPrime = 1;
        int j = 2;
        while (j < i && isPrime) {
            if (i % j == 0) {
                isPrime = 0;
                break;// 跳出循环
            }
            else {
                j++;
            }
        }
        
        if (isPrime) {
            count++;
            printf("%5d",i);
        }
    }
    
    printf("\n");
    printf("1到100以内素数的个数为：%d\n", count);
}
/*
 (4)一个数如果恰好等于它的因子之和，这个数就称为“完数”。例如6 = 1+2+3
 找出10000以内的所有完数。
 */
void PerfectNumber() {
    int MaxNum = 10000;
    
    int p[100]; // 保存分解的因子
    int num, s, count, c = 0;
    
    for (num = 2; num < MaxNum; num++) {
        count = 0;
        s = num;
        // 把每一个数拆分成因子，并放到数组中
        for (int i = 1; i < num/2 + 1; i++) {
            if (num % i == 0) {
                p[count++] = i;
                s-=i;// 每一次减因子
            }
        }
        
        if (s == 0) {
            printf("%4d是一个完数", num);
            printf("%d = %d", num, p[0]);
            // 遍历因子数组
            for (int i = 1; i < count; i++) {
                printf("+%d", p[i]);
            }
            
            printf("\n");
            c++;
        }
    }
    
    printf("共找到%d完全数", c);
}

int main(int argc, const char * argv[]) {
    Table99();
    Fabocci();
    Prime();
    PerfectNumber();
    return 0;
}
