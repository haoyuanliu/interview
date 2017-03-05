#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "qh_vector.h"

void test()
{
    int len = 100;
    qh::vector<int> nums;
    for(int i = 0; i < len; ++i)
        nums.push_back(i);
    for(int i = 0 ; i < nums.size(); ++i)
        printf("%d ", nums[i]);
    printf("\n");

    int temp;
    for(int i = 0; i < len; ++i)
    {
        nums.pop_back(&temp);
        printf("%d ", temp);
    }
    printf("\n");
}

void test1()
{
    int len = 100;
    qh::vector<int> nums(len, 2);
    for(int i = 0; i < nums.size(); ++i)
        printf("%d ", nums[i]);
    printf("\n");
    qh::vector<int> nums2 = nums;
    for(int i = 0; i < nums2.size(); ++i)
        printf("%d ", nums2[i]);
    printf("\n");
}

void test2()
{
    qh::vector<std::string> str(5, "Hello");
    str.push_back("Hello");
    str.push_back("Nihao");
    for(int i = 0 ; i < str.size(); ++i)
        std::cout << str[i] << std::endl;

    std::string s;
    while(str.size())
    {
        str.pop_back(&s);
        std::cout << s << std::endl;
    }
}

int main(int argc, char* argv[])
{
    //TODO ���������ӵ�Ԫ���ԣ�Խ��Խ�ã�����·��������ԽȫԽ��
    //TODO ��Ԫ����д�����ο�INIParser�Ǹ���Ŀ����Ҫдһ��printf��Ҫ��assert���ж����жϡ�
    test();
    //test1();
    test2();

#ifdef WIN32
    system("pause");
#endif

	return 0;
}
