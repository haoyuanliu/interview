#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>

#include "qh_string.h"

void test()
{
    qh::string str1;
    assert(str1.data() == NULL && str1.size() == 0);

    char s[] = "Hello";
    qh::string str2(s);
    assert(str2.size() == 5);

    qh::string str3(s, 10);
    assert(str3.size() == 10);

    qh::string str4(str3);
    assert(str4.size() == 10);

    qh::string str5(str2);
    assert(str5.size() == 5);

    qh::string str6 = str5;
    assert(str6.size() == 5);
}

void test1()
{
    char s[] = "Hello";
    qh::string str1(s);
    printf("%s\n", str1.data());
    printf("%s\n", str1.c_str());
    qh::string str2(str1);
    printf("%s\n", str2.data());
    for(int i = 0; i < str2.size(); ++i)
        printf("%c", str2[i]);
    printf("\n");
}

int main(int argc, char* argv[])
{
    test();
    test1();

#ifdef WIN32
    system("pause");
#endif
    std::cout << "Success!\n";
	return 0;
}
