/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-7-18
 */

#include <iostream>
#include <string>
using namespace std;

#define tab "\t"

void Demo() {
  std::string s = "我是bin3";
  std::cout << "s.length()=" << s.length() << std::endl;
  std::wstring ws = L"我是bin3";
  std::cout << "ws.length()=" << ws.length() << std::endl;
  std::wcout << "ws=" << ws << "\n" << "chars(" << ws.length() << "):";
  for (std::size_t i = 0; i < ws.length(); ++i) {
    std::wcout << ws[i] << std::endl;
  }
  std::cout << "Demo end" << std::endl;
}

void Demo2() {
  locale def;
  cout<<def.name()<<endl;
  locale current = cout.getloc();
  cout<<current.name()<<endl;

  float val=1234.56;
  cout<<val<<endl;

  //chage to french/france
  cout.imbue(locale("chs"));
  current=cout.getloc();
  cout<<current.name()<<endl;
  cout<<val<<endl;

  //上面是说明locale的用法，下面才是本例的内容，因为其中用到了imbue函数
  cout<<"*********************************"<<endl;

  //为了保证本地化输出（文字/时间/货币等），chs表示中国，wcout必须使用本地化解析编码
  wcout.imbue(std::locale("chs"));

  //string 英文，正确颠倒位置，显示第二个字符正确
  string str1("ABCabc");
  string str11(str1.rbegin(),str1.rend());
  cout<<"UK\ts1\t:"<<str1<<tab<<str1[1]<<tab<<str11<<endl;

  //wstring 英文，正确颠倒位置，显示第二个字符正确
  wstring str2=L"ABCabc";
  wstring str22(str2.rbegin(),str2.rend());
  wcout<<"UK\tws4\t:"<<str2<<tab<<str2[1]<<tab<<str22<<endl;

  //string 中文，颠倒后，变成乱码，第二个字符读取也错误
  string str3("你好么？");
  string str33(str3.rbegin(),str3.rend());
  cout<<"CHN\ts3\t:"<<str3<<tab<<str3[1]<<tab<<str33<<endl;

  //正确的打印第二个字符的方法
  cout<<"CHN\ts3\t:RIGHT\t"<<str3[2]<<str3[3]<<endl;

  //中文，正确颠倒位置，显示第二个字符正确
  wstring str4=L"你好么？";
  wstring str44(str4.rbegin(),str4.rend());
  wcout<<"CHN\tws4\t:"<<str4<<tab<<str4[1]<<tab<<str44<<endl;

  wstring str5(str1.begin(),str1.end());//只有char类型的string时才可以如此构造
  wstring str55(str5.rbegin(),str5.rend());
  wcout<<"CHN\tws5\t:"<<str5<<tab<<str5[1]<<tab<<str55<<endl;

  wstring str6(str3.begin(),str3.end());//如此构造将失败!!!!
  wstring str66(str6.rbegin(),str6.rend());
  wcout<<"CHN\tws6\t:"<<str6<<tab<<str6[1]<<tab<<str66<<endl;
}

int main(int argc, char **argv) {
  Demo();
//  Demo2();

  return 0;
}
