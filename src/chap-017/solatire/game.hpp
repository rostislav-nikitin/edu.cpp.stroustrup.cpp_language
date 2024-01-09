#ifndef GAME_HPP
#define GAME_HPP

#include <cstdlib>
#include <string>
#include <iostream>
#include <istream>
#include <ctime>
#include <algorithm>

#include "card.hpp"
#include "home.hpp"
#include "target.hpp"
#include "column.hpp"

namespace Solatire
{
	namespace Engine
	{

		class Game
		{
			static const int CARDS_COUNT = 52;

			static const int COLUMNS_COUNT = 7;
			static const int ALL_COLUMNS_COUNT = COLUMNS_COUNT + 1;
			static const int HOME_COLUMN_INDEX = 0;

			Home<Card> _home;
			Target<Card> _target;
			Column<Card> _columns[COLUMNS_COUNT];

			void init();	

			bool all_columns_full() const;
			int free_count() const;
			void show_home();
			void show_columns();

			int get_max_column_size() const;

			void draw_home();
			void draw_target();
			void draw_columns();

			class MoveResult
			{
				bool _ok;
				std::string _error_message;
			public:
				MoveResult();
				MoveResult(std::string const &error_message);

				bool get_ok() const;
				std::string get_error_message() const;
			};

			MoveResult move_from_home_to_column(int column_number);
			MoveResult move_from_home_to_target();
			MoveResult move_from_column_to_target(int column_number);
			MoveResult move_from_column_to_column(int from_column_number, int to_column_number);

		public:
			Game();

			void show_all();
			void draw();
			void run();
		};

		Game::MoveResult::MoveResult() : _ok(true), _error_message()
		{
		}

		Game::MoveResult::MoveResult(std::string const &error_message) : _ok(false), _error_message(error_message)
		{
		}

		bool Game::MoveResult::get_ok() const
		{
			return _ok;
		}
		std::string Game::MoveResult::get_error_message() const
		{
			return _error_message;
		}

		bool Game::all_columns_full() const
		{
			for(int idx = 0; idx < COLUMNS_COUNT; ++idx)
			{
				if((_columns[idx].invisible_size() + _columns[idx].visible_size()) < (idx + 1))
					return false;
			}

			return true;
		}

		Game::Game()
		{
			std::srand(std::time(0));
			init();
		}
		void Game::init()
		{
			_home.reset();
			_target.reset();
			for(int idx = 0; idx < COLUMNS_COUNT; ++idx)
				_columns[idx].reset();


			bool all_non_house_filled = all_columns_full();
			std::vector<int> used_cards;

			while(used_cards.size() < CARDS_COUNT)
			{
				//Find next card number
				int n;
				while(1)
				{
					n = std::rand() / (RAND_MAX / CARDS_COUNT);
					if(std::find(used_cards.begin(), used_cards.end(), n) == used_cards.end())
					{
						used_cards.push_back(n);
						break;
					}
				}

				if(!all_non_house_filled)
				{
					//Fill column with card
					for(int column_index = 0; column_index < COLUMNS_COUNT; ++column_index)
					{
						if((_columns[column_index].invisible_size() + 1) < (column_index + 1))
						{
							_columns[column_index].push_invisible(n);
							break;
						}
						else if(_columns[column_index].visible_size() < 1)
						{
							_columns[column_index].push_visible(n);
							break;
						}
					}
			
					all_non_house_filled = all_columns_full();
				}
				else
				{
					// File home with a card
					_home.push(n);
				}
			}
		}

		void Game::show_all()
		{
			show_home();
			show_columns();
		}

		void Game::show_home()
		{
			std::cout << "HOME" << std::endl;
			std::cout << "----------------------------------------" << std::endl;

			while(_home.size())
			{
				Card card = _home.top();

				std::cout << card.get_suit() << card.get_rank()  << ", ";
				_home.pop();
			}

			std::cout << std::endl << std::endl;
		}

		void Game::show_columns()
		{
			//Show invisible
			for(int idx = 0; idx < COLUMNS_COUNT; ++idx)
			{
				std::cout << idx << std::endl;
				std::cout << "----------------------------------------" << std::endl;
				while(_columns[idx].invisible_size())
				{
					Card card = _columns[idx].invisible_top();

					std::cout << card.get_suit() << card.get_rank()  << ", ";
					_columns[idx].pop_invisible();
				}
				while(_columns[idx].visible_size())
				{
					Card card = _columns[idx].visible_top();

					std::cout << card.get_suit() << card.get_rank()  << ", ";
					_columns[idx].pop_visible();
				}


				std::cout << std::endl << std::endl;
			}
		}


		int Game::get_max_column_size() const
		{
			int result = 0;
			for(int idx = 0; idx < COLUMNS_COUNT; ++idx)
			{
				int column_size = _columns[idx].invisible_size() + _columns[idx].visible_size();
				if(column_size > result)
					result = column_size;
			}

			return result;
		}
		
