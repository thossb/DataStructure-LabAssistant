#include <stdio.h>
#include <deque>
#include <stdio.h>
#include <queue>
#include <functional>
#define ll long long
#define gc getchar

template <typename T> void getnum(T &val){
    char ch; bool bo=0; val=0;
    for(ch=gc();ch<'0'||'9'<ch;ch=gc()) if(ch=='-') bo=1;
    for(;'0'<=ch&&ch<='9';val=(val<<3)+(val<<1)+ch-48, ch=gc());
    if(bo) val=-val;
}

int main(){
    int n,i;
    while(1){
        getnum(n);
        if(n == 0)break;
        if(n<0){ printf("Mana ada kartu minus!"); break;}
        std::deque<int> cards;
        for(i = 1; i<= n; i++){
            cards.push_back(i);
        }
        printf("Discarded cards: ");
        while(cards.size() > 1){
            if(cards.size() != 2)
                printf("%d, ", cards.front());
            else printf("%d\n", cards.front());
            cards.pop_front();
            cards.push_back(cards.front());
            cards.pop_front();
        }
        printf("Remaining card: %d\n",cards.front());
}
return 0;
}
