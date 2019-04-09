#include<stdio.h>
#include<math.h>

main()
{
	int distance_covered=0 , current_position=0 , previous_position=0;
	bool flag = true;
	
	while(flag)
		{
			current_position=143;
			previous_position=125;
			int queue[] = {86, 1470, 913, 1774, 948, 1509, 1022, 1750, 130};
			
			previous_position = current_position;
			for(int i=0;i<9;i++)
                        {
				current_position = queue[i];
				distance_covered = distance_covered + abs(current_position-previous_position);
				previous_position = current_position;
			}
			
			printf("\nThe total cylinders covered are : %d",distance_covered);
			flag = false;
		}
}
