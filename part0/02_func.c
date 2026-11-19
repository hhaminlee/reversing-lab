// 2장: 함수에 값을 넘기고 결과를 돌려받음
int add(int x, int y) {
    return x + y;
}

int call_add(void) {
    return add(3, 4);
}

int main(void) { return call_add(); }
