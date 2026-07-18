#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#include<cfloat>
#include<algorithm>

using namespace std;

struct Point{
    double x,y;
};


double dist(Point p1,Point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

double bruteForce(vector<Point>&pts,int l,int r){
    double minDist= DBL_MAX;

    for(int i=l;i<r;i++){
        for(int j=i+1;j<r;j++){
            minDist=min(minDist,dist(pts[i],pts[j]));
        }
    }
    return minDist;
}

double stripClosest(vector<Point>&strip,double d){
    double minDist=d;
    int n =strip.size();

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((strip[j].y - strip[i].y)<minDist){
                minDist=min(minDist,dist(strip[i],strip[j]));
            }
        }
    }
    return minDist;
}

double closestUtil(vector<Point>&px,vector<Point>&py){
    int n=px.size();

    if(n<=3) return bruteForce(px,0,n);

    int mid=n/2;
    Point midPoint=px[mid];

    vector<Point>pxl(px.begin(),px.begin()+mid);
    vector<Point>pxr(px.begin()+mid,px.end());

    vector<Point>pyl,pyr;

    for(auto p : py){
        if(p.x<=midPoint.x){
            pyl.push_back(p);
        }else{
            pyr.push_back(p);
        }
    }

    double dl=closestUtil(pxl,pyl);
    double dr=closestUtil(pxr,pyr);

    double d=min(dl,dr);

    vector<Point>strip;

    for(auto p : py){
        if(abs(p.x-midPoint.x)<d){
            strip.push_back(p);
        }
    }

    return min(d,stripClosest(strip,d));
}

double closest(vector<Point>&points){
    vector<Point>px= points;
    vector<Point>py= points;

    sort(px.begin(),px.end(),[](Point a, Point b){
        return a.x<b.x;
    });

    sort(py.begin(),py.end(),[](Point a, Point b){
        return a.y<b.y;
    });

    return closestUtil(px,py);
}

int main(){
    int n;
    cin>>n;

    vector<Point> points(n);


    for (int i = 0; i < n; i++) {

        cin>>points[i].x>> points[i].y;
    }

    double answer = closest(points);

    cout << fixed << setprecision(6);

    cout << "Closest distance = "
         << answer
         << endl;


    return 0;
}
