#include <iostream>
#include <string>
#include <sstream>

#define RESET       "\033[0m"     // 모든 색상과 스타일 초기화

#define BLACK       "\033[30m"    // 텍스트 색상: 검정색
#define RED         "\033[31m"    // 텍스트 색상: 빨간색
#define GREEN       "\033[32m"    // 텍스트 색상: 초록색
#define YELLOW      "\033[33m"    // 텍스트 색상: 노란색
#define BLUE        "\033[34m"    // 텍스트 색상: 파란색
#define MAGENTA     "\033[35m"    // 텍스트 색상: 자홍색
#define CYAN        "\033[36m"    // 텍스트 색상: 청록색
#define WHITE       "\033[37m"    // 텍스트 색상: 흰색

#define BOLDBLACK   "\033[1m\033[30m"    // 굵은 텍스트 색상: 검정색
#define BOLDRED     "\033[1m\033[31m"    // 굵은 텍스트 색상: 빨간색
#define BOLDGREEN   "\033[1m\033[32m"    // 굵은 텍스트 색상: 초록색
#define BOLDYELLOW  "\033[1m\033[33m"    // 굵은 텍스트 색상: 노란색
#define BOLDBLUE    "\033[1m\033[34m"    // 굵은 텍스트 색상: 파란색
#define BOLDMAGENTA "\033[1m\033[35m"    // 굵은 텍스트 색상: 자홍색
#define BOLDCYAN    "\033[1m\033[36m"    // 굵은 텍스트 색상: 청록색
#define BOLDWHITE   "\033[1m\033[37m"    // 굵은 텍스트 색상: 흰색

#define BACKGROUND_BLACK       "\033[40m"   // 배경색: 검정색
#define BACKGROUND_RED         "\033[41m"   // 배경색: 빨간색
#define BACKGROUND_GREEN       "\033[42m"   // 배경색: 초록색
#define BACKGROUND_YELLOW      "\033[43m"   // 배경색: 노란색
#define BACKGROUND_BLUE        "\033[44m"   // 배경색: 파란색
#define BACKGROUND_MAGENTA     "\033[45m"   // 배경색: 자홍색
#define BACKGROUND_CYAN        "\033[46m"   // 배경색: 청록색
#define BACKGROUND_WHITE       "\033[47m"   // 배경색: 흰색

class ScalarConverter
{
public:
	~ScalarConverter(void);
	ScalarConverter& operator=(const ScalarConverter& rhs);
	ScalarConverter(const ScalarConverter& other);

	static void convert(std::string target);

private:

	ScalarConverter(void);

	static double		_doubleType;
	static std::string	convertedType;
	void stringToOtherType(std::string& target);
	void charToOtherType(std::string& target);
};