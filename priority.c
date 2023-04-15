#include<stdio.h>


int check_press(int floor, int floor_stat[]){
	if(floor_stat[floor] == 1){
		return 1;
	}
	return 0;
}
int prio_floor(int floor, int floor_stat[]){
}