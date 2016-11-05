
#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <bitset>
using    namespace    std;
////////////////////////////////////////////////////////////
int    main()
{
	//ʹ��bitset�ඨ��100λ�Ķ��������У������洢ÿ���������Ƿ�Ź���
    bitset<100> prisoner(0);
    int    day = 1;//�ѹ��˵�����
    int counter;//ͳ����
    int close_count = 0;//�Ѿ��صƴ���
    int i;//����ŷ������

	//ʹ�� time���������ϵͳʱ��Ȼ��time_t������ת��Ϊ(unsigned)��ʼ���������; 
    srand((unsigned)time(NULL)); 
 
    counter = rand() % 100;//��һ����Ǹ�����Ϊͳ����
    bool    flag = false;//�Ƶ�״̬
    prisoner.set(counter);//ʹ��set������ͳ����������Ϊ�Ѿ�ͳ�ƹ�
 
    while (true)
    {
        ++day;
        i = rand() % 100;
        if (flag && i == counter)
        {//���ǿ��ģ�����ͳ������
            flag = false;
            ++close_count;
        }
        else if (!flag && !prisoner[i])
        {//���ǹصģ�����δͳ�ƹ�������
            flag = true;
            prisoner.set(i);
        }
		//�����е������������ŷ��֮������ѭ��
        if (close_count == 99)
        {
            break;
        }
    }
	//�����Ҫ��������
    cout << "Out of prison:" << day << "days\t\t" << day/365 << "years" << endl;
    system("pause");
    return 0;
}
