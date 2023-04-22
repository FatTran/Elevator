void up_queue(int floor, int floor_queue[])
	{
		int i, j;
		int index = 0;
		for(i = 8 - 1; i >  index ; i--){
			floor_queue[i] = floor_queue[i - 1];
		}
		floor_queue[index] = floor;
		for (i = 0; i < 8; i++) 
		{
			if (floor_queue[i] != 0) 
				{
				for (j = i + 1; j < 8; j++) 
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
void down_queue( int floor, int floor_queue[])
	{
		int i, j;
		int index = 0;
		for(i = 8 - 1; i >  index ; i--){
			floor_queue[i] = floor_queue[i - 1];
		}
		floor_queue[index] = floor;
		for (i = 0; i < 8; i++) 
		{
			if (floor_queue[i] != 0) 
				{
				for (j = i + 1; j < 8; j++) 
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
void delete_queue(int floor_queue[])
{
	int i;
			for(i = 0 ; i < 8; i++)
				{
					if (i + 1 < 8) 
						{
						floor_queue[i] = floor_queue[i + 1];
						}
					else 
						{
						floor_queue[i] = 0;
						}
				}
				return;
	}
int checker(int floor, int floor_queue[])
{
	int i;
	for(i = 0; i < 8; i++){
		if(floor_queue[i] == floor){
			return 1;
		}
	}
	return 0;
}
void add_queue(int floor, int cur_floor, int up_floor_queue[], int down_floor_queue[])
{
		if(floor > cur_floor && !checker(floor, up_floor_queue)){
				up_queue( floor, up_floor_queue);
			}
		if(floor < cur_floor && !checker(floor, down_floor_queue)){
				down_queue( floor, down_floor_queue);
			}
		return;
}