		void Game::draw()
		{
			//system("clear");
			draw_home();
			draw_target();
			draw_columns();
		}
		void Game::draw_home()
		{
			std::cout << "    HOME" << std::endl;
			std::cout << "|-----|-----|" << std::endl;

			std::string home_size = std::to_string(_home.size());
			std::cout << "| " << home_size;
			if(home_size.size() == 1)
				std::cout << "  ";
			else if(home_size.size() == 2)
				std::cout << " ";
			std::cout << " | ";

			if(_home.size() != 0)
			{
	 			std::string card_sign = to_string(_home.top().get_suit()) + to_string(_home.top().get_rank());
				std::cout << card_sign;
				if(card_sign.size() == 2)
					std::cout << " ";
			}
			else
			{
				std::cout << "   ";
			}
		   
			std::cout << " |"  << std::endl;
			std::cout << "|-----|-----|" << std::endl;
		}

		void Game::draw_target()
		{
			std::cout << "                     TARGET" << std::endl;
			//Head
			std::cout << "            |";
			for(Suit key = Suit::First; key <= Suit::Last; key = static_cast<Suit>(static_cast<int>(key) + 1))
			{
				std::cout << "-----|";
			}
			std::cout << std::endl;
			// Suits
			std::cout << "            |  ";
			for(Suit key = Suit::First; key <= Suit::Last; key = static_cast<Suit>(static_cast<int>(key) + 1))
			{
				std::cout << key << "  |  ";
			}
			std::cout << std::endl;


			std::cout << "            |";
			for(Suit key = Suit::First; key <= Suit::Last; key = static_cast<Suit>(static_cast<int>(key) + 1))
			{
				std::cout << "-----|";
			}
			std::cout << std::endl;


			// Items
			/*
			_target[0].push_back(Card(10));
			_target[0].push_back(Card(11));
			_target[1].push_back(Card(1));
			_target[3].push_back(Card(5));
			*/
			//std::cout << "cnt=" << _target.get_max_count() << std::endl;
			for(int q_idx = 0; q_idx < _target.get_max_count(); ++q_idx)
			{
				std::cout << "            | ";
				for(Suit key = Suit::First; key <= Suit::Last; key = static_cast<Suit>(static_cast<int>(key) + 1))
				{
					std::deque<Card> &q = _target[static_cast<int>(key)];
					if(q.size() > q_idx)
					{
						std::string card_name = (to_string(q[q_idx].get_suit()) + to_string(q[q_idx].get_rank()));
						int size = card_name.size();
						int spaces = 3 - size;
						std::cout << card_name << std::string(spaces, ' ') << " | ";
					}
					else
					{
						std::cout << " -  | ";
					}
				}
				std::cout << std::endl;
			}

			std::cout << std::endl << std::endl;
		}

		void Game::draw_columns()
		{
			std::cout << "                  COLUMNS" << std::endl;
			int max_column_size = get_max_column_size();

			for(int number = 1; number <= max_column_size; ++number)
			{
				//std::cout << number << std::endl;
				std::cout << "| ";
				for(int column_index = 0; column_index < COLUMNS_COUNT; ++column_index)
				{
					if(_columns[column_index].invisible_size() >= number)
					{
						std::cout << "*** | ";
					}
					else if(_columns[column_index].visible_size() >= (number - _columns[column_index].invisible_size()))
					{
						int v_idx = number - _columns[column_index].invisible_size() - 1;
						Card card = _columns[column_index][v_idx];
						std::string card_sign = to_string(card.get_suit()) + to_string(card.get_rank());
						std::cout << card_sign;
						if(card_sign.size() == 2)
							std::cout << " ";
						std::cout << " | ";
					}
					else
					{
						std::cout << "    | ";
					}
				}
				std::cout << std::endl;
			}
		}


		void Game::run()
		{
			draw();
			while(1)
			{
				try
				{
					//std::cout << _target.get_counts_sum() << std::endl;

					if(_target.get_counts_sum() == CARDS_COUNT)
					{
						std::cout << "Congratulations!" << std::endl << "You WIN!" << std::endl;
						break;
					}

					std::cout << ">";
					char buffer[1024 + 1];
					std::cin.getline(buffer, 1024);
					buffer[1024] = '\0';

					std::string command(buffer);

					if(command == "Q" || command == "q")
						break;

					if(command == "R" || command == "r")
						init();

					MoveResult move_result;

					if(command == "H" || command == "h")
					{
						if(_home.size() > 0)
						{
							Card card = _home.top();
							_home.pop();
							_home.push(card);
						}
					}
					else
					{
						int arrow_pos = command.find("->");
						if(arrow_pos != std::string::npos)
						{
							std::string left = command.substr(0, arrow_pos);
							std::string right = command.substr(arrow_pos + 2);

//							std::cout << left << "::" << right << std::endl;
							if(left[0] == 'H' || left[0] == 'h')
							{
								if(right[0] == 'C' || right[0] == 'c')
								{
									move_result = move_from_home_to_column(atoi(right.substr(1).c_str()));
								}
								else if(right[0] == 'T' || right[0] == 't')
								{
									move_result = move_from_home_to_target();
								}
							}
							else if(left[0] == 'C' || left[0] == 'c')
							{
								if(right[0] == 'T' || right[0] == 't')
								{
									move_result = move_from_column_to_target(atoi(left.substr(1).c_str()));
								}
								else if(right[0] == 'C' || right[0] == 'c')
								{
									move_result = move_from_column_to_column(atoi(left.substr(1).c_str()), atoi(right.substr(1).c_str()));
								}
							}
						
						}
					}

					draw();

					if(!move_result.get_ok())
					{
						std::cout << "Error: " << move_result.get_error_message() << std::endl;
					}
					else
					{
						std::cout << "OK" << std::endl;
					}
				}
				catch(...)
				{
					std::cout << "UNINDEFIED ERROR" << std::endl;
				}

				//std::cout << command;
			}
		}


