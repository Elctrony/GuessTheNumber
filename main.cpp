#include "bits/stdc++.h"

using namespace std;


#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define en cout<<'\n'

enum INPUT {
    OUT,
    ONE_TRIANGLE,
    TWO_TRIANGLE,
    THREE_TRIANGLE,
    ONE_RECTANGLE,
    TWO_RECTANGLE,
    ONE_TRIANGLE_ONE_RECTANGLE,
    TWO_TRIANGLE_ONE_RECTANGLE,
    THREE_RECTANGLE,
};

vvi TriToRec(string s){
    // 0 Triangle | 1 Rectangle
    string os = s; //original
    //123
    vvi res(3,vi(2));
    res[0][0]=s[0]-'0';
    res[1][0]=s[1]-'0';
    res[2][0]=s[2]-'0';
    swap(s[0],s[1]);
    //213
    cout<<s; //Q1
    en;
    int ans;
    cin>>ans;
    if(ans==ONE_TRIANGLE){
        s= os;
        swap(s[0],s[2]);
        //321
        cout<<s;//Q2
        en;
        cin>>ans;
        if(ans==ONE_TRIANGLE){ // sure 1 is false : 2 in 3 or 3 in 2
            s= os;
            swap(s[0],s[2]);
            //321
            swap(s[1],s[2]);
            //312
            cout<<s;// if Triangle then 3 in 2 is answer otherwise 2 in 3 is answer;
            en;
            cin>>ans;
            if(ans==ONE_TRIANGLE){
                res[0][1]=-1;
                res[1][1]=-1;
                res[2][1]=2;
            }else if(ans==ONE_RECTANGLE){
                res[0][1]=-1;
                res[1][1]=3;
                res[2][1]=-1;
            }else{
                cout<<"YOU LIE!!!!";
                res[0][1]=-1;
                res[1][1]=-1;
                res[2][1]=-1;
            }
        }else if(ans==ONE_RECTANGLE){// either 1 on 3 or 3 in 1
            s = os;
            //321 to 231
            swap(s[0],s[2]);
            swap(s[0],s[1]);
            //231
            cout<<s;
            en;
            cin>>ans;
            if(ans==ONE_TRIANGLE){
                res[0][1]=-1;
                res[1][1]=-1;
                res[2][1]=1;
            }else if(ans==ONE_RECTANGLE){
                res[0][1]=3;
                res[1][1]=-1;
                res[2][1]=-1;
            }else{
                cout<<"YOU LIE!!!!";
                res[0][1]=-1;
                res[1][1]=-1;
                res[2][1]=-1;
            }
        }else{
            cout<<"YOU LIE!!!!";
            res[0][1]=-1;
            res[1][1]=-1;
            res[2][1]=-1;
        }
    }else if(ans==ONE_RECTANGLE){ //either 2 in 1 or 1 in 2
        //231
        s= os;
        swap(s[0],s[2]);
        swap(s[0],s[1]);
        cout<<s;
        en;
        cin>>ans;
        if(ans==ONE_TRIANGLE){
            res[0][1]=2;
            res[1][1]=-1;
            res[2][1]=-1;
        }else if(ans==ONE_RECTANGLE){
            res[0][1]=-1;
            res[1][1]=1;
            res[2][1]=-1;
        }else{
            cout<<"YOU LIE!!!!";
            res[0][1]=-1;
            res[1][1]=-1;
            res[2][1]=-1;
        }
    }else{
        cout<<"YOU LIE!!!!";
        res[0][1]=-1;
        res[1][1]=-1;
        res[2][1]=-1;
    }
    return res;
}

vvi CheckOneRec(string s){
    vvi res(3,vi(2));
    res[0][0]=s[0]-'0';
    res[1][0]=s[1]-'0';
    res[2][0]=s[2]-'0';
    int ans;
    string os =s;
    swap(s[0],s[1]);
    cout<<s;
    en;
    cin>>ans;
    if(ans==ONE_RECTANGLE){
        res[0][1]=-1;
        res[1][1]=-1;
        res[2][1]=3;
    }else if(ans==ONE_TRIANGLE){// 1 in 1 or 2 in 2
        s = os;
        swap(s[0],s[2]);
        //321
        cout<<s;
        en;
        cin>>ans;
        if(ans==ONE_RECTANGLE){
            res[0][1]=-1;
            res[1][1]=2;
            res[2][1]=-1;
        }else if(ans==ONE_TRIANGLE){
            res[0][1]=1;
            res[1][1]=-1;
            res[2][1]=-1;
        }else{
            cout<<"YOU LIE!!!!";
            res[0][1]=-1;
            res[1][1]=-1;
            res[2][1]=-1;
        }
    }else{
        cout<<"YOU LIE!!!!";
        res[0][1]=-1;
        res[1][1]=-1;
        res[2][1]=-1;
    }
    return res;
}

