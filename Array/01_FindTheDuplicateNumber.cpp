// ques link: https://leetcode.com/problems/find-the-duplicate-number/

// Frute Force Approach:TC=O(nlogn)-> bakwas, space complexity:O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());  //sort func likhne me mistake krta hai 😀,syntax dekh
        int i=0;
        while(i<nums.size()-1){
            if(nums[i]==nums[i+1]){
                return nums[i];
            }
            i++;
        }
        return -1;

    }
};


//method 2: by using Linked list cycle and floyd Algorithm: https://res.cloudinary.com/sameerkhan/image/upload/v1728039987/codehelp%20dsa%20images/Screenshot_2024-10-04_163651_hxbogp.png 

// time complexity:O(N)

/*
    step 1: represeent array in LL with cycle:
        https://res.cloudinary.com/sameerkhan/image/upload/v1728039987/codehelp%20dsa%20images/Screenshot_2024-10-04_163651_hxbogp.png
    step2:ab hme wo point dhoodna hai, jahah pr LL ki cycle start horhi hai,isko hm dhoond skte hai, by using flued algorith
        https://res.cloudinary.com/sameerkhan/image/upload/v1728040706/codehelp%20dsa%20images/Screenshot_2024-10-04_163651_se4wqw.png
    step3:isko krne k liye hm 2 pointer lenge, named as slow and fast pointer
            in each iteration, slow pointer increment by 1 and fast pointer will increment by 2, until we find first intersection pointer jahan pr dono pointer first time meet krenge
    step4:ek baar jb hme first wala point of intersection milgya,uske baad hme sirf floyd algoritm lagana hai, or dhoodna hai
    step5: fast pointer ko starting node se point krado,or fir slow or fast ko 1-1 step increment krke iterate krte jao
    step6: jahan pr ye meet kre, wo hmara second point of interection hoga or wahi ans hoga.

*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];
        // Move slow and fast pointers at least once before starting the loop
        slow = nums[slow];
        fast = nums[nums[fast]];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        fast=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};


