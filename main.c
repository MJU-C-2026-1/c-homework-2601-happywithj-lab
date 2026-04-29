/* 
  파일이름: main.c
  작 성 자: 박승우
  하 는 일: 야구 타자 성적 관리 시스템 v2.0
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
    printf("\t야구 타자 성적 관리 시스템 v2.0\n");
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
    
    printf("\n========== 타자 등급 판정 ==========\n");

    if (current_avg >= 0.330)
    {            
        printf("타자 등급\t: S급 타자\n");
    }
    else if (current_avg >= 0.300)
    {
        printf("타자 등급\t: A급 타자\n"); 
    }
    else if (current_avg >= 0.270)
    {
        printf("타자 등급\t: B급 타자\n");
    }
    else if (current_avg >= 0.250)
    {
        printf("타자 등급\t: C급 타자\n");
    }
    else
    {
        printf("타자 등급\t: D급 타자\n");
    }

    printf("\n========== 강타자 여부 판정 ==========\n");
    
    if (current_avg >= 0.300)
    {
        if (home_run >= 30)
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

    if (current_avg >= 0.300 && home_run >= 30)
    {
        printf("강타자 여부\t: 강타자입니다.\n");
    }
    else
    {   
        printf("강타자 여부\t: 일반 타자입니다.\n"); 
    }

    printf("===================================\n");                  
    
    
    return 0; 
}
