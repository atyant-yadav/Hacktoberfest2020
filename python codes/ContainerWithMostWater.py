# CONTAINER WITH MOST WATER:
#
# In this question, height of bars of a bar graph is given and we need to find out the max water that can be stored.
#
    # Question Link
# https://leetcode.com/problems/container-with-most-water/submissions/
#
#
# Algorithm:
# 	1.
# We can notice that area between two bars is given by the product of the min pf height b/w two bars and width between them.
# 	2.
# we set one pointer to 0th index and other to the last index.
# 	3.
# We calculate the max_ area and shift the pointer whichis pointing at the smaller height to the next height.
# 	4.
# In this way when the starting pointer crosses the end pointer , we stop and return max_area.




def maxArea(height):
    i = 0
    j = len(height) - 1
    max_area = 0
    while i<j:
        width = j-i
        cur_area = min(height[i],height[j]) * width
        max_area = max(max_area,cur_area)

        if height[i] < height[j]:
            i+=1
        else:
            j-=1

    return max_area

