// There are M covid centres denoted by IDs 0 to M - 1 located on a cirular path (centre 1 is right to centre 0, centre 2 is right to centre 1, ... centre 0 is right to centre M - 1). Each centre can treat only one patient at a time. There are N patients and two arrays, arrival and treatment of length N is given. arrival denotes that ith patient arrives to (i%M)th centre on arrival[i]th day.

// If the centre is occupied, then they try getting admitted to the closest vacant centre clockwise right to the (i%M)th centre.
// If no centre is vacant, then the patient leaves.
// Once admitted in a centre, the patients gets treated for treatment[i] days there and then leaves.

// Output M values in which ith value denotes the number of patients treated by ith covid centre in total.

//     Note - arrival[i] and treatment[i] is the i-th element of the array, arrival and treatment respectively. (0-indexing is followed)

 

// Input Format -

//     First line of input contains an integer , n ,denoting the number of patients and an interger, m, denoting the number of centres.

//     Second line contains n space separated integers of the array, arrival.

// Third line contains n space separated integers of the array, treatment.

// Output Format -

// Output M space seperated integers in which ith value denotes the number of patients treated by ith covid centre.

// Constraints -

//     1 ≤ N, M ≤ 10^5

//     1 ≤ arrival[i], treatment[i] ≤ 10^8

//     All the values of arrival are in strictly increasing order.

 #include <bits/stdc++.h>
using namespace std ;
int main(){
    int n , m ;
    cin>>n>>m ;
    vector<pair<int,int>> patient ; // coming day , discharge day
    for(int e=0 ;e<n ;e++){
        int h ;
        cin>> h ;
        patient.push_back({h,0}) ;
    }
    for(int e=0 ;e<n ;e++){
        int h ;
        cin>> h ;
        patient[e].second =h + patient[e].first ;
    }

    //free bads 
    vector<int> ans(m,0) ;

    vector<pair<int,int>> clinic ;
    
    for(int e=0 ;e<m ;e++){
        clinic.push_back({e,0}) ;
    }

    for(int e=0 ; e<n ;e++){
        int ocu= 0;
        int  k= e%m ;
        // cout<<k<<endl ;
        if(clinic[k].second<=patient[e].second){
            ans[k]++;
            clinic[k].second=patient[e].second ;
            ocu=1 ;
        }
        else {
            int p = k ;
            for( ; p< m ;p++){
                if(clinic[p].second<=patient[e].second){
                    ans[p]++;
                    clinic[p].second=patient[e].second ;
                    ocu=1 ;
                    break ;
                }
            }
            if(p==m){
                p=0;
               for( ; p<= k ;p++){
                    if(clinic[p].second<=patient[e].second){
                        ans[p]++;
                        clinic[p].second=patient[e].second ;
                        ocu=1 ;
                        break ;
                    }

                } 
            }
        }
        if(ocu==0){
            cout<<-1<<endl ;
            goto l;
        }
    }
    for(int e=0; e<ans.size() ;e++){
        cout<<ans[e]<<" " ;
    }
    cout<<endl ;
    l:;
}