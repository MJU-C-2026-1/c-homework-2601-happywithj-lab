/* 
  파일이름: main.c
  작 성 자: 박승우
  하 는 일: 야구 타자 성적 관리 시스템 V1.0
*/

#include <stdio.h>

int main()
{
    char initial;               // 타자 이니셜
    int game;                   // 경기 수
    int at_bat;                 // 타수
    int hit;                    // 안타 수
    int home_run;               // 홈런 수
    float last_avg;             // 지난 시즌 타율
    float current_avg;          // 현재 타율
    float avg_diff;             // 타율 차이
    float f_hit;                // 실수 계산용 안타 수
    float f_at_bat;             // 실수 계산용 타수

    printf("================================================\n");
    printf("\t야구 타자 성적 관리 시스템 V1.0\n");
    printf("================================================\n\n");

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

    f_hit = hit;
    f_at_bat = at_bat;

    current_avg = f_hit / f_at_bat;
    avg_diff = current_avg - last_avg;

    printf("\n");
    printf("========== 타자 성적 결과 ==========\n");
    printf("타자 이니셜\t: %c\n", initial);
    printf("경기 수\t\t: %d\n", game);
    printf("타수\t\t: %d\n", at_bat);
    printf("안타 수\t\t: %d\n", hit);
    printf("홈런 수\t\t: %d\n", home_run);
    printf("지난 시즌 타율\t: %.3f\n", last_avg);
    printf("현재 타율\t: %.3f\n", current_avg);
    printf("타율 차이\t: %.3f\n", avg_diff);
    printf("====================================\n");

    return 0; 
}
