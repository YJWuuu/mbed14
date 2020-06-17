#include"mbed.h"

Serial pc(USBTX,USBRX); //tx,rx
Serial uart(D1,D0); //tx,rx
DigitalIn button(SW2);

Thread thread1;

void send_thread(){
   while(1){
      if( button == 0){
         char s[21];
         sprintf(s,"QRCodeDecoding");
         uart.puts(s);
         wait(0.5);
      }
   }
}
int main(){
   uart.baud(9600);
   thread1.start(send_thread);
   while(1) {
      if(uart.readable()){
            char recv = uart.getc();
            pc.putc(recv);
            // pc.printf("\r\n");
      }
   }
}