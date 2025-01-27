// partial
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        set<vector<int>> st;
        vector<bool> vec;
        vector<vector<int>> newvec(prerequisites.begin(), prerequisites.end());
        int n=prerequisites.size();
        for(int one=0; one<n-1; one++){
            for(int two=one+1; two<n; two++){
                if(prerequisites[one][1]==prerequisites[two][0])
                newvec.emplace_back({prerequisites[one][0], prerequisites[two][1]});
            }
        }
        for(int one=n; one<prerequisites.size()-1; one++){
            for(int two=one+1; two<prerequisites.size(); two++){
                if(newvec[one][1]==newvec[two][0])
                st.insert({prerequisites[one][0], prerequisites[two][1]});
            }
        }
        for(auto it:newvec) st.insert(it);
        for(auto it:queries) {
            if(st.find(it)!=st.end()){
                vec.emplace_back(true);
                continue;
            } else {
                vec.emplace_back(false);
                st.insert(it);
            }
        }
        return vec;
    }
};


//partial
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        set<vector<int>> st;
        vector<bool> vec;
        int n=prerequisites.size();
        for(int one=0; one<n-1; one++){
            for(int two=one+1; two<n; two++){
                if(prerequisites[one[1]]==prerequisites[two[0]]) st.insert({prerequisites[one[0]], prerequisites[two[1]]});
            }
        }
        for(auto it:prerequisites) st.insert(it);
        for(auto it:queries) {
            if(st.find(it)!=st.end()){
                vec.emplace_back(true);
                continue;
            } else {
                vec.emplace_back(false);
                st.insert(it);
            }
        }
        return vec;
    }
};


// working
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // set<vector<int>> st;
        // vector<bool> vec;
        // int n=prerequisites.size();
        // for(int one=0; one<n-1; one++){
        //     for(int two=one+1; two<n; two++){
        //         if(prerequisites[one[1]]==prerequisites[two[0]]) st.insert({prerequisites[one[0]], prerequisites[two[1]]});
        //     }
        // }
        // for(auto it:prerequisites) st.insert(it);
        // for(auto it:queries) {
        //     if(st.find(it)!=st.end()){
        //         vec.emplace_back(true);
        //         continue;
        //     } else {
        //         vec.emplace_back(false);
        //         st.insert(it);
        //     }
        // }
        // return vec;
        vector<vector<bool>> isPrerequisite(numCourses,
                                            vector<bool>(numCourses, false));
        for (auto edge : prerequisites) {
            isPrerequisite[edge[0]][edge[1]] = true;
        }

        for (int intermediate = 0; intermediate < numCourses; intermediate++) {
            for (int src = 0; src < numCourses; src++) {
                for (int target = 0; target < numCourses; target++) {
                    isPrerequisite[src][target] =
                        isPrerequisite[src][target] ||
                        (isPrerequisite[src][intermediate] &&
                         isPrerequisite[intermediate][target]);
                }
            }
        }

        vector<bool> answer;
        for (auto q : queries) {
            answer.push_back(isPrerequisite[q[0]][q[1]]);
        }

        return answer;
    }
};
