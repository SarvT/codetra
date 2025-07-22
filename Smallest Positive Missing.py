class Solution:
    def missingNumber(self, arr):
        # code 
        set_arr = set(arr)
        set_arr = list(set_arr)
        
        list_pos = []
        
        for i in range(len(set_arr)):
            if set_arr[i] > 0:
                list_pos.append(set_arr[i])
                
        if(len(list_pos) == 0): return 1
                
        smallest = list_pos[0]
        
        for j in range(len(list_pos)):
            if smallest > list_pos[j]:
                smallest = list_pos[j]
                
        if smallest != 1:
            return 1
        
        while True:
            smallest += 1
            if smallest not in list_pos:
                return smallest
