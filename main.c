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
sbit IN1 = P1^0;
sbit IN2 = P1^1;
sbit open = P1^2;
sbit close = P1^3;
int floor;
//1s = 100 ticks
int tps = 100; //ticks per second
int cur_floor = 1;
const int move_time = 2;
const int open_time = 1;
const int close_time = 1;
int up_floor_queue[8] = {0};
int down_floor_queue[8] = {0};
void Init(void) _task_ 0{
	P0 = 0;
	P1 = 0;
	P2 = 0;
	P3 = 0;
	os_create_task(1);
	os_create_task(2);
	os_create_task(3);
	os_create_task(4);
	os_create_task(5);
	os_create_task(6);
	os_delete_task(0);
}

void InputFloor(void) _task_ 1{
	while(1){
		if(BUTTON1 == 1){
			floor = 1;
			add_queue(floor, cur_floor, up_floor_queue, down_floor_queue);
			os_send_signal(3);
			while(BUTTON1 == 1);
		}
		if(BUTTON2 == 1){
			floor = 2;
			add_queue(floor, cur_floor, up_floor_queue, down_floor_queue);
			os_send_signal(3);
			while(BUTTON2 == 1);
		}
		if(BUTTON3 == 1){
			floor = 3;
			add_queue(floor, cur_floor, up_floor_queue, down_floor_queue);
			os_send_signal(3);
			while(BUTTON3 == 1);
		}
		if(BUTTON4 == 1){
			floor = 4;
			add_queue(floor, cur_floor, up_floor_queue, down_floor_queue);
			os_send_signal(3);
			while(BUTTON4 == 1);
		}
		if(BUTTON5 == 1){
			floor = 5;
			add_queue(floor, cur_floor, up_floor_queue, down_floor_queue);
			os_send_signal(3);
			while(BUTTON5 == 1);
		}
		if(BUTTON6 == 1){
			floor = 6;
			add_queue(floor, cur_floor, up_floor_queue, down_floor_queue);
			os_send_signal(3);
			while(BUTTON6 == 1);
		}
		if(BUTTON7 == 1){
			floor = 7;
			add_queue(floor, cur_floor, up_floor_queue, down_floor_queue);
			os_send_signal(3);
			while(BUTTON7 == 1);
		}
		if(BUTTON8 == 1){
			floor = 8;
			add_queue(floor, cur_floor, up_floor_queue, down_floor_queue);
			os_send_signal(3);
			while(BUTTON8 == 1);
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
void Move(void) _task_ 3
	{
	while(1)
		{
		os_wait1(K_SIG);
		if(floor == cur_floor)
			{
			os_send_signal(4);
			os_wait2(K_TMO, tps);
			os_send_signal(5);
			os_wait2(K_TMO, open_time * tps);
			os_wait2(K_TMO, tps);
			os_send_signal(6);
			os_wait2(K_TMO, close_time * tps);
			}
		if(floor > cur_floor)
			{
			while(cur_floor < up_floor_queue[0])
				{
				IN1 = 1;
				IN2 = 0;
				os_wait2(K_TMO, move_time * tps);
				cur_floor = cur_floor + 1;
				if(cur_floor == up_floor_queue[0])
					{
						delete_queue(up_floor_queue);
						os_send_signal(4);
						os_wait2(K_TMO, tps);
						os_send_signal(5);
						os_wait2(K_TMO, open_time * tps);
						os_wait2(K_TMO, tps);
						os_send_signal(6);
						os_wait2(K_TMO, open_time * tps);
					}
				}
			}
		if(floor < cur_floor)
			{
			while(cur_floor > down_floor_queue[0])
				{
					IN1 = 0;
					IN2 = 1;
					os_wait2(K_TMO, move_time * tps);
					cur_floor = cur_floor - 1;
					
					if(cur_floor == down_floor_queue[0] && cur_floor != 1)
						{
						delete_queue(down_floor_queue);
						os_send_signal(4);
						os_wait2(K_TMO, tps);
						os_send_signal(5);
						os_wait2(K_TMO, open_time * tps);
						os_wait2(K_TMO, tps);
						os_send_signal(6);
						os_wait2(K_TMO, close_time * tps);
						}
					if(cur_floor == 1){
						os_send_signal(4);
						break;
					}
				}
			}
		}
	}
void Stop(void) _task_ 4
{
	while(1)
	{
		os_wait1(K_SIG);
		IN1 = 0;
		IN2 = 0;
	}
}
void OpenDoor(void) _task_ 5
{
	while(1)
	{
		os_wait1(K_SIG);
		open = 1;
		os_wait2(K_TMO, open_time * tps);
		open = 0;
	}
}
void CloseDoor(void) _task_ 6
{
	while(1)
	{
		os_wait1(K_SIG);
		close = 1;
		os_wait2(K_TMO, close_time * tps);
		close = 0;
	}
}
