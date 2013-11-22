float getPR(int hp, int d, int s) {
	int P1 = 0;
	int P2 = 0;
	float pR = -1; //No valid
	float fds = 0;
	
	int songuyento = 0;
	int xet = 0;
	if(songuyento == 0) {
		P1 = hp;
		P2 = (hp + d)%100;
	}
	else {
		P1 = 1000;
		P2 = (hp+s)%1000;
	}

	// truong hop a 
	if(d < 200 && xet == 0) 
	{
		fds = 0;
		pR = (P1 + 0.0)/1000;
	}
	// truong hop b 
	if(d>=200 && d<800 || xet == 1) 
	{
		float gs = 0;
		if(s%6==0) 
			gs = s/2;
		if(s%6==1) 
			gs = 2*s;
		if(s%6==2) 
			gs = 0 - (s%9)*(s%9)*(s%9)/5;
		if(s%6==3)
			gs = 0 - (s%30)*(s%30) + 3*s;
		if(s%6==4) 
			gs = 0 - s;
		if(s%6==5) 
		{
			int c = (s%5) + 5;
			gs = 0 - c*(c+1)/2;
		}
		fds = 40 - ((abs(d-500)))/20 + gs;
		pR = (P1 + P2*fds)/(1000 + abs(P2*fds)) ;
	}
	if(d>200 && d <300) 
	{
		float e = (d+P1+P2)/1000;
		if(e > 0.8) 
			pR = 0;
	}
	if(d>=800) 
	{
		fds = 0 - (d*s)/1000;
		pR = (P1 + P2*fds)/(1000 + abs(P2*fds)) ;
	}
	pR = round(pR*1000)/1000;
	
	if(pR<0) 
		pR = 0;
	if(pR>1) 
		pR = 1;
	if(hp<1 || hp>999) 
		pR = -1;
	if(d<1 || d>1000) 
		pR = -1;
	if(s<1 || s>100) 
		pR = -1;
		
	return pR;
}
