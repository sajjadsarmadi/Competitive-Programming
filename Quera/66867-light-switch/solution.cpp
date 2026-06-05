#include <iostream>
#include <vector>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int k , n ;
    string name;
    cin >>k >>n;
    vector <int> final(k+1) ;
    
    while (n--){
        
        cin >> name; 
        for (int i = 0; i <k ; i++){
            if (name[i] == 'W')
                final[i+1] += 1;
        }
        name = "";
    }    
    for (int  i = 1; i < k+1; i++)
    {
        if ((final[i] %2) == 0)
            cout << 'B';
        if ((final[i] % 2) == 1)
            cout<< 'F';
    }
    
}
