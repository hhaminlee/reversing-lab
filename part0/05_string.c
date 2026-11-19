// 5장: 문자열은 바이트 배열이고, 비교는 strcmp로 함
#include <string.h>

int check_pw(const char *input) {
    char secret[] = "Thanks for all the fish";
    return strcmp(input, secret) == 0;
}

int main(void) { return check_pw("hello"); }
