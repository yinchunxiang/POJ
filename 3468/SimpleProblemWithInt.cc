#include <iostream>
#include <vector>
#include <numeric> 
#include <queue> 

using namespace std;

const int MAXN = 100000;
struct SegmentTreeNode{
    int left_;
    int right_;
    long long nsum_;
    long long delta_;
    SegmentTreeNode(int left , int right) : left_(left), right_(right), nsum_(0), delta_(0) {}
    SegmentTreeNode() : left_(-1), right_(-1), nsum_(0), delta_(0) {}
};
SegmentTreeNode segment_tree[MAXN * 4];
int data[MAXN];

void init_segment_tree(int root, int left, int right) {
    segment_tree[root].left_ = left;
    segment_tree[root].right_ = right;
    if (left == right) {
        segment_tree[root].nsum_ = data[left];
        return;
    }
    
    int mid = left + ( (right - left) >> 1);
    int lc = (root << 1) + 1;
    int rc = lc + 1;
    init_segment_tree(lc, left, mid);
    init_segment_tree(rc, mid + 1, right);
    segment_tree[root].nsum_ = segment_tree[lc].nsum_ + segment_tree[rc].nsum_;
    return; 
}

void update(int root, int left, int right, int delta) {
    if (segment_tree[root].left_ == left && segment_tree[root].right_ == right) {
        segment_tree[root].delta_ += delta;
        segment_tree[root].nsum_ += delta * (right - left + 1);
        return;
    }

    int lc = (root << 1) + 1;
    int rc = lc + 1;
    if (segment_tree[root].delta_) {
        segment_tree[lc].delta_ += segment_tree[root].delta_;
        segment_tree[lc].nsum_ += segment_tree[root].delta_ * (segment_tree[lc].right_ - segment_tree[lc].left_ + 1);

        segment_tree[rc].delta_ += segment_tree[root].delta_;
        segment_tree[rc].nsum_ += segment_tree[root].delta_ * (segment_tree[rc].right_ - segment_tree[rc].left_ + 1);

        segment_tree[root].delta_ = 0;
    }
    int mid = segment_tree[root].left_ + ((segment_tree[root].right_ - segment_tree[root].left_) >> 1);
    if (right <= mid) {
        update(lc, left, right, delta);
    }
    else if (mid < left) {
        update(rc, left, right, delta);
    }
    else {
        update(lc, left, mid, delta);
        update(rc, mid + 1, right, delta);
    }
    segment_tree[root].nsum_ = segment_tree[lc].nsum_ + segment_tree[rc].nsum_;
    return;
}

long long query(int root, int left, int right) {
    if (segment_tree[root].left_ == left && segment_tree[root].right_ == right) {
        return segment_tree[root].nsum_;
    }

    int lc = (root << 1) + 1;
    int rc = lc + 1;
    if (segment_tree[root].delta_) {
        segment_tree[lc].delta_ += segment_tree[root].delta_;
        segment_tree[lc].nsum_ += segment_tree[root].delta_ * (segment_tree[lc].right_ - segment_tree[lc].left_ + 1);

        segment_tree[rc].delta_ += segment_tree[root].delta_;
        segment_tree[rc].nsum_ += segment_tree[root].delta_ * (segment_tree[rc].right_ - segment_tree[rc].left_ + 1);

        segment_tree[root].delta_ = 0;
    }

    int mid = segment_tree[root].left_ + ((segment_tree[root].right_ - segment_tree[root].left_) >> 1);
    long long lq = 0;
    long long rq = 0;
    if (mid >= right) {
        lq = query(lc, left, right);
    }
    else if (mid < left) {
        rq = query(rc, left, right);
    }
    else {
        lq = query(lc, left, mid);
        rq = query(rc, mid + 1, right);
    }
    return lq + rq;
}

int main(int argc, const char *argv[])
{
    int N = 0; int ops = 0; cin >> N >> ops;
    //cout << N << " " << ops << endl;
    for (int i = 0; i < N; ++i) {
        cin >> data[i]; 
        //cout << data[i] << " ";
    }
    //cout << endl;
    init_segment_tree(0, 0, N - 1);
    /*
    for (int i = 0; i < N; ++i) {
        cout << segment_tree[i].left_ << " " << segment_tree[i].right_ << " " << segment_tree[i].nsum_<< endl;
    }
    */
    int begin = 0; int end = 0; int initial = 0;
    for (int i = 0; i < ops; ++i) {
        char op_type;
        cin >> op_type;
        //cout << op_type << " ";
        switch (op_type) { 
            case 'Q':
                cin >> begin >> end;
                //cout << begin << " " << end << endl;
                cout << query(0, begin - 1, end - 1) << endl;
                break;
            case 'C':
                cin >> begin >> end >> initial;
                //cout << begin << " " << end << " " << initial << endl;
                update(0, begin - 1, end - 1, initial);
                break;
        }
    }
    return 0;
}



