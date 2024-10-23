<div align="center">
  <h1>🔄 push_swap</h1>
  <p>42Seoul의 다섯 번째 프로젝트: 제한된 명령어로 스택 정렬하기</p>

  <img src="assets/05_push_swap_review.jpg" alt="push_swap Evaluation" width="800">

  [![42 Score](https://img.shields.io/badge/Score-100%2F100-success?style=for-the-badge&logo=42)](https://github.com/your-username/push_swap)
  [![Norminette](https://img.shields.io/badge/Norminette-passing-brightgreen?style=for-the-badge)](https://github.com/42School/norminette)
</div>

## 📋 목차
1. [프로젝트 소개](#-프로젝트-소개)
2. [필수 요구사항](#-필수-요구사항)
3. [구현 가이드](#-구현-가이드)
4. [알고리즘 설명](#-알고리즘-설명)
5. [테스트 및 디버깅 가이드](#-테스트-및-디버깅-가이드)
6. [성능 최적화](#-성능-최적화)
7. [Checker 프로그램](#-checker-프로그램)
8. [메모리 관리](#-메모리-관리)
9. [트러블슈팅](#-트러블슈팅)
10. [참고 자료](#-참고-자료)

## 🎯 프로젝트 소개
push_swap은 제한된 명령어만을 사용하여 스택을 정렬하는 프로그램을 만드는 프로젝트입니다. 두 개의 스택(a와 b)을 사용하여 최소한의 동작으로 스택 a를 오름차순 정렬해야 합니다.

### 주요 학습 목표
- 정렬 알고리즘의 이해와 구현
- 자료구조(스택) 활용
- 알고리즘 최적화
- 메모리 관리

## 📃 필수 요구사항

1. **프로그램 규칙**
   - 두 개의 스택 (a, b) 사용
   - 처음에 모든 숫자는 스택 a에 있음
   - 스택 b는 비어있음
   - 숫자들은 중복되지 않음
   - 목표: 스택 a를 오름차순으로 정렬

2. **사용 가능한 명령어**
   ```
   sa: swap a - 스택 a의 상위 두 원소 교체
   sb: swap b - 스택 b의 상위 두 원소 교체
   ss: sa와 sb를 동시에 실행
   pa: push a - b의 상위 원소를 a로 이동
   pb: push b - a의 상위 원소를 b로 이동
   ra: rotate a - a의 모든 원소를 위로 1칸 이동
   rb: rotate b - b의 모든 원소를 위로 1칸 이동
   rr: ra와 rb를 동시에 실행
   rra: reverse rotate a - a의 모든 원소를 아래로 1칸 이동
   rrb: reverse rotate b - b의 모든 원소를 아래로 1칸 이동
   rrr: rra와 rrb를 동시에 실행
   ```

3. **성능 기준**
   - 3개 정렬: 3개 미만의 명령어
   - 5개 정렬: 12개 미만의 명령어
   - 100개 정렬: 700개 미만의 명령어 (5점)
   - 500개 정렬: 5500개 미만의 명령어 (5점)

## 🛠 구현 가이드

### 1. 스택 구조체 정의
```c
typedef struct s_stack
{
    int             *numbers;
    int             size;
    int             top;
    struct s_stack  *next;
} t_stack;
```

### 2. 기본 연산 구현
```c
// 스택 초기화
t_stack *init_stack(int size)
{
    t_stack *stack;
    
    stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->numbers = (int *)malloc(sizeof(int) * size);
    if (!stack->numbers)
    {
        free(stack);
        return (NULL);
    }
    stack->size = size;
    stack->top = -1;
    stack->next = NULL;
    return (stack);
}

// Push 연산
void push(t_stack *stack, int value)
{
    if (stack->top < stack->size - 1)
        stack->numbers[++stack->top] = value;
}

// Pop 연산
int pop(t_stack *stack)
{
    if (stack->top >= 0)
        return (stack->numbers[stack->top--]);
    return (0);
}
```

### 3. Makefile 구성
```makefile
NAME = push_swap
CHECKER = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = push_swap.c \
       operations.c \
       quick_sort.c \
       utils.c \
       stack.c \
       error.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re
```

## 🔄 알고리즘 설명

### 1. 프로그램 실행 흐름도
```
입력값 검증 → 스택 초기화 → 정렬 수행 → 결과 출력
    ↓             ↓            ↓           ↓
  중복체크     메모리할당    Quick Sort    명령어
  범위체크     초기값설정    Partition     최소화
  숫자변환     에러처리      재귀호출      출력
    ↓             ↓            ↓           ↓
   Error     Stack A, B     정렬완료      Done
```

### 2. 스택 동작 시각화
```
명령어 실행에 따른 스택 변화:

sa          pb          ra 
[2]         [3]         [2]
[1]   →     [2]   →     [3]
[3]         [1]         [1]

rra         pa          완료
[3]         [1]         [1]
[1]    →    [2]   →     [2]
[2]         [3]         [3]
```

### 3. Quick Sort 시각화
```
초기 상태:
Stack A: [5 2 3 1 4]  Stack B: []
Pivot: 3

Step 1 - Partition:
Stack A: [5 4]        Stack B: [1 2 3]    // 3 이하는 B로 이동
                                         // 3보다 큰 수는 A에 남김

Step 2 - A 정렬:
Stack A: [4 5]        Stack B: [1 2 3]    // A의 두 수 정렬

Step 3 - B to A:
Stack A: [4 5 3 2 1]  Stack B: []         // B의 수들을 A로 이동

최종 결과:
Stack A: [1 2 3 4 5]  Stack B: []         // 완전히 정렬됨
```

### 4. Quick Sort 구현
```c
void quick_sort_a(t_stack *a, t_stack *b, int size)
{
    int pivot;
    int pushed;
    
    if (size <= 3)
    {
        sort_small_a(a, size);
        return;
    }
    
    // pivot 선택 및 파티션
    pivot = find_pivot(a, size);
    pushed = partition_a(a, b, pivot, size);
    
    // a 스택 정렬 (pivot보다 큰 부분)
    quick_sort_a(a, b, size - pushed);
    
    // b 스택 정렬 (pivot보다 작은 부분)
    quick_sort_b(a, b, pushed);
}

void quick_sort_b(t_stack *a, t_stack *b, int size)
{
    int pivot;
    int pushed;
    
    if (size <= 3)
    {
        sort_small_b(a, b, size);
        return;
    }
    
    // pivot 선택 및 파티션
    pivot = find_pivot(b, size);
    pushed = partition_b(a, b, pivot, size);
    
    // a 스택 정렬
    quick_sort_a(a, b, pushed);
    
    // b 스택 나머지 부분 정렬
    quick_sort_b(a, b, size - pushed);
}
```

## 🧪 테스트 및 디버깅 가이드

### 1. 단계별 테스트 시나리오
```bash
# 1단계: 기본 케이스
./push_swap 2 1                  # 2개 정렬
./push_swap 3 2 1                # 3개 정렬
./push_swap 4 3 2 1              # 4개 정렬
./push_swap 5 4 3 2 1            # 5개 정렬

# 2단계: 엣지 케이스
./push_swap ""                   # 빈 입력
./push_swap 42                   # 1개 입력
./push_swap 2147483647 -2147483648   # INT 범위
./push_swap 1 2 3 4 5            # 이미 정렬된 경우

# 3단계: 랜덤 테스트
# 100개 테스트
for i in {1..10}; do
    ARG=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')"); \
    echo "Test $i: $(./push_swap $ARG | wc -l) moves"
done

# 500개 테스트
for i in {1..10}; do
    ARG=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')"); \
    echo "Test $i: $(./push_swap $ARG | wc -l) moves"
done
```

### 2. 성능 벤치마크
| 입력 크기 | 평균 명령어 수 | 최소 | 최대 | 목표 |
|-----------|---------------|------|------|------|
| 3개       | 2-3          | 0    | 3    | <3   |
| 5개       | 8-10         | 0    | 12   | <12  |
| 100개     | 550-650      | 500  | 700  | <700 |
| 500개     | 5000-5300    | 4800 | 5500 | <5500|

### 3. 디버깅 도구
```c
// 스택 상태 출력 함수
void debug_print_stacks(t_stack *a, t_stack *b)
{
    printf("\n=== Stack Status ===\n");
    printf("Stack A: ");
    for (int i = a->top; i >= 0; i--)
        printf("%d ", a->numbers[i]);
    printf("\nStack B: ");
    for (int i = b->top; i >= 0; i--)
        printf("%d ", b->numbers[i]);
    printf("\n==================\n");
}

// 명령어 실행 추적
void execute_command(t_stack *a, t_stack *b, char *cmd)
{
    printf("Executing: %s\n", cmd);
    if (!strcmp(cmd, "sa")) sa(a);
    else if (!strcmp(cmd, "sb")) sb(b);
    // ... 다른 명령어들 ...
    debug_print_stacks(a, b);
}
```

### 4. 시각화 도구
```bash
# Python 시각화 스크립트 실행
python3 visualizer.py $(./push_swap 5 4 3 2 1)
```

## 📊 성능 최적화

### 1. Pivot 선택 최적화
```c
// 최적화 전: 단순 중간값 선택
int find_pivot_simple(t_stack *stack, int size)
{
    return stack->numbers[size / 2];
}

// 최적화 후: 중간값 최적화
int find_pivot_optimized(t_stack *stack, int size)
{
    int *temp;
    int i;
    int pivot;
    
    temp = (int *)malloc(sizeof(int) * size);
    i = -1;
    while (++i < size)
        temp[i] = stack->numbers[stack->top - i];
    quick_sort(temp, 0, size - 1);
    pivot = temp[size / 2];
    free(temp);
    return (pivot);
}
```

### 2. 명령어 최적화 예시
```c
// 최적화 전
ra(a);
rb(b);
ra(a);
rb(b);

// 최적화 후
rr(a, b);
rr(a, b);
```

### 3. 시각적 실행 흐름
```
초기 상태          pb + pb           sa
[5]                [5]               [4]
[4]                [4]               [5]
[3]  []    ->      [3]  [2]   ->    [3]  [2]
[2]                      [1]              [1]
[1]

ra + ra           pa + pa           완료
[3]               [1]               [1]
[4]               [2]               [2]
[5]  [2]   ->     [3]  []    ->    [3]
      [1]         [4]               [4]
                  [5]               [5]
```

## 🔍 Checker 프로그램

### 1. 프로그램 설명
- Checker는 push_swap의 정렬 결과를 검증하는 프로그램
- 표준 입력으로 명령어를 받아 실행
- 최종 상태가 정렬되었는지 확인

### 2. 사용 방법
```bash
# 기본 사용법
./checker 3 2 1
rra
pb
sa
pa
[Ctrl+D]

# push_swap과 함께 사용
./push_swap 3 2 1 | ./checker 3 2 1
```

### 3. 결과 해석
- `OK`: 모든 명령어 실행 후 스택이 정렬됨
- `KO`: 모든 명령어 실행 후 스택이 정렬되지 않음
- `Error`: 잘못된 명령어나 인자 입력

## 💾 메모리 관리

### 1. 메모리 누수 체크
```bash
# 기본 체크
valgrind --leak-check=full ./push_swap 1 2 3 4 5

# 상세 체크
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         ./push_swap 1 2 3 4 5
```

### 2. 메모리 관리 주의사항
```c
// 스택 메모리 해제
void free_stack(t_stack *stack)
{
    if (stack)
    {
        if (stack->numbers)
            free(stack->numbers);
        free(stack);
    }
}

// 에러 발생 시 메모리 정리
void handle_error(t_stack *a, t_stack *b)
{
    free_stack(a);
    free_stack(b);
    write(2, "Error\n", 6);
    exit(1);
}
```

### 3. 체크리스트
- [ ] 모든 malloc 호출에 대한 에러 체크
- [ ] 모든 동적 할당 메모리 해제
- [ ] 에러 상황에서 메모리 누수 방지
- [ ] 스택 초기화/해제 순서 확인

## ❗ 트러블슈팅

### 1. 일반적인 문제와 해결방안
1. **스택 오버플로우**
   ```c
   #define MAX_RECURSION_DEPTH 1000
   static int recursion_depth = 0;
   
   void quick_sort_a(t_stack *a, t_stack *b, int size)
   {
       if (++recursion_depth > MAX_RECURSION_DEPTH)
           handle_error(a, b);
       // 정렬 로직 수행
       recursion_depth--;
   }
   ```

2. **정렬 실패**
   ```c
   int is_sorted(t_stack *stack)
   {
       int i;
   
       i = stack->top;
       while (i > 0)
       {
           if (stack->numbers[i] > stack->numbers[i - 1])
               return (0);
           i--;
       }
       return (1);
   }
   ```

3. **비효율적인 명령어**
   ```c
   // 최적화 전
   ra(a); rb(b);
   ra(a); rb(b);
   
   // 최적화 후
   rr(a, b);
   rr(a, b);
   ```

### 2. 자주 발생하는 에러와 해결방법
1. **메모리 관련**
   - 스택 범위 체크 누락
   - NULL 포인터 검사 필요
   - 메모리 해제 순서 주의

2. **입력 검증**
   - INT_MAX/MIN 범위 검사
   - 숫자가 아닌 입력 처리
   - 중복 숫자 체크

3. **알고리즘 관련**
   - pivot 선택 방법 개선
   - 작은 크기 배열 최적화
   - 정렬 완료 조건 확인

## 📚 참고 자료
- [스택 자료구조](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [퀵 정렬 알고리즘](https://en.wikipedia.org/wiki/Quicksort)
- [시간 복잡도](https://en.wikipedia.org/wiki/Time_complexity)