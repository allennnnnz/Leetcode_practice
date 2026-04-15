class Solution {

public:
    /*
    try every posibi
    bool canBeEqual(string s1, string s2) {
        string combination_1;
        string combination_2;
        for(int i=0 ;i<4;i++){
            for(int j=0 ; j<4 ;j++){
                if((j-i) == 2 || i-j == 0){
                    combination_1 = s1;
                    swap(combination_1[i],combination_1[j]);
                    for(int m=0 ;m<4;m++){
                        for(int n=0 ; n<4 ;n++){
                                if((n-m)==2 || n-m ==0){
                                    combination_2 = s2;
                                    swap(combination_2[m],combination_2[n]);
                                    if(combination_1 == combination_2){
                                        cout<<"s1 : "<<combination_1<<endl;
                                        cout<<"s2 : "<<combination_2<<endl;
                                        return true;
                                    }
                                }
                        }
                    }
                }
                
            }
        }
        return false;
    }
    */
    bool canBeEqual(string s1, string s2) {
        if(s1 == s2){
            return true;
        }
        for(int i=0;i<2;i++){
            string combination_1;
            combination_1 = s1;
            swap(combination_1[i],combination_1[i+2]);
            for(int j=0;j<2;j++){
                string combination_2;
                combination_2 = s2;
                swap(combination_2[j],combination_2[j+2]);
                if(combination_1 == combination_2 || s1 == combination_2 || combination_1 == s2){
                    return true;
                }
            }
        }
        return false;
    }
};