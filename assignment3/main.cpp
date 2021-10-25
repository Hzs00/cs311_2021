#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "json.hpp"

int main(int argc, char* argv[])
{
	//professor commands
	std::string commandInit = "--init";
	std::string commandIterations = "--iterations";
	std::string commandMove = "--last_opponent_move";
	std::string confessMove = "confess";
	std::string silentMove = "silent";
	std::string zeroMove = "zero";

	std::vector<std::string> arguments = std::vector<std::string>();
	for (int i = 0; i < argc; i++)
	{
		arguments.push_back(std::string(argv[i]));
	}

	// read a JSON file
	std::ifstream inputStream("data.json");
	nlohmann::json dataJSON;
	inputStream >> dataJSON;

	//game is reset with commandInit
	if (arguments[1].compare(commandInit) == 0) {
		dataJSON.clear();
		//stack is reset with new opponent
	}
	//check amount of iterations that will be played and send to json
	if (argc >= 5 && arguments[3].compare(commandIterations) == 0) {
		dataJSON["AmountofTurns"] = atoi(arguments[4].c_str());
		std::ofstream outputStream("data.json");
		outputStream << dataJSON << "\n";
	}
	//checks opponents last move 
	if (arguments[1].compare(commandMove) == 0) {
		//if we are on the final turn, algorithm will confess
		if (dataJSON["opponentMoveLog"].size() + 1 >= dataJSON["AmountofTurns"]) {
			std::cout << "confess";
			int moveLogSize = dataJSON["opponentMoveLog"].size();
			dataJSON["opponentMoveLog"][moveLogSize] = confessMove;
			std::ofstream outputStream("data.json");
			outputStream << dataJSON << "\n";
		}
		//checks if opponents move is confess, silent, or zero and algorithm reciprocates with same move
		else {
			if (arguments[2].compare(confessMove) == 0) {
				//check json log for previous moves
				std::cout << "confess";
				int moveLogSize = dataJSON["opponentMoveLog"].size();
				dataJSON["opponentMoveLog"][moveLogSize] = confessMove;
				std::ofstream outputStream("data.json");
				outputStream << dataJSON << "\n";
				//then send stack data to json
			}
			else if (arguments[2].compare(silentMove) == 0) {
				std::cout << "silent";
				int moveLogSize = dataJSON["opponentMoveLog"].size();
				dataJSON["opponentMoveLog"][moveLogSize] = silentMove;
				std::ofstream outputStream("data.json");
				outputStream << dataJSON << "\n";
			}
			else if (arguments[2].compare(zeroMove) == 0) {
				std::cout << "silent";
				int moveLogSize = dataJSON["opponentMoveLog"].size();
				dataJSON["opponentMoveLog"][moveLogSize] = zeroMove;
				std::ofstream outputStream("data.json");
				outputStream << dataJSON << "\n";
			}
		}
	}
}
