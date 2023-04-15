#include<RTX51TNY.H>
#include<REGX52.H>
#include "queue.h"
sbit BUTTON1 = P3^0;
sbit BUTTON2 = P3^1;
sbit BUTTON3 = P3^2;
sbit BUTTON4 = P3^3;
sbit BUTTON5 = P3^4;
sbit BUTTON6 = P3^5;
sbit BUTTON7 = P3^6;
sbit BUTTON8 = P3^7;
sbit check = P1^7;
sbit check1 = P1^6;
sbit IN1 = P1^0;
sbit IN2 = P1^1;
sbit open = P1^2;
sbit close = P1^3;
int floor;
int cur_floor = 1;
int temp_floor;
//1 tick = 10ms
const int move_time = 2;
const int open_time = 1;
const int close_time = 1;
int up_floor_queue[8] = {0};
int down_floor_queue[8] = {0};
int prev_dir = 1;
int dir = 0;
// up = 1, down = -1, stop = 0
void Startup(void) _task_ 0{
	P1 = 0;
	P2 = 0;
	os_create_task(0);
	os_create_task(1);
	os_create_task(2);
	os_create_task(3);
	os_delete_task(0);
}
void InputFloor(void) _task_ 1{
	while(1){
		if(BUTTON1 == 0){
			floor = 1;
			if(floor > cur_floor){
				up_queue( floor, up_floor_queue, 8);
			}
			else{
				down_queue( floor, down_floor_queue, 8);
			}
			os_send_signal(3);
			while(BUTTON1 == 0);
		}
		if(BUTTON2 == 0){
			floor = 2;
			if(floor > cur_floor){
				up_queue( floor, up_floor_queue, 8);
			}
			else{
				down_queue( floor, down_floor_queue, 8);
			}
			os_send_signal(3);
			while(BUTTON2 == 0);
		}
		if(BUTTON3 == 0){
			floor = 3;
			if(floor > cur_floor){
				up_queue( floor, up_floor_queue, 8);
			}
			else{
				down_queue( floor, down_floor_queue, 8);
			}
			os_send_signal(3);
			while(BUTTON3 == 0);
		}
		if(BUTTON4 == 0){
			floor = 4;
			if(floor > cur_floor){
				up_queue( floor, up_floor_queue, 8);
			}
			else{
				down_queue( floor, down_floor_queue, 8);
			}
			os_send_signal(3);
			while(BUTTON4 == 0);
		}
		if(BUTTON5 == 0){
			floor = 5;
			if(floor > cur_floor){
				up_queue( floor, up_floor_queue, 8);
			}
			else{
				down_queue( floor, down_floor_queue, 8);
			}
			os_send_signal(3);
			while(BUTTON5 == 0);
		}
		if(BUTTON6 == 0){
			floor = 6;
			if(floor > cur_floor){
				up_queue( floor, up_floor_queue, 8);
			}
			else{
				down_queue( floor, down_floor_queue, 8);
			}
			os_send_signal(3);
			while(BUTTON6 == 0);
		}
		if(BUTTON7 == 0){
			floor = 7;
			if(floor > cur_floor){
				up_queue( floor, up_floor_queue, 8);
			}
			else{
				down_queue( floor, down_floor_queue, 8);
			}
			os_send_signal(3);
			while(BUTTON7 == 0);
		}
		if(BUTTON8 == 0){
			floor = 8;
			if(floor > cur_floor){
				up_queue( floor, up_floor_queue, 8);
			}
			else{
				down_queue( floor, down_floor_queue, 8);
			}
			os_send_signal(3);
			while(BUTTON8 == 0);
		}
	}
}

void FloorDisplay(void) _task_ 2{
	while(1){
		switch(cur_floor){
			case 1:
				P2 = 0x06;
				break;
			case 2:
				P2 = 0x5B;
				break;
			case 3:
				P2 = 0x4F;
				break;
			case 4:
				P2 = 0x66;
				break;
			case 5:
				P2 = 0x6D;
				break;
			case 6:
				P2 = 0x7D;
				break;
			case 7:
				P2 = 0x07;
				break;
			case 8:
				P2 = 0x7F;
				break;
		}
	}
}
void Move(void) _task_ 3{
	while(1){
		os_wait1(K_SIG);
		os_clear_signal(3);
		if(floor == cur_floor){
		//open door
			open = 1;
			os_wait2(K_TMO, open_time * 100);
			open = 0;
			os_wait2(K_TMO, 100);
			close = 1;
			os_wait2(K_TMO, close_time * 100);
			close = 0;
		}
		if(floor > cur_floor){
		// move up
			while(cur_floor < up_floor_queue[0]){
				IN1 = 1;
				IN2 = 0;
				os_wait(K_TMO, move_time * 100 , 0);
				cur_floor = cur_floor + 1;
				if(cur_floor == up_floor_queue[0]){
					IN1 = 0;
					IN2 = 0;
					delete_queue(0, up_floor_queue, 8);
					open = 1;
					os_wait2(K_TMO, open_time * 100);
					open = 0;
					os_wait2(K_TMO, 100);
					close = 1;
					os_wait2(K_TMO, close_time * 100);
					close = 0;
				}
			}
		}
		//move down
		if(floor < cur_floor){
			while(cur_floor > down_floor_queue[0]){
				if(cur_floor != 1){
					IN1 = 0;
					IN2 = 1;
					os_wait2(K_TMO, move_time * 100);
					cur_floor = cur_floor - 1;
					if(cur_floor == down_floor_queue[0]){
						IN1 = 0;
						IN2 = 0;
						delete_queue(0, down_floor_queue, 8);
						open = 1;
						os_wait2(K_TMO, open_time * 100);
						open = 0;
						os_wait2(K_TMO, 100);
						close = 1;
						os_wait2(K_TMO, close_time * 100);
						close = 0;
					}
				}
				else{
					IN1 = 0;
					IN2 = 0;
				}
			}
		}
	}
}
/*void up(void) _task_ 4{
	while(1){
		check = 1;
		os_wait2(K_TMO, 200);
		check1 = 1;
	}
}*/
/*void down(void) _task_ 5{
	while(1){
		os_wait1(K_SIG);
		IN1 = 0;
		IN2 = 1;
	}
}
void stop(void) _task_ 6{
	while(1){
		os_wait1(K_SIG);
		IN1 = 0;
		IN2 = 0;
	}
}*/