		Game::MoveResult Game::move_from_home_to_column(int column_number)
		{
			//std::cout << column_number << std::endl;
			int idx = column_number - 1;
			// check rule
			if(_home.size() == 0)
			{
				return MoveResult("Home is empty.");
			}
			if((_columns[idx].visible_size() != 0) 
				&& (_home.top().get_black() == _columns[idx].visible_top().get_black()))
			{
				return MoveResult("Invalid color.");
			}
			if((_columns[idx].visible_size() != 0) 
				&& ((static_cast<int>(_home.top().get_rank()) + 1) != (static_cast<int>(_columns[idx].visible_top().get_rank()))))
			{
				//std::cout << "home rank=" << static_cast<int>(_home.top().get_rank()) << std::endl;
				//std::cout << "column rnak + 1=" << (static_cast<int>(_columns[idx].visible_top().get_rank()) + 1) << std::endl;
				return MoveResult("Invalid rank.");
			}

			Card card = _home.top();
			_home.pop();
			_columns[idx].push_visible(card);

			return MoveResult();
		}

		Game::MoveResult Game::move_from_home_to_target()
		{
			if(_home.size() == 0)
			{
				return MoveResult("Home is empty.");
			}

			Card card = _home.top();
			Suit suit = card.get_suit();
			Rank rank = card.get_rank();

			std::deque<Card> &target = _target[static_cast<int>(suit)];
			if(target.size() == 0)
			{
				if(rank != Rank::Ace)
				{
					std::cout << "ACE ERROR" << std::endl;
					return MoveResult("For empty target card rank should be Ace.");
				}
			}
			else
			{
				if ((static_cast<int>(rank) + 1) != (static_cast<int>(target.back().get_rank())))
				{
					return MoveResult("Rank is wrong.");
				}
			}

			target.push_back(card);
			_home.pop();


			return MoveResult();
		}

		Game::MoveResult Game::move_from_column_to_target(int column_number)
		{
			int idx = column_number - 1;
			if(_columns[idx].visible_size() == 0)
			{
				return MoveResult("Column is empty");
			}

			Card card = _columns[idx].visible_top();
			Suit suit = card.get_suit();
			Rank rank = card.get_rank();

			std::deque<Card> &target = _target[static_cast<int>(suit)];
			if(target.size() == 0)
			{
				if(rank != Rank::Ace)
				{
					return MoveResult("For empty target card rank should be Ace.");
				}
			}
			else
			{
				if ((static_cast<int>(rank) + 1) != (static_cast<int>(target.back().get_rank())))
				{
					return MoveResult("Rank is wrong.");
				}
			}

			target.push_back(card);
			_columns[idx].pop_visible();
			if(_columns[idx].visible_size() == 0 && _columns[idx].invisible_size() != 0)
			{
				Card invisible_card = _columns[idx].invisible_top();
				_columns[idx].push_visible(invisible_card);
				_columns[idx].pop_invisible();
			}

			return MoveResult();
		}

		Game::MoveResult Game::move_from_column_to_column(int from_column_number, int to_column_number)
		{
			int from_idx = from_column_number - 1;
			int to_idx = to_column_number - 1;

			if(_columns[from_idx].visible_size() == 0)
			{
				return MoveResult("Source column is empty.");
			}

			if((_columns[to_idx].visible_size() != 0) 
				&& (_columns[from_idx].visible_top().get_black() == _columns[to_idx].visible_top().get_black()))
			{
				return MoveResult("Invalid Suit");
			}
			
			if((_columns[to_idx].visible_size() != 0) 
				&& ((static_cast<int>(_columns[from_idx].visible_top().get_rank()) + 1) != (static_cast<int>(_columns[to_idx].visible_top().get_rank()))))
			{
				return MoveResult("Invalid rank");
			}

			Card card = _columns[from_idx].visible_top();
			_columns[to_idx].push_visible(card);
			_columns[from_idx].pop_visible();

			if(_columns[from_idx].visible_size() == 0 && _columns[from_idx].invisible_size() != 0)
			{
				Card cardToMove = _columns[from_idx].invisible_top();
				_columns[from_idx].push_visible(cardToMove);
				_columns[from_idx].pop_invisible();
			}

			return MoveResult();;
		}


	}
}

#endif
