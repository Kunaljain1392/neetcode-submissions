class Solution {
public:
    
    int findDuplicate(vector<int>& arr) {

        // arr ko list mano
        // or jese list me nikalte hai entry point of loop vese hi nikalo

        int slow = arr[0];
        int fast = arr[0];  
        do {
            slow = arr[slow];
            fast = arr[arr[fast]];
        } while(slow != fast);
        slow = arr[0];
        while(slow != fast) {
            slow = arr[slow];
            fast = arr[fast];
        }

        return slow;
    }
};
