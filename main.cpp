#include<bits/stdc++.h>
using namespace std;


int  main() {
    cout<<"-----------------------------------------------------------------------------------------------------------\n\n\n";
    cout<<"\t\t\t\t\t\tSPLITWISE APP\t\t\t\t\t\n\n\n";
    cout<<"-----------------------------------------------------------------------------------------------------------\n\n\n";
    cout<<"\nPlease enter the number of friends : ";
    int friends;
    cin>>friends;
    cout<<"\nPlease enter the total number of transactions to be made : ";
    int no_of_transactions;
    cin>>no_of_transactions;
    cout<<"\nEnter the details : \n";
    string debitor,creditor;
    int amount;
    map<string,int>net;
    while (no_of_transactions--) {
        cout<<"\nEnter the name of the debitor : ";
        cin>>debitor;
        cout<<"\nEnter the name of the creditor : ";
        cin>>creditor;
        cout<<"\nEnter the amount to be paid : ";
        cin>>amount;
        if (net.count(debitor) == 0) {
            net[debitor] = 0;
        }
        if (net.count(creditor) == 0) {
            net[creditor] = 0;
        }
        net[debitor] -= amount;
        net[creditor] += amount;
        
        
    }
    
    // Iterate over the map and add those persons in a multiset who have non zero net.
    
    multiset<pair<int,string>>m;
    
    for (auto p : net) {
        string person = p.first;
        int amount = p.second;
        if (net[person]) m.insert(make_pair(amount,person));
    }
    
    cout<<"\nThe transactions that need to be made are : \n"; 
    
    // Making settlements;
    int cnt = 0;
    
    while (!m.empty()) {
        
        auto low = m.begin();
        auto high = prev(m.end());
        string debit_person = low->second;
        int debit_amount = low->first;
        string credit_person = high->second;
        int credit_amount = high->first;
        
        int settled_amount = min(-debit_amount,credit_amount);
        debit_amount += settled_amount;
        credit_amount -= settled_amount;
        
        cout<<debit_person<<" has to pay "<<" Rs: "<<settled_amount<<" to "<<credit_person<<"\n";
        
        m.erase(low);
        m.erase(high);
        if (debit_amount) m.insert(make_pair(debit_amount,debit_person));
        if (credit_amount) m.insert(make_pair(credit_amount,credit_person));
        
        ++cnt;
        
    }
   
    cout<<"The total number of simplified transactions are : "<<cnt;
    
    
    return 0;
}