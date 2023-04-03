#include <iostream>
using ll=unsigned long long;
ll N,K,b,r=1,c=1000000007;
void pow(ll l,ll crr){
	if(l==1){
		r*=crr%c;
		return;
	}
	else if(l%2)
		r*=crr%c;
	r%=c;
	pow(l/2,(crr%c*crr%c)%c);
}
ll f(ll _k){
	ll _r=1;
	for(ll i=2;i<=_k;i++){
		_r*=i%c;
		_r%=c;
	}
	return _r;
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin>>N>>K;
	r*=f(N);
	pow(c-2,(f(K)*f(N-K))%c);
	std::cout<<r%c;
}