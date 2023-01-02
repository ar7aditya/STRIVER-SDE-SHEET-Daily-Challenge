class Solution {
public:
    int flag=0;
    bool detectCapitalUse(string word) {
       if(word.size()==1) return true; 
         if(word[0]>=65 && word[0]<=90){
        if(word[1]>=65 && word[1]<=90) flag=1;
         }
       for(int i=1;i<word.size();i++){
           if(flag){
                if(word[i]<65 || word[i]>90) return false;
           } 
           else{
               if(word[i]<97 || word[i]>122) return false;
           }
        }
        return true;
    }
};