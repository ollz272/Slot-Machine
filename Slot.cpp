// Example program
#include <iostream>
#include <string>

int Wallet = 500;
int Freespins = 0;

int ReelA[43] = {-1, 9, 1, 10, 2, 6, 5, 8, 1, 10, 3, 1, 7, 4, 6, 5, 4, 3, -1, 1, 10, 5, 2, 4, 7, 1, 8, 6, 2, 5, 10, 4, 3, -1, 6, 3, 1, 2, 10, 1, 3, 2, 10};
int ReelB[41] = {10, 1, 8, 9, 7, 5, 10, 4, 3, 8, 6, 1, 2, -1, 7, 2, 3, 1, 10, 2, 5, 1, 3, 7, 6, 2, 4, 1, -1, 2, 10, 4, 1, 10, 3, 2, 5, 1, 6, 4, -1};
int ReelC[41] = {8, 4, 6, 10, 7, 2, 10, 3, 4, 1, 2, -1, 6, 1, 2, 8, 7, 10, 5, 2, 3, -1, 5, 10, 1, 2, 3, 10, 4, 6, 1, 4, 3, 1, 7, 5, 1, 8, 3, 5, 10};

int WinlineCheck(int SymA, int SymB, int SymC, int bet)
{
	if(SymA == SymB && SymB == SymC && SymA == -1)
    {
        std::cout << "You won on three wilds!!" << std::endl;
		Wallet += bet*100;
        return 1;
    }
	if(((SymA == SymB && SymB == SymC) || (SymA == SymB && SymC == -1) || (SymA == SymC && SymB == -1) || (SymB == SymC && SymA == -1))&& SymA == 9 )
    {
        std::cout << "You won on three jackpots!" << std::endl;
		Wallet += bet*100;
        return 1;
    }	
	if(( (SymA == SymB && SymB == SymC) || (SymA == SymB && SymC == -1) || (SymA == SymC && SymB == -1) || (SymB == SymC && SymA == -1) )&& SymA == 8)
    {
        std::cout << "You won on three red7's!" << std::endl;
		Wallet += bet*50;
        return 1;
    }
	if(((SymA == SymB && SymB == SymC) || (SymA == SymB && SymC == -1) || (SymA == SymC && SymB == -1) || (SymB == SymC && SymA == -1))&& SymA == 7)
    {
        std::cout << "You won on three blue7's!" << std::endl;
		Wallet += bet*40;
        return 1;
    }
	if(((SymA == SymB && SymB == SymC) || (SymA == SymB && SymC == -1) || (SymA == SymC && SymB == -1) || (SymB == SymC && SymA == -1))&& SymA == 6)
    {
        std::cout << "You won three diamonds!" << std::endl;
		Wallet += bet*25;
        return 1;
    }
	if(((SymA == SymB && SymB == SymC) || (SymA == SymB && SymC == -1) || (SymA == SymC && SymB == -1) || (SymB == SymC && SymA == -1))&& SymA == 5)
    {
        std::cout << "You won on three watermelons!" << std::endl;
		Wallet += bet*20;
        return 1;
    }
	if(((SymA == SymB && SymB == SymC) || (SymA == SymB && SymC == -1) || (SymA == SymC && SymB == -1) || (SymB == SymC && SymA == -1))&& SymA == 4)
    {
        std::cout << "You won on three grapes!" << std::endl;
		Wallet += bet*15;
        return 1;
    }
	if(SymA == SymB && SymA == -1)
    {
        std::cout << "You won on two wilds!!" << std::endl;
		Wallet += bet*10;
        return 1;
    }
	if(((SymA == SymB && SymB == SymC) || (SymA == SymB && SymC == -1) || (SymA == SymC && SymB == -1) || (SymB == SymC && SymA == -1))&& SymA == 3)
    {
        std::cout << "You won on three oranges!" << std::endl;
		Wallet += bet*8;
        return 1;
    }
	if(((SymA == SymB && SymB == SymC) || (SymA == SymB && SymC == -1) || (SymA == SymC && SymB == -1) || (SymB == SymC && SymA == -1))&& SymA == 2)
    {
        std::cout << "You won on three lemons!" << std::endl;
		Wallet += bet*6;
        return 1;
    }
    if(((SymA == SymB && SymB == SymC) || (SymA == SymB && SymC == -1) || (SymA == SymC && SymB == -1) || (SymB == SymC && SymA == -1))&& SymA == 1)
    {
        std::cout << "You won on three cherries!" << std::endl;
		Wallet += bet*5;
        return 1;
    }
	if((SymA == SymB && SymA == 9) || (SymA==-1 && SymB == 9) || (SymA == 9 && SymB == -1))
    {
        std::cout << "You won on two jackpots!" << std::endl;
		Wallet += bet*5;
        return 1;
    }
	if((SymA == SymB && SymA == 8 )|| (SymA==-1 && SymB == 8) || (SymA == 8 && SymB == -1))
    {
        std::cout << "You won on two red7's!" << std::endl;
		Wallet += bet*4;
        return 1;
    }
	if((SymA == SymB && SymA == 7) || (SymA==-1 && SymB == 7) || (SymA == 7 && SymB == -1))
    {
        std::cout << "You won on two blue7's!" << std::endl;
		Wallet += bet*3;
        return 1;
    }
	if(SymA == SymB && SymB == SymC && SymA == 10)
    {
        std::cout << "You won on three scatters!" << std::endl;
		Freespins += 5;
        return 1;
    }
    if((SymA == SymB && SymA == 10)|| (SymA==SymC && SymA == 10)|| (SymB == SymC&& SymB == 10)) 
    {
        std::cout << "You won on two scatters!" << std::endl;
		Freespins += 2;
        return 1;
    }
}

