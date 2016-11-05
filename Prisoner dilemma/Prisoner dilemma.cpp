
#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <bitset>
using    namespace    std;
////////////////////////////////////////////////////////////
int    main()
{
	//使用bitset类定义100位的二进制序列，用来存储每个囚犯的是否放过风
    bitset<100> prisoner(0);
    int    day = 1;//已过了的天数
    int counter;//统计者
    int close_count = 0;//已经关灯次数
    int i;//随机放风的囚犯

	//使用 time函数来获得系统时间然后将time_t型数据转化为(unsigned)初始化随机函数; 
    srand((unsigned)time(NULL)); 
 
    counter = rand() % 100;//第一天的那个囚犯为统计者
    bool    flag = false;//灯的状态
    prisoner.set(counter);//使用set方法将统计囚犯设置为已经统计过
 
    while (true)
    {
        ++day;
        i = rand() % 100;
        if (flag && i == counter)
        {//灯是开的，且是统计囚犯
            flag = false;
            ++close_count;
        }
        else if (!flag && !prisoner[i])
        {//灯是关的，且是未统计过的囚犯
            flag = true;
            prisoner.set(i);
        }
		//当所有的囚犯都出来放风过之后跳出循环
        if (close_count == 99)
        {
            break;
        }
    }
	//输出需要的总天数
    cout << "Out of prison:" << day << "days\t\t" << day/365 << "years" << endl;
    system("pause");
    return 0;
}
