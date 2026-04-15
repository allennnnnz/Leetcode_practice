class Robot {
public:
    vector<int> pos;
    vector<string> dir = {"East","North","West","South"};
    int max_x;
    int max_y;
    int face;
    int lenth;
    Robot(int width, int height) 
        : pos({0,0}), face(0),
            max_x(width - 1), max_y(height - 1),
              lenth(2*(width+height-2))
    {
    }
    
    void step(int num) {
        num = num%lenth;
        if(lenth > 0){
            num %= lenth;
            if(num == 0) num = lenth;
        }
        while(num>0){
                if(face == 0){
                    if(pos[0] + num <= max_x){
                        pos[0] = pos[0] + num;
                        break;
                    }else{
                        num -= (max_x - pos[0]);
                        pos[0] = max_x;
                        face = 1;
                    }
                }
                else if(face == 1){
                    if(pos[1] + num <= max_y){
                        pos[1] = pos[1] + num;
                        break;
                    }else{
                        num -= (max_y - pos[1]);
                        pos[1] = max_y;
                        face = 2;
                    }
                }
                else if(face == 2){
                    if(pos[0] - num >= 0){
                        pos[0] = pos[0] - num;
                        break;
                    }else{
                        num -= pos[0];
                        pos[0] = 0;
                        face = 3;
                    }
                }
                else if(face == 3){
                    if(pos[1] - num >= 0){
                        pos[1] = pos[1] - num;
                        break;
                    }else{
                        num -= pos[1];
                        pos[1] = 0;
                        face = 0;
                        
                    }
                }
        }
        

    }
    
    vector<int> getPos() {
        return pos;
    }
    
    string getDir() {
        return dir[face];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */