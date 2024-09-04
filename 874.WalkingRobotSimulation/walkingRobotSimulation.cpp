
# include <iostream>
# include <set>
# include <vector>
# include <algorithm>
using namespace std;



class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // convert obstacles to container `set` for quick lookup
        std::set<std::pair<int, int> > obs;
        for (auto obstacle : obstacles) {
            obs.insert({obstacle[0], obstacle[1]});
        }
        std::vector<std::vector<char> > dir(2, std::vector<char>(2));
        dir[0][0] = 'N'; dir[0][1] = 'S'; dir[1][0] = 'W'; dir[1][1] = 'E';

        int dirX = 0, dirY = 0, x = 0, y = 0;
        int mx = 0;
        for (int i = 0, j = 0; i < commands.size(); i++) {
            int step = commands[i];
            int nextX = x, nextY = y;
            while(commands[i] > 0 && step > 0) {
                if (dir[dirX][dirY] == 'N') {
                    nextY += 1;
                }
                else if (dir[dirX][dirY] == 'S') {
                    nextY -= 1;
                }
                else if (dir[dirX][dirY] == 'E') {
                    nextX += 1;
                }
                else if (dir[dirX][dirY] == 'W') {
                    nextX -= 1;
                }
                if (obs.find({nextX, nextY}) != obs.end()) {
                    break; 
                }
                mx = max(mx, nextX*nextX + nextY*nextY);
                x = nextX;
                y = nextY;
                step--;
            }
            if (commands[i] == -1 && (dir[dirX][dirY] == 'N')) {
                dirX = 1 , dirY = 1;
            }
            else if(commands[i] == -2 && (dir[dirX][dirY] == 'N')) {
                dirX = 1 , dirY = 0;
            }
            else if(commands[i] == -1 && (dir[dirX][dirY] == 'E')) {
                dirX = 0 , dirY = 1;
            }
            else if(commands[i] == -2 && (dir[dirX][dirY] == 'E')) {
                dirX = 0 , dirY = 0;
            }
            else if(commands[i] == -1 && (dir[dirX][dirY] == 'S')) {
                dirX = 1 , dirY = 0;
            }
            else if(commands[i] == -2 && (dir[dirX][dirY] == 'S')) {
                dirX = 1 , dirY = 1;
            }
            else if(commands[i] == -1 && (dir[dirX][dirY] == 'W')) {
                dirX = 0 , dirY = 0;
            }
            else if(commands[i] == -2 && (dir[dirX][dirY] == 'W')) {
                dirX = 0 , dirY = 1;
            }
        }
        return mx;
    }
};