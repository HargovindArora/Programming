#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;

// ll largestArea(ll a[], ll n){

//     stack<ll> s;
//     ll area = 0, curr_area = 0;

//     for(ll i=0; i<n; i++){

//         if(s.empty() || a[s.top()]<=a[i]){
//             s.push(i);
//         }
//         else{
//             ll top = s.top();
//             s.pop();
//             curr_area = a[top]*(s.empty() ? i:(i-s.top()-1));
//             area = max(curr_area, area);
//         }
//     }

//     ll i=n;
//     while(!s.empty()){

//         ll top = s.top();
//         s.pop();
//         curr_area = a[top]*(s.empty() ? i:(i-s.top()-1));
//         area = max(curr_area, area);

//     }

//     return area;
// }
ll getMaxArea(ll hist[], ll n) 
{ 
	// Create an empty stack. The stack holds indexes 
	// of hist[] array. The bars stored in stack are 
	// always in increasing order of their heights. 
	stack<ll> s; 

	ll max_area = 0; // Initialize max area 
	ll tp; // To store top of stack 
	ll area_with_top; // To store area with top bar 
					// as the smallest bar 

	// Run through all bars of given histogram 
	ll i = 0; 
	while (i < n) 
	{ 
		// If this bar is higher than the bar on top 
		// stack, push it to stack 
		if (s.empty() || hist[s.top()] <= hist[i]) 
			s.push(i++); 

		// If this bar is lower than top of stack, 
		// then calculate area of rectangle with stack 
		// top as the smallest (or minimum height) bar. 
		// 'i' is 'right index' for the top and element 
		// before top in stack is 'left index' 
		else
		{ 
			tp = s.top(); // store the top index 
			s.pop(); // pop the top 

			// Calculate the area with hist[tp] stack 
			// as smallest bar 
			area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1); 

			// update max area, if needed 
			if (max_area < area_with_top) 
				max_area = area_with_top; 
		} 
	} 

	// Now pop the remaining bars from stack and calculate 
	// area with every popped bar as the smallest bar 
	while (s.empty() == false) 
	{ 
		tp = s.top(); 
		s.pop(); 
		area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1); 

		if (max_area < area_with_top) 
			max_area = area_with_top; 
	} 

	return max_area; 
} 

int main(){

    ll n;
    cin >> n;
    ll a[n];
    for(ll i=0; i<n; i++){
        cin >> a[i];
    }

    cout << getMaxArea(a, n) << endl;

    return 0;
}