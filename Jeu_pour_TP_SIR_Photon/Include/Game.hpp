#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <unordered_map>
#include <memory>

#include <ResourceIdentifiers.hpp>
#include <NetworkLogic.hpp>

#include "Menus.h"
#include "FirstMenu.h"
#include "SecondMenu.h"
#include "Questions.h"
#include "LoadData.h"


class Game : private sf::NonCopyable
{
	public:
																	Game();
		void														run();


		struct MenuItem
		{
		public:
			sf::Rect<int>			rect;
			Menus::Action			action;
		};

	public:
		static const int											Width;
		static const int											Height;
		std::unordered_map<Menus::Action, std::shared_ptr<Menus>>	pageMap;
		std::shared_ptr<Menus>										currentPage;

		Menus::Action												currentMode = Menus::Vide;
		Menus::Action												currentTheme = Menus::Vide;
		int															currentScore;

		Menus::Action												opponentMode = Menus::Vide;
		Menus::Action												opponentTheme = Menus::Vide;
		int															opponentScore;

		LoadData													data;


		std::vector<std::string>									vectorOfZeros;
		std::vector<std::string>									vectorChoice;


	private:
		void														processEvents();
		void														render();

	private:
		static const sf::Time										TimePerFrame;

		sf::RenderWindow											mWindow;

		int															mPlayerNumber;

		NetworkLogic												mNetworkLogic;
};

#endif // GAME_HPP
