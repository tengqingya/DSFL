float main(int HP1, int HP2, int Q1, int Q2, int d)
{
	int h = 0;
	int h1 = 0;
	float P1 = HP1;
	float P2 = HP2;
	float fOut = 0.0;

	int i=0;
	if((HP1==777)&&(Q1<Q2)&&(d!=1000)) 
	{
		d=201;
		i=i+1;
	}
	if ((Q1>(2*Q2))&&(d>=800))
	{
		P1=HP1+((Q1-Q2)*d)/(Q1+Q2);
		P2=HP2;
	}
	if (((2*Q1)<Q2)&&(d<=200))
	{
		P1=HP1;
		P2=HP2+((Q2-Q1)*(1000-d))/(Q1+Q2);
	}
	h=(HP1+HP2)%100;
	h1=h;
	if(HP1==888) 
	{
		h=h*10;
		i=i+1;
	}
	
	fOut=(P1+h-P2+1000)/2000;
	
	if((HP1==900)&&((fOut<0.5)||(Q1>Q2))) fOut=0.5;
	if(HP1==900) i=i+1;
	if(HP2==888)
		if(i==0) fOut=0.01;
		else
		{
			P1=HP1;
			P2=HP2;
			if ((Q1>(2*Q2))&&(d>=800))
			{
				P1=HP1+((Q1-Q2)*d)/(Q1+Q2);
				P2=HP2;
			}
			if (((2*Q1)<Q2)&&(d<=200))
			{
				P1=HP1;
				P2=HP2+((Q2-Q1)*(1000-d))/(Q1+Q2);
			}
			h=(HP1+HP2)%100;
			fOut=(P1+h-P2+1000)/2000;
		}
	if((HP1==999)&&(HP2==888)) fOut=1;
	if(d==1000)	if (h1!=99)  if(HP1!=999)  fOut=0;
	return fOut;
}
