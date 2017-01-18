#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<set>

using namespace std;
typedef long long ll;

class Animal{
public:
    ll x,y;
    Animal(ll xi, ll yi){
        x = xi, y = yi;
    }
    
    bool operator < (Animal a) const {
        if (x == a.x) {
            return y < a.y;
        }
        return x < a.x;
    }
    
    bool operator == (Animal a) const{
        return x == a.x && y == a.y;
    }
};

typedef set<Animal>::iterator ASIT;
typedef pair<ASIT, ASIT> PASIT;
typedef set<ll>::iterator SIT;
typedef pair<SIT, SIT> PSIT;

int hunter_num, animal_num, L;
set<ll> hunters;
set<Animal> animals;


ll getLength(ll hunterX, ll ax, ll ay){
    return abs(hunterX - ax) + ay;
}

int main()
{
    cin >> hunter_num >> animal_num >> L;
    
    
    for (int i = 0; i < hunter_num; i++){
        ll x;
        cin >> x;
        hunters.insert(x);
    }
    
    
    for (int i = 1; i <= animal_num; i++) {
        ll a,b;
        cin >> a >> b;
        animals.insert(Animal(a, b));
    }
    
    
    int result = 0;
    
    for (Animal animal : animals) {
        ll ax = animal.x, ay = animal.y;
//        printf("animal : %lld %lld\n", ax, ay);
        
        SIT pSit = hunters.lower_bound(ax);
        ll hx1 = *(pSit);
        
        ll hx2 = -1;
        if (pSit != hunters.begin()) {
            hx2 = *(--pSit);
            pSit++;
        }
        
        
        if (getLength(hx1, ax, ay) <= L) {
//            printf("animal %lld %lld hunted\n", ax, ay);
//            animals.erase(animal);
            result++;
            continue;
        }
        
        if (hx2 != -1 && getLength(hx2, ax, ay) <= L) {
//            printf("animal %lld %lld hunted\n", ax, ay);
//            animals.erase(animal);
            result++;
            continue;
        }
    }
    
    
    printf("%d\n", result);
    
    return 0;
}
