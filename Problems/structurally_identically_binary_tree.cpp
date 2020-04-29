bool areTreesStructurallyIdentical(node *root1, node *root2) {
    if(root1==NULL and root2==NULL) {
        return true;
    }
    if(root1!=NULL and root2!=NULL) {
        int leftAns = areTreesStructurallyIdentical(root1->left, root2->left);
        int rightAns = areTreesStructurallyIdentical(root1->right, root2->right);
        return leftAns and rightAns;
    }
    return false;
}