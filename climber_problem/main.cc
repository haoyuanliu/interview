#include <stdio.h>
#include <iostream>
#include <sstream>
#include <assert.h>

#define H_ARRAYSIZE(a) \
    ((sizeof(a) / sizeof(*(a))) / \
    static_cast<size_t>(!(sizeof(a) % sizeof(*(a)))))

int resolve(const char* input)
{
    int res = 0;
    std::istringstream strs(input);
    std::string str;
    int len;
    strs >> len;
    int left = 0;
    int right = 0;
    int start = 0;
    int end = 0;
    int height = 0;
    int maxHeight = 0;
    while(strs >> str)
    {
        left = atoi(str.substr(0, str.find(',')).data());
        right = atoi(str.substr(str.find(',')+1, str.rfind(',')).data());
        height = atoi(str.substr(str.rfind(',')+1).data());
        
        if(left > end)
        {
            res += maxHeight * 2;
            start = left;
            end = right;
            maxHeight = height;
        }
        else
        {
            start = std::min(start, left);
            end = std::max(end, right);
            maxHeight = std::max(maxHeight, height);
        }
    }
    res += maxHeight * 2;
    res += end;
    std::cout << res << std::endl;
    return res;
}

int main(int argc, char* argv[])
{
    const char* input[] = {
        "3\n1,3,2\n2,4,4\n6,7,5\n", //The giving example
        "1\n1,2,1\n",
        "2\n1,2,1\n2,3,2",
        "3\n1,2,1\n2,3,2\n3,6,1",
        "4\n1,2,1\n2,3,2\n3,6,1\n5,8,2",
        "5\n1,2,1\n2,3,2\n3,6,1\n5,8,2\n7,9,1",
        "1\n0,1,1",
        "2\n0,1,1\n2,4,3",
        "3\n0,1,1\n2,4,3\n3,5,1",
        "4\n0,1,1\n2,4,3\n3,5,1\n5,6,1",
        "5\n0,1,1\n2,4,3\n3,5,1\n5,6,1\n6,8,3",
        //TODO please add more test case here
        };
    int expectedSteps[] = {25, 4, 7, 10, 14, 15, 3, 12, 13, 14, 20};
    for (size_t i = 0; i < H_ARRAYSIZE(input); ++i)
    {
        resolve(input[i]);
        //assert(resolve(input[i]) == expectedSteps[i]);
    }
    return 0;
}