vvi TwoTriToRec(string s){
    vvi res(3,vi(2));
    res[0][0]=s[0]-'0';
    res[1][0]=s[1]-'0';
    res[2][0]=s[2]-'0';
    int ans;
    string os =s;
    swap(s[0],s[1]);
    //213
    cout<<s;
    en;
    cin>>ans;
    if(ans==TWO_RECTANGLE){// 1 in 2 and 2 in 1
        res[0][1]=2;
        res[1][1]=1;
        res[2][1]=-1;
    }else if(ans==ONE_TRIANGLE_ONE_RECTANGLE){// 1 in 2 or 2 in 1 and 3 in either
        // 312 | 321 | 231 | 132

        // 321
        s = os;
        swap(s[0],s[2]);
        cout<<s;
        en;
        cin>>ans;
        if(ans==TWO_RECTANGLE){
            res[0][1]=3;
            res[1][1]=-1;
            res[2][1]=1;
        }else if(ans==ONE_TRIANGLE_ONE_RECTANGLE){
            res[0][1]=2;
            res[1][1]=-1;
            res[2][1]=1;
        }else if(ans==TWO_TRIANGLE){
            res[0][1]=-1;
            res[1][1]=1;
            res[2][1]=2;
        }else{
            cout<<"ERROR: YOU LIE!!";
            res[0][1]=-1;
            res[1][1]=-1;
            res[2][1]=-1;
        }
    }else if(ans==TWO_TRIANGLE){// 1 in 3 or 2 in 3 and 3 in either
        s = os;
        swap(s[0],s[2]);
        //321 //sol: 132
        cout<<s;
        en;
        cin>>ans;
        if(ans==TWO_RECTANGLE){
            res[0][1]=3;
            res[1][1]=-1;
            res[2][1]=1;
        }else if(ans==ONE_TRIANGLE_ONE_RECTANGLE){
            swap(s[0],s[1]);
            cout<<s; en;
            cin>>ans;
            if(ans==TWO_RECTANGLE){
                res[0][1]=3;
                res[1][1]=-1;
                res[2][1]=2;
            }else if(ans==TWO_TRIANGLE){
                res[0][1]=-1;
                res[1][1]=3;
                res[2][1]=1;
            }else{
                cout<<"ERROR: YOU LIE!!";
                res[0][1]=-1;
                res[1][1]=-1;
                res[2][1]=-1;
            }
        }else if(ans==TWO_TRIANGLE){
            res[0][1]=-1;
            res[1][1]=3;
            res[2][1]=2;
        }else{
            cout<<"ERROR: YOU LIE!!";
            res[0][1]=-1;
            res[1][1]=-1;
            res[2][1]=-1;
        }
        return res;
    }else{
        cout<<"ERROR: YOU LIE!!";
        res[0][1]=-1;
        res[1][1]=-1;
        res[2][1]=-1;
    }
    return res;
}

vvi TwoRecCheck(string s){
    vvi res(3,vi(2));
    res[0][0]=s[0]-'0';
    res[1][0]=s[1]-'0';
    res[2][0]=s[2]-'0';
    int ans;
    string os =s;
    swap(s[0],s[1]);
    //213
    cout<<s;
    en;
    cin>>ans;
    if(ans==TWO_TRIANGLE){
        res[0][1]=1;
        res[1][1]=2;
        res[2][1]=-1;
        return res;
    }else if(ans==ONE_TRIANGLE_ONE_RECTANGLE){// 3 is correct 1 or 2 is wrong

        // 321
        s = os;
        swap(s[0],s[2]);
        cout<<s;
        en;
        cin>>ans;
        if(ans==TWO_TRIANGLE){
            res[0][1]=1;
            res[1][1]=-1;
            res[2][1]=3;
        }else if(ans==ONE_TRIANGLE_ONE_RECTANGLE){
            res[0][1]=-1;
            res[1][1]=2;
            res[2][1]=3;
        }else{
            cout<<"YOU LIE!!!!";
            res[0][1]=-1;
            res[1][1]=-1;
            res[2][1]=-1;
        }
    }else{
        cout<<"YOU LIE!!!!";
        res[0][1]=-1;
        res[1][1]=-1;
        res[2][1]=-1;
    }
    return res;
}

