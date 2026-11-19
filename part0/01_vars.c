// 1장: 변수는 메모리 칸에 이름을 붙인 것임
int vars(void) {
    int a = 5;
    int b = a + 3;
    return b;
}

int main(void) { return vars(); }
