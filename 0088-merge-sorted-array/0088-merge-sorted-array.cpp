class Solution {
public:
    //use two pointer to point two sorted arr , pick the smaller one put into the result arr , if there is one of the sorted has empty put the rest element in other arr to the result arr cus it must be lager than all the element in the result arr 
    /*v1
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr = 0;
        int cur = nums1[0];
        int count = 0;

        if(m!= 0 && n!= 0){
            for(int i=0 ; i<m+n ; i++ ){
                if(count != m){
                   if(nums1[i]>nums2[ptr]){
                        nums1[i+1] = nums1[i];
                        nums1[i] = nums2[ptr];
                        ptr++;
                        if(ptr==n){
                            break;
                        }
                    }else{
                        count++;
                    } 
                }else{
                    nums1[i] = nums2[ptr];
                    ptr++;
                }
                
            }
           
        }
        if(m == 0){
            nums1 = nums2;
        }

        
        
        
    }
    */
    /*
    //use old merge sort merge
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums1_cp(m);
        for(int i=0 ; i < m ;i++){
            nums1_cp[i] = nums1[i];
        }
        int ptr1 = 0;
        int ptr2 = 0;
        int ptr3 = 0;
        while(ptr1 < m && ptr2 < n){
            if(nums1_cp[ptr1]<=nums2[ptr2]){
                nums1[ptr3] = nums1_cp[ptr1];
                ptr1++;
            }else{
                nums1[ptr3] = nums2[ptr2];
                ptr2++;
            }
            ptr3++;
        }
        if(ptr1 == m && ptr2 != n){
            for(int i=ptr3 ; i< m+n ; i++){
                nums1[i] = nums2[ptr2];
                ptr2++;
            }
        }
        if(ptr2 == n && ptr1 != m){
            for(int i=ptr3 ; i< m+n ; i++){
                nums1[i] = nums1_cp[ptr1];
                ptr1++;
            }
        }
    }
    */
    //there has space for the merge in the back so if I put the largest num from the back it wont affect the num already in nums1
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr1 = m - 1;
        int ptr2 = n - 1;
        int i = m + n - 1;

        while (ptr1 >= 0 && ptr2 >= 0) {
            if (nums1[ptr1] > nums2[ptr2]) {
                nums1[i] = nums1[ptr1];
                ptr1--;
            } else {
                nums1[i] = nums2[ptr2];
                ptr2--;
            }
            i--;
        }

        while (ptr2 >= 0) {
            nums1[i] = nums2[ptr2];
            ptr2--;
            i--;
        }
    
    }
};