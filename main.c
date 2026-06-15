/* 
  파일이름: main.c
  작 성 자: 박승우
  하 는 일: 야구 타자 성적 관리 시스템 v4.0
*/

#include <stdio.h>

#define MAX_PLAYER 5

/* ===== 전역 변수 선언 ===== */
char initial[MAX_PLAYER];               // 타자 이니셜 배열
int game[MAX_PLAYER];                   // 경기 수 배열
int at_bat[MAX_PLAYER];                 // 타수 배열
int hit[MAX_PLAYER];                    // 안타 수 배열
int home_run[MAX_PLAYER];               // 홈런 수 배열

float last_avg[MAX_PLAYER];             // 지난 시즌 타율 배열
float current_avg[MAX_PLAYER];          // 현재 타율 배열
float avg_dif[MAX_PLAYER];              // 타율 차이 배열

int player_count = 0;                   // 입력된 타자 수
int is_input = 0;                       // 입력 여부 확인
int is_calculated = 0;                  // 계산 여부 확인

/* ===== 함수 원형 선언 ===== */
void print_menu();
void input_players();
float calculate_average(float f_hit, float f_at_bat);
void calculate_all_stats(int hit_arr[], int at_bat_arr[], float last_avg_arr[], float current_avg_arr[], float avg_diff_arr[], int count);
void print_all_players(char initial_arr[], int game_arr[], int at_bat_arr[], int hit_arr[], int home_run_arr[], float last_avg_arr[], float current_avg_arr[], float avg_diff_arr[], int count);
void analyze_all_players(char initial_arr[], float current_avg_arr[], int home_run_arr[], int count);
void print_grade(float avg);
void analyze_power_hitter(float avg, int hr);

/* ===== 메인 함수 ===== */
int main()
{
    int menu;

    while (1)
    {
        print_menu();

        scanf("%d", &menu); 
        
        if (menu == 1)
        {
            input_players();
        }

        else if (menu == 2)
        {
            calculate_all_stats(hit, at_bat, last_avg, current_avg, avg_diff, player_count);
        }

        else if (menu == 3)
        {
            print_all_players(initial, game, at_bat, hit, home_run, last_avg, current_avg, avg_diff, player_count);
        }

        else if (menu == 4)
        {
            analyze_all_players(initial, current_avg, home_run, player_count);
        }

        else if (menu == 0)
        {
            printf("\n프로그램을 종료합니다.\n");
            break;
        }

        else
        {
            printf("\n잘못된 메뉴 번호입니다.\n");
        }
    }

    return 0;
}

/* ===== 메뉴 출력 함수 ===== */
void print_menu()
{
    printf("\n================================================\n");
    printf("\t야구 타자 성적 관리 시스템 V4.0\n");
    printf("================================================\n");

    printf("1. 타자 정보 입력\n");
    printf("2. 전체 타율 계산\n");
    printf("3. 전체 타자 성적 출력\n");
    printf("4. 전체 타자 등급 및 강타자 여부 분석\n");
    printf("0. 프로그램 종료\n");

    printf("================================================\n");
    printf("메뉴를 선택하세요 : ");
}

/* ===== 타자 정보 입력 함수 ===== */
void input_player()
{
    printf("\n========== 타자 정보 입력 ==========\n");

    printf("타자의 영문 이니셜 한 글자를 입력하세요 : ");
    scanf(" %c", &initial);

    printf("경기 수를 입력하세요 : ");
    scanf("%d", &game);

    printf("타수를 입력하세요 : ");
    scanf("%d", &at_bat);

    printf("안타 수를 입력하세요 : ");
    scanf("%d", &hit);

    printf("홈런 수를 입력하세요 : ");
    scanf("%d", &home_run);

    printf("지난 시즌 타율을 입력하세요 (예: 0.275) : ");
    scanf("%f", &last_avg);

    /* 전역 변수 값 변경 */
    is_input = 1;
    is_calculated = 0;

    printf("\n타자 정보 입력 완료!\n");
}

