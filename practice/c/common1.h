typedef unsigned char uchar;
typedef enum _Week { Sun, Mon, Tue, Wed, Thu, Fri, Sat } Week;
typedef struct _Grade {
  char Name[20]; // 이름
  int Number;  // 학번
  int Korean; // 국어 점수
  int English; // 영어 점수
  int Math; // 수학 점수
} Grade;