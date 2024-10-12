#include <stdio.h>

int main() {
  int cookie;
  cookie = 0;
  char buf[16];
  printf("&buf: %p, &cookie: %p\n", buf, &cookie);
  gets(buf);

  printf("\ncookie = %10x \n", cookie);
  // ABCD
  if (cookie == 0x41424344) {
    printf("You Win!\n");
  }
}

// ngắt tạm thời random địa chỉ : sudo sysctl -w kernel.randomize_va_space=0
// #cat /proc/sys/kernel/randomize_va_space 
// #sudo bash -c 'echo "kernel.randomize_va_space = 0" >> /etc/sysctl.conf'
// Chú ý Quy ước kết thúc nhỏ 
// biên dịch chương trình
// 32bit $ gcc -fno-stack-protector -ggdb -mpreferred-stack-boundary=2 . /stack1.c -o stack1
// 64bit gcc -fno-stack-protector -ggdb -mpreferred-stack-boundary=4 ./stack1.c -o stack1
// Nhập chuỗi 16 ký tự
// Nhập chuỗi 28 ký tự
// Nhập chuỗi 30 ký tự
// Nhập chuỗi đúng để ra được “You win!”