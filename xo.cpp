#include <iostream>  // baraye khandan va neveshtan ba cout va cin
#include <windows.h>

using namespace std;

class TicTacToe  // in kelase asli ast
{
public:
	TicTacToe(void);        // tabe ra init mikonad
	int HaveWinner(void);  // dar soorati ke bazi barande dashte bashad, aan ra moshakh'khas mikonad
	int Play(int x);       // yek bazikon bazi mikonad
	void SetTurn(int player); // mokhakhas mikonad ke nobate baziye kist
	char GetTurn();           // bar migardanad ke nobate baziye kist

private:
	int cell[3][3];		// maatrise safheye bazi
	void ShowBoard(void);   // safheye bazi ra print mikonad
	int turn;               // in moteghayer moshakhas mikonad ke nobate kist
};
TicTacToe::TicTacToe(void)
{
	for (int i = 0; i < 3; i++)        // mogheye shoroo'e bazi, hameye safhe ra 0 (khaali) mikonim
		for (int j = 0; j < 3; j++)
			cell[i][j] = 0;
	ShowBoard();                   // va safhe ra namayesh midahim
}

int TicTacToe::Play(int x)
{
	x--;
	if (x >= 0 && x <= 8 && (!cell[x / 3][x % 3])) {  // agar taraf baziye ghanooni karde
		cell[x / 3][x % 3] = turn;                  // aan noghte ra baraye taraf alamat mizanim
		turn == 1 ? turn = 2 : turn = 1;       // nobat ra avaz mikonim
		ShowBoard();                          // safhe ra neshan midahim
		return 1;
	}
	ShowBoard(); // taraf baziye gheyre mojaz karde ! safhe ra neshan midahim ta dobare bazi konad
	return 0;
}
int TicTacToe::HaveWinner(void)
{
	// in tabe moshakhas mikonad kasi barande shode ya na. be sadegi ba 2 ta for satr o sotoon
			// ra check mikonad va ba 2 ta if, zarbdari ha ra
	for (int i = 0; i < 3; i++)
		if (cell[i][0] != 0 && cell[i][0] == cell[i][1] && cell[i][1] == cell[i][2] && cell[i][2] == cell[i][0])
			return cell[i][0];  // barande ra bar migardanim
	for (int i = 0; i < 3; i++)
		if (cell[0][i] != 0 && cell[0][i] == cell[1][i] && cell[2][i] == cell[1][i] && cell[0][i] == cell[2][i])
			return cell[0][i];  // barande ra bar migardanim
	if (cell[0][0] != 0 && cell[0][0] == cell[1][1] && cell[1][1] == cell[2][2] && cell[0][0] == cell[2][2])
		return cell[0][0];  // barande ra bar migardanim
	if (cell[0][2] != 0 && cell[0][2] == cell[1][1] && cell[2][0] == cell[1][1] && cell[2][0] == cell[0][2])
		return cell[1][1];  // barande ra bar migardanim

	// agar kasi barande nashode bashad va hameye khaane ha por bashad yani mosavi shode'and
	int tie = -1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (cell[i][j] == 0)
				tie = 0;
	return tie;   // barmigardanim ke bazi mosavi shode (-1)
}
void TicTacToe::SetTurn(int player)
{
	turn = player;
}
char TicTacToe::GetTurn()
{
	return (turn == 1 ? 'X' : 'O');
}
void TicTacToe::ShowBoard(void) // har vaght seda zade shava safheye bazi ra namayesh midahad
{
	system("CLS");
	cout << "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			if (cell[i][j] == 1)
				cout << "X ";
			else if (cell[i][j] == 2)
				cout << "O ";
			else
				cout << "* ";

		cout << "\n";
	}
}

int main()
{
	TicTacToe board;
	int x;
	char starter;

	// mikhanim ke che kasi bazi ra shoroo mikonad va aan ra moshakhas mikonim
	cout << "Who starts (X/O) ? ";
	cin >> starter;
	board.SetTurn(((starter == 'X' || starter == 'x') ? 1 : 2)); // baraye X => 1 va barate O => 2 ro dar nazar migire

	// ta vaghti ke barande nadarim ya bazi mosavi nashode
	while (!board.HaveWinner()) {
		cout << "Player " << board.GetTurn() << " : "; // bazi ra mikhanim va anjam midahim
		cin >> x;
		if (!board.Play(x)) // agar bazi gheyre mojaz bood
			cout << "Illegal Move ! Try again palyer " << board.GetTurn() << "\n";
	}

	// az while kharej shode'im yani bazi barande dashte ya mosavi shode
	if (board.HaveWinner() > 0) // agar barande dashte migooyim kist
		cout << "\n\nWoww... the winner is " << (board.HaveWinner() == 1 ? "X" : "O") << "\n";
	else
		cout << "\n\nA tie ! \n"; // dar gheyre in soorat yani moasvi shode

	system("PAUSE"); // baraye inke vaghti bazi tamoom shod, napare biroon!
	return 0; // khaste nabashid. bazi tamaam !
}
