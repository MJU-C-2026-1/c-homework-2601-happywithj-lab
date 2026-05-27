/* 
  파일이름: main.c
  작 성 자: 박승우
  하 는 일: 야구 타자 성적 관리 시스템 v3.0
*/

#include <stdio.h>

/* ===== 전역 변수 선언 ===== */
char initial;               // 타자 이니셜
int game;                   // 경기 수
int at_bat;                 // 타수
int hit;                    // 안타 수
int home_run;               // 홈런 수

int is_input = 0;           // 입력 여부 확인
int is_calculated = 0;      // 계산 여부 확인

float last_avg;             // 지난 시즌 타율
float current_avg;          // 현재 타율
float avg_diff;             // 타율 차이

/* ===== 함수 원형 선언 ===== */
void print_menu();
void input_player();
float calculate_average(float f_hit, float f_at_bat);
void calculate_stats();
void print_player_info();
void print_grade(float avg);
void analyze_power_hitter(float avg, int hr);

/* ===== 메인 함수 ===== */
int main()
{
    int menu;

    /* ===== 무한 반복 메뉴 ===== */
    while (1)
    {
        print_menu();

        scanf("%d", &menu); 
        
        /* 메뉴 1 : 타자 정보 입력 */
        if (menu == 1)
        {
            input_player();
        }

        /* 메뉴 2 : 현재 타율 계산 */
        else if (menu == 2)
        {
            calculate_stats();
        }

        /* 메뉴 3 : 타자 성적 출력 */
        else if (menu == 3)
        {
            print_player_info();
        }

        /* 메뉴 4 : 등급 및 강타자 분석 */
        else if (menu == 4)
        {
            print_grade(current_avg);
            analyze_power_hitter(current_avg, home_run);
        }

        /* 메뉴 0 : 프로그램 종료 */
        else if (menu == 0)
        {
            printf("\n프로그램을 종료합니다.\n");
            break;
        }

        /* 잘못된 메뉴 입력 */
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
  
}

   
    