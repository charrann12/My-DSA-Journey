/*
You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.


approach 1
we will be adding the elements while travesing the array into the map 
if the map size is more than 2 i.e, if map has more than 2 elements in it the other element must shrink. So 
will shrink left in such a way that the size of the map becomes 2 again. So we will place the l pointer at the 
next element after the completely shrinked element gets erased

time complexity is O(n+n) space complexity is O(3)
*/
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l =0, r=0, maxlen = 0;
        map<int, int>mpp;

        while(r<fruits.size()){
            mpp[fruits[r]]++;
            if(mpp.size()>2){
                while(mpp.size()>2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]] == 0) mpp.erase(fruits[l]);
                l++;
            }
            }

            if(mpp.size()<=2){
                maxlen = max(maxlen, r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};

/* approach 2
 remove the while loop
 by this when we are fixed with a maxlength the sliding window just enlarges by next length ie if the maxlen
 before 3rd element enter is 4 after the element enters the length will automatically become 5. And here we will just 
 shrink the elemnt by 1 time so len is 4 and enlarge by 1 element if the condition stays true it becomes the answer, else 
 again shrink.
 */

 class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l =0, r=0, maxlen = 0;
        map<int, int>mpp;

        while(r<fruits.size()){
            mpp[fruits[r]]++;
            if(mpp.size()>2){
                
                mpp[fruits[l]]--;
                if(mpp[fruits[l]] == 0) mpp.erase(fruits[l]);
                l++;
            }
            

            if(mpp.size()<=2){
                maxlen = max(maxlen, r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};

// time complexity is O(n) and space complexity is O(3);