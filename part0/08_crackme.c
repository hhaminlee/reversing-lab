// 8장: 나만의 미니 crackme
// 사용법: ./build/08_crackme-O2 비밀번호
#include <stdio.h>
#include <string.h>

int check_pw(const char *input) {
    char secret[] = "robot-fms-2026";   // 여기를 바꿔서 친구에게 풀게 해봐도 됨
    if (strlen(input) != strlen(secret)) {
        return 0;
    }
    return strcmp(input, secret) == 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("사용법: %s 비밀번호\n", argv[0]);
        return 1;
    }
    if (check_pw(argv[1])) {
        printf("Success!\n");
    } else {
        printf("Nope...\n");
    }
    return 0;
}