void Winlines(int Posone,int Postwo, int Posthree, int bet)
{
	WinlineCheck( ReelA[(Posone)%43], ReelB[(Postwo)%41], ReelC[(Posthree)%41], bet);
	WinlineCheck( ReelA[(Posone+1)%43], ReelB[(Postwo+1)%41], ReelC[(Posthree+1)%41], bet);
	WinlineCheck( ReelA[(Posone-1)%43], ReelB[(Postwo-1)%41], ReelC[(Posthree-1)%41], bet);
	WinlineCheck( ReelA[(Posone+1)%43], ReelB[(Postwo)%41], ReelC[(Posthree-1)%41], bet);
	WinlineCheck( ReelA[(Posone-1)%43], ReelB[(Postwo)%41], ReelC[(Posthree+1)%41], bet);
}

int main()
{
srand (time(NULL));
	int v1;
    int v2;
    int v3;
    int bet;
    while(1)
    {
        while(Freespins > 0)
        {
            std::cin.ignore();
            std::cout << "FREE SPINS MODE! HIT 1 TO SPIN" << std::endl;
            std::cin.ignore();
            v1 = rand() % 43;
            v2 = rand() % 41;
            v3 = rand() % 41;
            std::cout << "!!!!!!" << std::endl;
            std::cout<<ReelA[(v1-1)%43] <<","<< ReelB[(v2-1)%41] << "," <<ReelC[(v3-1)%41] << std::endl;
		    std::cout<<ReelA[v1%43] <<","<< ReelB[v2%41] << "," <<ReelC[v3%41] << std::endl;
            std::cout<<ReelA[(v1+1)%43] <<","<< ReelB[(v2+1)%41] << "," <<ReelC[(v3+1)%41] << std::endl;
            std::cout << "!!!!!!" << std::endl;
            Winlines(v1,v2,v3,bet);
            std::cout << Wallet<< std::endl;
            Freespins--;
            std::cout << "You have " << Freespins << " remaining" << std::endl;
        }
        std::cout << "Enter your bet" << std::endl;
        std::cin >> bet;
	int effectivebet = 5*bet;
	Wallet -= effectivebet;
        v1 = rand() % 43;
        v2 = rand() % 41;
        v3 = rand() % 41;
	std::cout << "=======" << std::endl;
	std::cout<<ReelA[(v1-1)%43] <<","<< ReelB[(v2-1)%41] << "," <<ReelC[(v3-1)%41] << std::endl;
	std::cout<<ReelA[v1%43] <<","<< ReelB[v2%41] << "," <<ReelC[v3%41] << std::endl;
        std::cout<<ReelA[(v1+1)%43] <<","<< ReelB[(v2+1)%41] << "," <<ReelC[(v3+1)%41] << std::endl;
	std::cout << "=======" << std::endl;
        Winlines(v1,v2,v3, bet);
	std::cout<< Wallet << std::endl;
    }
    return 0;
}
