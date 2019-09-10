/* placement algorithm for page, clock policy*/
/* Ngakan Putu Ariastu, 14 Oktober 2017  */

#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int input[50];
	int table [5]; // data stored
	int table_range[5];	//barrier 
	int size_in;
	int size_tab;
	int hit;
	int n_fault=0;
	int n_hit=0;
	int i,j,k,l,m;
	int target=0;
	int replaced;
	float perct1,perct2;
	
	/* read table size used */
	printf("input table size: ");
	scanf("%d",&size_tab);
	printf("\n");
	
	/* initialize table as empty */
	for (i=0;i<size_tab;i++)
	{
		table[i]=9999;
		table_range[i]=0;
	}
	
	/* read how many data to process */
	printf("input in size: ");
	scanf("%d",&size_in);
	printf("\n");
	
	/* read data */
	for (i=0;i<size_in;i++)
	{
		scanf("%d",&input[i]);
	}
	
	
	/* start clock process */
	for (i=0;i<size_in;i++)
	{
		/* print current page status and inside */
		for (k=0;k<size_tab;k++)
		{
			printf("%d %d\n", table[k], table_range[k]);
		}
	
		printf ("-----------------------------------\n");
		
		/* check whether data is in the page */
		for (j=0;j<size_tab;j++)
		{	
			/* hit = 1 define the data is inside the page */
			if (input[i]== table[j])
			{
				hit = 1;	
				table_range[j]= 1;	//set or reset the barrier
				n_hit++;
				break;
			}
			else 
			{
				hit = 0;
			}
		}
		
		/* if the data is not in the page */
		if (hit == 0)
		{
			n_fault++;
			replaced =0; //status whether the data in page have been replaced or not
			
			/* replace data in the barrier with 0 barrier */
			while (replaced ==0 )
			{
				/* barrier is 0 */
				if (table_range[target] == 0)
				{
					table[target] = input[i];
					table_range[target]= 1;
					replaced = 1;
				}	
				/* barrier is 1 */
				else 
				{
					/*reduce barrier */
					table_range[target]=0; 
					target++;
				}
				/* set page pointer to 0 when target exceed page size */
				if (target==size_tab)
					target =0;
			}
			target++;
			if (target==size_tab)
				target =0;
			printf ("fault\n");
			
		}
	}
	/* print last staus of page */
	for (k=0;k<size_tab;k++)
		{
			printf("%d %d\n", table[k], table_range[k]);
		}
	
		printf ("-----------------------------------\n");
	
	perct1 = (float)n_fault/(float)size_in *100.0;	// percentage of fault with pre paging
	perct2 = (float)(n_fault-size_tab)/(float)size_in *100.0;// percentage of fault without pre paging
	printf("fault = %d\nhit = %d",n_fault,n_hit);
	printf("\nfault (with prefault) = %f",perct1);
	printf("\nfault (without prefault) = %f",perct2);
	
	return 0;
	
}
