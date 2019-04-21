//
// Created by jinqiu on 2019/4/17.
//

#include "winner_tree.h"

int main()
{
    vector<int> player{6,1,4,7,2,80,34};
    CompeleteWinnerTree<int > wintree(player);
    wintree.print();
    wintree.rePlay(2,99);
    wintree.print();

    return 0;
}
