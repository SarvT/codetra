stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(st.empty() or a[i]>a[st.top()])
            st.push(i);
        }
        
        int ans=0;
        int i=0;
        while(i<n and !st.empty())
        {
            if(a[i]<=a[st.top()] and i<=st.top())
            {
                ans=max(ans,st.top()-i);
                st.pop();
            }
            else if(i>st.top())
            st.pop();
            else
            i++;
        }
        return ans;
