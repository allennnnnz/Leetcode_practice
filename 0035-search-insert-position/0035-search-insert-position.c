int Binary_search(int* nums,int f,int r,int target){
    
    int mid_pos = (f+r)/2;

    if(f>r){
        return f;
    }
    if (nums[mid_pos] == target){
        return mid_pos;
    }
    if (nums[mid_pos] < target){
        return Binary_search(nums,mid_pos+1,r,target);
    }
    else{
         return Binary_search(nums,f,mid_pos-1,target);
    }
    return mid_pos;
}



int searchInsert(int* nums, int numsSize, int target) {
    int res = Binary_search(nums,0,numsSize-1,target);
  
    return res;
}