#include<stdio.h>
void up_queue(int floor, int floor_queue[], int n){
		int i, j;
		int index = 0;
		for(i = n - 1; i >  index ; i--){
			floor_queue[i] = floor_queue[i - 1];
		}
		floor_queue[index] = floor;
		for (i = 0; i < n; i++) {
			if (floor_queue[i] != 0) {
				for (j = i + 1; j < n; j++) {
					if (floor_queue[j] != 0) {
						if (floor_queue[i] > floor_queue[j]) {
							int temp = floor_queue[i];
							floor_queue[i] = floor_queue[j];
							floor_queue[j] = temp;
							}
						}
					}
				}
			}
		}
void down_queue( int floor, int floor_queue[], int n){
		int i, j;
		int index = 0;
		for(i = n - 1; i >  index ; i--){
			floor_queue[i] = floor_queue[i - 1];
		}
		floor_queue[index] = floor;
		for (i = 0; i < n; i++) {
			if (floor_queue[i] != 0) {
				for (j = i + 1; j < n; j++) {
					if (floor_queue[j] != 0) {
						if (floor_queue[i] < floor_queue[j]) {
							int temp = floor_queue[i];
							floor_queue[i] = floor_queue[j];
							floor_queue[j] = temp;
							}
						}
					}
				}
			}
		}
void delete_queue(int index, int floor_queue[], int n){
	int i,j;
	for(i = 0 ; i < n; i++){
		if(i == index){
			for(j = i ; j < n; j++){
				if (j + 1 < n) {
					floor_queue[j] = floor_queue[j + 1];
				}
				else {
					floor_queue[j] = 0;
				}
			}
			break;
		}
	}
}