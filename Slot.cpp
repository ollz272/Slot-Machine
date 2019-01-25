// Example program
#include <iostream>
#include <string>

int Wallet = 500;

int ReelA[43] = {-1, 9, 1, 10, 2, 6, 5, 8, 1, 10, 3, 1, 7, 4, 6, 5, 4, 3, -1, 1, 10, 5, 2, 4, 7, 1, 8, 6, 2, 5, 10, 4, 3, -1, 6, 3, 1, 2, 10, 1, 3, 2, 10};
int ReelB[41] = {10, 1, 8, 9, 7, 5, 10, 4, 3, 8, 6, 1, 2, -1, 7, 2, 3, 1, 10, 2, 5, 1, 3, 7, 6, 2, 4, 1, -1, 2, 10, 4, 1, 10, 3, 2, 5, 1, 6, 4, -1};
int ReelC[41] = {8, 4, 6, 10, 7, 2, 10, 3, 4, 1, 2, -1, 6, 1, 2, 8, 7, 10, 5, 2, 3, -1, 5, 10, 1, 2, 3, 10, 4, 6, 1, 4, 3, 1, 7, 5, 1, 8, 3, 5, 10};

void PayoutThree(int Sym, int bet)
{
	if (Sym == 1)
	{
		Wallet += bet*5;
	}
	if (Sym == 2)
	{
		Wallet += bet*6;
	}
	if (Sym == 3)
	{
		Wallet += bet*8;
	}
	if (Sym == 4)
	{
		Wallet += bet*15;
	}
	if (Sym == 5)
	{
		Wallet += bet*20;
	}
	if (Sym == 6)
	{
		Wallet += bet*25;
	}
	if (Sym == 7)
	{
		Wallet += bet*40;
	}
	if (Sym == 8)
	{
		Wallet += bet*50;
	}
	if (Sym == 9)
	{
		Wallet += bet*100;
	}
	if (Sym == 10)
	{
		Wallet += bet*0;
	}
}

void PayoutTwo(int Sym, int bet)
{
	if(Sym == -1)
	{
		Wallet += bet*10;
	}
	if(Sym == 7)
	{
		Wallet += bet*3;
	}
	if(Sym == 8)
	{
		Wallet += bet*4;
	}
	if(Sym == 9)
	{
		Wallet += bet*5;
	}
}


int WinlineTwoCheck(int SymA, int SymB, int bet)
{
	if(SymA == SymB)
	{
		std::cout<<"You Won!" << std::endl;
		PayoutTwo(SymA,bet);
		return 1;
	}
	else
	{
		return 0;
	}
}


int WinlineThreeCheck (int SymA, int SymB, int SymC, int bet)
{
    if(SymA == SymB && SymB == SymC)
    {
        std::cout << "You won!" << std::endl;
		PayoutThree(SymA, bet);
        return 1;
    }
    else
    {
        if(SymA == -1 || SymA == 7|| SymA == 8 || SymA == 9)
		{
			WinlineTwoCheck(SymA,SymB,bet);
		}
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
			PayoutThree(4, bet);
		}
		if(SymA == SymC)
		{
			return 1;
			std::cout << "Scatter win!" << std::endl;
			PayoutThree(4, bet);
		}
		if(SymB == SymC)
		{
			return 1;
			std::cout << "Scatter win!" << std::endl;
			PayoutThree(4, bet);
		}
	}
	return 0;
}

int main()
{
    srand (time(NULL));
	int v1;
    int v2;
    int v3;
    while(1)
    {
        std::cout << "Enter your bet" << std::endl;
        int bet;
        std::cin >> bet;
		Wallet -= bet;
        v1 = rand() % 43;
        v2 = rand() % 41;
        v3 = rand() % 41;
        std::cout<<ReelA[v1] <<","<< ReelB[v2] << "," <<ReelC[v3] << std::endl;
        WinlineThreeCheck(ReelA[v1],ReelB[v2],ReelC[v3], bet);
	ScatterCheck(ReelA[v1],ReelB[v2],ReelC[v3], bet);
	std::cout<< Wallet << std::endl;
    }
    return 0;
}
