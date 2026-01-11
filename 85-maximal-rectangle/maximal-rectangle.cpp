class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> nsi(n),psi(n);
        stack<int> st;
        st.push(n-1);
        nsi[n-1]=n;
        for(int i=n-2;i>=0;i--) {
            while(st.size() && heights[st.top()]>=heights[i]) st.pop();
            if(st.size()) nsi[i]=st.top();
            else nsi[i]=n;
            st.push(i);
        }

        while(st.size()) st.pop();

        st.push(0);
        psi[0]=-1;
        for(int i=1;i<n;i++) {
            while(st.size() && heights[st.top()]>=heights[i]) st.pop();
            if(st.size()) psi[i]=st.top();
            else psi[i]=-1;
            st.push(i);
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++) {
            ans=max(ans,(nsi[i]-psi[i]-1)*heights[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> v(n,vector<int> (m));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(i==0) {
                    if(matrix[i][j]=='1') v[i][j]=1;
                    else v[i][j]=0;
                }
                else {
                    if(matrix[i][j]=='1') v[i][j]=v[i-1][j]+1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++) {
            int a=largestRectangleArea(v[i]);
            ans=max(ans,a);
        }
        return ans;
    }
};