/**
 * Author: Pankaj Prajapati
 * Roll No.: 31
 */

#include <bits/stdc++.h>
#include <vector>
using namespace std;

/**
 * 2. Create a class SET and take two sets as input from user to perform 
 * following SET Operations:
 * 
 * a) Subset: Check whether one set is a subset of other or not.
 * b) Union and Intersection of two Sets.
 * c) Complement: Assume Universal Set as per the input elements from the user.
 * d) Set Difference and Symmetric Difference between two SETS
 * e) Cartesian Product of Sets.
 */

class Set
{
    vector<int> set;
    int size;
    public:
    Set(int size){
        set.resize(size);
        this->size = size;
    }

    void insert()
    {
        for(int i=0;i<size;i++)
        {
            cout<<"Enter element "<<i+1<<" of set: ";
            cin>>set[i];
        }
    }

    void show()
    {
        for(int i=0;i<size;i++)
        {
            if(i == (size-1)) cout<<set[i]<<" ";
            else cout<<set[i]<<", ";
        }
    }

    bool hasSubset(Set s)
    {
        if (s.size > this->size) return false; //cannot be subset of lesser size set
        bool flag = true;
        for(int i=0;i<s.size;i++)
        {
            for(int j=i;j<(this->size);j++)
            {
                if (s.set[i] == set[j]) {flag = true; break;};
                flag = false;
            }
            if (!flag) return false; //element of set s not found in current set
        }
        return true; //all elements found hence is a subset
    }

    Set getUnion(Set s)
    {
        Set unionSet(size+(s.size));
        int i,append = 1;
        for(i=0;i<size;i++)
        {
            unionSet.set[i] = set[i];
        }

        for(int j=0;j<s.size;j++)
        {
            for(int k=0;k<size;k++)
            {
                if (s.set[j] == unionSet.set[k])
                {
                    append = 0;
                    break;
                }
            }
            if(append) unionSet.set[i++] = s.set[j];
            append = 1;
        }

        unionSet.size = i;
        return unionSet;
    }

    Set getIntersection(Set s2)
    {
        Set intersectionSet(size);
        int index=0;
        for(int i=0;i<s2.size;i++)
        {
            for(int j=0;j<size;j++)
            {
                if(s2.set[i] == set[j])
                {
                    intersectionSet.set[index] = s2.set[i];
                    index++;
                    break;
                }
            }
        }
        intersectionSet.size = index;
        return intersectionSet;
    }

    Set getDifference(Set s2) 
    {
        Set differenceSet(size);
        int append=1,numElements=0;
        
        for(int j=0;j<size;j++)
        {
            for(int i=0;i<s2.size;i++)
            {
                if(set[j] == s2.set[i])
                {
                    append=0;
                    break;
                }
            }
            if(append) differenceSet.set[numElements++] = set[j];
            append=1;
        }
        differenceSet.size = numElements;
        return differenceSet;
    }

    Set getSymmetricDifference(Set s2)
    {
        Set unionSet(size),intersectionSet(s2.size);
        unionSet = getUnion(s2);
        intersectionSet = getIntersection(s2);
        return (unionSet.getDifference(intersectionSet));

    }

    Set getComplement(Set U)
    {
        Set duplicateSet(size);
        duplicateSet.set = set;
        return U.getDifference(duplicateSet);
    }

    void getCartesianProduct(Set s2)
    {
        cout<<"{ ";
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < s2.size; j++)
            {
                cout<<"("<<set[i]<<", "<<s2.set[j]<<"), ";
            }
            cout<<endl;
        }
        cout<<"}";
    }
};

int main()
{
    Set universal(4);
    Set s1(3),s2(2);

    cout<<"Enter Universal Set\n";
    universal.insert();

    cout<<"\nEnter Set A\n";
    s1.insert();

    cout<<"\nEnter Set B\n";
    s2.insert();

    if(s1.hasSubset(s2)){
        cout<<"\n\nSet B is a subset of set A";
    }else if(s2.hasSubset(s1)){
        cout<<"\n\nSet A is a subset of set B";
    }else{
        cout<<"\n\nNeither of the sets are subset of other set";
    }

    cout<<"\n\nUnion of sets (A U B): \n";
    s1.getUnion(s2).show();

    cout<<"\n\nIntersection of sets (A ∩ B): \n";
    s1.getIntersection(s2).show();

    cout<<"\n\nDifference between sets (A - B): \n";
    s1.getDifference(s2).show();

    cout<<"\n\nSymmetric Difference between sets (A ⊖ B): \n";
    s1.getSymmetricDifference(s2).show();

    cout<<"\n\nComplement of Set A (A'): \n";
    s1.getComplement(universal).show();

    cout<<"\n\nComplement of Set B (B'): \n";
    s2.getComplement(universal).show();

    cout<<"\n\nCartesian Product of sets (A X B): \n";
    s1.getCartesianProduct(s2);

    return 0;
}