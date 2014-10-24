#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct node {
    int value_;
    node *prev_;
    node *next_;

    node(int value) : value_(value), prev_(NULL), next_(NULL) { }
    node() : value_(0), prev_(NULL), next_(NULL) {}
};

const int INF = 1000000000 + 1111111;

struct delink {
    node *head;
    node *tail;

    int size;
    void init( int n) {
        size = n;
        if (!n) return ;
        node* last NULL;
        head = new node(INF);
        tail = head; 
        last = head;
        for ( int i = 0; i <= n; ++i) {
            int x;
            if (i < n) scanf ( "%d" , &x);
            else x = INF;
            tail = new node(x);
            tail->prev_ = last;
            last->next_ = tail;
            last = tail;

        }

    }

    int gao() {

        node* now = head->next;
        node *tmp = NULL;
        node *k = NULL;

        int tot = 0, t;

        while (size-- > 1) {
            while (!now->prev_ || now->prev_->d > now->next_->d) now = now->next_;

            t = now->prev->d + now->d;

            now->next->prev_ = now->prev->prev;

            now->prev->prev->next_ = now->next;

            k = now->prev->prev;

            now = new node(t);

            tot += t;

            while (k->d <= t) k = k->prev;

            now->next_ = k->next;

            now->prev_ = k;

            k->next->prev_ = now;

            k->next_ = now;

            now = now->prev;

        }

        return tot;

    }
}dq;

int main() {

    int n;

    while ( scanf ( "%d" , &n), n) {

        dq.init(n);

        printf ( "%d\n" , dq.gao());

    }

    return 0;
}
