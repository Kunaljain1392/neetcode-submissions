class Solution {
public:
    
    int findDuplicate(vector<int>& arr) {

        // APPROACH - 1 : arr ko list mano
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

        // APPROACH - 2 : array ke elemt -1 index wali value ko 
        // negative krdo agr value phele se hi negative hai to vo duplicate hai 
        // curr arr[i] duplicate hai
        // nhi to usse negative kr do l


        return slow;
    }
};