vvi ThreeTriToRec(string s){
    vvi res(3,vi(2));
    res[0][0]=s[0]-'0';
    res[1][0]=s[1]-'0';
    res[2][0]=s[2]-'0';
    // 231 or 312
    int ans;
    string os =s;
    swap(s[0],s[1]);
    swap(s[1],s[2]);
    cout<<s;
    en;
    cin>>ans;
    if(ans==THREE_RECTANGLE){
        res[0][1]=3;
        res[1][1]=1;
        res[2][1]=2;
    }else if(ans==THREE_TRIANGLE){
        res[0][1]=2;
        res[1][1]=3;
        res[2][1]=1;
    }else{
        cout<<"YOU LIE!!!!";
        res[0][1]=-1;
        res[1][1]=-1;
        res[2][1]=-1;
    }
    return res;
}


vvi OneTriRec(string s){
    vvi res(3,vi(2));
    res[0][0]=s[0]-'0';
    res[1][0]=s[1]-'0';
    res[2][0]=s[2]-'0';
    int ans;
    string os =s;
    swap(s[0],s[1]);
    //213
    cout<<s;
    en;
    cin>>ans;
    if(ans==TWO_RECTANGLE){
        swap(s[1],s[2]); //231
        cout<<s;
        en;
        cin>>ans;
        if(ans==ONE_TRIANGLE_ONE_RECTANGLE){
            res[0][1]=-1;
            res[1][1]=1;
            res[2][1]=3;
        }else if(ans==TWO_TRIANGLE){
            res[0][1]=2;
            res[1][1]=-1;
            res[2][1]=3;
        }else{
            cout<<"YOU LIE!!!!";
            res[0][1]=-1;
            res[1][1]=-1;
            res[2][1]=-1;
        }
        return res;
    }else if(ans==TWO_TRIANGLE){// either 1 in place or 2 on place and 3 on verse
        s = os;
        swap(s[0],s[2]);
        //321
        cout<<s;
        en;
        cin>>ans;
        if(ans==TWO_RECTANGLE){//213
            swap(s[0],s[1]); //231
            cout<<s;
            en;
            cin>>ans;
            if(ans==ONE_TRIANGLE_ONE_RECTANGLE){
                res[0][1]=3;
                res[1][1]=2;
                res[2][1]=-1;
            }else if(ans ==TWO_TRIANGLE){
                res[0][1]=-1;
                res[1][1]=2;
                res[2][1]=1;
            }else {
                cout << "YOU LIE!!!!";
                res[0][1] = -1;
                res[1][1] = -1;
                res[2][1] = -1;
            }
        }else if(ans==TWO_TRIANGLE){//102 or 130
            s = os;
            swap(s[1],s[2]);
            swap(s[0],s[1]);
            //312
            cout<<s;
            en;
            cin>>ans;
            if(ans==TWO_TRIANGLE){
                res[0][1]=1;
                res[1][1]=-1;
                res[2][1]=2;
            }else if(ans==ONE_TRIANGLE_ONE_RECTANGLE){
                res[0][1]=1;
                res[1][1]=3;
                res[2][1]=-1;
            }else{
                cout << "YOU LIE!!!!";
                res[0][1] = -1;
                res[1][1] = -1;
                res[2][1] = -1;
            }
        }else{
            cout<<"YOU LIE!!!!";
            res[0][1]=-1;
            res[1][1]=-1;
            res[2][1]=-1;
        }
    }else{
        cout<<"YOU LIE!!!!";
        res[0][1]=-1;
        res[1][1]=-1;
        res[2][1]=-1;
    }
    return res;
}

