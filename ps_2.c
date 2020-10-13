/*! 
* \author Madhur Malik
* \version 1.0
* \date Oct 13 2020
* Code for problem statement 2
*/

#include<stdio.h>
#include<stdlib.h>


void main (){
    int n1,n2 =0;  //< variables for sizes of nums1 and nums2
    int i=0;
    printf("Enter the number of elements in first array : ");
    scanf(" %d", &n1);
    printf("Enter the number of elements in second array : ");
    scanf(" %d", &n2);
    int *nums1 = (int*) malloc((n1+n2)*sizeof(int));  //< allocatiing mem for nums1 to accomodate nums2
    if(nums1==NULL)                     
    {
        printf("Error! memory not allocated.");
        exit(0);
    }
    int *nums2 = (int*) malloc(n2*sizeof(int));         //< allocating mem for nums2
    if(nums2==NULL)                     
    {
        printf("Error! memory not allocated.");
        exit(0);
    }
    printf("Elements must be added in ascending order \n");
    /*! reading in elements for nums1 */
    for ( i = 0; i < n1; i++)
    {
        printf("Enter the %d element for nums1 array: ", i );
        scanf("%d", nums1+i);
    }
    
    /*! reading in elements for nums2 */
    for ( i = 0; i < n2; i++)
    {
        printf("Enter the %d element for nums2 array: ", i );
        scanf("%d", nums2+i);
    }
    
    
    int *temp = (int*) malloc((n1+n2)*sizeof(int));  //< temp memory allocation to make the modification
    /*! Copying the values of nums1 */
    for ( i = 0; i < n1; i++)
    {
       *(temp +i) = *(nums1+i);
    }

    /*! Checking and modifying nums1 */
    int j,k=0;
    i=0;
    while (i<n1 && j<n2)
    {
        if(*(nums2+j) < *(temp+i))
        {
            *(nums1+k)=*(nums2+j);
            j++;
        }
        else{
            *(nums1+k)=*(temp+i);
            i++;
        }
        k++;
    }
    /*! Copying the left over elements to the nums1 array */
    while (i<n1)
    {
        *(nums1+k)=*(temp+i);
        i++;
    }
    

    while (j<n1)
    {
        *(nums1+k)=*(nums2+j);
        j++;
    }


    /*! printing the sorted arrays */
    printf(" \n The two merged sorted arrays are : ");

    k=0;

    while (k<=(n1+n2))
    {
        printf("%d ", *(nums1+k));
    }
    
  
    free(temp);
    free(nums1);
    free(nums2);
}
