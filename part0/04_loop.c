// 4장: 반복문은 뒤로 점프하는 모양이 됨
int sum(int n) {
    int total = 0;
    for (int i = 1; i <= n; i++) {
        total += i;
    }
    return total;
}

int main(void) { return sum(10); }
