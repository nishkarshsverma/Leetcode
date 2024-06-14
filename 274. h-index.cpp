class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int xx=*max_element(citations.begin(),citations.end());
        vector<int>freq(xx+1,0);

        for(int i=0; i<n; i++){
            freq[citations[i]]++;
        }

        for(int i=xx; i>=0; i--){

            if(i==xx)
                freq[i]=freq[i];
            else
                freq[i]=freq[i]+freq[i+1];

            if(freq[i]>=i)
                return i;
        }
        return 0;
    }
};
