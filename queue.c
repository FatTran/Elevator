#include<stdio.h>
void up_queue(int floor, int floor_queue[], int n)
	{
		int i, j;
		int index = 0;
		for(i = n - 1; i >  index ; i--){
			floor_queue[i] = floor_queue[i - 1];
		}
		floor_queue[index] = floor;
		for (i = 0; i < n; i++) 
		{
			if (floor_queue[i] != 0) 
				{
				for (j = i + 1; j < n; j++) 
					{
					if (floor_queue[j] != 0 && floor_queue[i] > floor_queue[j]) 
						{
							int temp = floor_queue[i];
							floor_queue[i] = floor_queue[j];
							floor_queue[j] = temp;
						}
					}
				}
			}
		return;
		}
void down_queue( int floor, int floor_queue[], int n)
	{
		int i, j;
		int index = 0;
		for(i = n - 1; i >  index ; i--){
			floor_queue[i] = floor_queue[i - 1];
		}
		floor_queue[index] = floor;
		for (i = 0; i < n; i++) 
		{
			if (floor_queue[i] != 0) 
				{
				for (j = i + 1; j < n; j++) 
					{
					if (floor_queue[j] != 0 && floor_queue[i] < floor_queue[j]) 
						{
							int temp = floor_queue[i];
							floor_queue[i] = floor_queue[j];
							floor_queue[j] = temp;
						}
					}
				}
			}
		return;
	}
void delete_queue(int floor_queue[], int n)
{
	int i,j;
	for(i = 0; i < n; i++)
		{
			for(j = i ; j < n; j++)
				{
					if (j + 1 < n) 
						{
						floor_queue[j] = floor_queue[j + 1];
						}
					else 
						{
						floor_queue[j] = 0;
						}
				}
				return;
			}
}
int checker(int value, int floor_queue[], int n)
{
	int i;
	for(i = 0; i < n; i++){
		if(floor_queue[i] == value){
			return 1;
		}
	}
	return 0;
}
void add_queue(int floor, int cur_floor, int up_floor_queue[], int down_floor_queue[])
{
		if(floor > cur_floor && !checker(floor, up_floor_queue, 8)){
				up_queue( floor, up_floor_queue, 8);
			}
		if(floor < cur_floor && !checker(floor, down_floor_queue, 8)){
				down_queue( floor, down_floor_queue, 8);
			}
		return;
}
