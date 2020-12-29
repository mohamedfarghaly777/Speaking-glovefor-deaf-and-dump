
#include "LIB/STD_TYPES.h"
#include "DURT_int.h"
#include "DIO_int.h"
#include "avr/delay.h"




u8 normal_buffer[10] = {0x7E,0xFF,0x06,0x09,0x00,0x00,0x02,0xFE,0xF0,0xEF};

u8 send_buffer[10] = {0x7E,0xFF,0x06,0x09,0x00,0x00,0x02,0x00,0x00,0xEF};

void mp3_init(){

	for(int i =0; i<10; i++){
		UART_vidSendChar(normal_buffer[i]);
	}
}

	void send_play(u16 file_number){
		u8 param2= (file_number&0x00FF);
		u8 param1= ((file_number>>8)&0x00FF);
		send_buffer[3]=0x03;
		send_buffer[5]=param1;
		send_buffer[6]=param2;
	u16	Checksum = 0-(send_buffer[1]+send_buffer[2]+send_buffer[3]+send_buffer[4]+send_buffer[5]+send_buffer[6]);

	u8 check2= (Checksum &0x00FF);
	u8 check1= ((Checksum>>8)&0x00FF);
	send_buffer[7]=check1;
	send_buffer[8]=check2;

		for(int i =0; i<10; i++){
				UART_vidSendChar(send_buffer[i]);
			}


	}







void main(void)
{
	u8 port_value=0;
	DIO_vidSetPinDirection(PortD,Pin0,Input);
	DIO_vidSetPortDir(PortC,Input);
	DIO_vidSetPortValue(PortC,0xFF);


	DIO_vidSetPinDirection(PortD,Pin1,Output);
	DIO_vidSetPortDir(PortA,Output);

	UART_vidInit();




	/*DETRMINING THE SOURCE IS TF CARD */
	_delay_ms(3000);
	mp3_init();
	/*playing song 0000*/



	while(1)
	{
		for(int i=0 ; i<10; i++){
			port_value= dio_u8GetPortValue(PortC);
		_delay_ms(100);
	}

if(port_value==0xFE){

	send_play(1);
}
else if (port_value==0xFD){
	send_play(2);

}
else if (port_value==0xFC){
	send_play(3);

}
else if (port_value==0xFB){
	send_play(4);

}

else if (port_value==0xFA){
	send_play(5);

}

else if (port_value==0xF9){
	send_play(6);

}

else if (port_value==0xF8){
	send_play(7);

}

else if (port_value==0xF7){
	send_play(8);

}

else if (port_value==0xF6){
	send_play(9);

}

else if (port_value==0xF5){
	send_play(10);

}

else if (port_value==0xF4){
	send_play(11);

}

else if (port_value==0xF3){
	send_play(12);

}
else if (port_value==0xF2){
	send_play(13);

}
else if (port_value==0xF1){
	send_play(14);

}
else if (port_value==0xF0){
	send_play(15);

}
else if (port_value==0xEF){
	send_play(16);

}
else if (port_value==0xEE){
	send_play(17);

}
else if (port_value==0xED){
	send_play(18);

}
else if (port_value==0xEC){
	send_play(19);

}
else if (port_value==0xEB){
	send_play(20);

}
else if (port_value==0xEA){
	send_play(21);

}
else if (port_value==0xE9){
	send_play(22);

}
else if (port_value==0xE8){
	send_play(23);

}
else if (port_value==0xE7){
	send_play(24);

}
else if (port_value==0xE6){
	send_play(25);

}
else if (port_value==0xE5){
	send_play(26);

}
else if (port_value==0xE4){
	send_play(27);

}
else if (port_value==0xE3){
	send_play(28);

}
else if (port_value==0xE2){
	send_play(29);

}
else if (port_value==0xE1){
	send_play(30);

}
else if (port_value==0xE0){
	send_play(31);

}


	}
}
