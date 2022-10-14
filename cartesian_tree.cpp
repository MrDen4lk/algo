#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define len(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbeging(), a.rend()

mt19937 mt_rand(time(0));
const int INF = 2e9;

struct item {
    int key, prior, cnt, min, max, sum, add;
	bool rev;
    item* left = nullptr;
    item* right = nullptr;
    item(int key_) {
        key = key_;
        prior = mt_rand();
		cnt = 1;
		rev = false;
		min = key_;
        max = key_;
        sum = key_;
        add = 0;  
    }
};

int cnt (item*& root) {
    return root ? root->cnt : 0;
}

void upd_cnt (item* root) {
    if (root) {
        root->cnt = 1 + cnt(root->left) + cnt(root->right);
    }
}

int get_min(item* root) {
	return root ? root->min : INF;
}

void upd_min(item* root) {
	if (root) {
		root->min = min(root->key, min(get_min(root->left), get_min(root->right)));
	}
}

int get_max(item* root) {
    return root ? root->max : -INF;
}

void upd_max(item* root) {
    if (root) {
        root->max = max(root->key, max(get_max(root->left), get_max(root->right)));
    }
}

int get_sum (item* root) {
    return root ? root->sum : 0;
}

void upd_sum(item* root) {
    if (root) {
        root->sum = root->key + get_sum(root->left) + get_sum(root->right);
    }
}

void set_reverse(item* root) {
	if (root) {
		root->rev ^= true;
	}
}

void pull_reverse(item* root) {
	if (root && root->rev) {
		swap(root->left, root->right);
		set_reverse(root->left);
		set_reverse(root->right);
		root->rev = false;
	}
}

void set_addation (item* root, int add) {
    if (root) {
        root->sum += cnt(root) * add;
        root->key += add;
        root->add += add;
    }
}

void pull_addation(item* root) {
    if (root) {
        set_addation(root->left, root->add);
        set_addation(root->right, root->add);
        root->add = 0;
    }
}

void Split(item* root, item*& left, item*& right, int key, int cap = 0) {
    if (!root) {
        return void(right = left = nullptr);
    }
    pull_addation(root);
	pull_reverse(root);
    int cur_key = cap + cnt(root->left);
    if (key <= cur_key) {
        Split(root->left, left, root->left, key, cap), right = root;
    } else {
        Split(root->right, root->right, right, key, cur_key + 1), left = root;
    }
    upd_cnt(root);
	upd_min(root);
    upd_max(root);
    upd_sum(root);
}

void Merge(item*& root, item* left, item* right) {
    if (!left || !right) {
        return void(root = left ? left : right);
    }
    pull_addation(left);
    pull_addation(right);
	pull_reverse(left);
	pull_reverse(right);
    if (left->prior > right->prior) {
        Merge(left->right, left->right, right), root = left;
    } else {
        Merge(right->left, left, right->left), root = right;
    }
    upd_cnt(root);
    upd_min(root);
    upd_max(root);
    upd_sum(root);
}

int SumOnLine(item*& root, int l, int r) {
    item *left, *right, *mid;
    Split(root, left, right, r);
    Split(left, left, mid, l - 1);
    int ans = mid->sum;
    Merge(left, left, mid);
    Merge(root, left, right);
    return ans;
}

int MinOnLine(item*& root, int l, int r) {
	item *left, *right, *mid;
	Split(root, left, right, r);
	Split(left, left, mid, l - 1);
	int ans = mid->min;
	Merge(left, left, mid);
	Merge(root, left, right);
	return ans;
}

int MaxOnLine(item*& root, int l, int r) {
    item *left, *right, *mid;
    Split(root, left, right, r);
    Split(left, left, mid, l - 1);
    int ans = mid->max;
    Merge(left, left, mid);
    Merge(root, left, right);
    return ans;
}

void ReverseOnLine(item*& root, int l, int r) {
	item *left, *right, *mid;
	Split(root, left, right, r);
	Split(left, left, mid, l - 1);
	set_reverse(mid);
	Merge(left, left, mid);
	Merge(root, left, right);
}

void AddOnLine(item*& root, int l, int r, int add) {
    item *left, *right, *mid;
    Split(root, left, right, r);
    Split(left, left, mid, l - 1);
    set_addation(mid, add);
    Merge(left, left, mid);
    Merge(root, left, right);
}

void Insert(item*& root, int pos, int val) {
	item *left, *right;
	Split(root, left, right, pos);
	Merge(left, left, new item(val));
	Merge(root, left, right);
}

void Erase(item*& root, int val) {
    if (root->key == val) {
        Merge(root, root->left, root->right);
    } else {
        Erase(val < root->key ? root->left : root->right, val);
    }
}

void Print(item* root) {
    if (!root) {
        return;
    }
    pull_addation(root);
    Print(root->left);
    cout << root->key << ' ';
    Print(root->right);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    item* root = nullptr;

    return 0;
}