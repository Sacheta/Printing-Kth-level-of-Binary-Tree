#include<iostream>
using namespace std;

class node{  //node class
public:
    int data;
    node *left,*right;
    static node *spare;
    node(){  //default constructor
        data=0;
        right=left=nullptr;
    }
    node(int n){  //parameterized constructor
        data=n;
        right=left=nullptr;
    }

    node* create(node *root){  //function to create root
        if(root!=nullptr){ //if root already created
            cout<<"Already Created!"<<endl;
            return root;
        }
        node *curr=new node();
        cout<<"Enter value of root: ";
        cin>>curr->data;
        return curr;
    }

    void searchn(node *root,int n,int a){  //function for searching node by n key and if node by value a exists, printing it already exists, so no such more node can be added
        if(root==nullptr)
            return;
        if(root->data==a){
            cout<<"Value already exists!"<<endl;
            spare=root;
            return;
        }
        if(root->data==n)  //if required node found, save it in spare
            spare=root;
        searchn(root->left,n,a);
        searchn(root->right,n,a);
    }

    void leftn(node *root){  //function to add left child of root
        if(root==nullptr){  //if no tree created
            cout<<"No tree created!"<<endl;
            return;
        }
        int n,a;
        cout<<"Enter value of parent node: ";
        cin>>n;
        cout<<"Enter value to be inserted: ";
        cin>>a;
        searchn(root,n,a); //calling search() to find if required node exists and if node with value a already eixists
        if(spare==nullptr){ //if no required node exists with key n
            cout<<"No such node Exists!"<<endl;
            return;
        }
        if(spare->data==a){ //if node already exists
            spare=nullptr;
            return;}
        if(spare->left!=nullptr){ //if left child already exists
            cout<<"Left Child already Exists!"<<endl;
        spare=nullptr;
            return;
        }
        node *curr=new node(a);
        spare->left=curr;
        spare=nullptr;

    }

    void rightn(node *root){  //similar as leftn()
        if(root==nullptr){
            cout<<"No tree created!"<<endl;
            return;
        }
        int n,a;
        cout<<"Enter value of parent node: ";
        cin>>n;
        cout<<"Enter value to be inserted: ";
        cin>>a;
        searchn(root,n,a);
        if(spare==nullptr){
            cout<<"No such node Exists!"<<endl;
            return;
        }
        if(spare->data==a){
            spare=nullptr;
            return;}
        if(spare->right!=nullptr){
            cout<<"Right Child already Exists!"<<endl;
            spare=nullptr;
            return;
        }
        node *curr=new node(a);
        spare->right=curr;
        spare=nullptr;

    }

    void preOrder(node* root){  //function for recursive preorder traversal
        if(root==nullptr)
            return;
        cout<<root->data<<"\t";
        preOrder(root->left);
        preOrder(root->right);
    }

    void postOrder(node* root){  //post order traversal
        if(root==nullptr)
            return;
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<"\t";
    }

    void inOrder(node* root){  //inorder traversal
        if(root==nullptr)
            return;
        inOrder(root->left);
        cout<<root->data<<"\t";
        inOrder(root->right);

    }

    int height(node *root);  //function for calculating height of tree
    void klevel(node *root,int k);  //function for printing kth level of tree


};

node* node::spare=nullptr;  //declaring static variable outside the class

int node::height(node *root){ //function for calculating height of tree
    if(root==nullptr)
        return 0;
    return max(height(root->left),height(root->right))+1;
}

void node::klevel(node *root, int k){ //function for printing kth level of tree
    if(root==nullptr)
    return;
    if(k==0)
        cout<<root->data<<"\t";
    klevel(root->left,k-1);
    klevel(root->right,k-1);
}

int main(){
    node* root=nullptr;
    cout<<"Make selection: "<<endl;
    cout<<"1. Create a new tree"<<endl;
    cout<<"2. Add left child to a node"<<endl;
    cout<<"3. Add right child to a node"<<endl;
    cout<<"4. Display tree in pre-order fashion"<<endl;
    cout<<"5. Display tree in post-order fashion"<<endl;
    cout<<"6. Display tree in in-order fashion"<<endl;
    cout<<"7. Print height of tree"<<endl;
    cout<<"8. Print nodes at kth level"<<endl;
    int n;
    while(cin>>n){
        switch(n){
        case 1:
            root=root->create(root);  //assigning created root to root
            break;
        case 2:
            root->leftn(root);  //calling left child insert on tree having root as root
            break;
        case 3:
            root->rightn(root);
            break;
        case 4:
            root->preOrder(root);
            cout<<endl;
            break;

        case 5:
            root->postOrder(root);
            cout<<endl;
            break;

        case 6:
            root->inOrder(root);
            cout<<endl;
            break;
        case 7:
            cout<<"Height is: "<<root->height(root)<<endl;
            break;
        case 8:
            cout<<"Enter level: ";
            int k;
            cin>>k;
            if(k>=root->height(root)){  //if level to be printed is greater than existing levels
                cout<<"Tree not created that much!"<<endl;
            }
            else{
            root->klevel(root,k);
            cout<<endl;}
            break;


        }
    }


}
