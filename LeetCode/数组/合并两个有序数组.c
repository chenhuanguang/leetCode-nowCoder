void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    
    int i=m-1,j=n-1,idx=m+n-1;
    while(i>=0 && j>=0)
    {
        if(nums1[i]>=nums2[j])
        {
            nums1[idx--]=nums1[i--];
        }
        else{ 
            nums1[idx--]=nums2[j--];
        }  
    }
    //如果nums2中有剩余元素，拷贝
        if(j>=0)
        {
            memcpy(nums1,nums2,sizeof(int)*(j+1));
        }
}