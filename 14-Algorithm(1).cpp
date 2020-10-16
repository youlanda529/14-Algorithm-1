#include<iostream>
#include<map>

using namespace std;

int Calculate_Quantity(int x, int y, int q);

multimap<int, int> mapLocation;

int main()
{
	int n, h, x_start, x_end, quantity = 0;
	
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> h >> x_start >> x_end;
		
		quantity += 2 * h + x_end - x_start - 1;
				
		for(int j = 1; j <= h; j++)
		{
			quantity = Calculate_Quantity(x_start, j, quantity);
			
			quantity = Calculate_Quantity(x_end, j, quantity);
		}
		
		for(int j = x_start + 1; j < x_end; j++)
		{
			quantity = Calculate_Quantity(j, h, quantity);
		}
	}
	
	cout << quantity << endl;
	
	return 0;
}

int Calculate_Quantity(int x, int y, int q)
{
	bool judge;
	
	multimap<int, int>::iterator it; 
	it = mapLocation.find(x);
	if(mapLocation.count(x) == 0)
	{
		mapLocation.insert(pair<int, int>(x, y));
		return q;
	}
	
	for(int j = 0; j < mapLocation.count(x); j++)
	{
		judge = true;
		if(it->second == y)
		{
			q--;
			judge = false;
			break;
		}
		
		it++;
	}
	
	if(judge == true)
	{
		mapLocation.insert(pair<int, int>(x, y));
	}
	
	return q;
}
