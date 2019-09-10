/* placement algorithm for page, optimum */
/* Ngakan Putu Ariastu, 14 Oktober 2017  */

#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int input[50];
	int table [5]; // page table
	int table_range[5]; //store range of current page data to 
						//future use in the list of process
	int size_in;
	int size_tab;
	int hit;
	int n_fault=0;
	int n_hit=0;
	int i,j,k,l,m;
	int target;
	float perct1,perct2;
	
	/*read page size */
	printf("input table size: ");
	scanf("%d",&size_tab);
	printf("\n");
	
	/* initialize data in page to empty */
	for (i=0;i<size_tab;i++)
	{
		table[i]=9999;
	}
	
	/* read data to be processed */
	printf("input in size: ");
	scanf("%d",&size_in);
	printf("\n");
	for (i=0;i<size_in;i++)
	{
		scanf("%d",&input[i]);
	}
	

	/* start optimal process */
	for (i=0;i<size_in;i++)
	{	
		/* update range to future use in page */
		for (k=0;k<size_tab;k++)
		{
			for(l=i;l<size_in;l++)
			{	
				/* if there will be time in the future 
				data would be used	*/ 
				if (table[k] == input[l])
				{
					table_range[k] = l-i;
					break;
				}
				/* otherwise set range to infinity */
				table_range[k] = 9999;
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
			/* search empty page or page with the biggest or 
			 longest time to be used */
			for ( m=0;m<size_tab;m++)
			{
				/* if page empty */
				if (table[m]==9999)
				{
					target = m;
					break;
				}
				/* search the data with longest time to be used */
				if (table_range[target] < table_range[m])
				{
					target = m;
				}
			}
			/* replace it */
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
