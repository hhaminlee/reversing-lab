# UnCrackable Level 1 풀이 스크립트
# jadx에서 찾은 문자열 두 개를 아래 따옴표 안에 붙여넣고 실행함
import base64
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes

# 🔑 열쇠: 숫자와 a~f로만 된 32글자 문자열
KEY_HEX = "8d127684cbc37c17616d806cf50473cc"

# 🔒 잠긴 상자: = 로 끝나는 문자열
BOX_B64 = "5UJiFctbmgbDoLXmpL12mkno8HT4Lv8dlat8FxR2GOc="

key = bytes.fromhex(KEY_HEX)          # 글자를 바이트로 바꿈
box = base64.b64decode(BOX_B64)       # 글자를 바이트로 바꿈

# 앱과 똑같은 방식(AES/ECB)으로 상자를 엶
opener = Cipher(algorithms.AES(key), modes.ECB()).decryptor()
opened = opener.update(box) + opener.finalize()

# 끝에 붙은 채움 바이트(패딩)를 잘라냄
opened = opened[:-opened[-1]]

print("비밀 문자열:", opened.decode())
