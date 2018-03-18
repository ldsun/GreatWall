Question is: 

Given an array consists of only 0 and 1, and they are scattered randomly. How to remove 0 at most K times, so that you have a longest subarray of 1s, point out the start index and end index of that subarray. 

Analysis:
1. All removed Os can't have 0s that are not removed in between. 
2. When updating start index, need to cross over at least one 0.
3. When updating end index, as long as there's available 0s, you can move to next 0. If there's no available 0 to remove, stop before next 0. 
4. When calculating the length of 1s: end index - start index + 1 - # of removed 0s
