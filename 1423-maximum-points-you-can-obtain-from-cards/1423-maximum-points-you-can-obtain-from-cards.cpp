class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int maxi=0,score=0,n=cardPoints.size(),sum=0;
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        score=sum;
        for(int i=0;i<k;i++){
            sum-=cardPoints[k-i-1];
            sum+=cardPoints[n-i-1];
            score=max(score,sum);
        }
        return score;
    }
};