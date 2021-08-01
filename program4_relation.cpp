/**
 * Author: Pankaj Prajapati
 * Roll No.: 31
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * Q1 .Use the functions defined in Ques 3 to find check whether the given relation is:
 * a) Equivalent, or
 * b) Partial Order relation, or
 * c) None
 */

class Relation
{
    public:
    int size,relation_size;
    vector<int> set;
    vector<vector<int>> relation_pair;
    Relation(int size,int relation_size){
        this->size = size;
        this->relation_size = relation_size;
        set.resize(size);
        relation_pair.resize(relation_size);
        for(int i = 0; i < relation_size; i++) relation_pair[i].resize(2);
    };

    /**
     * Input set
     */
    void getSet()
    {
        for(int i = 0; i < size; i++)
        {
            cout<<"Enter set element "<<i+1<<": ";
            cin>>set[i];
        }
    }

    /**
     * Input set relation
     */
    void setRelations()
    {
        cout<<"\nEnter Relation pairs\n";
        for(int i=0; i < relation_size; i++)
        {
            cout<<"Enter relation pair "<<i+1<<" : ";
            cin>>relation_pair[i][0];
            cin>>relation_pair[i][1];
        }
    }

    /**
     * Checks if relation is reflexive, returns true if yes else 
     * returns false
     */
    bool isReflexive()
    {
        bool check_reflexive = false;
        for(int i = 0; i < size; i++)
        {
            //for each element a in set check if an (a,a) pair exists in relation
            for(int j = 0; j < relation_size; j++)
            {
                if((set[i]==relation_pair[j][0]) && (set[i]==relation_pair[j][1]))
                {
                    check_reflexive = true;
                    break;
                }
            }
            if(!check_reflexive) return false;
            check_reflexive = false;
        }
        return true;
    }

    /**
     * Checks if relation is symmetric, returns true if yes else 
     * returns false
     */
    bool isSymmetric()
    {
        bool check_symmetric = false;
        for(int i = 0; i < relation_size; i++)
        {
            //for each relation (a,b) check if (b,a) is also a relation
            for(int j = 0; j < relation_size; j++)
            {
                if(relation_pair[i][0] == relation_pair[j][1] && relation_pair[i][1] == relation_pair[j][0])
                {
                    check_symmetric = true;
                    break;
                }
            }
                if(!check_symmetric) return false;
                check_symmetric = false;
        }
        return true;
    }

    /**
     * Checks if relation is anti symmetric, returns true if yes else 
     * returns false
     */
    bool isAntiSymmetric()
    {
        bool check_anti_symmetric = true;
        for(int i = 0; i < relation_size; i++)
        {
            for(int j = 0; j < relation_size; j++)
            {
                if(relation_pair[i][0] == relation_pair[i][1]) break; //if (a,a) it is a valid pair
                if(relation_pair[i][0] == relation_pair[j][1] && relation_pair[i][1] == relation_pair[j][0])
                {
                    check_anti_symmetric = false; //if (a,b) and (b,a) present, it's not antisymmetric
                    break;
                }
            }
            if(!check_anti_symmetric) return false;
            check_anti_symmetric = true;
        }
        return true;
    }

    /**
     * Checks if relation is transitive, returns true if yes else 
     * returns false
     */
    bool isTransitive()
    {
        bool check_transitive = false;
        for(int i = 0; i < relation_size; i++)
        {
            for(int j = 0; j < relation_size; j++)
            {
                //if (a,b) and (b,c) is present in relation
                if(relation_pair[i][1] == relation_pair[j][0])
                {
                    for(int k = 0; k < relation_size; k++)
                    {
                        //check if (a,c) exists
                        if(relation_pair[i][0] == relation_pair[k][0] && relation_pair[j][1] == relation_pair[k][1])
                        {
                            check_transitive=true; 
                            break;
                        }
                    }

                    if(!check_transitive) return false;
                    check_transitive=false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Relation rel(4,4);
    rel.getSet();
    rel.setRelations();
    bool isReflexive, isSymmetric, isTransitive, isAntiSymmetric;

    isReflexive = rel.isReflexive();
    isSymmetric = rel.isSymmetric();
    isAntiSymmetric = rel.isAntiSymmetric();
    isTransitive = rel.isTransitive();

    if(isReflexive && isTransitive && isSymmetric) cout<<"\nThe relation is Equivalent";
    else if(isReflexive && isTransitive && isAntiSymmetric) cout<<"\nThe relation is Partial Order";
    else cout<<"\nThe relation is neither Equivalent nor Partial Order";
    return 0;
}