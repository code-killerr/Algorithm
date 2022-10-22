#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    int videoStitching(vector< vector<int> >& clips, int time) {
        if (clips.size() < 0) return -1;
        if (clips.size() == 0 && time == 0) return 0;
        if (clips.size() == 0 && time > 0) return -1;
        int result = videoCutting(clips, 0, time);
        return result;
    }

    int videoCutting(vector< vector<int> >& clips, int start, int end){
        int max = 0;
        vector<int> maxClip;
        int index = 0;
        int timeEnd = 0;
        int timeStart = 0;
        int pre = 0;
        int eofEnd = 0;
        for (int i = 0;i < clips.size();i++){
            if (clips[i][0] >= end || clips[i][1] <= start) continue;
            int temp = fabs(clips[i][1] > end ? end : clips[i][1]  - clips[i][0] < start ? start : clips[i][0]);
            if (temp > max){
                max = temp;
                maxClip = clips[i];
                index = i;
            }
        }
        if (maxClip.empty()) return -1;
        timeStart = maxClip[0];
        timeEnd = maxClip[1];
        std::swap(maxClip, clips.back());
        clips.pop_back();
        if(timeStart > start)
            pre = videoCutting(clips,start, timeStart);
        if(timeEnd < end)
            eofEnd = videoCutting(clips, timeEnd, end);

       if (pre == -1 || eofEnd == -1) return -1;

        return 1 + pre + eofEnd;
    }
};

int main(){
    Solution test;
    vector< vector<int> > vec(16);
    int a[16][2] = {{0,1},{6,8},{0,2},{5,6},{0,4},{0,3},{6,7},{1,3},{4,7},{1,4},{2,5},{2,6},{3,4},{4,5},{5,7},{6,9}};

    for (int i = 0;i < 16;i++){
        vector<int> b(2);
        b.push_back(a[i][0]);
        b.push_back(a[i][1]);
        vec.push_back(b);
    }

    int result = test.videoStitching(vec, 9);

    std::cout<<result;
    return 0;
}
