# reversing-lab

앱 리버싱을 처음 배우는 사람을 위한 한국어 실습 교재입니다.
OWASP의 연습용 앱 **UnCrackable**을 풀면서 바이트, 암호화, 어셈블리를 기초부터 익힙니다.

**웹에서 바로 보기**: https://hhaminlee.github.io/reversing-lab/

## 교재 구성

| 순서 | 교재 | 내용 |
|---|---|---|
| 0부 | [내 코드 뜯어보기](guide/c-to-assembly.html) | 직접 쓴 C 코드를 컴파일해서 어셈블리와 한 줄씩 짝지어 보기 |
| 1부 | [리버싱 첫걸음](guide/reversing-basics.html) | 바이트, 16진수, Base64, AES, 패딩, 비트 플래그. UnCrackable Level 1 풀기 |
| 2부 | [리버싱 둘째 걸음](guide/level2-native.html) | 네이티브 코드, 레지스터, 리틀 엔디안. UnCrackable Level 2 풀기 |

각 장은 **비유 → 실제 데이터 → 직접 해보기 → 확인 문제** 순서로 진행합니다.
교재는 인터넷 없이도 동작합니다. 글꼴과 라이브러리를 저장소 안에 포함했습니다.

어셈블리가 처음이라면 **0부 → 1부 → 2부** 순서를 권합니다.

## 폴더 구조

```
reversing-lab/
├── guide/                 교재 (HTML)
│   ├── c-to-assembly.html   0부
│   ├── reversing-basics.html 1부
│   ├── level2-native.html   2부
│   ├── assets/guide.css     공통 스타일
│   ├── fonts/pretendard/    글꼴 (OFL 1.1)
│   └── vendor/crypto-js/    암호 라이브러리 (MIT)
├── part0/                 0부 실습용 C 예제와 show.sh
└── notes/                 Level 1 풀이 스크립트
```

## 실습 환경 준비

교재의 명령은 저장소를 `~/Desktop/reversing-lab`에 받았다고 가정합니다. 리눅스(Ubuntu) 기준입니다.

```bash
git clone https://github.com/hhaminlee/reversing-lab.git ~/Desktop/reversing-lab
cd ~/Desktop/reversing-lab
```

### 1. jadx (Java 디컴파일러, 1부·2부)

```bash
mkdir -p tools
curl -sL -o tools/jadx.zip https://github.com/skylot/jadx/releases/download/v1.5.7/jadx-1.5.7.zip
unzip -q tools/jadx.zip -d tools/jadx && rm tools/jadx.zip
```

Java 11 이상이 필요합니다.

### 2. 연습용 APK (1부·2부)

```bash
mkdir -p apks
for n in 1 2 3; do
  curl -sL -o apks/UnCrackable-Level$n.apk \
    https://raw.githubusercontent.com/OWASP/mastg/master/Crackmes/Android/Level_0$n/UnCrackable-Level$n.apk
done
```

### 3. 0부 실습 도구

`gcc`, `objdump`(binutils), `gdb`가 필요합니다. Ubuntu에서는 보통 이미 설치되어 있습니다.

```bash
./part0/show.sh 01_vars.c vars
```

## 주의

- 교재에는 UnCrackable Level 1, 2의 **정답이 들어 있습니다**. 2부 정답은 접어 두었습니다.
- 교재의 기법은 **본인 소유이거나 분석이 허락된 앱**에만 사용하세요.

## 출처와 라이선스

- 실습 대상: [OWASP MASTG](https://github.com/OWASP/mastg) UnCrackable Apps ([mas.owasp.org/crackmes](https://mas.owasp.org/crackmes/)), CC BY-SA 4.0
- 교재 속 Java 코드는 jadx 1.5.7로 디컴파일한 결과이고, 어셈블리는 GNU objdump 2.42로 디스어셈블한 결과입니다. 원본 소스코드가 아닙니다.
- 글꼴: [Pretendard](https://github.com/orioncactus/pretendard) 1.3.9, SIL Open Font License 1.1
- 라이브러리: [crypto-js](https://github.com/brix/crypto-js) 4.2.0, MIT License
- 이 저장소의 교재와 예제: **CC BY-SA 4.0** ([LICENSE](LICENSE)). 글꼴과 라이브러리는 각 폴더의 LICENSE를 따릅니다.
