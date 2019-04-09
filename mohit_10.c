#include<stdio.h>
#include<math.h>

main(){
	
	int distance_covered=0 , cur_pos=0 , prev_pos=0;
	bool flag = true;
	
	while(flag)
		{
			cur_pos=143;
			prev_pos=125;
			int my_queue[] = {86, 1470, 913, 1774, 948, 1509, 1022, 1750, 130};
			
			prev_pos = cur_pos;
			for(int i=0;i<9;i++)
                        {
				cur_pos = my_queue[i];
				distance_covered = distance_covered + abs(cur_pos-prev_pos);
				prev_pos = cur_pos;
			}
			
			printf("\nThe total cylinders covered are : %d",distance_covered);
			flag = false;
		}
}
