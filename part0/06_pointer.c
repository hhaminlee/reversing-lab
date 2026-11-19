// 6장: 포인터는 주소를 담는 변수임
void set_seven(int *p) {
    *p = 7;
}

int use_pointer(void) {
    int v = 0;
    set_seven(&v);
    return v;
}

int main(void) { return use_pointer(); }
