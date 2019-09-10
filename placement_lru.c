/* placement algorithm for page, lru */
/* Ngakan Putu Ariastu, 14 Oktober 2017  */

#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int input[50];
	int table [5]; //page table
	int table_range[5]; //store current used status of data in the page 
	int size_in;
	int size_tab;
	int hit;
	int n_fault=0;
	int n_hit=0;
	int i,j,k,l,m;
	int target; //pointer to data in page table
	float perct1,perct2;
	
	/* read size of page table*/
	printf("input table size: ");
	scanf("%d",&size_tab);
	printf("\n");
	
	/* initialize data and range in page */
	for (i=0;i<size_tab;i++)
	{
		table[i]=9999;
		table_range[i]=9999;
	}
	
	/* read data */
	printf("input in size: ");
	scanf("%d",&size_in);
	printf("\n");
	for (i=0;i<size_in;i++)
	{
		scanf("%d",&input[i]);
	}
	
	/* start LRU proces */
	for (i=0;i<size_in;i++)
	{	
		/* update last used count status */
		for (k=0;k<size_tab;k++)
		{
			for(l=0;l<=i;l++)
			{
				if (table[k] == input[l])
				{
					table_range[k] = i-l;
				}
			}
		}	
		
		/* print current status of page */
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
				n_hit++;
				break;
			}
			else 
			{
				hit = 0;
			}
		}
		
		/* replace data in page if hit = 0*/
		if (hit == 0)
		{
			n_fault++;
			target = 0;
			/* search data in page with biggest last used count */
			for ( m=0;m<size_tab;m++)
			{
				if (table_range[target] < table_range[m])
				{
					target = m;
				}
			}
			table[target] = input[i]; 
			printf ("fault\n");
			
		}
	}
	
	/* print last page status */
	for (k=0;k<size_tab;k++)
		{
			printf("%d %d\n", table[k], table_range[k]);
		}
	
		printf ("-----------------------------------\n");
		
	perct1 = (float)n_fault/(float)size_in *100.0;// percentage of fault with pre paging
	perct2 = (float)(n_fault-size_tab)/(float)size_in *100.0;// percentage of fault without pre paging
	printf("fault = %d\nhit = %d",n_fault,n_hit);
	printf("\nfault (with prefault) = %f",perct1);
	printf("\nfault (without prefault) = %f",perct2);
	
	return 0;
	
}