/* ===== 현재 타율 계산 함수 ===== */
float calculate_average(float f_hit, float f_at_bat)
{
    return f_hit / f_at_bat;
}

/* ===== 타율 계산 함수 ===== */
void calculate_stats()
{
    float f_hit;
    float f_at_bat;

    /* 입력 여부 확인 */
    if (is_input == 0)
    {
        printf("\n먼저 타자 정보를 입력하세요.\n");
    }

    /* 타수 0 검사 */
    else if (at_bat == 0)
    {
        printf("\n타수가 0이면 계산할 수 없습니다.\n");
    }

    else
    {
        /* int → float 변환 */
        f_hit = hit;
        f_at_bat = at_bat;

        /* 현재 타율 계산 */
        current_avg = calculate_average(f_hit, f_at_bat);

        /* 타율 차이 계산 */
        avg_diff = current_avg - last_avg;

        /* 계산 완료 상태 변경 */
        is_calculated = 1;

        printf("\n현재 타율 계산 완료!\n");
    }
}

/* ===== 타자 성적 출력 함수 ===== */
void print_player_info()
{
    if (is_input == 0)
    {
        printf("\n먼저 타자 정보를 입력하세요.\n");
    }

    else if (is_calculated == 0)
    {
        printf("\n먼저 현재 타율을 계산하세요.\n");
    }

    else
    {
        printf("\n========== 타자 성적 결과 ==========\n");

        printf("타자 이니셜\t: %c\n", initial);
        printf("경기 수\t\t: %d\n", game);
        printf("타수\t\t: %d\n", at_bat);
        printf("안타 수\t\t: %d\n", hit);
        printf("홈런 수\t\t: %d\n", home_run);

        printf("지난 시즌 타율\t: %.3f\n", last_avg);
        printf("현재 타율\t: %.3f\n", current_avg);
        printf("타율 차이\t: %.3f\n", avg_diff);
    }
}

/* ===== 타자 등급 판정 함수 ===== */
void print_grade(float avg)
{
    if (is_calculated == 0)
    {
        printf("\n먼저 현재 타율을 계산하세요.\n");
    }

    else
    {
        printf("\n========== 타자 등급 판정 ==========\n");

        /* 다중 조건문 */
        if (avg >= 0.330)
        {
            printf("타자 등급\t: S급 타자\n");
        }

        else if (avg >= 0.300)
        {
            printf("타자 등급\t: A급 타자\n");
        }

        else if (avg >= 0.270)
        {
            printf("타자 등급\t: B급 타자\n");
        }

        else if (avg >= 0.250)
        {
            printf("타자 등급\t: C급 타자\n");
        }

        else
        {
            printf("타자 등급\t: D급 타자\n");
        }
    }
}

/* ===== 강타자 분석 함수 ===== */
void analyze_power_hitter(float avg, int hr)
{
    if (is_calculated == 0)
    {
        printf("\n먼저 현재 타율을 계산하세요.\n");
    }

    else
    {
        printf("\n========== 강타자 여부 판정 ==========\n");

        /* 중첩 조건문 */
        if (avg >= 0.300)
        {
            if (hr >= 30)
            {
                printf("중첩 조건 판정\t: A급 이상이면서 홈런 30개 이상입니다.\n");
            }

            else
            {
                printf("중첩 조건 판정\t: A급 이상이지만 홈런 30개 미만입니다.\n");
            }
        }

        else
        {
            printf("중첩 조건 판정\t: 현재 타율이 0.300 미만입니다.\n");
        }

        /* 논리 연산자 && */
        if (avg >= 0.300 && hr >= 30)
        {
            printf("강타자 여부\t: 강타자입니다.\n");
        }

        else
        {
            printf("강타자 여부\t: 일반 타자입니다.\n");
        }
    }
}



   
    