class Solution {
public:
    int score(vector<string>& cards, char x) {
        
  
        map<char, int> type1;
        map<char, int> type2;//used to measure freq of type1 and type 2 ;
       
        int n=0, m=0,k=0; //count of type 1,type 2, type 3

        for(auto it : cards){
            if(it[0]==x && it[1]==x){
                k++;
            }
            else if(it[0]==x){
                type1[it[1]]++;
                n++;
            }
            else if(it[1]==x){
                type2[it[0]]++;
                m++;
            }
        }
        int ans=0;
        int t1_max=0, t2_max=0;//t1max->max freq of a card of type1, t2max->max freq
        //of type2
        int paired1 = 0, paired2=0, unpaired = 0;//paired1->type1 pairs, paired2->type2 
        //pairs
        for(auto [u, v] : type1){
            t1_max=max(t1_max, v);
        }
        paired1=min(n/2,n-t1_max);

        for(auto [u, v] : type2){
            t2_max=max(t2_max, v);
        }
        paired2=min(m/2,m-t2_max);
        unpaired+=n-2*paired1 + m-2*paired2;


        ans=paired1+paired2;

        ans+=min(unpaired,k);//this preliminary ans

        if(k>unpaired){
            ans+=min(paired1+paired2, (k-unpaired)/2);
        }
        
        return ans;
    }
};