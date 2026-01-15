### 산술식
## Op         설명                       인수타입  우선순위
>  +X         +X                          숫자      1
>  -X         -X                          숫자      1
>  X*Y        X*Y                         숫자      2
>  X/Y        X/Y(소수점 나누기)            숫자      2
>  bnot X     X의 비트 NOT                 정수      2
>  X div Y    X와 Y의 나누기                정수      2
>  X rem Y    X를 Y로 나눈 나머지           정수      2
>  X band Y   X와 Y의 비트 AND             정수      2
>  X+Y        X+Y                         숫자      3
>  X-Y        X-Y                         숫자      3
>  bor        X와 Y의 비트 OR              정수      3
>  bxor       X와 Y의 비트 XOR             정수      3
>  bsl        X를 산술적 N비트 좌측 이동     정수      3
>  bsr        X를 N비트 우측 이동           정수      3

### 가드 술어
## 술어                    의미
> is_Atom(X)              X는 애텀이다.
> is_binary(X)            X는 바이너리다.
> is_constant(X)          X는 상수다.
> is_float(X)             X는 부동형이다.
> is_function(X)          X는 펀이다.
> is_function(X, N)       X는 N개의 인수를 가지는 펀이다.
> is_integer(X)           X는 정수다.
> is_list(X)              X는 리스트다.
> is_number(X)            X는 정수 또는 부동형이다.
> is_pid(X)               X는 프로세스 식별자다.
> is_port(X)              X는 포트다.
> is_reference(X)         X는 레퍼런스다.
> is_tuple(X)             X는 튜플이다.
> is_record(X, Tag)       X는 형이 Tag인 레코드다.
> is_record(X, Tag, N)    X는 형이 Tag이고 크기가 N인 레코드다.

### 가드 빌트인 함수
## 기능             의미
> abs(X)           X의 절대값.
> element(N, X)    X의 N번째 요소. 이때 X는 튜플이어야 함.
> float(X)         X를 부동형으로 변환. 이때 X는 숫자여야 함.
> hd(X)            리스트 X의 헤드.
> length(X)        리스트 X의 길이.
> node()           현재 노드.
> node(X)          X가 생성되었던 노드. X는 프로세스거나 식별자 또는 레퍼런스나 포트일 수 있다.
> round(X)         X를 정수로 변환. 이때 X는 숫자여야 함.
> self()           현재 프로세스의 식별자.
> size(X)          X의 크기. X는 튜플이거나 바이너리일 수 있다.
> trunc(X)         X를 정수로 절삭함. 이때 X는 숫자여야 함.
> tl(X)            리스트 X의 꼬리(tail).
