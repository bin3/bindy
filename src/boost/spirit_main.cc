/*
 * Copyright (c) 2012 Binson Zhang. All rights reserved.
 *
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2012-8-11
 */

#define  BOOST_SPIRIT_NO_REGEX_LIB

#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include <iostream>
#include <string>
#include <list>
#include <map>

#define CODE_CPP_KEYWORD_ENUM "enum"

namespace haha {
//简单表示c++的enum的类
struct CPPCodeEnum {
  //enum的名称
  std::string enumName;
  //成员的名称
  std::list<std::string> enumMembers;
};
}

namespace haha {
namespace fusion = boost::fusion;
namespace phoenix = boost::phoenix;
namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

//enum的简单解析器
template<typename Iterator>
struct CPPCodeEnumGrammar: qi::grammar<Iterator, CPPCodeEnum(),
    ascii::space_type> {
  CPPCodeEnumGrammar() :
      CPPCodeEnumGrammar::base_type(start) {

    using qi::_val;
    using qi::_1;
    using qi::lit;
    using qi::lexeme;
    using qi::raw;
    using qi::space;
    using ascii::char_;
    using ascii::string;
    using phoenix::push_back;
    //解析一个变量名（他不符合C++的命名规范，暂时只是个替代品）
    quoted_string = lexeme[+(qi::alpha | qi::digit | char_('_'))];

    //解析“enum”
    start = lit(CODE_CPP_KEYWORD_ENUM)
        >>
        //取得enum名
        *quoted_string[phoenix::bind(&CPPCodeEnum::enumName, _val) = _1]
        >> char_("{") >>
        //解析enum的成员
        *(quoted_string[push_back(
            phoenix::bind(&CPPCodeEnum::enumMembers, _val), _1)] % ',') >>
        //可有可无的逗号小尾巴
        -char_(",") >> char_("}");

  }

  qi::rule<Iterator, std::string(), ascii::space_type> quoted_string;
  qi::rule<Iterator, CPPCodeEnum(), ascii::space_type> start;
};
}

int main(int argc, char *argv[]) {
  //模拟C++的一段代码
  std::string code = "enum myename {m1,m2  ,m3 ,m4 ,}";

  using boost::spirit::ascii::space;

  haha::CPPCodeEnumGrammar<std::string::const_iterator> myCPPCodeEnumGrammar;
  haha::CPPCodeEnum data;

  bool r = phrase_parse(code.begin(), code.end(), myCPPCodeEnumGrammar, space, data);
  std::cout << "r=" << r << std::cout;

  return 0;
}