vvi TwoTriOneRec(string s){
    vvi res(3,vi(2));
    res[0][0]=s[0]-'0';
    res[1][0]=s[1]-'0';
    res[2][0]=s[2]-'0';
    int ans;
    string os =s;
    swap(s[0],s[1]);
    //213
    cout<<s;
    en;
    cin>>ans;
    if(ans==THREE_RECTANGLE){
        res[0][1]=2;
        res[1][1]=1;
        res[2][1]=3;
    }
    else if(ans==THREE_TRIANGLE){// either 1 in place or 2 in place
        s = os;
        swap(s[0],s[2]);
        cout<<s;
        en;
        cin>>ans;
        if(ans==THREE_RECTANGLE){
            res[0][1]=3;
            res[1][1]=2;
            res[2][1]=1;
        }else if(ans==THREE_TRIANGLE){
            res[0][1]=1;
            res[1][1]=3;
            res[2][1]=2;
        }else{
            cout<<"YOU LIE!!!!";
            res[0][1]=-1;
            res[1][1]=-1;
            res[2][1]=-1;
        }
    }else{
        cout<<"YOU LIE!!!!";
        res[0][1]=-1;
        res[1][1]=-1;
        res[2][1]=-1;
    }
}
void PrintRules(){
    /*

   OUT,
   ONE_TRIANGLE,
   TWO_TRIANGLE,
   THREE_TRIANGLE,
   ONE_RECTANGLE,
   TWO_RECTANGLE,
     ONE_TRIANGLE_ONE_RECTANGLE,
   TWO_TRIANGLE_ONE_RECTANGLE,
   THREE_RECTANGLE,


    */
    cout<<"GAME RULES:";
    en;
    cout<<"PRESS 0 to say OUT";
    en;
    cout<<"PRESS 1 to say 1 Triangle";
    en;
    cout<<"PRESS 2 to say 2 Triangles";
    en;
    cout<<"PRESS 3 to say 3 Triangles";
    en;
    cout<<"PRESS 4 to say 1 Rectangle";
    en;
    cout<<"PRESS 5 to say 2 Rectangles";
    en;
    cout<<"PRESS 6 to say 1 Triangle and 1 Rectangle";
    en;
    cout<<"PRESS 7 to say 2 Triangles and 1 Rectangle";
    en;
    cout<<"PRESS 8 to say 3 Rectangles and GAME OVER";
    en;
    cout<<"__________________________________________";
    en;
    cout<<"GAME begin: ";
    en;
}

int main() {
    PrintRules();

    string querys[]={"123","456","789"};

    char answer[3]={'0','0','0'};
    for(int x=0;x<3;x++) {
        string st = querys[x];
        vvi res;
        cout << st;
        en;
        int ans;
        cin >> ans;
        if(ans==OUT){
            continue;
        } else if (ans == ONE_TRIANGLE) {
            res = TriToRec(st);
        } else if (ans == TWO_TRIANGLE) {
            res = TwoTriToRec(st);
        } else if (ans == THREE_TRIANGLE) {
            res = ThreeTriToRec(st);
        } else if (ans == ONE_RECTANGLE) {
            res = CheckOneRec(st);
        } else if (ans == TWO_RECTANGLE) {
            res = TwoRecCheck(st);
        } else if (ans == THREE_RECTANGLE) {
            cout <<"The Guessed number is: "<< st;
            return 0;
        }else if(ans==ONE_TRIANGLE_ONE_RECTANGLE){
            res = OneTriRec(st);
        }else if(ans==TWO_TRIANGLE_ONE_RECTANGLE){
            res = TwoTriOneRec(st);
        }
        for (int i = 0; i < 3; i++) {
            if (res[i][1] != -1) {
                if(answer[res[i][1]-1]=='0')
                    answer[res[i][1]-1]=(res[i][0]+'0');
                else{
                    cout<<res[i][1]<<" : "<<answer[res[i][1]-1]<<" : "<<res[i][0];
                    en;
                    cout<<"YOU LIE!!!!";
                    en;
                    cout<<"GAME OVER";
                    en;
                    return 0;
                }
                //cout << res[i][0] << " : " << res[i][1];
                //en;
            }
        }
        bool finish=0;
        for (int i = 0; i < 3; i++) {
           if(answer[0]!='0'&&answer[1]!='0'&&answer[2]!='0'){
               finish=1;
               break;
           }
        }
        if(finish) break;
      //  cout<<answer[0]<<answer[1]<<answer[2];
    }
    cout<<"THE Guessed number is: ";
    cout<<answer[0]<<answer[1]<<answer[2];
    return 0;
}
