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
void input_players()
{
    int i;

    printf("\n========== 타자 정보 입력 ==========\n");

    printf("입력할 타자 수를 입력하세요 (최대 5명) : ");
    scanf("%d", &player_count);

    if (player_count > MAX_PLAYER)
    {
        player_count = MAX_PLAYER;
        printf("\n최대 5명까지만 입력할 수 있습니다.\n");
    }

    for (i = 0; i < player_count; i++)
    {
        printf("\n[%d번 타자 정보 입력]\n", i + 1);

        printf("타자의 영문 이니셜 한 글자를 입력하세요 : ");
        scanf(" %c", &initial[i]);

        printf("경기 수를 입력하세요 : ");
        scanf("%d", &game[i]);

        printf("타수를 입력하세요 : ");
        scanf("%d", &at_bat[i]);

        printf("안타 수를 입력하세요 : ");
        scanf("%d", &hit[i]);

        printf("홈런 수를 입력하세요 : ");
        scanf("%d", &home_run[i]);

        printf("지난 시즌 타율을 입력하세요 (예: 0.275) : ");
        scanf("%f", &last_avg[i]);
    }

    is_input = 1;
    is_calculated = 0;

    printf("\n타자 정보 입력 완료!\n");
}
   /* ===== 현재 타율 계산 함수 ===== */
   float calculate_average(float f_hit, float f_at_bat)
   {
       return f_hit / f_at_bat;
   }
    