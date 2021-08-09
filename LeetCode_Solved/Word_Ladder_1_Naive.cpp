/*Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
*/

//Time Complexity -> O(26 * N * N * W) W->Word length
//Space -> O(N^2*W)


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> myset;
        bool isPresent = false;
        
        //Insert all words from given dictionary to myset
        for(auto word : wordList){
            if(endWord.compare(word) == 0)
                isPresent = true;
            myset.insert(word);
        }
        
        if(isPresent == false)
            return -0;
        
        //Now we will be taking queue and apply BFS
        queue<string> Q;
        Q.push(beginWord);
        int depth = 0;      //measure the level of BFS
        
        while(!Q.empty()){
            
            ++depth;
            int lsize = Q.size();
            
            while(lsize--){
                
                string curr = Q.front();
                Q.pop();
                
                //check for all possible 1 depth words
                for(int i = 0; i < curr.length(); i++){
                    
                    string temp = curr;
                    for(char c = 'a'; c <= 'z'; c++){   //Try for all possible characters
                        temp[i] = c;
                        
                        //skip the same word
                        if(curr.compare(temp) == 0)
                            continue;
                        
                        //If EndWord is found
                        if(temp.compare(endWord) == 0)
                            return depth+1;
                        
                        if(myset.find(temp) != myset.end()){
                            
                            Q.push(temp);
                            myset.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};