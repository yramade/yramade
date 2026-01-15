#include <iostream>

class Date {
  int year_;
  int month_; // 1부터 12까지;
  int day_; // 1부터 31까지

  private:
    bool isLeapYear(int year) { // 윤년 계산
      if (year % 400 == 0) return true;     // 400의 배수는 윤년
      if (year % 100 == 0) return false;    // 100의 배수는 평년
      if (year % 4 == 0) return true;       // 4의 배수는 윤년
      return false;                         // 나머지는 평년
    }
    int getDaysInMonth (int year, int month) { // 해당 월의 일수 리턴
      int month_day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      if(month == 2 && isLeapYear(year)) return 29; // 2월 윤년 체크
      return month_day[month - 1];
    }

  public:
    void setDate(int year, int month, int day) {
      year_ = year;
      month_ = month;
      day_ = day;
    };

    void AddDay(int inc) {
      day_ += inc;

      while (getDaysInMonth(year_, month_) < day_) {
        day_ -= getDaysInMonth(year_, month_);
        month_ ++;

        if (month_ > 12) {
          month_ = 1;
          year_ ++;
        }
      }
    };

    void AddMonth(int inc) {
      month_ += inc;

      while (month_ > 12) {
        month_ -= 12;
        year_ ++;
      }

      // 현재 일자가 바뀐 달의 마지막 일자보다 크면 마지막 일자로 맞춤
      int days_in_month = getDaysInMonth(year_, month_);
      if (day_ > days_in_month) {
        day_ = days_in_month;
      }
    };
    void AddYear(int inc) {
      year_ += inc;
      
      // 윤년에서 평년으로 바뀌는 경우 2월 29일 처리
      if (month_ == 2 && day_ == 29 && !isLeapYear(year_)) {
        day_ = 28;
      }
    };

    void ShowDate(){
      std::cout << year_ << "년 " << month_ << "월 " << day_ << "일" << std::endl;
    };
};

int main()
{
  int year, month, day;
  std::cout << "연도 입력 : ";
  std::cin >> year;
  std::cout << "월 입력 : ";
  std::cin >> month;
  std::cout << "일자 입력 : ";
  std::cin >> day;

  Date date;
  date.setDate(year, month, day);

  while (1)
  {
    int order = 0;
    std::cout << "1. 연도 더하기" << std::endl;
    std::cout << "2. 월 더하기" << std::endl;
    std::cout << "3. 일 더하기" << std::endl;
    std::cout << "4. 날짜 출력" << std::endl;
    std::cout << "5. 종료" << std::endl;

    std::cin >> order;

    switch (order)
    {
    case 1: 
      std::cout << "더할 연도 입력 : ";
      std::cin >> year;
      date.AddYear(year);
      date.ShowDate();
      break;
    case 2: 
      std::cout << "더할 월 입력 : ";
      std::cin >> month;
      date.AddMonth(month);
      date.ShowDate();
      break;
    case 3:
      std::cout << "더할 일자 입력 : ";
      std::cin >> day;
      date.AddDay(day);
      date.ShowDate();
      break;
    case 4:
      date.ShowDate();
      break;
    case 5:
    default:
      std::cout << "종료합니다." << std::endl;
      return 0;
    }
  }
  

  return 0;
}