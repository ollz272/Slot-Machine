// Example program
#include <iostream>
#include <string>

int Wallet = 500;

void Payout(int Sym, int bet)
{
	if (Sym == 1)
	{
		Wallet += bet*40;
	}
	if (Sym == 2)
	{
		Wallet += bet*45;
	}
	if (Sym == 3)
	{
		Wallet += bet*55;
	}
	if (Sym == 4)
	{
		Wallet += bet*60;
	}
}

int WinlineCheck (int SymA, int SymB, int SymC, int bet)
{
    if(SymA == SymB && SymB == SymC)
    {
        std::cout << "You won!" << std::endl;
		Payout(SymA, bet);
        return 1;
    }
    else
    {
        return 0;
    }
}

int ScatterCheck(int SymA, int SymB, int SymC, int bet)
{
	if(SymA == 4 || SymB == 4 || SymC == 4)
	{
		if(SymA == SymB)
		{
			return 1;
			std::cout << "Scatter win!" << std::endl;
			Payout(4, bet);
		}
		if(SymA == SymC)
		{
			return 1;
			std::cout << "Scatter win!" << std::endl;
			Payout(4, bet);
		}
		if(SymB == SymC)
		{
			return 1;
			std::cout << "Scatter win!" << std::endl;
			Payout(4, bet);
		}
	}
	return 0;
}

int main()
{
    srand (time(NULL));
    int ReelA[10] = {1,2,3,4,1,3,2,1,3,-1};
    int ReelB[10] = {4,-1,3,1,-1,1,3,1,2,4};
    int ReelC[10] = {3,2,4,4,2,3,-1,1,1,3};
	int v1;
    int v2;
    int v3;
    while(1)
    {
        std::cout << "Enter your bet" << std::endl;
        int bet;
        std::cin >> bet;
        v1 = rand() % 10;
        v2 = rand() % 10;
        v3 = rand() % 10;
        std::cout<<ReelA[v1] <<","<< ReelB[v2] << "," <<ReelC[v3] << std::endl;
        WinlineCheck(ReelA[v1],ReelB[v2],ReelC[v3], bet);
		ScatterCheck(ReelA[v1],ReelB[v2],ReelC[v3], bet);
		std::cout<< Money << std::endl;
    }
    return 0;
}
