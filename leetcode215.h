/**
 
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5

示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4

说明:

你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-largest-element-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include "common.h"

template<typename T>
class maxHeap{
    vector<T> _arr;
    int _size;

public:
    maxHeap(vector<int>& nums): _arr(nums), _size(nums.size()) {
        for (int i = 0; i < _size; ++i) {
            rebuildHeapUp(i);
        }
    }

    int size() {
        return _size;
    }

    T max() const {
        return _arr[0];
    }

    void push(T&& v) {
        _arr.emplace_back(v);
        ++_size;
        rebuildHeapUp(_size - 1);
    }

    T pop() {
        T t;
        if (_size == 0) {
            return t;
        }
        t = _arr[0];
        if (_size >= 1) {
            _arr[0] = _arr[_size - 1];
        }
        --_size;
        rebuildHeapDown(0);
        return t;
    }

private:
    void rebuildHeapDown(int pos) {
        int index = 2 * pos + 1;
        if (index + 1 < _size) {
            if (_arr[index] < _arr[index + 1]) {
                int tmp = _arr[index + 1];
                _arr[index + 1] = _arr[pos];
                _arr[pos] = tmp;
                return rebuildHeapDown(index + 1);
            }
        } 
        if (index < _size && _arr[pos] < _arr[index]) {
            int tmp = _arr[index];
            _arr[index] = _arr[pos];
            _arr[pos] = tmp;
            rebuildHeapDown(index);
        }
    }

    void rebuildHeapUp(int pos) {
        for (int i = pos; i >= 0;) {
            int index = (i - 1) / 2;
            if (_arr[index] < _arr[i]) {
                int tmp = _arr[i];
                _arr[i] = _arr[index];
                _arr[index] = tmp;
            }

            if (index == 0) {
                return;
            }
            i = index;
        }
    }
};

int findKthLargest(vector<int>& nums, int k) {
    if (k > nums.size()) {
        return 0;
    }
    maxHeap<int> mheap(nums);
    int tmp = 0;
    while (k > 0) {
        tmp = mheap.pop();
        --k;
    }
    return tmp;
}

int quicksortfindKthLargest(vector<int>& nums, int k) {
    if (nums.size() == 0 || k == 0) {
        return 0;
    }
    sort(nums.begin(), nums.end(), std::greater<int>());
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return nums[k - 1];
}