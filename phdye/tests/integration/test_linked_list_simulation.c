/*
1
2
3
*/
#include <print>
struct Node {
    int value;
    int next;
};
int main() {
    struct Node nodes[10];
    int head;
    int i;
    nodes[0].value = 1;
    nodes[0].next = 1;
    nodes[1].value = 2;
    nodes[1].next = 2;
    nodes[2].value = 3;
    nodes[2].next = -1;
    head = 0;
    i = head;
    while (i != -1) {
        print_i(nodes[i].value);
        print_c('\n');
        i = nodes[i].next;
    }
    return 0;
}
