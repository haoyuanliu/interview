#include "ini_parser.h"

#include <string.h>
#include <assert.h>
#include <stdio.h>

void test()
{
    const char* ini_text = "a=1\nb=2\n";
    qh::INIParser parser;
    if(!parser.Parse(ini_text, strlen(ini_text), "\n", "="))
    {
        printf("Success!\n");
    }
}

void test1()
{
    const char* ini_text= "a=1\nb=2\n";
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "\n", "=")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "");
}

void test2()
{
    const char* ini_text= "a=1||b=2||c=3";
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "||", "=")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "3");
}


void test3()
{
    const char* ini_text= "||||a:1||b:2||||c:3||||||";
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "||", ":")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "3");
}

void test4()
{
    qh::INIParser parser;
    const std::string ini_file_path= "./test.ini";
    if(!parser.Parse(ini_file_path))
        std::cout << "False!" << std::endl;

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "1");

    const std::string& d = parser.Get("d", NULL);
    assert(d == "5");
}

int main(int argc, char* argv[])
{
    //TODO ���������ӵ�Ԫ���ԣ�Խ��Խ�ã�����·��������ԽȫԽ��
    test();
    test1();
    test2();
    test3();
    test4();
    std::cout << "Finished!" << std::endl;
    return 0;
}
