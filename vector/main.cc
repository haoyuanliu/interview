#include <stdlib.h>
#include <stdio.h>
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

int main(int argc, char* argv[])
{
    //TODO ���������ӵ�Ԫ���ԣ�Խ��Խ�ã�����·��������ԽȫԽ��
    //TODO ��Ԫ����д�����ο�INIParser�Ǹ���Ŀ����Ҫдһ��printf��Ҫ��assert���ж����жϡ�
    test();

#ifdef WIN32
    system("pause");
#endif

	return 0;
}
