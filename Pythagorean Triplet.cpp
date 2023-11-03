class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    // code here
	    unordered_map<int , bool>Hashmap;
	  for(int i = 0; i < n ; i++){
	      Hashmap[arr[i]*arr[i]] = true;
	      arr[i] = arr[i]*arr[i];
	  }
	  for(int i = 0; i < n ; i++){
	      for(int j = i+1; j < n ; j++){
	          if(Hashmap[arr[i]+arr[j]]) return true;
	      }
	  } 
	  return false;
	}
};
